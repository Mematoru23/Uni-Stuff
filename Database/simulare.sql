CREATE DATABASE simulare
USE simulare

CREATE TABLE Customers (
    ID INT PRIMARY KEY,
    Name NVARCHAR(256),
    DoB DATE,
    City NVARCHAR(256)
);

CREATE TABLE Flowers (
    ID INT PRIMARY KEY,
    Name NVARCHAR(256),
    Color NVARCHAR(50),
    Price DECIMAL(10,2)
);

CREATE TABLE Orders (
    ID INT PRIMARY KEY,
    CustomerID INT,
    FlowerID INT,
    Quantity INT,
    TotalPrice DECIMAL(10,2),
    OrderDate DATE,
    FOREIGN KEY (CustomerID) REFERENCES Customers(ID),
    FOREIGN KEY (FlowerID) REFERENCES Flowers(ID)
);

INSERT INTO Customers (ID, Name, DoB, City)
VALUES (1, 'Joe', '1980-01-01', 'Bucuresti'),
       (2, 'Mama', '1990-02-02', 'Targu Mures'),
       (3, 'Bob', '2000-03-03', 'Cluj-Napoca');

INSERT INTO Flowers (ID, Name, Color, Price)
VALUES (1, 'Rose', 'roz', 10.00),
       (2, 'idk', 'galben', 15.00),
       (3, 'flowers', 'alb', 20.00);

INSERT INTO Orders (ID, CustomerID, FlowerID, Quantity, TotalPrice, OrderDate)
VALUES (1, 1, 1, 5, 50.30, '2023-12-01'),
       (2, 2, 2, 10, 150.25, '2023-12-02'),
       (3, 3, 3, 15, 300.00, '2023-12-03');

-- view --
GO
CREATE VIEW ClientsAndPrices AS
SELECT c.Name AS ClientName, SUM(o.TotalPrice) AS TotalOrderAmount
FROM Customers c
JOIN Orders o ON c.ID = o.CustomerID
JOIN Flowers f ON o.FlowerID = f.ID
WHERE c.City IN ('Bucuresti', 'Targu Mures', 'Cluj-Napoca', 'Brasov') AND f.Color = 'roz'
GROUP BY c.ID, c.Name
HAVING SUM(o.TotalPrice) > 150
GO
SELECT * FROM ClientsAndPrices;

-- validator --
GO
CREATE FUNCTION ValidClientData(
	@ID INT,
    @Name NVARCHAR(256),
    @DoB DATE,
    @City NVARCHAR(256)
)
RETURNS BIT
AS
BEGIN
    DECLARE @IsValid BIT = 1;
    IF @DoB >= '2010-01-01'
        SET @IsValid = 0;
    IF @City NOT IN ('Bucuresti', 'Targu Mures', 'Cluj-Napoca', 'Brasov', 'Sibiu', 'Iasi', 'Braila')
        SET @IsValid = 0;

    RETURN @IsValid;
END;
GO

-- procedure --
CREATE PROCEDURE InsertClient
	@ClientID INT,
    @ClientName NVARCHAR(256),
    @ClientDoB DATE,
    @ClientCity NVARCHAR(256)
AS
BEGIN
    DECLARE @IsValid BIT;
    SET @IsValid = dbo.ValidClientData(@ClientID, @ClientName, @ClientDoB, @ClientCity);

    BEGIN TRY
        IF @IsValid = 1
        BEGIN
            INSERT INTO Customers (ID, Name, DoB, City)
            VALUES (@ClientID, @ClientName, @ClientDoB, @ClientCity);
            PRINT 'Inserat cu succes.';
        END
        ELSE
        BEGIN
            THROW 51000, 'Datele invalide.', 1;
        END;
    END TRY
    BEGIN CATCH
        PRINT 'Eroare: ' + ERROR_MESSAGE();
    END CATCH;
END;
GO
EXEC InsertClient 5, 'Eu', '1995-08-20', 'Bucuresti';


-- trigger --
DROP TRIGGER IdkNameForThis;
GO
CREATE TRIGGER IdkNameForThis
ON Orders
INSTEAD OF INSERT
AS
BEGIN
    DECLARE @TimeStamp DATETIME = GETDATE();

    INSERT INTO Orders (ID, CustomerID, FlowerID, Quantity, TotalPrice, OrderDate)
    SELECT
        I.ID,
        I.CustomerID,
        I.FlowerID,
        I.Quantity,
        I.TotalPrice,
        I.OrderDate
    FROM
        INSERTED I
    JOIN
        Flowers F ON I.FlowerID = F.ID
    WHERE
        ISNUMERIC(I.ID) = 1
        AND ISNUMERIC(I.TotalPrice) = 1
        AND CAST(I.TotalPrice AS DECIMAL(10,2)) >= 0
        AND F.Color IN ('roz', 'albastru', 'rosu', 'verde', 'galben', 'alb');

    IF @@ROWCOUNT > 0
        PRINT 'Insert reusit la ' + CONVERT(NVARCHAR, @TimeStamp, 120);
    ELSE
        PRINT 'Insert esuat la ' + CONVERT(NVARCHAR, @TimeStamp, 120);
END;
GO

INSERT INTO Orders (ID, CustomerID, FlowerID, Quantity, TotalPrice, OrderDate)
VALUES (10, 1, 3, 5, 150.12, '2002-12-01');
SELECT * FROM Orders;

SELECT * FROM Customers;
SELECT * FROM Flowers;