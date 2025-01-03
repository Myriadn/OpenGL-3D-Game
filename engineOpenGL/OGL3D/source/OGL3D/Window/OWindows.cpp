#include <OGL3D/Window/OWindows.h>
#include <Windows.h>
#include <assert.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		OWindows* window = (OWindows *)GetWindowLongPtr(hWnd, GWLP_USERDATA);
		window->onDestroy();
		break;
	}

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return NULL;
}

OWindows::OWindows()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpszClassName = L"OGL3DWindow";
	wc.lpfnWndProc = &WndProc;

	assert(RegisterClassEx(&wc));

	RECT rc = { 0, 0, 900, 600 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, L"OGL3DWindow", L"Myriadn | OpenGL 3D Game", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	assert(m_handle);

	SetWindowLongPtr((HWND)m_handle, GWLP_USERDATA, (LONG_PTR)this);

	ShowWindow((HWND)m_handle, SW_SHOW);
	UpdateWindow((HWND)m_handle);
}

OWindows::~OWindows()
{
	DestroyWindow((HWND)m_handle);
}

void OWindows::onDestroy()
{
	m_handle = nullptr;
}

bool OWindows::isClosed()
{
	return !m_handle;
}
