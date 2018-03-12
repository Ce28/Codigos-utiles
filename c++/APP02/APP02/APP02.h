
// APP02.h: archivo de encabezado principal para la aplicación PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluir 'stdafx.h' antes de incluir este archivo para PCH"
#endif

#include "resource.h"		// Símbolos principales


// CAPP02App:
// Consulte la sección APP02.cpp para obtener información sobre la implementación de esta clase
//

class CAPP02App : public CWinApp
{
public:
	CAPP02App();

// Reemplazos
public:
	virtual BOOL InitInstance();

// Implementación

	DECLARE_MESSAGE_MAP()
};

extern CAPP02App theApp;