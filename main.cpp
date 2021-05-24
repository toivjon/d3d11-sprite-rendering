#include <windows.h>
#include <wrl/client.h>

#include <exception>
#include <vector>

// The name of the window class being registered for the application.
constexpr auto WindowClassName = TEXT("d3d11-sprite-rendering");

auto CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LPARAM {
    switch (msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, lParam, wParam);
}

// Register a window class or throw an exception on failure.
void registerWindowClass(HINSTANCE instance) {
    WNDCLASS windowClass = {};
    windowClass.lpszClassName = WindowClassName;
    windowClass.lpfnWndProc = WndProc;
    windowClass.hInstance = instance;
    if (RegisterClass(&windowClass) == 0) {
        throw std::exception("Failed to register window class!");
    }
}

// Build and show a window for the application or throw an exception on failure.
auto createWindow(HINSTANCE instance, int show) -> HWND {
    auto window = CreateWindow(WindowClassName,
                               TEXT("D3D11 - Sprite Rendering"),
                               WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               CW_USEDEFAULT,
                               nullptr,
                               nullptr,
                               instance,
                               nullptr);
    if (window == nullptr) {
        throw std::exception("Failed to create window!");
    }
    ShowWindow(window, show);
    UpdateWindow(window);
    return window;
}

auto WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmd, int show) -> int {
    UNREFERENCED_PARAMETER(prevInstance);
    UNREFERENCED_PARAMETER(cmd);
    try {
        registerWindowClass(instance);
        createWindow(instance, show);

        MSG message = {};
        while (GetMessage(&message, nullptr, 0, 0)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
    } catch (...) {
    }

    return 0;
}
