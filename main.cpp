#include <windows.h>

auto CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) -> LPARAM {
  return DefWindowProc(hwnd, msg, lParam, wParam);
}

auto WINAPI WinMain(HINSTANCE instance, HINSTANCE prevInstance, LPSTR cmd, int show) -> int {
  UNREFERENCED_PARAMETER(instance);
  UNREFERENCED_PARAMETER(prevInstance);
  UNREFERENCED_PARAMETER(cmd);
  UNREFERENCED_PARAMETER(show);

  // register a window class for the application.
  WNDCLASS windowClass = {};
  windowClass.lpszClassName = TEXT("d3d11-sprite-rendering");
  windowClass.lpfnWndProc = WndProc;
  if (RegisterClass(&windowClass) == 0) {
    OutputDebugStringA("Failed to register window class!");
    return -1;
  }

  // TODO

  return 0;
}