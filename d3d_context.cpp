#include "d3d_context.hpp"

#include <exception>
#include <string>
#include <vector>

using namespace test;

#ifdef _DEBUG
// Enable Direct3D debug layer in debug builds.
constexpr UINT DeviceFlags = D3D11_CREATE_DEVICE_DEBUG;
#else
// No additional Direct3D device flags in non-debug builds.
constexpr UINT DeviceFlags = 0;
#endif

// A utility to format the given HRESULT into a string.
auto HRString(HRESULT hr) -> std::string {
    LPSTR buffer = nullptr;
    auto flags = 0;
    flags |= FORMAT_MESSAGE_ALLOCATE_BUFFER;
    flags |= FORMAT_MESSAGE_FROM_SYSTEM;
    flags |= FORMAT_MESSAGE_IGNORE_INSERTS;
    auto size = FormatMessageA(flags,
                               nullptr,
                               hr,
                               MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                               (LPSTR)(&buffer),
                               0,
                               nullptr);
    std::string result(buffer, size);
    LocalFree(buffer);
    return result;
}

// A utility that throws whether the given HRESULT is FAILED.
void AssertHR(HRESULT hr) {
    if (FAILED(hr)) {
        std::string message("Direct3D error");
        message += "\n\n";
        message += "Application received a Direct3D error: ";
        message += std::to_string(hr);
        message += "\n\n";
        message += HRString(hr);
        throw std::exception(message.c_str());
    }
}

D3DContext::D3DContext(HWND hwnd) {
    // Build a new Direct3D device and device context.
    std::vector<D3D_FEATURE_LEVEL> featureLevels = {D3D_FEATURE_LEVEL_11_1};
    AssertHR(D3D11CreateDevice(nullptr,
                               D3D_DRIVER_TYPE_HARDWARE,
                               nullptr,
                               DeviceFlags,
                               &featureLevels[0],
                               UINT(featureLevels.size()),
                               D3D11_SDK_VERSION,
                               &mDevice,
                               nullptr,
                               &mDeviceCtx));
}
