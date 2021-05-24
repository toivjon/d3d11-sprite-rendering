#ifndef TEST_D3D_CONTEXT_HPP
#define TEST_D3D_CONTEXT_HPP

#include <d3d11.h>
#include <windows.h>
#include <wrl/client.h>

using namespace Microsoft::WRL; // yep, ugly but still more readable than using full qualifiers.

namespace test {
class D3DContext final {
  public:
    D3DContext(HWND hwnd);

  private:
    ComPtr<ID3D11Device> mDevice;
    ComPtr<ID3D11DeviceContext> mDeviceCtx;
    ComPtr<IDXGISwapChain> mSwapChain;
};
} // namespace test

#endif
