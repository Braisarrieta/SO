CREATE DATABASE BackgroundDB;
USE BackgroundDB;

CREATE TABLE Backgrounds (
	BackgroundID INT PRIMARY KEY AUTO_INCREMENT,
	Imagen LONGBLOB
	Audio LONGBLOB
);

CREATE DATABASE HistorialDB;
USE HistorialDB;

CREATE TABLE Historiales(
	Username VARCHAR(100) NOT NULL,
	HistorialID INT PRIMARY KEY AUTO_INCREMENT,
	victorias INT NOT NULL,
	derrotas INT NOT NULL,
	N_Partidas INT NOT NULL,
	Personajes VARCHAR(100) NOT NULL
);


INSERT INTO Backgrounds (BackgroundID, Imagen, Audio)
VALUES(1, 'Kame House', 'Audio_Kame'),
	  (2, 'Namek', 'Audio_Namek'),
	  (3, 'Cuarto Mente y Tiempo', 'Audio_Mente_Tiempo'); 
INSERT INTO Historiales(Username, HistorialID, victorias, derrotas, N_Partidas, Personajes)
VALUES('BraisArrieta', 1, 3, 3, 6, 2),
	  ('AngelaCiutat', 2, 4, 2, 6, 3),
	  ('GrigoryFilimonov', 3, 2, 4, 6, 1);
