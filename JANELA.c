#include <x11.h>

LRESULT CALLBACK MainProc (HWND, UINT, WPARAM, LPARAM);

char szClassName[ ] = "WindowsApp";

int WINAPI WinMain (HINSTANCE hT, HINSTANCE hP, LPSTR arg, int show)
{
    HWND hwnd;
    MSG msg;
    WNDCLASSEX wc;

    wc.hInstance = hT;
    wc.lpszClassName = szClassName;
    wc.lpfnWndProc = MainProc;
    wc.style = CS_DBLCLKS;
    wc.cbSize = sizeof (WNDCLASSEX);

    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    if (!RegisterClassEx(&wc)) return 0;

    hwnd = CreateWindowEx (
        0,
        szClassName,          // classe
        "Windows App",        // titulo
        WS_OVERLAPPEDWINDOW,  // "estilo"
        100,100,800,600,      // x, y, w, h
        HWND_DESKTOP,         // parent
        NULL,
        hT,
        NULL
        );
    HWND bt = CreateWindowEx (
        0,
        "button",             // classe
        "Hello World",        // titulo
        WS_VISIBLE|WS_CHILD,  // "estilo"
        200,200,150,50,       // x, y, w, h
        hwnd,                 // parent
        NULL,
        NULL,
        NULL
        );

    ShowWindow (hwnd,show);

    //
    // LOOP PRINCIPAL: "ate fechar a janela"
    //
    while (GetMessage(&msg,NULL,0,0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK MainProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_COMMAND:
        MessageBox (0, "Clicando no BOTAO", "TUTULO ERRO: ;)", MB_ICONINFORMATION);
        break;

    case WM_DESTROY:
        PostQuitMessage (0);
        break;
    default:
        return DefWindowProc (hwnd, msg, wParam, lParam);
    }

    return 0;
}
