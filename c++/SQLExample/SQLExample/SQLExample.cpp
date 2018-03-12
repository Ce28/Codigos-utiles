// SQLExample.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <iostream>
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>

using namespace std;

void showSQLError(unsigned int handleType, const SQLHANDLE& handle)
{
	SQLCHAR SQLState[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
	{
		cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	SQLHANDLE SQLEnvHandle = NULL;
	SQLHANDLE SQLConnectionHandle = NULL;
	SQLHANDLE SQLStatementHandle = NULL;
	SQLRETURN retCode = 0;
	//char SQLQuery[] = "SELECT * FROM ctl_CRUDChristian";
	//char SQLQuery[] = "INSERT INTO EmpleadosCoppel.dbo.ctl_CRUDChristian(iCodigo,cNombre,cApellidoPaterno,cApellidoMaterno,cDireccion,cTelefono,dFechaNacimiento) VALUES (3,'Marco','Piña','Angulo','Calle Miguel Barragan','6671433244','1994-07-21')";
	char SQLQuery[] = "DELETE FROM EmpleadosCoppel.dbo.ctl_CRUDChristian WHERE iCodigo = 3";
	//char SQLQuery[] = "UPDATE EmpleadosCoppel.dbo.ctl_CRUDChristian	SET cNombre = 'Ariel',cApellidoPaterno = 'Ochoa',cApellidoMaterno = 'Gamez',cDireccion = 'Miguel Barragan',cTelefono = '6671423147',dFechaNacimiento = '2000-08-20'	WHERE iCodigo = 3";
	do
	{
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
		{
			break;
		}
		if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		{
			break;
		}
		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
		{
			break;
		}
		if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
		{
			break;
		}

		SQLCHAR retConString[1024];
		switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=localhost, 1433; DATABASE=EmpleadosCoppel; UID=Sapien; PWD=123;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT))
		{
		case SQL_SUCCESS:
			break;
		case SQL_SUCCESS_WITH_INFO:
			break;
		case SQL_NO_DATA_FOUND:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_INVALID_HANDLE:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		case SQL_ERROR:
			showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
			retCode = -1;
			break;
		default:
			break;
		}

		if (retCode == -1)
		{
			break;
		}

		if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
		{
			break;
		}
	

		//Funciona para el insert, update y delete. Muestra la cantidad de renglones modificados.
		retCode = SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS);
		if (SQL_SUCCEEDED(retCode))
		{
			SQLINTEGER numRows;
			retCode = SQLRowCount(SQLStatementHandle, &numRows);
			cout << numRows;
		}
		else
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}

		//Funciona para el select. Muestra todos los datos mientras lea uno.
		if (SQL_SUCCESS == SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS))
		{
			int codigo;
			char name[256];
			while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS)
			{
				SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &codigo, sizeof(name), NULL);
				SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
				cout << codigo << " " << name << endl;
			}
		}
		else
		{
			showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
			break;
		}

	} while (FALSE);

	SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
	SQLDisconnect(SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);


	getchar();

	return 0;
}

