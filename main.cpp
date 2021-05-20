#include <windows.h>

#include <exception>

auto CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LPARAM {
  switch (msg) {
    case WM_DESTROY:
      PostQuitMessage(0);
      return 0;
  }
  return DefWindowProc(hwnd, msg, lParam, wParam);
}

auto createWindow(HINSTANCE instance, int show) -> HWND {
  // Register a window class for the application.
  WNDCLASS windowClass = {};
  windowClass.lpszClassName = TEXT("d3d11-sprite-rendering");
  windowClass.lpfnWndProc = WndProc;
  windowClass.hInstance = instance;
  if (RegisterClass(&windowClass) == 0) {
    throw std::exception("Failed to register window class!");
  }

  // Build and show a new window that uses the registered window class.
  auto window = CreateWindow(windowClass.lpszClassName, TEXT("D3D11 - Sprite Rendering"),
                             WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                             CW_USEDEFAULT, nullptr, nullptr, instance, nullptr);
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
