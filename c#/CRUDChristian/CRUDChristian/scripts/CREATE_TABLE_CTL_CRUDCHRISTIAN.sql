USE EmpleadosCoppel
GO

IF EXISTS (SELECT NAME FROM SYSOBJECTS(NOLOCK) WHERE NAME = 'ctl_CRUDChristian')
	DROP TABLE ctl_CRUDChristian
GO

CREATE TABLE EmpleadosCoppel.dbo.ctl_CRUDChristian
(
	iCodigo				INT DEFAULT 0 NOT NULL,
	cNombre				VARCHAR(50) DEFAULT '' NOT NULL,
	cApellidoPaterno	VARCHAR(40) DEFAULT '' NOT NULL,
	cApellidoMaterno	VARCHAR(40) DEFAULT '' NOT NULL,
	cDireccion			VARCHAR(50) DEFAULT '' NOT NULL,
	cTelefono			VARCHAR(10) DEFAULT '' NOT NULL,
	dFechaNacimiento	DATE DEFAULT '' NOT NULL
)
GO

/***************************************************
BASE DE DATOS:	EmpleadosCoppel
TABLA:			ctl_CRUDChristian
FECHA:			29/01/2018
DESCRIPCIÓN:	Script encargado de la creación de la tabla ctl_CRUDChristian
REALIZO:		Sapien Gamez Christian Enrique
SOLICITO:		Armenta Gonzalez Carmen Lidia
***************************************************/

/**
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','','Script encargado de la creación de la tabla ctl_CRUDChristian'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','iCodigo','Numero de empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','cNombre','Nombre del empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','cApellidoPaterno','Apellido paterno del empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','cApellidoMaterno','Apellido materno del empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','cDireccion','Direccion del empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','cTelefono','Telefono del empleado'
EXEC PROC_DOCUMENTACION 'EmpleadosCoppel.dbo.ctl_CRUDChristian','dFechaNacimiento','Fecha de nacimiento del empleado'
**/

