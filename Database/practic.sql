CREATE DATABASE InscriereLaCursuri;
USE InscriereLaCursuri;

CREATE TABLE Studenti (
    StudentID INT PRIMARY KEY,
    Nume VARCHAR(50),
    Prenume VARCHAR(50),
    DataNasterii DATE,
	Telefon VARCHAR(50)
);

CREATE TABLE Cursuri (
    CursID INT PRIMARY KEY,
    NumeCurs VARCHAR(100),
    Descriere TEXT,
    ProfesorID INT,
    FOREIGN KEY (ProfesorID) REFERENCES Profesori(ProfesorID)
);

CREATE TABLE Inscrieri (
    InscriereID INT PRIMARY KEY,
    StudentID INT,
    CursID INT,
    Nota INT,
    FOREIGN KEY (StudentID) REFERENCES Studenti(StudentID),
    FOREIGN KEY (CursID) REFERENCES Cursuri(CursID)
);

CREATE TABLE Profesori (
    ProfesorID INT PRIMARY KEY,
    NumeProfesor VARCHAR(50),
    PrenumeProfesor VARCHAR(50),
);

INSERT INTO Studenti (StudentID, Nume, Prenume, DataNasterii, Telefon)
VALUES
    (1, 'Vasilinovici', 'Ion', '2002-02-23', '0723123123'),
    (2, 'Vintila', 'Eu', '1999-02-25', '0723123123'),
    (3, 'Cineva', 'Andrei', '1992-02-23', '0723123123');

INSERT INTO Profesori (ProfesorID, NumeProfesor, PrenumeProfesor)
VALUES
    (1, 'Ghita', 'Romanta'),
    (2, 'Cineva', 'Mihai'),
    (3, 'Vale', 'Eusebiu');

INSERT INTO Cursuri (CursID, NumeCurs, Descriere, ProfesorID)
VALUES
    (101, 'Mate', 'Calcule', 1),
    (102, 'Info', 'Programare nu in Java', 2),
    (103, 'Chimie', 'Ceva', 3);

INSERT INTO Inscrieri (InscriereID, StudentID, CursID, Nota)
VALUES
    (1, 1, 101, 8),
    (2, 1, 102, 9),
    (3, 2, 101, 7),
    (4, 2, 103, 8),
    (5, 3, 102, 10);

SELECT * FROM Studenti;
SELECT * FROM Profesori;
SELECT * FROM Cursuri;
SELECT * FROM Inscrieri;

GO
CREATE FUNCTION CalculateAverageGrade(@StudentID INT)
RETURNS DECIMAL(5, 2)
AS
BEGIN
    DECLARE @AverageGrade DECIMAL(5, 2);

    SELECT @AverageGrade = AVG(Nota)
    FROM Inscrieri
    WHERE StudentID = @StudentID;

    RETURN ISNULL(@AverageGrade, 0);
END;

GO
SELECT dbo.CalculateAverageGrade(3);
