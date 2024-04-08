

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
#include <conio.h>
#include <fstream>
#include <string>
int64_t fSndMsg(int64_t fJEid_snd)
{
    int64_t fSnd00 = 0xFFFFFFF;
    int64_t fSnd01 = 0x00000010L;
    int64_t fSnd02 = 0x00000040L;
    int64_t fSnd03 = 0x00000030L;
    //
    int64_t fSoundThread = 0;
    switch (fJEid_snd)
    {
    case 1:
        fSoundThread = fSnd00;
    case 2:
        fSoundThread = fSnd01;//Critical Error 
    case 3:
        fSoundThread = fSnd02;
    case 4:
        fSoundThread = fSnd03;
        break;
    }
    MessageBeep(fSoundThread);
    return fSoundThread;
}
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
static bool bCPUTest = false;
static bool ts_window = true;
static bool fCAboutW;
//
const GLubyte* fJ_vendor = glGetString(GL_VENDOR);// Returns the vendor
const GLubyte* fJ_rendered = glGetString(GL_RENDERER);
//
void ResetDeviceWGL();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

std::string ld_V()
{
    float fBr = 0;
    int64_t fV = 0;
    int64_t fto_tick = 0;
    int64_t fto_tick_out = 0;
    int64_t fRcpu = 0;
    std::string fTcpu;
    //
    fto_tick = GetTickCount64();
    //
    for (int64_t fG = 1; fG > 0; fG++)
    {
        Sleep(1);
        fV++;
        if (fV > 30)
        {
            fV = 0;
        }
        if (fV == 30)
        {
            fBr++;
            if (fBr == 100) { ts_window = false; fG = -1; }
            fto_tick_out = GetTickCount64();
            fRcpu = fto_tick_out - fto_tick;
            if (fRcpu > 0) { fTcpu = "Very Powerful CPU!!    "; }
            if (fRcpu >= 200) { fTcpu = "Very Fast               "; }
            if (fRcpu >= 500) { fTcpu = "Fast                    "; }
            if (fRcpu >= 800) { fTcpu = "Very Slow CPU!!    "; }
            return "Score\n" + std::to_string(fRcpu) + "\n\n" + "YourCPU\n\n\n" + fTcpu;
        }
    }
}
int main(int, char**)
{
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"ImGui Example", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"JEx64 - OpenGL3", WS_OVERLAPPEDWINDOW, 100, 80, 500, 800, nullptr, nullptr, wc.hInstance, nullptr);

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

    ImGui_ImplWin32_InitForOpenGL(hwnd);
    ImGui_ImplOpenGL3_Init();
    static bool fCAboutW;
    ImVec4 clear_color = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    ImVec2 fJ_size;
    //io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 12.0f);
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
            static bool bShowButtons = true;
            //
            static float df = 0.0f;
            bool C_XinputControllerState = false;
            static float  fByteArray = 0;
            static float fLX = 0;
            static float fLY = 0;
            static float fRX = 0;
            static float fRY = 0;
            //
            static float fLT = 0;
            static float fRT = 0;
            //
            ShowWindow(GetConsoleWindow(), 2);
            static bool b_vsync = false;
            static bool fL_motor = false;
            static bool fR_motor = false;
            static int  v_Rmotor = 0;
            static int v_Lmotor = 0;
            ImGui::Begin(" JE x64 OpenGL3_SSE4.2cpp20",&fJEFrame);                          // Create a window called "Hello, world!" and append into it.
            ImGui::Checkbox("vsync", &b_vsync);
            if (b_vsync) { Sleep(13); }
            else { Sleep(0); }
            ImGuiStyle& style = ImGui::GetStyle();
            style.WindowRounding = 5.3f;
            style.FrameRounding = 2.3f;
            style.ScrollbarRounding = 0;
            style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
            style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.70f, 0.70f, 0.70f, 0.65f);
            style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.00f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.90f, 0.80f, 0.80f, 0.40f);
            style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.90f, 0.65f, 0.65f, 0.45f);
            style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.08f, 0.08f, 0.08f, 0.80f);
            style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
            style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.60f);
            style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.55f, 0.53f, 0.55f, 0.51f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.56f, 0.56f, 0.56f, 0.91f);
            style.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 0.83f);
            style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.62f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.30f, 0.30f, 0.84f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.03f, 0.8f, 0.5f, 0.90f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
            style.Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.69f, 1.00f, 0.53f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.44f, 0.61f, 0.86f, 1.00f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.38f, 0.62f, 0.83f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
            style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
            style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
            style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
            ImGui::Text("Wellcome on JE!!");               // Display some text (you can use a format strings too)
            fLX = (xController1->GetState().Gamepad.sThumbLX / 32768.0f);
            fLY = (xController1->GetState().Gamepad.sThumbLY / 32768.0f);
            fRX = (xController1->GetState().Gamepad.sThumbRX / 32768.0f);
            fRY = (xController1->GetState().Gamepad.sThumbRY / 32768.0f);
            fLT = (xController1->GetState().Gamepad.bLeftTrigger / 32768.0f);
            fRT = (xController1->GetState().Gamepad.bRightTrigger / 32768.0f);
            ImGui::Text(("FPS:" + std::to_string(io.Framerate)).c_str());
            if (xController1->IsConnected() || C_XinputControllerState)
            {
                ImGui::Text("Controller connnected!!");
                C_XinputControllerState = true;
            }
            else
            {
                ImGui::Text("Contoller not Found!! \nPlease Plug Xinput Controller!!");
                C_XinputControllerState = false;
            }
            //
            if (GetAsyncKeyState(VK_F5))
            {
                C_XinputControllerState = true;
            }
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
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B) { fB_b = fB_b - 0.1f; if (fB_b < 0.1f) { fB_b = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_A) { fB_a = fB_a - 0.1f; if (fB_a < 0.1f) { fB_a = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_X) { fB_x = fB_x - 0.1f; if (fB_x < 0.1f) { fB_x = 0.0f; } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_Y) { fB_y = fB_y - 0.1f; if (fB_y < 0.1f) { fB_y = 0.0f;} }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_RIGHT_SHOULDER) { fB_rs = fB_rs - 0.1f; if (fB_rs < 0.1f) { fB_rs = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_LEFT_SHOULDER) { fB_ls = fB_ls - 0.1f; if (fB_ls < 0.1f) { fB_ls = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_UP) { fB_du = fB_du - 0.1f; if (fB_du < 0.1f) { fB_du = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_DOWN) { fB_dd = fB_dd - 0.1f; if (fB_dd < 0.1f) { fB_dd = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_LEFT) { fB_dl = fB_dl - 0.1f; if (fB_dl < 0.1f) { fB_dl = 0.0f;
            } }
            if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_RIGHT) { fB_dr = fB_dr - 0.1f; if (fB_dr < 0.1f) { fB_dr = 0.0f; } }
            //
            if (C_XinputControllerState)
            {
                fJEFrame = true;
            }
            if (fJEFrame)
            {
                fJEFrame = ImGui::MemAlloc(10024);
                if (GetAsyncKeyState(VK_LEFT))
                {
                    df = df + 0.1f;
                    if (df > 100.0f)
                    {
                        df = 100.0f;
                    }
                }
                else
                {
                    df = df - 0.1f;
                    if (df < 0.0f)
                    {
                        df = 0.0f;
                    }
                }
                bShowButtons = false;
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
                ImGui::Checkbox("Lmotor", &fL_motor);
                ImGui::Checkbox("Rmotor", &fR_motor);
                xController1->Vibrate(v_Lmotor, v_Rmotor);
                if (fR_motor)
                {
                    ImGui::InputInt("Rduration", &v_Rmotor, 1, 100);
                }
                if (fL_motor)
                {
                    ImGui::InputInt("Rduration", &v_Lmotor, 1, 100);
                }
                if (ImGui::Button("Back to menu",ImVec2(150.0f,60.0f)))                           // Buttons return true when clicked (most widgets return true when edited/activated)
                {
                    fJEFrame = false;
                }
                if(ImGui::ColorButton("Controls",ImVec4(100.0f,200.0f,100.0f,10.0f),1, ImVec2(150.0f, 60.0f)))
                {
                    bShowButtons = true;
                }
            }
           // static bool bCPUTest = false;
            //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
            // io.Fonts->AddFontFromFileTTF("./WhiteRabbit.ttf", 15.0f);
            if(!fJEFrame){ bShowButtons = true; }
            if (bShowButtons)
            {
                if (ImGui::Button("Exit to JE", ImVec2(150.0f, 60.0f))) { exit(0); }
                if (ImGui::Button("CPUTest", ImVec2(150.0f, 60.0f))) { bCPUTest = true; }
                if (!fJEFrame) { if (ImGui::Button("JoyStick Test", ImVec2(150.0f, 60.0f))) { fJEFrame = true; }}
                if (ImGui::Button("About", ImVec2(150.0f, 60.0f))) { fCAboutW = true; }
            }
            ImGui::Text("Build: 1.0.1 C++20 OpenGL 3.0 Debug");
            ImGui::SameLine();
            ImGui::End();
        }
        
        if (fCAboutW)
        {
            ImGui::Begin("About", &fCAboutW);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::TextColored(ImVec4(0.0f, 200.0f, 100.0f, 10.0f), "JE - KeyBoard Emulator on Gamepad\nPowerful Test Gamepad with beatiful design n\on OpenGL 3.0 to Uses API ImGui))n\--------------------------------\nCompiled to Visual Studio 2022 n\Build Project: 1.0.1 x64 (C++20)\nUsed My JoyStickAPI 1.0.0 (C++11)\n-------------------------------\nGITHUB:\ngithub.com/hcpp20334\nGITHUB REPO JE:\ngithub.com/hcpp20334/JoyStickTest\n--------------------------------");
           // ImGui::TextColored(ImVec4(0.0f, 200.0f, 100.0f, 10.0f),( std::to_string(fJ_vendor).c_str()));
            std::cout << &fJ_vendor << &fJ_rendered << "\n";
            if (ImGui::Button("OK"))
                fCAboutW = false;
            ImGui::End();
        }
        if (bCPUTest)
        {
            static std::string v_Cscore;
            static int64_t v_CFirst = 0;
            static int64_t v_COutV = 0;
            static int64_t fV = 0;
            static int64_t fc_0 = 0;
            ImGui::Begin("CPU Test", &bCPUTest);
            ImGui::TextColored(ImVec4(11.8f, 88.1f, 43.0f, 10.f), "Test CPU");
            ImGui::Text((v_Cscore).c_str());
            
                //std::cout << "Cycle:" << fT_cpuSpeed << "Score" << v_Cscore << std::endl;
            if (ImGui::Button("TEST"))
            {
                v_Cscore = ld_V();
            }
            if (ImGui::Button("Close"))
                bCPUTest = false;
            ImGui::End();
        }
        // 3. Show another simple window.
        
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
