// Dear ImGui: standalone example application for Win32 + OpenGL 3

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

// This is provided for completeness, however it is strongly recommended you use OpenGL with SDL or GLFW.

#pragma once
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_win32.h"
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <GL/GL.h>
#include <tchar.h>
#include <string>
#include "JoyStick.h"
#include <iostream>
// Data stored per platform window
struct WGL_WindowData { HDC hDC; };

// Data
static HGLRC            g_hRC;
static WGL_WindowData   g_MainWindow;
static int              g_Width;
static int              g_Height;

// Forward declarations of helper functions
bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);
void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);
void ResetDeviceWGL();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Main code
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"JEx64 - OpenGL3", WS_OVERLAPPEDWINDOW, 100, 100, 500, 800, nullptr, nullptr, wc.hInstance, nullptr);

    // Initialize OpenGL
    if (!CreateDeviceWGL(hwnd, &g_MainWindow))
    {
        CleanupDeviceWGL(hwnd, &g_MainWindow);
        ::DestroyWindow(hwnd);
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    wglMakeCurrent(g_MainWindow.hDC, g_hRC);

    // Show the window
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_InitForOpenGL(hwnd);
    ImGui_ImplOpenGL3_Init();

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != nullptr);

    // Our state
    ///io.Fonts->AddFontDefault();
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\Fonts\ArialUni.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
    bool show_demo_window = false;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    ImVec2 fJ_size;
    // Main loop
    bool done = false;
    while (!done)
    {
        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                done = true;
        }
        if (done)
            break;

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
        {
            JoyStickAPI* xController1;
            JoyStickAPI* xController2;
            xController1 = new JoyStickAPI(1);
            xController2 = new JoyStickAPI(2);
            static float fB_a = 0.0f;
            static float fB_b = 0.0f;
            static float fB_x = 0.0f;
            static float fB_y = 0.0f;
            static float fB_rt = 0.0f;
            static float fB_rb = 0.0f;
            static float fB_lb = 0.0f;
            static float fB_lt= 0.0f;
            static float fB_du = 0.0f;
            static float fB_dd = 0.0f;
            static float fB_dl = 0.0f;
            static float fB_dr = 0.0f;
            static float fB_ls = 0.0f;
            static float fB_rs = 0.0f;
            static int counter = 0;
            static bool fJEFrame = false;
            static float fC_Rcol = 0.0f;
            static float fC_Gcol = 0.0f;
            static float fC_Bcol = 0.0f;
            //
            bool C_XinputControllerState = false;
            static float  fByteArray = 0;
            static float fLX = 0;
            static float fLY = 0;
            static float fRX = 0;
            static float fRY = 0;
            //
            static float fLT = 0;
            static float fRT = 0;
            static bool fCAboutW;
            ImGui::Begin(" JEx64 Build 1.0 ");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("Wellcome on JE!!");               // Display some text (you can use a format strings too)
            //ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            //ImGui::Checkbox("Another Window", &show_another_window);
            if (GetAsyncKeyState('V'))
            {
                fB_a= fB_a + 0.1f;
                fB_b= fB_b + 0.1f;
                fB_x= fB_x + 0.1f;
                fB_y= fB_y + 0.1f;
                fB_rt= fB_rt + 0.1f;
                fB_rb = fB_rb + 0.1f;
                fB_lb = fB_lb + 0.1f;
                fB_lt = fB_lt + 0.1f;
                if (fB_b > 1)
                {
                    fB_a = 1.000f;
                    fB_b = 1.000f;
                    fB_x = 1.000f;
                    fB_y = 1.000f;
                    fB_rt = 1.000f;
                    fB_rb = 1.000f;
                    fB_lb = 1.000f;
                    fB_lt = 1.000f;
                }
            }
            if (!GetAsyncKeyState('V'))
            {
                fB_a = fB_a - 0.1f;
                fB_b = fB_b - 0.1f;
                fB_x = fB_x - 0.1f;
                fB_y = fB_y - 0.1f;
                fB_rt = fB_rt - 0.1f;
                fB_rb = fB_rb - 0.1f;
                fB_lb = fB_lb - 0.1f;
                fB_lt = fB_lt - 0.1f;
                if (fB_b < 1)
                {
                    fB_a = 0.000f;
                    fB_b = 0.000f;
                    fB_x = 0.000f;
                    fB_y = 0.000f;
                    fB_rt = 0.000f;
                    fB_rb = 0.000f;
                    fB_lb = 0.000f;
                    fB_lt = 0.000f;
                }

            }
            fLX = (xController1->GetState().Gamepad.sThumbLX / 32768.0f);
            fLY = (xController1->GetState().Gamepad.sThumbLY / 32768.0f);
            fRX = (xController1->GetState().Gamepad.sThumbRX / 32768.0f);
            fRY = (xController1->GetState().Gamepad.sThumbRY / 32768.0f);
            fLT = (xController1->GetState().Gamepad.bLeftTrigger / 32768.0f);
            fRT = (xController1->GetState().Gamepad.bRightTrigger / 32768.0f);
            ImGui::Text(("FPS:" + std::to_string(io.Framerate)).c_str());
            if (xController1->IsConnected())
            {
                ImGui::Text("Controller connnected!!");
                C_XinputControllerState = true;
            }
            else
            {
                ImGui::Text("Contoller not Found!! Please Plug Xinput Controller!!");
                C_XinputControllerState = false;
            }
            //
            //button detector
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) { fB_b = fB_b + 0.1f; if (fB_b > 1.000f) { fB_b = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) { fB_a = fB_a + 0.1f; if (fB_a > 1.000f) { fB_a = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) { fB_x = fB_x + 0.1f; if (fB_x > 1.000f) { fB_x = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y) { fB_y = fB_y + 0.1f; if (fB_y > 1.000f) { fB_y = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) { fB_rs = fB_rs + 0.1f; if (fB_rs > 1.000f) { fB_rs = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) { fB_ls = fB_ls + 0.1f; if (fB_ls > 1.000f) { fB_ls = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) { fB_du = fB_du + 0.1f; if (fB_du > 1.000f) { fB_du = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) { fB_dd = fB_dd + 0.1f; if (fB_dd > 1.000f) { fB_dd = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) { fB_dl = fB_dl + 0.1f; if (fB_dl > 1.000f) { fB_dl = 1.000f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) { fB_dr = fB_dr + 0.1f; if (fB_dr > 1.000f) { fB_dr = 1.000f; } }
            //
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) { fB_b = fB_b - 0.1f; if (fB_b < 0.1f) { fB_b = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) { fB_a = fB_a - 0.1f; if (fB_a < 0.1f) { fB_a = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) { fB_x = fB_x - 0.1f; if (fB_x < 0.1f) { fB_x = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y) { fB_y = fB_y - 0.1f; if (fB_y < 0.1f) { fB_y = 0.0f;} }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) { fB_rs = fB_rs - 0.1f; if (fB_rs < 0.1f) { fB_rs = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) { fB_ls = fB_ls - 0.1f; if (fB_ls < 0.1f) { fB_ls = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) { fB_du = fB_du - 0.1f; if (fB_du < 0.1f) { fB_du = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) { fB_dd = fB_dd - 0.1f; if (fB_dd < 0.1f) { fB_dd = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) { fB_dl = fB_dl - 0.1f; if (fB_dl < 0.1f) { fB_dl = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) { fB_dr = fB_dr - 0.1f; if (fB_dr < 0.1f) { fB_dr = 0.0f; } }
            //
            if (fJEFrame)
            {
                ImGui::Text(" Buttons ");
                ImGui::SliderFloat("A", &fB_a, 0.0f, 1.0f);
                ImGui::SliderFloat("X", &fB_x, 0.0f, 1.0f);
                ImGui::SliderFloat("Y", &fB_y, 0.0f, 1.0f);
                ImGui::SliderFloat("B", &fB_b, 0.0f, 1.0f);
                ImGui::SliderFloat("RT", &fB_rt, 0.0f, 1.0f);
                ImGui::SliderFloat("RB", &fB_rb, 0.0f, 1.0f);
                ImGui::SliderFloat("LB", &fB_lb, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("LT", &fB_lt, 0.0f, 1.0f);
                ImGui::SliderFloat("UP", &fB_du, 0.0f, 1.0f);
                ImGui::SliderFloat("Dowm", &fB_dd, 0.0f, 1.0f);
                ImGui::SliderFloat("Left", &fB_dl, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("Right", &fB_dr, 0.0f, 1.0f);
                ImGui::Text(" Axis ");
                ImGui::SliderFloat("LX", &fLX, 0.0f, 1.0f);
                ImGui::SliderFloat("RX", &fLY, 0.0f, 1.0f);
                ImGui::SliderFloat("LY", &fRX, 0.0f, 1.0f);
                ImGui::SliderFloat("RY", &fRY, 0.0f, 1.0f);
                ImGui::SliderFloat("LT", &fLT, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("RT", &fRT, 0.0f, 1.0f);
                if (ImGui::Button("Back to menu",ImVec2(150.0f,60.0f)))                           // Buttons return true when clicked (most widgets return true when edited/activated)
                {
                    fJEFrame = false;
                }
            }
            //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
            // io.Fonts->AddFontFromFileTTF("./WhiteRabbit.ttf", 15.0f);
            if (ImGui::Button("Exit to JE", ImVec2(150.0f, 60.0f)))                              // Buttons return true when clicked (most widgets return true when edited/activated)
            {
                exit(0);
            }
            if (!fJEFrame)
            {
                if (ImGui::Button("JoyStick Test", ImVec2(150.0f, 60.0f)))                              // Buttons return true when clicked (most widgets return true when edited/activated)
                {
                    fJEFrame = true;
                }
           }
            if (ImGui::Button("About", ImVec2(150.0f, 60.0f)))
            {
                fCAboutW = true;
           }
            if (fCAboutW)
            {
                ImGui::Text("  JE Build 1.0 win64 OpenGL3 \n JE  -  Keyboard emulator on Gamepad!! \n and JoyStick Test\n Compiled to Visual Studio 2022 Ñ++20 ImGui");
                if (ImGui::Button("Back", ImVec2(150.0f, 60.0f)))
                {
                    fCAboutW = false;

      
                }
            }
            ImGui::SameLine();
            ImGui::End();
        }

        // 3. Show another simple window.
        if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

        // Rendering
        ImGui::Render();
        glViewport(0, 0, 400, 800);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Present
        ::SwapBuffers(g_MainWindow.hDC);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceWGL(hwnd, &g_MainWindow);
    wglDeleteContext(g_hRC);
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions
bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    HDC hDc = ::GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { 0 };
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    const int pf = ::ChoosePixelFormat(hDc, &pfd);
    if (pf == 0)
        return false;
    if (::SetPixelFormat(hDc, pf, &pfd) == FALSE)
        return false;
    ::ReleaseDC(hWnd, hDc);

    data->hDC = ::GetDC(hWnd);
    if (!g_hRC)
        g_hRC = wglCreateContext(data->hDC);
    return true;
}

void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    wglMakeCurrent(nullptr, nullptr);
    ::ReleaseDC(hWnd, data->hDC);
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            g_Width = LOWORD(lParam);
            g_Height = HIWORD(lParam);
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
