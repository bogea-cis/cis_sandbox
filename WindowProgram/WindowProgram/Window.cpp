#include "Window.h"
HWND TextBox1;
HWND TextBox2;
HWND TextField;
HWND BeepButton;
HWND QuitButton;

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CREATE:

    //create a button for wParam = 1
    BeepButton = CreateWindow(TEXT("button"), TEXT("Beep"), WS_VISIBLE | WS_CHILD, 20, 50, 80, 25, hWnd, (HMENU)1, NULL, NULL);

    //create a button for wParam = 2
    QuitButton = CreateWindow(TEXT("button"), TEXT("Quit"), WS_VISIBLE | WS_CHILD, 120, 50, 80, 25, hWnd, (HMENU)2, NULL, NULL);

    //create a TextBox with old border style
    TextBox1 = CreateWindow(TEXT("Edit"), TEXT("Test text 1"), WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 150, 150, 20, hWnd, NULL, NULL, NULL);

    //create a TextBox with new 3D border style
    TextBox2 = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("Edit"), TEXT("Test text 2"), WS_VISIBLE | WS_CHILD, 20, 200, 150, 20, hWnd, NULL, NULL, NULL);

    //create a TextField non editable
    TextField = CreateWindow(TEXT("EDIT"), TEXT(""), WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY, 20, 250, 150, 20, hWnd, (HMENU)3, NULL, NULL);

    break;

  case WM_COMMAND:
    if (LOWORD(wParam) == 1) {
      Beep(40, 50);
      int len = GetWindowTextLength(TextBox1) + 1;
      char* text = new char[len];
      GetWindowText(TextBox1, &text[0], len);

      SendMessage(TextBox2, EM_SETSEL, -1, -1);
      SendMessage(TextBox2, EM_REPLACESEL, 0, (LPARAM)&text[0]);
      SendMessage(TextField, EM_SETSEL, -1, -1);
      SendMessage(TextField, EM_REPLACESEL, 0, (LPARAM)&text[0]);
      delete[] text;

      SetWindowText(TextBox1, "");
    }
    if (LOWORD(wParam) == 2) {
      PostQuitMessage(0);
    }
    break;

  case WM_CLOSE:
    DestroyWindow(hWnd);
    break;

  case WM_DESTROY:
    PostQuitMessage(0);
    return 0;
  }

  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window()
  : m_hInstance(GetModuleHandle(nullptr))
{
  const char* CLASS_NAME = "My Window Class";

  WNDCLASS wndClass = {};
  wndClass.lpszClassName = CLASS_NAME;
  wndClass.hInstance = m_hInstance;
  wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
  wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
  wndClass.lpfnWndProc = WindowProc; 

  RegisterClass(&wndClass);

  DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

  int width = 640;
  int height = 480;

  RECT rect;
  rect.left = 250;
  rect.top = 250;
  rect.right = rect.left + width;
  rect.bottom = rect.top + height;

  AdjustWindowRect(&rect, style, false);

  m_hWnd = CreateWindowEx(
    0,
    CLASS_NAME,
    "Bogea program",
    style,
    rect.left,
    rect.top,
    rect.right - rect.left,
    rect.bottom - rect.top,
    NULL,
    NULL,
    m_hInstance,
    NULL
  );

  ShowWindow(m_hWnd, SW_SHOW);
}


Window::~Window()
{
  const char* CLASS_NAME = "My Window Class";

  UnregisterClass(CLASS_NAME, m_hInstance);
}

bool Window::ProcessMessages()
{
  MSG msg = {};

  while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
  {
    if (msg.message == WM_QUIT)
    {
      return false;
    }

    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }

  return true;
}