
// APP02.h: archivo de encabezado principal para la aplicaci�n PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// S�mbolos principales


// CAPP02App:
// Consulte la secci�n APP02.cpp para obtener informaci�n sobre la implementaci�n de esta clase
//

class CAPP02App : public CWinApp
{
public:
	CAPP02App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementaci�n

	DECLARE_MESSAGE_MAP()
};

extern CAPP02App theApp;