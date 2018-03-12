USE EmpleadosCoppel
GO

IF EXISTS (SELECT NAME FROM SYSOBJECTS(NOLOCK) WHERE NAME = 'proc_UtileriasCRUDChristian')
	DROP PROCEDURE dbo.proc_UtileriasCRUDChristian
GO

CREATE PROCEDURE dbo.proc_UtileriasCRUDChristian
	@iOpcion		TINYINT,
	@iParametro1	INT,		
	@cParametro2	VARCHAR(50),
	@cParametro3	VARCHAR(40),	
	@cParametro4	VARCHAR(40),	
	@cParametro5	VARCHAR(50),	
	@cParametro6	VARCHAR(10),	
	@dParametro7	DATE
/*************************************************************
FECHA:			29/01/2018
DESCRIPCION:	Opcion
					0: Crear
					1: Busqueda
					2: Actualizar
					3: Eliminar
					4: Busqueda por cNombre
					5: Busqueda por iCodigo
REALIZO:		Sapein Gamez Christian Enrique
SOLICITO:		Armenta Gonzalez Carmen Lidia
*************************************************************/

/*************************************************************
MODIFICO:		Sapien Gamez Christian Enrique
SOLICITO:		Armenta Gonzalez Carmen Lidia
PETICION:		143343
*************************************************************/
AS
BEGIN
	--Ejecuta la creacion del nuevo registro en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian.
	IF @iOpcion = 0
	BEGIN
		INSERT INTO EmpleadosCoppel.dbo.ctl_CRUDChristian(
					iCodigo,
					cNombre,
					cApellidoPaterno,
					cApellidoMaterno,
					cDireccion,
					cTelefono,
					dFechaNacimiento)
		VALUES (
					@iParametro1,
					@cParametro2,
					@cParametro3,
					@cParametro4,
					@cParametro5,
					@cParametro6,
					@dParametro7)
	END

	--Ejecuta una consulta en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian.
	ELSE IF @iOpcion = 1
	BEGIN
		SELECT iCodigo, cNombre, cApellidoPaterno, cApellidoMaterno, cDireccion, cTelefono, dFechaNacimiento 
			FROM EmpleadosCoppel.dbo.ctl_CRUDChristian
	END

	--Ejecuta el actualizar de un registro en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian.
	ELSE IF @iOpcion = 2
	BEGIN
		UPDATE EmpleadosCoppel.dbo.ctl_CRUDChristian
		SET cNombre = @cParametro2,
			cApellidoPaterno = @cParametro3,
			cApellidoMaterno = @cParametro4,
			cDireccion = @cParametro5,
			cTelefono = @cParametro6,
			dFechaNacimiento = @dParametro7
		WHERE iCodigo = @iParametro1
	END

	--Ejecuta un delete en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian.
	ELSE IF @iOpcion = 3
	BEGIN
		DELETE FROM EmpleadosCoppel.dbo.ctl_CRUDChristian 
			WHERE iCodigo = @iParametro1
	END	
	
	--Ejecuta una consulta en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian.
	ELSE IF @iOpcion = 4
	BEGIN
		SELECT iCodigo, cNombre, cApellidoPaterno, cApellidoMaterno, cDireccion, cTelefono, dFechaNacimiento 
			FROM EmpleadosCoppel.dbo.ctl_CRUDChristian
			WHERE cNombre like '%' + @cParametro2 + '%'
	END

	--Ejecuta una consulta en la tabla EmpleadosCoppel.dbo.ctl_CRUDChristian por iCodigo.
	ELSE IF @iOpcion = 5
	BEGIN
		SELECT iCodigo, cNombre, cApellidoPaterno, cApellidoMaterno, cDireccion, cTelefono, dFechaNacimiento 
			FROM EmpleadosCoppel.dbo.ctl_CRUDChristian
			WHERE iCodigo = @iParametro1
	END
END
GO

/*****
GRANT EXECUTE ON proc_UtileriasCRUDChristian TO sysprogsmuebles
GO
proc_documentacion 'proc_UtileriasCRUDChristian','','Administra las diferentes opciones'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@iOpcion','Numero de opcion'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@iParametro1','Parametro de entrada 1'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@cParametro2','Parametro de entrada 2'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@cParametro3','Parametro de entrada 3'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@cParametro4','Parametro de entrada 4'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@cParametro5','Parametro de entrada 5'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@cParametro6','Parametro de entrada 6'
GO
proc_documentacion 'proc_UtileriasCRUDChristian','@dParametro7','Parametro de entrada 7'
GO
*****/

