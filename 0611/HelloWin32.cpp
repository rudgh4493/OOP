#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpszCmdLine,
	int nCmdShow)
{
	HWND 		hwnd;			// ������ �ڵ�
	MSG 		msg;			// �޽��� ����ü
	WNDCLASSEX	WndClass;   		// ������ Ŭ���� ����ü		

	// �� ������ Ŭ���� ����ü WndClass�� ���� ä�� ������ Ŭ������ ����Ѵ�. 
	WndClass.cbSize = sizeof(WNDCLASSEX);				// ����ü ũ��
	WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	// Ŭ���� ��Ÿ��
	WndClass.lpfnWndProc = WndProc;					// ������ ���ν���
	WndClass.cbClsExtra = 0;						// ������Ŭ���� �����Ϳ���
	WndClass.cbWndExtra = 0;						// �������� �����Ϳ���
	WndClass.hInstance = hInstance;				// �ν��Ͻ� �ڵ�
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);			// ������ �ڵ�
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);			// Ŀ�� �ڵ�
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ��� �귯�� �ڵ�
	WndClass.lpszMenuName = NULL;				      // �޴� �̸�
	WndClass.lpszClassName = "EasyText";			          // ������ Ŭ���� �̸�
	WndClass.hIconSm = 0;					 // �⺻���� ���� ������

	// ������ Ŭ������ ����Ѵ�. 
	RegisterClassEx(&WndClass);

	// �� ������ �����츦 �����Ѵ�. 
	hwnd = CreateWindow(					// ������ ���� API���Լ�
		"EasyText",			// ��ϵ� ������ Ŭ���� �̸�
		"ù ������ ���α׷���", 			// Ÿ��Ʋ �ٿ� ��µ� ���ڿ�
		WS_OVERLAPPEDWINDOW,		// ������ ��Ÿ��
		CW_USEDEFAULT,			// ������ ���� ����� x ��ǥ
		CW_USEDEFAULT,			// ������ ���� ����� y ��ǥ
		CW_USEDEFAULT,			// �������� �ʺ�
		CW_USEDEFAULT,			// �������� ����
		NULL,				// �θ� �������� �ڵ�
		NULL,				// �޴� �Ǵ� �ڽ� �������� �ڵ�
		hInstance,			// ���ø����̼� �ν��Ͻ� �ڵ�
		NULL				// ������ ���� �������� �ּ� 
	);

	// ������ �����츦 ȭ�鿡 ǥ���Ѵ�. 
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// �� �޽��� ť�κ��� �޽����� �޾ƿ� �޽����� �ش� ������ ���ν����� ������. 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);		// �޽����� �����Ѵ�. 
		DispatchMessage(&msg);		// �޽����� �ش� ������ ���ν����� ������. 
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;						// ����̽� ���ؽ�Ʈ
	RECT rect;						// RECT ����ü
	PAINTSTRUCT ps;					// ����Ʈ ����ü
	LPCSTR szMsg1 = "I love Window Programming!";		// �����쿡 ��µ� ���ڿ�
	LPCSTR szMsg2 = "Ű���尡 ���������ϴ�.";			// Ű���带 ������ �� ��µ� ���ڿ�
	LPCSTR szMsg3 = "Ű���尡 ���������ϴ�.";			// Ű���带 ������ �� ��µ� ���ڿ�


	// �� Ŀ�ο��� ���� �޽����� switch ���� �̿��Ͽ� ó��
	switch (message)
	{
	case WM_CREATE:					// ������ ���� �޽����� �� ���
		break;
	case WM_PAINT:					// ȭ�鿡 ��� �޽����� �� ���
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 10, 10, szMsg1, strlen(szMsg1));  	// �����쿡 ���ڿ��� ���
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:				// Ű������ Ű�� ���� ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg2, strlen(szMsg2), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_KEYUP:					// Ű������ Ű�� ������ ���
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, szMsg3, strlen(szMsg3), &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		ReleaseDC(hwnd, hdc);
		break;
	case WM_LBUTTONDBLCLK:             		// ���� ���콺�� ���� Ŭ���� ���
		MessageBox(hwnd, "���콺 ���� Ŭ��!", "���콺 �޽���", MB_OK | MB_ICONASTERISK);
		break;
	case WM_DESTROY:				// ���α׷� ���� �޽����� �� ���
		PostQuitMessage(0);
		break;
	default:						// �� ���� �޽����� �� ���
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}