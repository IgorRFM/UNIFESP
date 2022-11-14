    CREATE DATABASE telemedDB;


CREATE TABLE Paciente (
    ID_Paciente int(10) AUTO_INCREMENT,
    Nome varchar(255),
    Data_Nascimento date,
    Login varchar(255),
    Senha varchar(255),
    Convenio varchar(255),
    Email varchar(255),
    PRIMARY KEY (ID_Paciente)
);


CREATE TABLE Area_Medicina (
    ID_Area int(10) NOT NULL,
    Nome_Area char(255) NOT NULL,
    PRIMARY KEY(ID_Area)
);
CREATE TABLE Medicamento (
    ID_Remedio int(10) NOT NULL AUTO_INCREMENT,
    Nome_Medicamento char(255) NOT NULL,
    Jejum int(10),
    Horario char(255),
    Receita char(255),
    PRIMARY KEY (ID_Remedio)
);

CREATE TABLE Medico (
    ID_Medico int(10) AUTO_INCREMENT,
    Nome varchar(255),
    Login varchar(255),
    Senha varchar(255),
    Preco_Particular int(10),
    Dias_Atendimento date,
    Horario_Atendimento timestamp,
    Email varchar(255),
    Area_Medicina_ID_Area int(10),
    PRIMARY KEY (ID_Medico),
    FOREIGN KEY (Area_Medicina_ID_Area) REFERENCES Area_Medicina(ID_Area)
);

CREATE TABLE Exame (
    ID_Exame int(10) NOT NULL AUTO_INCREMENT,
    Nome_Exame char(255) NOT NULL,
    Clinica char(255) NOT NULL,
    Data date NOT NULL,
    Jejum char(255),
    PRIMARY KEY (ID_Exame)
);

CREATE TABLE Consulta (
    ID_Consulta int(10) NOT NULL AUTO_INCREMENT,
    Data date NOT NULL,
    Horario time NOT NULL,
    Link char(255) NOT NULL,
    ID_Paciente int(10) NOT NULL,
    ID_Medico int(10) NOT NULL,
    Receitas char(255),
    Exames char(255),
    PRIMARY KEY (ID_Consulta),
    FOREIGN KEY (ID_Paciente) REFERENCES Paciente(ID_Paciente),
    FOREIGN KEY (ID_Medico) REFERENCES Medico(ID_Medico)
);

CREATE TABLE Medicamento_Consulta (
    ID_Remedio int(10) NOT NULL,
    ID_Consulta int(10) NOT NULL,
    FOREIGN KEY (ID_Remedio) REFERENCES Medicamento(ID_Remedio),
    FOREIGN KEY (ID_Consulta) REFERENCES Consulta(ID_Consulta)
);
CREATE TABLE Exame_Consulta (
    ID_Exame int(10) NOT NULL,
    ID_Consulta int(10) NOT NULL,
    FOREIGN KEY (ID_Exame) REFERENCES Exame(ID_Exame),
    FOREIGN KEY (ID_Consulta) REFERENCES Consulta(ID_Consulta)
);