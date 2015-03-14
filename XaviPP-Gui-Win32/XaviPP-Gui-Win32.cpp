/*
 * XaviPP-Gui-Win32.c: GUI Frontend for Xavi using MFC Framework
 * Copyright 2015 Vincent Damewood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define _WIN32_WINNT NTDDI_WIN7
#include <afxwin.h>

#include <XaviPP/FunctionCaller.hpp>

#include "EvalWindow.hpp"

class XaviApp : public CWinApp
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

BOOL XaviApp::InitInstance()
{
	CWinApp::InitInstance();
	
	Xavi::FunctionCaller::SetUp();

	if (!(m_pMainWnd = new EvalWindow))
		return FALSE;

	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

int XaviApp::ExitInstance()
{
	Xavi::FunctionCaller::TearDown();

	return CWinApp::ExitInstance();
}

XaviApp theApp;
