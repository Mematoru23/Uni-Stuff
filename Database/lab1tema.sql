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
    PRIMARY KEY (GameID, PlayerID),
    FOREIGN KEY (GameID) REFERENCES Games(GameID),
    FOREIGN KEY (PlayerID) REFERENCES Players(PlayerID)
);

CREATE TABLE Scores (
    ScoreID INT PRIMARY KEY,
    Score INT,
    GameID INT,
    PlayerID INT,
    FOREIGN KEY (GameID) REFERENCES Games(GameID),
    FOREIGN KEY (PlayerID) REFERENCES Players(PlayerID)
);