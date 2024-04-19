
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
#include <Psapi.h>
#include <urlmon.h>
#include <clocale>
#include <thread>

#pragma comment (lib , "Urlmon.lib")
uint64_t fDataMemUsage() // Work Function !!! Check Sym RAM to Current Program //
{
    PROCESS_MEMORY_COUNTERS pmc;
    pmc.cb = sizeof(pmc);
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize;
}

#pragma once



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
    MessageBeep((UINT)(fSoundThread));
    return fSoundThread;
}
bool LoadTextOnFile(char* File, uint64_t fStrLineMax,std::string* f_buffer,std::string* getfile,bool *Tb_state)
{
   std::string fLoadbuffer;
    int64_t fBuf_lineCounts = 0;
    std::ifstream FileRes(File);
    int64_t  fCbuf = 0;
    fStrLineMax = 5;
    bool EndReadFile;
    *getfile = File;
    if (!FileRes.is_open())
    {
        *f_buffer = "Error: resource falled!";
    }
    while(1)
    {
       std::getline(FileRes, fLoadbuffer);
        fCbuf++;
        if (fCbuf <= 30)
        {
            fCbuf = 0;
            fLoadbuffer = fLoadbuffer + "\n";
            return -1;
        }
        if (fBuf_lineCounts >= fStrLineMax)
        {
            EndReadFile = true;
            return Tb_state;
            free(f_buffer);
        }
         *f_buffer = *f_buffer + fLoadbuffer;
    }
}
int64_t ResetBool(bool *State)
{
    *State = false;
    return 0;
    fSndMsg(1);
    
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

static int64_t ld_V(std::string *buff)
{
    float fBr = 0;
    int64_t fV = 0;
    int64_t fto_tick = 0;
    int64_t fto_tick_out = 0;
    int64_t fJ_stack = 0;
    std::string fTcpu;
    std::string fBuffer_f = "1234567890abcdef";
    int64_t fSizeBuf_f = 0;
    int64_t fChunkSeed = 0;
    //
    fto_tick = fBuffer_f.size();
    //
    for (int64_t fG = 1; fG > 0; fG++)
    {
        srand(time(0));
        fSizeBuf_f = fBuffer_f.size();
        fChunkSeed = rand() % fSizeBuf_f / fSizeBuf_f;
        fBuffer_f = fBuffer_f + fBuffer_f[fSizeBuf_f - fChunkSeed];
        *buff = fBuffer_f;
        Sleep(13);
        fV++;
        if (fV > 30)
        {
            fV = 0;
        }
        if (fV == 30)
        {
            fBr++;
            if (fBr == 100) { ts_window = false; fG = -1;
            }
            fto_tick_out = fBuffer_f.size();
            if (fJ_stack > 0) { fTcpu = "Very Powerful CPU!!    "; }
            if (fJ_stack >= 200) { fTcpu = "Very Fast               "; }
            if (fJ_stack >= 500) { fTcpu = "Fast                    "; }//
            if (fJ_stack >= 800) { fTcpu = "Very Slow CPU!!    "; }
            fJ_stack = fto_tick_out - fto_tick;
          //  std::to_integer()
            return fJ_stack;
            
        }
        
    }
    
}

    
int main(int, char**)
{
    static std::string fBuffer0 = "## JE - Poweful Gamepad Tester!! Build 1.0.8\n"
        "## Compile to C++20 (x64)OpenGL3.0 SSE4.2\n\n"
        "Navigation\n-------------------------------------------\n"
        " -------------------------------------------\n"
        "Settings - on / off flags\n"
        "* Vsync - Limit framerate to 60\n"
        "* Invert Vibration Value - Fix Bug to Rea\n"
        "  data to Xinput Emulators\n"
        "------------------------------------------ -\n"
        " CPUTest - Test Speed you CPUTest\n"
        "* Button Test - start CPUTest\n"
        "------------------------------------------ -\n"
        "Update - Update Center to Update New Version!!\n"
        "(NEED THE INTERNET)\n"
        "------------------------------------------ -\n"
        "Exit - to Close App\n"
        "------------------------------------------ -\n";
    ImDrawListSplitter JEApp;
    static bool fCAboutW;
    ImVec4 clear_color = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    ImVec2 fJ_size;
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
    static float fB_lt = 0.0f;
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
    static bool bShowButtons = false;
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
   // ShowWindow(GetConsoleWindow(), 2);
    static bool b_vsync = false;
    static bool fL_motor = false;
    static bool fR_motor = false;
    static bool v_flagClMemory = false;
    static bool v_bExit = false;
    static int  v_Rmotor = 0;
    static int v_Lmotor = 0;
    static bool v_bSettings = false;
    static bool v_bSettingsCh_b = false;
    static bool v_bInvertVibValue = false;
    static bool rd_text;
    static bool v_Penis = false;
    static bool fFontsState;
    static bool v_bThemeJE;
    static bool bTh_Classic;
    static bool bTh_Dark;
    static bool bTh_Light;
    //
    static std::string filestr;
    static std::string fStrMsgBuf;
    static std::string fBuffer_data;
    //
    static int64_t fThemeId = 0;
    static int th_bar = 1000;

    int64_t Val = 0;
    // Create application window
    //ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"JE x64", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"JE_x64_OpenGL3_SSE4.2 C++20 Build 1.0.8", WS_OVERLAPPEDWINDOW | WS_EX_NOPARENTNOTIFY, 100, 80, 500, 800, nullptr, nullptr, wc.hInstance, nullptr);

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
    ::ShowWindow(GetConsoleWindow(), 2);
    ::UpdateWindow(hwnd);
    std::string fStrParam;
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
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 13.0f);
    std::ifstream Set_prm("JE_CONFIG.TXT");
    Set_prm.is_open();
    while (std::getline(Set_prm, fStrParam))
    {
        if (fStrParam == "fJE_Font_WR=false;") { fFontsState = false; }if (fStrParam == "fJE_Font_WR=true;") { fFontsState = true; }
        if (fStrParam == "fJETheme=0;") { bTh_Dark = true; bTh_Light = false; bTh_Classic = false; }
        if (fStrParam == "fJETheme=1;") { bTh_Dark = false; bTh_Light = false; bTh_Classic = true; }
        if (fStrParam == "fJETheme=2;") { bTh_Dark = false; bTh_Light = false; bTh_Classic = false; }
        if (fStrParam == "fJEVsync=true;") { b_vsync = true; }if (fStrParam == "fJEVsync=false;") { b_vsync = false; }
        if (fStrParam == "fJEInvertVibrationValue=true;") { v_bInvertVibValue = true; }if (fStrParam == "fJEInvertVibrationValue=false;") { v_bInvertVibValue = false; }
    }
    if (fFontsState)
    {
        io.Fonts->AddFontFromFileTTF("C:\\Windows\\fonts\\unispace bd.ttf", 20.0f);
    }
    else
    {
        io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 15.0f);
    }
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
           // static bool fJEUpdate = false;
           // glfwWindowHint(GLFW_REFRESH_RATE, 60)
            setlocale(0, "rus");
            ImGui::Begin("\tJE x64_OpenGL3_SSE4.2 C++20",&fJEFrame, ImGuiWindowFlags_NoCollapse + ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.
            ImGui::SetWindowPos(ImVec2(6.0f, 19.0f));
            ImGui::SetWindowSize(ImVec2(475.0f, 703.0f));
           // ImDrawList* Image;
           // Image->AddImage()
            std::ofstream WriteConfigJE("JE_CONFIG.TXT");
               // ImGui::Begin("THEME EDITOR", &v_bThemeJE);
                if (bTh_Dark)
            {
                    bTh_Light = false;
                    bTh_Classic = false;
                fStrMsgBuf = "Theme 0";
                WriteConfigJE.is_open();
                WriteConfigJE << "fJETheme=0;" << std::endl;
               // WriteConfigJE.close();
                ImGuiStyle& style = ImGui::GetStyle();
                style.WindowRounding = 5.3f;
                style.FrameRounding = 2.3f;
                style.ScrollbarRounding = 0;
                style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.90f);
                style.Colors[ImGuiCol_WindowBg] = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
                style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
                style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 0.85f);
                style.Colors[ImGuiCol_Border] = ImVec4(0.72f, 0.772f, 0.72f, 0.60f);
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
                style.Colors[ImGuiCol_Button] = ImVec4(0.32f, 0.32f, 0.83f, 0.90f);
                style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.50f, 0.69f, 0.99f, 0.68f);
                style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.80f, 0.50f, 0.50f, 1.00f);
                style.Colors[ImGuiCol_Header] = ImVec4(1.08f, 1.08f, 1.08f, 1.80f);
                style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.08f, 0.08f, 0.08f, 0.80f);
                style.Colors[ImGuiCol_HeaderActive] = ImVec4(1.08f, 1.08f, 1.08f, 1.80f);
                style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
                style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
                style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
                style.Colors[ImGuiCol_PlotLines] = ImVec4(0.08f, 0.08f, 0.08f, 0.80f);
                style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);
            }
                if (bTh_Classic) {
                    bTh_Dark = false;
                    bTh_Light = false;
                ImGui::StyleColorsClassic(); fStrMsgBuf = "Theme 1 Apply!!";  WriteConfigJE.is_open();
                WriteConfigJE << "fJETheme=1;" << std::endl;
                //WriteConfigJE.close();
            }
                if (bTh_Light) {
                    bTh_Dark = false;
                    bTh_Classic = false;
                ImGui::StyleColorsLight(); fStrMsgBuf = "Theme 1 Apply!!";  WriteConfigJE.is_open();
                WriteConfigJE << "fJETheme=2;" << std::endl;
                //WriteConfigJE.close();
            }
                //if (th_bar == 0) { bTh_Light = true; }if (th_bar <= 500) { bTh_Classic = true; }if (th_bar == 1000) { bTh_Dark = true; }
                
                //ImGui::End();
            JEApp.ClearFreeMemory();
            if (v_bSettings)
            {
                ImGui::Begin("SETTINGS", &v_bSettings, ImGuiWindowFlags_NoCollapse);
                JEApp.ClearFreeMemory();
                if (v_bSettings) { v_bSettingsCh_b = true; }
                if (b_vsync) { Sleep(13); 
                WriteConfigJE << "fJEVsync=true;" << std::endl;
                }
                else { Sleep(0);
                WriteConfigJE << "fJEVsync=false;" << std::endl;
                }
                //ImGui::Checkbox("AUTO CLEARNING MEMORY(DEBUG)", &v_flagClMemory);
                ImGui::Text("::: MAIN SETTINGS :::\n");
                ImGui::MenuItem("VSYNC", "", &b_vsync, true);
                ImGui::MenuItem("INVERT VIBRATION VALUE FOR EMU XINPUT", "", &v_bInvertVibValue, true);
               // ImGui::Checkbox("EMU XINPUT(DEBUG)", &C_XinputControllerState);
                ImGui::MenuItem("SELECT FONTS","", & fFontsState,true);
                ImGui::Text("::: THEME EDITOR :::\n");
                ImGui::MenuItem("DARK","1",&bTh_Dark, true);
                ImGui::MenuItem("LIGHT", "2", &bTh_Light,true);
                ImGui::MenuItem("CLASSIC", "3", &bTh_Classic,true);
                ImGui::Text(("Message: "+fStrMsgBuf).c_str());
                if (ImGui::Button("SAVE"))
                {
                    std::ofstream buf("restart.bat");
                    buf.is_open();
                    buf << "taskkill /im JE_x64_OpenGL3_SSE4.2cpp20.exe>nul\n";
                    buf << "start ./JE_x64_OpenGL3_SSE4.2cpp20.exe>nul\n";
                    buf << " del restart.bat>nul" << std::endl;
                    buf << "exit" << std::endl;
                    buf.close();
                    WinExec("restart.bat", 1);
                }
                if (v_bInvertVibValue)
                {
                    WriteConfigJE << "fJEInvertVibrationValue=true;" << std::endl;
                }
                else
                {
                    WriteConfigJE << "fJEInvertVibrationValue=false;" << std::endl;
                }
                if (fFontsState)
                {
                    //ImGui::Text("Selected WhiteRabbit!!");
                    fStrMsgBuf = "FONT WHITERABBIT!!";
                    WriteConfigJE << "fJE_Font_WR=true;" << std::endl;
                   // WriteConfigJE.close();
                }
                else
                {
                    //WriteConfigJE.is_open();
                    WriteConfigJE << "fJE_Font_WR=false;" << std::endl;
                   // WriteConfigJE.close();
                    //UpdateWindow(hwnd);
                    //ImGui::Text("Selected unispace bd!!");
                    fStrMsgBuf = "FONT UNISPACE BD!!";
                }

                ImGui::End();
            }
            static bool fJEUpdate = false;
            ImGui::BeginMainMenuBar();
            ImGui::MenuItem("SETTINGS","", &v_bSettings,true);
            ImGui::MenuItem("ABOUT","", & fCAboutW,true);
            ImGui::MenuItem("CPUTEST","", & bCPUTest,true);
            ImGui::MenuItem("UPDATE","", & fJEUpdate,true);
            ImGui::MenuItem("EXIT","", & v_bExit,true);
            if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
            {
                v_Penis = true;
            }
            if (GetAsyncKeyState('G') && GetAsyncKeyState('A') && GetAsyncKeyState('Y'))
            {
                v_Penis = true;
            }
          //  static bool v_bExMsg = true;
            if (v_Penis)
            {
                JEApp.ClearFreeMemory();
                ImGui::Begin("Peni1s");
                ImGui::Text("\n\n\nYou Gay?���㯠 \n\n\n[V] - exit [N] - no");
                if (GetAsyncKeyState('V')) { ImGui::Text("Thanks!!why used my app!!"); Sleep(1000); v_Penis = false; }
                if (GetAsyncKeyState('N')) { v_bExit = false; }
                ImGui::End();
            }
            if (v_bExit)
            {
                JEApp.ClearFreeMemory();
                ImGui::Begin("EXIT");
                ImGui::TextColored(ImVec4(1.0f,0.0f,0.0f,1.0f),"\n::WARNING!!!::\n\nSETTINGS NOT SAVED!!\nUSER DATA WILL BE  LOST!!\n");
                if (ImGui::MenuItem("SAVE AND EXIT", "", &v_bExit, true)) { ImGui::Text("Thanks!!why used my app!!"); WriteConfigJE.close(); Sleep(1000); exit(0); }
                if (ImGui::MenuItem("BACK", "", &v_bExit, true)) { v_bExit = false; }
                ImGui::End();
            }
            ImGui::EndMainMenuBar();
            JEApp.ClearFreeMemory();
            ImGui::Text("\n\nWELLCOME TO JE!!\nCREATED BY HCPP\n\n\n\n");               // Display some text (you can use a format strings too)
            fLX = (xController1->GetState().Gamepad.sThumbLX / 32768.0f);
            fLY = (xController1->GetState().Gamepad.sThumbLY / 32768.0f);
            fRX = (xController1->GetState().Gamepad.sThumbRX / 32768.0f);
            fRY = (xController1->GetState().Gamepad.sThumbRY / 32768.0f);
            fLT = (xController1->GetState().Gamepad.bLeftTrigger / 255.0f);
            fRT = (xController1->GetState().Gamepad.bRightTrigger / 255.0f);
            if (xController1->IsConnected() || C_XinputControllerState)
            {
                ImGui::Text("CONTROLLER CONNECTED!!\n\n");
                C_XinputControllerState = true;
            }
            else
            {
                ImGui::Text("CONTROLLER NOT FOUND!! \nPLEASE PLUG YOUR CONTROLLER!!\n\n");
                C_XinputControllerState = false;
                //fSndMsg(1);
            }
            //
           // ImGui::ColorButton("JoyStickTest", ImVec4(0.90f, 0.65f, 0.65f, 0.45f),1,ImVec2(100.0f,50.0f));
            if (!bShowButtons)
            {
                if (ImGui::Button("\tJOYSTICKTEST", ImVec2(170.0f, 50.0f)))
                {
                    fJEFrame = true;
                    bShowButtons = true;
                }
            }
            if (fJEUpdate)
            {
                JEApp.ClearFreeMemory();
               // LPBINDSTATUSCALLBACK st_b;
                const TCHAR dURL[] = _T("https://hcpp20334.github.io/update/JE_x64_OpenGLv1.0.7SSE4.2cpp20_Release.zip");
                const TCHAR dFllePath[] = _T("JE_x64_OpenGLv1.0.7SSE4.2cpp20_Release.zip");
                int64_t fDwChannel_0 =  URLDownloadToFile(NULL, NULL, dFllePath, 0, NULL);
                static bool v_bDown = false;
                static bool v_bStatus = false;
                std::string btn_name = "DOWNLOAD";
                ImGui::Begin("\tUPDATE CENTER", &fJEUpdate, ImGuiWindowFlags_NoCollapse);
                ImGui::Text("UPDATE CENTER - UPDATE JE TO GITHUB SERVER");
               // std::cout << st_b << std::endl;
                if (ImGui::Button((btn_name).c_str(), ImVec2(100.f, 50.0f)))
                {
                    btn_name = "CONNECTING..";
                    Sleep(13);
                    v_bDown = true;
                }
                if (!v_bStatus)
                {
                   
                    ImGui::Text(("UPDATE FATAL ERROR!!" + std::to_string(fDwChannel_0)).c_str());
                }
                if (v_bStatus)
                {
                    btn_name = "DOWNLOAD OK";
                    ImGui::Text("UPDATE SUCCEEDED!\t\t\nSAVED TO: ./JEx64_OpenGL3_SSE4.2cpp20");
                    Sleep(13);
                    btn_name = "DOWNLOAD";
                    v_bDown = false;
                }
                if (v_bDown)
                {
                    fDwChannel_0 = URLDownloadToFile(NULL, dURL, dFllePath, 0, NULL);
                    if (SUCCEEDED(fDwChannel_0))
                    { 
                        v_bStatus = true;
                        
                        Sleep(3000);
                        v_bDown = false;
                        
                    }
                    if (FAILED(fDwChannel_0))
                    {
                        v_bStatus = false;
                        Sleep(1000);
                        v_bDown = false;

                    }
                }
                ImGui::End();
            }
            //button
            //  detector
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

                //
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
                }JEApp.ClearFreeMemory();
               //bShowButtons = false;
                ImGui::Text(" BUTTONS ");
                ImGui::SliderFloat("A", &fB_a, 0.0f, 1.0f);
                ImGui::SliderFloat("X", &fB_x, 0.0f, 1.0f);
                ImGui::SliderFloat("Y", &fB_y, 0.0f, 1.0f);
                ImGui::SliderFloat("B", &fB_b, 0.0f, 1.0f);
                ImGui::SliderFloat("RB", &fB_rb, 0.0f, 1.0f);
                ImGui::SliderFloat("LB", &fB_lb, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("UP", &fB_du, 0.0f, 1.0f);
                ImGui::SliderFloat("Dowm", &fB_dd, 0.0f, 1.0f);
                ImGui::SliderFloat("Left", &fB_dl, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("Right", &fB_dr, 0.0f, 1.0f);
                ImGui::Text(" AXIS ");
                ImGui::SliderFloat("LX", &fLX, 0.0f, 1.0f);
                ImGui::SliderFloat("RX", &fLY, 0.0f, 1.0f);
                ImGui::SliderFloat("LY", &fRX, 0.0f, 1.0f);
                ImGui::SliderFloat("RY", &fRY, 0.0f, 1.0f);
                ImGui::SliderFloat("LT", &fLT, 0.0f, 1.0f);                  // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::SliderFloat("RT", &fRT, 0.0f, 1.0f);
                ImGui::Checkbox("Lmotor", &fL_motor);
                ImGui::Checkbox("Rmotor", &fR_motor);
                if (v_bInvertVibValue)
                {
                    //WriteConfigJE.is_open();
                 
                    xController1->Vibrate(v_Lmotor, v_Rmotor);
                }
                else
                {
                    xController1->Vibrate((v_Lmotor * -1), (v_Rmotor * -1));
                   
                }
                
                if (fR_motor)
                {
                    ImGui::InputInt("Rduration", &v_Rmotor, 1, 100);
                }
                if (fL_motor)
                {
                    ImGui::InputInt("Lduration", &v_Lmotor, 1, 100);
                }
                if (!fL_motor || !fR_motor)
                {
                    v_Lmotor = 0;
                    v_Rmotor = 0;
                }
                if (ImGui::Button("Back to menu",ImVec2(150.0f,60.0f)))                           // Buttons return true when clicked (most widgets return true when edited/activated)
                {
                    fJEFrame = false;
                    bShowButtons = false;
                }
            }
           // static bool bCPUTest = false;
            //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
            // io.Fonts->AddFontFromFileTTF("./WhiteRabbit.ttf", 15.0f);
            ImGui::Begin("g",&fJEFrame, ImGuiWindowFlags_NoTitleBar);
            ImGui::SetWindowPos(ImVec2(14.0f, 480.0f));
            ImGui::SetWindowSize(ImVec2(377.0f, 40.0f));
            ImGui::Text(("BULID: 1.0.8 (x64) OpenGL3 SSE4.2_cpp20 \n[FPS:" + std::to_string((int64_t)io.Framerate) + " |MEM:" + std::to_string((int64_t)(fDataMemUsage() / 1024) / 1024) + "MiB]").c_str());
            ImGui::End();
            ImGui::SameLine();
            ImGui::End();
        }
        if (fCAboutW)
        {
            ImGui::Begin("\tAbout", &fCAboutW, ImGuiWindowFlags_NoCollapse);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::TextColored(ImVec4(0.0f, 200.0f, 100.0f, 10.0f), (fBuffer0).c_str());
           // ImGui::TextColored(ImVec4(0.0f, 200.0f, 100.0f, 10.0f),( std::to_string(fJ_vendor).c_str()));
            ImGui::Text(("Size Loaded: " + std::to_string((int64_t)fBuffer0.size())).c_str());
           // std::cout << &fJ_vendor << &fJ_rendered << "\n";
            if (ImGui::Button("OK"))
                fCAboutW = false;
            ImGui::End();
        }
        if (bCPUTest)
        {
            static int64_t v_Cscore = 0;
            static int64_t v_CFirst = 0;
            static int64_t v_COutV = 0;
            static int64_t fV = 0;
            static int64_t fc_0 = 0;
            static bool cp_state = false;
            ImGui::Begin("\tCPU Test", &bCPUTest, ImGuiWindowFlags_NoCollapse);
            
           // ImGui::Text(("cores: " + std::to_string(dDataCPU(3)) + "\nThreads: " + std::to_string(dDataCPU(4))).c_str());
            ImGui::TextColored(ImVec4(11.8f, 88.1f, 43.0f, 10.f), "Test CPU");
            ImGui::Text((std::to_string(v_Cscore)+"\nBuffer: "+ fBuffer_data).c_str());
             //std::cout << "Cycle:" << fT_cpuSpeed << "Score" << v_Cscore << std::endl;
            if (ImGui::Button("TEST"))
            {
                v_Cscore = ld_V(&fBuffer_data);
   
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
