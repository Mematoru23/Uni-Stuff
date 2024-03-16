CREATE DATABASE GAMES;
USE GAMES;

CREATE TABLE Developers (
    DeveloperID INT PRIMARY KEY,
    Name VARCHAR(100),
    Country VARCHAR(50)
);

CREATE TABLE Games (
    GameID INT PRIMARY KEY,
    Title VARCHAR(100),
    Genre VARCHAR(50),
    DeveloperID INT,
    FOREIGN KEY (DeveloperID) REFERENCES Developers(DeveloperID)
);

CREATE TABLE Players (
    PlayerID INT PRIMARY KEY,
    Username VARCHAR(50),
    Email VARCHAR(100)
);

CREATE TABLE Game_Players (
    GameID INT,
    PlayerID INT,
    ScoreID INT,
    PRIMARY KEY (GameID, PlayerID),
    FOREIGN KEY (GameID) REFERENCES Games(GameID),
    FOREIGN KEY (PlayerID) REFERENCES Players(PlayerID),
    FOREIGN KEY (ScoreID) REFERENCES Scores(ScoreID)
);

CREATE TABLE Scores (
    ScoreID INT PRIMARY KEY,
    Score INT
);

INSERT INTO Developers (DeveloperID, Name, Country) VALUES (1, 'John', 'USA'), (2, 'Jane', 'UK');
INSERT INTO Developers (DeveloperID, Name, Country) VALUES (3, 'Alice', 'Canada'), (4, 'Bob', 'Australia');
INSERT INTO Developers (DeveloperID, Name, Country) VALUES (5, 'Charlie', 'USA');
INSERT INTO Developers (DeveloperID, Name, Country) VALUES (6, 'Lucy', 'UK');
INSERT INTO Developers (DeveloperID, Name, Country) VALUES (7, 'Linus', 'Canada');

INSERT INTO Games (GameID, Title, Genre, DeveloperID) VALUES (1, 'Game 1', 'Action', 1), (2, 'Game 2', 'Adventure', 2);
INSERT INTO Games (GameID, Title, Genre, DeveloperID) VALUES (3, 'Game 3', 'RPG', 3), (4, 'Game 4', 'Strategy', 4);
INSERT INTO Games (GameID, Title, Genre, DeveloperID) VALUES (5, 'Game 5', 'Simulation', 5);
INSERT INTO Games (GameID, Title, Genre, DeveloperID) VALUES (6, 'Game 6', 'Puzzle', 6);
INSERT INTO Games (GameID, Title, Genre, DeveloperID) VALUES (7, 'Game 7', 'Horror', 7);

INSERT INTO Players (PlayerID, Username, Email) VALUES (1, 'Player1', 'player1'), (2, 'Player2', 'player2');
INSERT INTO Players (PlayerID, Username, Email) VALUES (3, 'Player3', 'random3'), (4, 'Player4', 'random4');
INSERT INTO Players (PlayerID, Username, Email) VALUES (5, 'Player5', 'random5');
INSERT INTO Players (PlayerID, Username, Email) VALUES (6, 'Player6', 'player6');
INSERT INTO Players (PlayerID, Username, Email) VALUES (7, 'Player7', 'player7');

INSERT INTO Scores (ScoreID, Score) VALUES (1, 2000), (2, 2500);
INSERT INTO Scores (ScoreID, Score) VALUES (3, 3000), (4, 3500);
INSERT INTO Scores (ScoreID, Score) VALUES (5, 4000);
INSERT INTO Scores (ScoreID, Score) VALUES (6, 4500);
INSERT INTO Scores (ScoreID, Score) VALUES (7, 5000);

INSERT INTO Game_Players (GameID, PlayerID, ScoreID) VALUES (1, 1, 1), (2, 2, 2);
INSERT INTO Game_Players (GameID, PlayerID, ScoreID) VALUES (3, 3, 3), (4, 4, 4);
INSERT INTO Game_Players (GameID, PlayerID, ScoreID) VALUES (5, 5, 5);
INSERT INTO Game_Players (GameID, PlayerID, ScoreID) VALUES (6, 6, 6);
INSERT INTO Game_Players (GameID, PlayerID, ScoreID) VALUES (7, 7, 7);

SELECT * FROM Developers;
SELECT * FROM Games;
SELECT * FROM Players;
SELECT * FROM Scores;
SELECT * FROM Game_Players;

delete from Game_Players;
delete from games;
delete from Players;
delete from Scores;
DELETE FROM Developers;

UPDATE Developers SET Name = 'JANE' WHERE DeveloperID = 1;
UPDATE Games SET Title = 'SUPER 1' WHERE GameID = 3;
UPDATE Players SET Username = 'SUPER PLAYER 5000' WHERE PlayerID = 5;
UPDATE Developers SET Name = 'JUCY' WHERE DeveloperID = 2;
UPDATE Games SET Title = 'SUPER 2', Genre = 'Strategy' WHERE GameID = 2;
UPDATE Players SET Username = 'JOHN', Email = 'SUPERplayer2' WHERE PlayerID = 2;

DELETE FROM Game_Players WHERE GameID IN (4, 5, 6);
DELETE FROM Games WHERE GameID IN (1, 2);
DELETE FROM Players WHERE PlayerID IN (1, 2, 3);
DELETE FROM Developers WHERE DeveloperID IN (1, 2);

SELECT DeveloperID FROM Developers WHERE Country = 'USA'
UNION
SELECT DeveloperID FROM Games WHERE Title LIKE '%Game%'

SELECT G.Title, D.Name, P.Username 
FROM Games G
INNER JOIN Developers D ON G.DeveloperID = D.DeveloperID
LEFT JOIN Game_Players GP ON G.GameID = GP.GameID
LEFT JOIN Players P ON GP.PlayerID = P.PlayerID

SELECT G.DeveloperID, COUNT(*) as GameCount
FROM Games G
GROUP BY G.DeveloperID
HAVING COUNT(*) > 1

SELECT Games.Title, AVG(Scores.Score) AS AverageScore
FROM Game_Players
JOIN Games ON Game_Players.GameID = Games.GameID
JOIN Scores ON Game_Players.ScoreID = Scores.ScoreID
GROUP BY Games.Title;

SELECT Games.Title, MAX(Scores.Score) AS HighestScore
FROM Game_Players
JOIN Games ON Game_Players.GameID = Games.GameID
JOIN Scores ON Game_Players.ScoreID = Scores.ScoreID
GROUP BY Games.Title;

SELECT * FROM Developers
WHERE DeveloperID IN (
    SELECT DeveloperID FROM Games
    WHERE Genre = 'Action'
)

SELECT * FROM Games G
WHERE EXISTS (
    SELECT * FROM Game_Players GP
    WHERE G.GameID = GP.GameID AND GP.ScoreID IN (
        SELECT ScoreID FROM Scores
        WHERE Score > 3000
    )
)

SELECT * FROM Games
WHERE Genre = 'Action' AND (DeveloperID = 1 OR DeveloperID = 2) AND NOT Title = 'Game 1'

SELECT DISTINCT Genre FROM Games


CREATE PROCEDURE InsertIntoDevelopers
    @Name VARCHAR(100),
    @Country VARCHAR(50)
AS
BEGIN
    INSERT INTO Developers(Name, Country)
    VALUES (@Name, @Country)
END

CREATE PROCEDURE InsertIntoGames
    @Title VARCHAR(100),
    @Genre VARCHAR(50),
    @DeveloperID INT
AS
BEGIN
    INSERT INTO Games(Title, Genre, DeveloperID)
    VALUES (@Title, @Genre, @DeveloperID)
END

CREATE PROCEDURE InsertIntoGame_Players
    @GameID INT,
    @PlayerID INT,
    @ScoreID INT
AS
BEGIN
    INSERT INTO Game_Players(GameID, PlayerID, ScoreID)
    VALUES (@GameID, @PlayerID, @ScoreID)
END

CREATE FUNCTION ValidateName(@Name VARCHAR(100))
RETURNS BIT
AS
BEGIN
    IF LEN(@Name) > 0
        RETURN 1
    ELSE
        RETURN 0
END

CREATE FUNCTION ValidateTitle(@Title VARCHAR(100))
RETURNS BIT
AS
BEGIN
    IF LEN(@Title) > 0
        RETURN 1
    ELSE
        RETURN 0
END

CREATE FUNCTION ValidateScore(@Score INT)
RETURNS BIT
AS
BEGIN
    IF @Score >= 0
        RETURN 1
    ELSE
        RETURN 0
END

CREATE VIEW View1 AS
SELECT Games.Title, Developers.Name, Players.Username
FROM Game_Players
JOIN Games ON Game_Players.GameID = Games.GameID
JOIN Developers ON Games.DeveloperID = Developers.DeveloperID
JOIN Players ON Game_Players.PlayerID = Players.PlayerID


CREATE TRIGGER InsertTrigger ON Game_Players
AFTER INSERT
AS
BEGIN
    PRINT 'Data și ora: ' + CONVERT(NVARCHAR, GETDATE()) + ', Tipul operației: Insert, Numele tabelului: Game_Players'
END

CREATE TRIGGER DeleteTrigger ON Game_Players
AFTER DELETE
AS
BEGIN
    PRINT 'Data și ora: ' + CONVERT(NVARCHAR, GETDATE()) + ', Tipul operației: Delete, Numele tabelului: Game_Players'
END
