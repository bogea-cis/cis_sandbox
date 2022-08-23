// winteste.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "winteste.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

// Elements of usage
HWND old_TextBox;         // exemplo Caixa de texto antiga
HWND now_TextBox;         // exemplo Caixa de texto mais atual
HWND show_TextField;      // exemplo Campo de exibicao de texto
HWND operation_Button;    // exemplo Botao para execucao de rotina
HWND exit_Button;         // exemplo Botao de saida do programa
HWND show_Lable;          // exemplo Lable
HFONT font_Label;          // exemplo de font para Label

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;


	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WINTESTE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINTESTE));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINTESTE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
  //wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
  wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WINTESTE);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
  case WM_CREATE:
    old_TextBox = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 50, 150, 20, hWnd, NULL, NULL, NULL);
    now_TextBox = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 100, 150, 20, hWnd, NULL, NULL, NULL);
    show_TextField = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 20, 150, 150, 20, hWnd, (HMENU)3, NULL, NULL);
    operation_Button = CreateWindow(TEXT("BUTTON"), TEXT("RUN"), WS_VISIBLE | WS_CHILD, 20, 200, 80, 25, hWnd, (HMENU)1, NULL, NULL);
    exit_Button = CreateWindow(TEXT("BUTTON"), TEXT("EXIT"), WS_VISIBLE | WS_CHILD, 120, 200, 80, 25, hWnd, (HMENU)2, NULL, NULL);
    show_Lable = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("STATIC"), TEXT("LABLE para exibição"), WS_CHILD | WS_VISIBLE | SS_CENTER, 20, 20, 210, 20, hWnd, HMENU(NULL), GetModuleHandle(NULL), NULL);
    font_Label = CreateFont(14, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Verdana");
    SendMessage(old_TextBox, WM_SETFONT, WPARAM(font_Label), TRUE);
    SendMessage(now_TextBox, WM_SETFONT, WPARAM(font_Label), TRUE);
    SendMessage(show_TextField, WM_SETFONT, WPARAM(font_Label), TRUE);
    SendMessage(show_Lable, WM_SETFONT, WPARAM(font_Label), TRUE);
    SendMessage(operation_Button, WM_SETFONT, WPARAM(font_Label), TRUE);
    SendMessage(exit_Button, WM_SETFONT, WPARAM(font_Label), TRUE);
    break;

  case WM_COMMAND:
    wmId = LOWORD(wParam);
    wmEvent = HIWORD(wParam);
    // Parse the menu selections:
    switch (wmId)
    {
    case IDM_ABOUT:
      DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
      break;

    case IDM_EXIT:
      DestroyWindow(hWnd);
      break;

    case 1:   // RUN  ( quando o botao RUN for pressionado)
      {
        int oldLen = GetWindowTextLength(old_TextBox) + 1;
        wchar_t* oldtext = new wchar_t[oldLen];
        GetWindowText(old_TextBox, &oldtext[0], oldLen);    // Leitura do que foi digitado em old_TextBox

        int nowLen = GetWindowTextLength(now_TextBox) + 1;
        wchar_t* nowtext = new wchar_t[nowLen];
        GetWindowText(now_TextBox, &nowtext[0], nowLen);    // Leitura do que foi digitado em now_TextBox

        SendMessage(show_TextField, EM_SETSEL, -1, -1);
        SendMessage(show_TextField, EM_REPLACESEL, 0, (LPARAM)&oldtext[0]);   // Escreve em show_TextField
        SendMessage(show_TextField, EM_REPLACESEL, 0, (LPARAM)&nowtext[0]);   // Escreve em show_TextField
        delete[] oldtext;
        delete[] nowtext;

        SetWindowText(old_TextBox, TEXT(""));   // limpa old_TextBox
        SetWindowText(now_TextBox, TEXT(""));   // limpa now_TextBox
        break;
      }

    case 2:   // EXIT  ( quando o botao EXIT for pressionado)
      PostQuitMessage(0);
      break;

    default:
      return DefWindowProc(hWnd, message, wParam, lParam);

    }

    break;

  case WM_SETFONT:
    break;

  case WM_PAINT:
    hdc = BeginPaint(hWnd, &ps);
    // TODO: Add any drawing code here...
    EndPaint(hWnd, &ps);
    break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}



