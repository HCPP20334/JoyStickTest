
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
#include "dSys.h"
#include <fstream>
#include <Psapi.h>
#include <urlmon.h>//
#include <clocale>
#include <thread>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "resource.h"
#include <sysinfoapi.h>
#include "Colors.h"
#include <unordered_map>
#pragma comment (lib , "Urlmon.lib")
uint64_t fDataMemUsage() // Work Function !!! Check Sym RAM to Current Program //
{
    PROCESS_MEMORY_COUNTERS pmc;
    pmc.cb = sizeof(pmc);
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize;
}

#pragma once


// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height,unsigned char *imgBuffer) {
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    *imgBuffer = *image_data;
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}
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
typedef double  long float64_t;
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
static bool bGPUTest = false;
static bool bKbTest = false;
bool renderFrame = false;
static bool fCAboutW;
//
uint64_t id = 0;
int64_t  idx = 0;


//
const GLubyte* fJ_vendor = glGetString(GL_VENDOR);// Returns the vendor
const GLubyte* fJ_rendered = glGetString(GL_RENDERER);
//
void ResetDeviceWGL();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static int64_t ld_V(std::string *buff,std::string* debug_str)
{
    std::string fBuffer_fIn = "01234567890/,./<>[{||*&^%$#@@}]";
    int64_t fBufferSizeOffset = fBuffer_fIn.size();
    uint64_t InTimeData = GetTickCount64();
    uint64_t OutTimeData = 0;
    uint64_t stackPointOut = 0;
    uint64_t randPointOffset = 0;
    for (int64_t stackPoint = 0; stackPoint < 1000000; stackPoint++)
    {
        srand(time(0));
        stackPointOut = stackPoint;
        randPointOffset = rand() % fBufferSizeOffset;
        fBuffer_fIn = fBuffer_fIn + fBuffer_fIn[randPointOffset];
        fBufferSizeOffset = fBuffer_fIn.size();
    }
    OutTimeData = GetTickCount64();
    *buff = std::to_string((float)(OutTimeData - InTimeData) / 3.14f);
    *debug_str = std::to_string(stackPointOut) + " count\nbufferSizeOffset:" + std::to_string((fBufferSizeOffset / 1024)) + " :KiB Loaded";
}
bool b_Msg = false;
uint64_t ImMessage(const char* str_text, const char* title_text)
{
   
    if (b_Msg)
    {
        ImGui::Begin(str_text, &b_Msg);
        ImGui::Text(title_text);
        if (ImGui::SmallButton("OK")) { b_Msg = false; }

        // *b_event = b_Msg;
        ImGui::End();
        return strlen(str_text);
    }
}
static bool kButton(bool state, bool bSameLine,std::string value) {
    if (state) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(1.0f, 0.0f, 0.33f, 1.0f));
    }
    if (!state) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.30f, 0.30f, 0.30f, 0.80f));
    }
    ImGui::Button((value).c_str(),ImVec2(50,50));
    ImGui::PopStyleColor();
    if (bSameLine) {
        ImGui::SameLine();
    }
    return state;
}
class ClockSystem {
public:
        uint64_t fC_second = fLTime(2);
        
};
static std::string SwapTextStr(int64_t code) {
    return std::to_string((char)code);
}
void StyleColorsDracula(ImGuiStyle* dst) {
    ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 1.0f };
    colors[ImGuiCol_MenuBarBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Border] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.29f };
    colors[ImGuiCol_BorderShadow] = ImVec4{ 0.0f, 0.0f, 0.0f, 0.24f };
    colors[ImGuiCol_Text] = ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f };
    colors[ImGuiCol_TextDisabled] = ImVec4{ 0.5f, 0.5f, 0.5f, 1.0f };
    colors[ImGuiCol_Header] = ImVec4{ 0.13f, 0.13f, 0.17, 1.0f };
    colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_HeaderActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Button] = ImVec4{ 0.13f, 0.13f, 0.17, 1.0f };
    colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_ButtonActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_CheckMark] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
    colors[ImGuiCol_PopupBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 0.92f };
    colors[ImGuiCol_SliderGrab] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.54f };
    colors[ImGuiCol_SliderGrabActive] = ImVec4{ 0.74f, 0.58f, 0.98f, 0.54f };
    colors[ImGuiCol_FrameBg] = ImVec4{ 0.13f, 0.13, 0.17, 1.0f };
    colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Tab] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TabHovered] = ImVec4{ 0.24, 0.24f, 0.32f, 1.0f };
    colors[ImGuiCol_TabActive] = ImVec4{ 0.2f, 0.22f, 0.27f, 1.0f };
    colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_ScrollbarBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 1.0f };
    colors[ImGuiCol_ScrollbarGrab] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4{ 0.24f, 0.24f, 0.32f, 1.0f };
    colors[ImGuiCol_Separator] = ImVec4{ 0.44f, 0.37f, 0.61f, 1.0f };
    colors[ImGuiCol_SeparatorHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
    colors[ImGuiCol_SeparatorActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 1.0f };
    colors[ImGuiCol_ResizeGrip] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.29f };
    colors[ImGuiCol_ResizeGripHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 0.29f };
    colors[ImGuiCol_ResizeGripActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 0.29f };
#ifdef IMGUI_HAS_DOCK
    colors[ImGuiCol_DockingPreview] = ImVec4{ 0.44f, 0.37f, 0.61f, 1.0f };
#endif
}
static bool bTh_Classic = true;
static bool bTh_Dark = false;
static bool bTh_Light = false;
int main(int, char**)
{

    static std::string fBuffer0 = 

        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⠟⠛⠛⠋⠉⠉⠉⠄⠄⠄⠄⠐⠒⠒⠶⣶⣤⡀⠄⠄⠄⠉⠉⠉⠙⠛⠛⠻⣿"
        "⣿⣦⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣶⣶⣶⠈⠻⣿⣆⠄⠄⠄⠄⠄⠄⠄⣠⣾⣿"
        "⣿⣿⣿⣦⡀⠄⠄⠄⠄⠄⢀⣼⣿⣿⣿⠁⠄⠄⢹⣿⡇⠄⠄⠄⠄⣠⣾⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣶⣄⠄⠄⠄⠙⢿⡿⠋⠻⣿⣦⣀⣸⣿⡿⠄⠄⣠⣾⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⡗⠄⠄⢀⣤⡀⠄⠄⠈⢿⣿⣿⣿⠃⠄⢾⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⡇⢀⣴⣿⣿⣿⣷⣶⣶⣿⣿⣿⣿⣷⣄⢸⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⠄⠺⣿⡿⠁⠄⠉⠉⠉⠉⠄⠄⠙⢿⠏⠈⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⡏⠄⠄⠈⠄⠄⣀⣤⣾⣶⣤⡀⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⠃⠄⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠄⠸⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿";
    ClockSystem clock;
    ImDrawListSplitter JEApp;
    static bool fCAboutW;
    ImVec4 clear_color = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    ImVec2 fJ_size;
    JoyStickAPI* xController1;
    JoyStickAPI* xController2;
    xController1 = new JoyStickAPI(1);
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
    bool fLoadingFrame = true;
    static float fC_Rcol = 0.0f;
    static float fC_Gcol = 0.0f;
    static float fC_Bcol = 0.0f;
    static bool bShowButtons = false;
    static bool b_Start = false;
    static bool b_Back = false;
    static bool bkb_emuFrame = false;
    static bool fWFrame = true;
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
    static bool Gamepad_enable;
    static bool fExitWindow = false;
    //
    static std::string filestr;
    static std::string fStrMsgBuf;
    static std::string fBuffer_data;
    static  std::string bStrStatus;
    //
    static int64_t fThemeId = 0;
    static int64_t b_data = 0;
    static int64_t b_type = 0;
    static int64_t fDelay = 0;
    static int64_t fGPUScore = 0;
    //
 
    uint64_t OutLatency = 0;
    int imgCountToRender = 0;
    static int th_bar = 1000;
    //

    //
     char fInputBuffer;
     bool stopBench = false;
     std::string buf_0;
    int64_t Val = 0;
    // Create application window
    ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"JE x64", nullptr };
    wc.hIcon = LoadIcon(wc.hInstance, MAKEINTRESOURCE(103));
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"JoyStickTest 1.1 OpenGL3_SSE4.2 (C++20)", WS_OVERLAPPEDWINDOW | WS_EX_TOOLWINDOW |  WS_EX_NOPARENTNOTIFY, 100, 80, 800, 480, nullptr, nullptr, wc.hInstance, nullptr);

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
   // ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::AnimateWindow(hwnd, 100, AW_BLEND);
    ::ShowWindow(GetConsoleWindow(), 2);
    ::UpdateWindow(hwnd);
    std::string fStrParam;
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls

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
        io.Fonts->AddFontFromFileTTF(".\\consola.ttf", 20.0f);
    }
    else
    {
        io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 20.0f);//
    }
    ImFont* font1 = io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 20.0f);
    ImFont* font2 = io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 40.0f);
    ImFont* font3 = io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 15.0f);
    struct GPU_DATA {
        std::string E_Brand = (const char*)glGetString(GL_VENDOR);
        std::string E_Model = (const char*)glGetString(GL_RENDERER);
        std::string E_GLVer = (const char*)glGetString(GL_VERSION);
    };
    GPU_DATA GPU;
    std::string fD_gpuBrand = GPU.E_Brand;
    std::string fD_gpuModel = GPU.E_Model;
    std::string fD_gpuGLVer = GPU.E_GLVer;
    SetColorAMD64(240);
   // std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "" << std::endl;
    int CPUInfo[4] = { -1 };
    unsigned   nExIds, i = 0;
    char CPUBrandString[0x40];
    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        // Interpret CPU brand string
        if (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    // Main loop
    bool done = false;
    ShowWindow(GetConsoleWindow(),0);
    const char* strFiles[] = { "test.png", "icon_amd_radeon.png" };
    GLuint GLArrayBuffer;
    GLuint GLArrayBuffer_1;
    int64_t a, b;
    int Ix = 128; int Iy = 128;
    int Ix1 = 128; int Iy1 = 128;
    unsigned char imgBuffer;
    unsigned char imgBufferAMD;
    bool load = LoadTextureFromFile(strFiles[0], &GLArrayBuffer, &Ix, &Iy, &imgBuffer);
    bool amdLogo = LoadTextureFromFile(strFiles[1], &GLArrayBuffer_1, &Ix1, &Iy1, &imgBufferAMD);
    IM_ASSERT(load);
    IM_ASSERT(amdLogo);
    static bool dgwnd = false;
    static std::string dCPUBrandString = CPUBrandString;
    while (!done)
    {

        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        fWFrame = true;
        bool fB_loadFrame = false;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            std::exception d;
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                exit(0);
              //  done = true;
            if (msg.message == WM_DESTROY)
                exit(0);
        }
        
        if (done)
            break;
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
           
           // fJEFrame = false;
           // std::cout << "[JE_ENGINE] Frame Cra" << std::endl;
          //  std::cout << "ADDR:" << &d << "->" << d << std::endl;
            ImGui::Begin("\tJE x64_OpenGL3_SSE4.2 C++20",&fJEFrame, ImGuiWindowFlags_NoCollapse + ImGuiWindowFlags_NoTitleBar);  
                // Create a window called "Hello, world!" and append into it.
                ImGui::SetWindowPos(ImVec2(-1.0f, 25.0f));
                ImGui::SetWindowSize(ImVec2(800.0f, 480.0f));
                JEApp.ClearFreeMemory();
                std::ofstream WriteConfigJE("JE_CONFIG.TXT");
                // ImGui::Begin("THEME EDITOR", &v_bThemeJE);
                ImGuiStyle& style = ImGui::GetStyle();
                if (bTh_Classic) {
                    bTh_Dark = false;
                    bTh_Light = false;
                    bTh_Classic = true;
                    // ImGui::StyleColorsClassic(); fStrMsgBuf = "Theme 1 Apply!!";  WriteConfigJE.is_open();
                    StyleColorsDracula(&style);
                    WriteConfigJE << "fJETheme=1;" << std::endl;
                    //WriteConfigJE.close();
                }
                if (bTh_Light) {
                    bTh_Dark = false;
                    bTh_Classic = false;
                    bTh_Light = true;
                    ImGui::StyleColorsLight();
                    WriteConfigJE.is_open();
                    WriteConfigJE << "fJETheme=2;" << std::endl;
                    //WriteConfigJE.close();
                }
                if (bTh_Dark)
                {
                    bTh_Light = false;
                    bTh_Classic = false;
                    bTh_Dark = true;
                    fStrMsgBuf = "Theme 0";
                    WriteConfigJE.is_open();
                    WriteConfigJE << "fJETheme=0;" << std::endl;
                    //WriteConfigJE.close();
                    
                    style.ButtonTextAlign = ImVec2(0.2f, 0.5f);
                    style.WindowRounding = 5.3f;
                    style.FrameRounding = 2.3f;
                    style.ScrollbarRounding = 0;
                    style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
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
                    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 1.0f);
                    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.30f, 0.30f, 0.30f, 1.0f);
                    style.Colors[ImGuiCol_Button] = ImVec4(0.30f, 0.30f, 0.30f, 0.80f);
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
                  //  style.Colors[ImGuiCol_WindowShadow] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
                    ImGuiButtonFlags btn_flags = ImGuiButtonFlags_MouseButtonMask_;
                    //ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(100.0f, 100.0f));
                }
                //ImGui::Text(("b0:" + std::to_string(bTh_Classic) + "b1:" + std::to_string(bTh_Dark) + "b1:" + std::to_string(bTh_Light)).c_str());
                JEApp.ClearFreeMemory();
                if (b_vsync) {
                    Sleep(13);
                    WriteConfigJE << "fJEVsync=true;" << std::endl;
                }
                else {
                    Sleep(0);
                    WriteConfigJE << "fJEVsync=false;" << std::endl;
                }
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    v_bExit = true;
                }
                if (dgwnd) {
                    std::exception mainStack;
                    ImGui::Text("f=%p", &v_bExit);
                    std::cout << "f=" << &v_bExit << std::endl;
                    ImGui::Begin("1d", &dgwnd, ImGuiWindowFlags_NoCollapse + ImGuiWindowFlags_NoTitleBar);
                    ImGui::SetWindowSize(ImVec2(600.0f, 600.0f));
                    ImGui::Text(("b_vsync:" + std::to_string(b_vsync)+"\tstack:=%p").c_str(), &b_vsync);
                    ImGui::Text(("fL_motor:"+std::to_string(fL_motor)+"\tstack:=%p").c_str(), &fL_motor);
                    ImGui::Text(("fL_motor:"+std::to_string(fL_motor)+"\tstack:=%p").c_str(), &fR_motor);
                    ImGui::Text(("v_flagClMemory:" + std::to_string(v_flagClMemory)+"\tstack:=%p").c_str(), &v_flagClMemory);
                    ImGui::Text(("imgBufferAMD:" + std::to_string(imgBufferAMD)+"\tstack:=%p").c_str(), &imgBufferAMD);
                    ImGui::Text(("v_bExit:" + std::to_string(v_bExit)+"\tstack:=%p").c_str(), &v_bExit);
                    ImGui::Text(("v_Rmotor:"+std::to_string(v_Rmotor)+"\tstack:=%p").c_str(), &v_Rmotor);
                    ImGui::Text(("v_Lmotor:" + std::to_string(v_Lmotor)+"\tstack:=%p").c_str(), &v_Lmotor);
                    ImGui::Text(("v_bSettings:" + std::to_string(v_bSettings) + "\tstack:=%p").c_str(), &v_bSettings);
                    ImGui::Text(("v_bSettingsCh_b:"+std::to_string(v_bSettingsCh_b)+"\tstack:=%p").c_str(), &v_bSettingsCh_b);
                    ImGui::Text(("v_bInvertVibValue:" + std::to_string(v_bInvertVibValue)+"\tstack:=%p").c_str(), &v_bInvertVibValue);
                    ImGui::Text(("rd_text:"+std::to_string(rd_text)+"\tstack:=%p").c_str(), &rd_text);
                    ImGui::Text(("v_Penis:"+std::to_string(v_Penis)+"\tstack:=%p").c_str(), &v_Penis);
                    ImGui::Text(("fFontsState:"+std::to_string(fFontsState)+"\tstack:=%p").c_str(), &fFontsState);
                    ImGui::Text(("imgBufferAMD:"+std::to_string(imgBufferAMD)+"\tstack:=%p").c_str(), &imgBufferAMD);
                    ImGui::Text(("v_bThemeJE:"+std::to_string(v_bThemeJE)+"\tstack:=%p").c_str(), &v_bThemeJE);
                    ImGui::Text(("bTh_Classic:"+std::to_string(bTh_Classic)+"\tstack:=%p").c_str(), &bTh_Classic);
                    ImGui::Text(("bTh_Dark:"+std::to_string(bTh_Dark)+"\tstack:=%p").c_str(), &bTh_Dark);
                    ImGui::Text(("bTh_Light:"+std::to_string(bTh_Light)+"\tstack:=%p").c_str(), &bTh_Light);
                    ImGui::Text(("Gamepad_enable:"+std::to_string(Gamepad_enable)+"\tstack:=%p").c_str(), &Gamepad_enable);
                    ImGui::Text(("C_XinputControllerState=" + std::to_string(C_XinputControllerState) + "\tstack=%p").c_str(), &C_XinputControllerState);
                    ImGui::End();
                }
                if (v_bSettings)
                {
                    ImGui::Begin("SETTINGS", &v_bSettings, ImGuiWindowFlags_NoCollapse);
                    JEApp.ClearFreeMemory();
                    // ImGui::Image((void*)(intptr_t)out_texture, ImVec2(Ix, Ix));
                    if (v_bSettings) { v_bSettingsCh_b = true; }
                    //ImGui::Checkbox("AUTO CLEARNING MEMORY(DEBUG)", &v_flagClMemory);
                    ImGui::Text("::: MAIN SETTINGS :::\n\n");
                    ImGui::MenuItem("VSYNC", "", &b_vsync, true);
                    ImGui::MenuItem("INVERT VIBRATION VALUE FOR EMU XINPUT", "", &v_bInvertVibValue, true);
                    // ImGui::Checkbox("EMU XINPUT(DEBUG)", &C_XinputControllerState);
                    ImGui::MenuItem("SELECT FONTS", "", &fFontsState, true);
                    ImGui::MenuItem("Debug Info", "", &dgwnd,true);
                    ImGui::Text("::: THEME EDITOR :::\n\n");
                    ImGui::Checkbox("DARK", &bTh_Dark);
                    ImGui::SameLine();
                    ImGui::Checkbox("LIGHT", &bTh_Light);
                    ImGui::SameLine();
                    ImGui::Checkbox("CLASSIC", &bTh_Classic);
                    ImGui::Text("_______________________________");
                    ImGui::PushFont(font3);
                    ImGui::Text(("CPU:" + dCPUBrandString).c_str());//
                    ImGui::Text(("GPU:" + (fD_gpuModel)).c_str());
                    ImGui::Text(("GPU GL:" + (fD_gpuGLVer)).c_str());
                    ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), ("[--RAM Memory--]\nMemory Load:" + std::to_string(fMemStatus(1))+":Procents | "+(std::to_string(fMemStatus(7) - fMemStatus(4))) + ":GB\nFree Memory:" + std::to_string(fMemStatus(4)) + " :GB\nTotal Memory" + std::to_string(fMemStatus(7)) + " :GB").c_str());
                    ImGui::PopFont();
                    ImGui::Text("_______________________________");
                    //ImMessage("Test_00", "Test Window");
                    //  ImGui::SliderInt("Win Volume", &fC_vol, 0, 100, "", 0);
                    if (GetAsyncKeyState((char)VK_UP) && GetAsyncKeyState((char)VK_LCONTROL))
                    {
                        keybd_event(VK_VOLUME_UP, 0x45, KEYEVENTF_EXTENDEDKEY | 0, NULL);
                    }
                    if (GetAsyncKeyState((char)VK_DOWN) && GetAsyncKeyState((char)VK_LCONTROL))
                    {
                        keybd_event(VK_VOLUME_DOWN, 0x45, KEYEVENTF_EXTENDEDKEY | 0, NULL);
                    }
                    //ImGuiKey_GamepadBack
                    if (ImGui::Button("SAVE"))
                    {
                        std::ofstream buf("restart.bat");
                        buf.is_open();
                        buf << "taskkill /im JEx64OpenGL.exe>nul\n";
                        buf << "start ./JEx64OpenGL.exe>nul\n";
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
                JEApp.ClearFreeMemory();
                if (GetAsyncKeyState('C')) {
                    MessageBoxA(hwnd, ("CPU:" + dCPUBrandString + "\ngpu_model: " + fD_gpuModel + "\ngpu_brand: " + fD_gpuBrand + "\ngpu_OpenGL_version: " + fD_gpuGLVer[0]+ fD_gpuGLVer[1]+ fD_gpuGLVer[2]+"\n[--Memory--]-RAM\nMemory Load:"+std::to_string(fMemStatus(1))+"%\nFree Memory:"+std::to_string(fMemStatus(4))+" :GB\nTotal Memory"+std::to_string(fMemStatus(7))+" :GB").c_str(), "JoyStickTest PC Hardware", 1);
                }
                static bool fJEUpdate = false;
                //XINPUT_STATE fDJUP;
                ImGui::BeginMainMenuBar();
                ImGui::MenuItem("SETTINGS", "", &v_bSettings, true);
                ImGui::MenuItem("ABOUT", "", &fCAboutW, true);
                ImGui::MenuItem("CPUTEST", "", &bCPUTest, true);
                ImGui::MenuItem("GPUTEST", "", &bGPUTest, true);
                ImGui::MenuItem("KeyBoard Test", "", &bKbTest, true);
                ImGui::MenuItem("UPDATE", "", &fJEUpdate, true);
                ImGui::MenuItem("EXIT", "", &v_bExit, true);
                if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
                {
                    v_Penis = true;
                }
                //  static bool v_bExMsg = true;
                if (GetAsyncKeyState('G') && GetAsyncKeyState('A') & GetAsyncKeyState('Y')) {
                    v_Penis = true;
                }
                if (v_Penis)
                {

                    ImGui::Begin("Memory Stack Runtime [V - to Close]");
                    //fWframeX = (rand() % 300);
                    srand(ImGui::GetTime());
                    JEApp.ClearFreeMemory();
                    ImGui::Text(":::::::::::::::::: MEMORY STACK :::::::::::::::::::");
                    ImGui::Text("---------------------------------------------------");
                    if (GetKeyState('R') > 0)
                    {
                        ImGui::SetWindowPos(ImVec2((rand() % 300), (rand() % 300)), 0);
                    }
                    if (GetAsyncKeyState('V')) { ImGui::Text("Thanks!!why used my app!!"); Sleep(1000); v_Penis = false; }
                    io.AddInputCharacter(ImGuiKey_GamepadDpadUp);
                    ImGui::End();
                }
                if (v_bExit)
                {
                    // exit:
                    JEApp.ClearFreeMemory();
                    ImGui::Begin("EXIT");
                    ImGui::PushFont(font2);
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), ":: WARNING!!! ::");
                    ImGui::PopFont();
                    ImGui::PushFont(font1);
                    ImGui::Text("\n:: SETTINGS NOT SAVED!! ::\n:: USER DATA WILL BE  LOST!! ::");
                    ImGui::PopFont();
                    if (ImGui::Button("SAVE AND EXIT",ImVec2(150.0f, 40.0f))) { ImGui::Text("Thanks!!why used my app!!"); WriteConfigJE.close(); Sleep(1000); exit(0); }
                    ImGui::SameLine();
                    if (ImGui::Button("BACK",ImVec2(150.0f,40.0f))) { v_bExit = false; }
                    ImGui::End();
                }
                ImGui::EndMainMenuBar();
                JEApp.ClearFreeMemory();
                static std::string key_pull;
               // xController1->GetBatteryState(&b_data, &b_type, &bStrStatus);
                if (bKbTest) {
                    ImGui::Begin("kb_test", &bKbTest);
                    ImGui::Text(("key_pullup: " + key_pull).c_str());

                    // Ассоциативный массив: ключ — код клавиши, значение — строковое представление
                    static const std::unordered_map<int, std::string> keyMap = {
                        {'1', "k1"}, {'Q', "kQ"},
                        {'2', "k2"}, {'W', "kW"},
                        {'3', "k3"}, {'E', "kE"},
                        {'4', "k4"}, {'R', "kR"},
                        {'5', "k5"}, {'T', "kT"},
                        {'6', "k6"}, {'Y', "kY"},
                        {'7', "k7"}, {'U', "kU"},
                        {'8', "k8"}, {'I', "kI"},
                        {'9', "k9"}, {'O', "kO"},
                        {'0', "k0"}, {'P', "kP"},
                        {'A', "kA"}, {'V', "kV"},
                        {'S', "kS"}, {'B', "kB"},
                        {'D', "kD"}, {'N', "kN"},
                        {'F', "kF"}, {'M', "kM"},
                        {'G', "kG"}, {VK_DIVIDE, "k/"},
                        {'H', "kH"}, {'.', "k."},
                        {'J', "kJ"}, {VK_ESCAPE, "kESC"},
                        {'K', "kK"}, {VK_F1, "kf1"},
                        {'L', "kL"}, {VK_F2, "kf2"},
                        {';', "k;"}, {VK_F3, "kf3"},
                        {'"', "k'"}, {VK_F4, "kf4"},
                        {'Z', "kZ"}, {VK_F5, "kf5"},
                        {'X', "kX"}, {VK_F6, "kf6"},
                        {'C', "kC"}, {VK_F7, "kf7"},
                        {VK_F8, "kf8"}, {VK_F9, "kf9"},
                        {VK_F10, "kf10"}, {VK_F11, "kf11"},
                        {VK_F12, "kf12"}
                    };
                    static bool bp0 = false; static bool bp12 = false; static bool bp24 = false;
                    static bool bp1 = false; static bool bp13 = false; static bool bp25 = false;
                    static bool bp2 = false; static bool bp14 = false; static bool bp26 = false;
                    static bool bp3 = false; static bool bp15 = false; static bool bp27 = false;
                    static bool bp4 = false; static bool bp16 = false; static bool bp28 = false;
                    static bool bp5 = false; static bool bp17 = false; static bool bp29 = false;
                    static bool bp6 = false; static bool bp18 = false; static bool bp30 = false;
                    static bool bp7 = false; static bool bp19 = false; static bool bp31 = false;
                    static bool bp8 = false; static bool bp20 = false; static bool bp32 = false;
                    static bool bp9 = false; static bool bp21 = false; static bool bp33 = false;
                    static bool bp10 = false; static bool bp22 = false; static bool bp34 = false;
                    static bool bp11 = false; static bool bp23 = false; static bool bp35 = false;
                    std::string key2;
                    kButton(bp0, true, "1");
                    kButton(bp1, true, "2");
                    kButton(bp2, true, "3");
                    kButton(bp3, true, "4");
                    kButton(bp4, true, "5");
                    kButton(bp5, true, "6");
                    kButton(bp6, true, "7");
                    kButton(bp7, true, "8");
                    kButton(bp8, true, "9");
                    kButton(bp9, false, "0");
                    kButton(bp10, true, "q");
                    kButton(bp11, true, "w");
                    kButton(bp12, true, "e");
                    kButton(bp13, true, "r");
                    kButton(bp14, true, "t");
                    kButton(bp15, true, "y");
                    kButton(bp16, true, "u");
                    kButton(bp17, true, "i");
                    kButton(bp18, true, "o");
                    kButton(bp19, false, "p");
                    kButton(bp20, true, "a");
                    kButton(bp21, true, "s");
                    kButton(bp22, true, "d");
                    kButton(bp23, true, "f");
                    kButton(bp24, true, "g");
                    kButton(bp25, true, "h");
                    kButton(bp26, true, "j");
                    kButton(bp27, true, "k");
                    kButton(bp28, false, "l");
                    kButton(bp29, true, "z");
                    kButton(bp30, true, "x");
                    kButton(bp31, true, "c");
                    kButton(bp32, true, "v");
                    kButton(bp33, true, "b");
                    kButton(bp34, true, "n");
                    kButton(bp35, true, "m");
                    static int64_t key_id = 0;
                    
                    
                    // Проверяем каждую клавишу в ассоциативном массиве
                    for (const auto& [key, keyName] : keyMap) {
                        if (GetAsyncKeyState(key)) {
                            
                            key_id++;
                            key_pull = "\n" + std::to_string(key_id) + "->kid->" + keyName;
                            key2 = keyName;
                            if (keyName == "k1") { bp0 = true; }if (keyName == "k4") { bp3 = true; }if (keyName == "k7") { bp6 = true; }
                            if (keyName == "k2") { bp1 = true; }if (keyName == "k5") { bp4 = true; }if (keyName == "k8") { bp7 = true; }
                            if (keyName == "k3") { bp2 = true; }if (keyName == "k6") { bp5 = true; }if (keyName == "k9") { bp8 = true; }
                            if (keyName == "k0") { bp9 = true; }if (keyName == "kQ") { bp10 = true; }if (keyName == "kW") { bp11 = true; }
                            if (keyName == "kE") { bp12 = true; }if (keyName == "kR") { bp13 = true; }if (keyName == "kT") { bp14 = true; }
                            if (keyName == "kY") { bp15 = true; }if (keyName == "kU") { bp16 = true; }if (keyName == "kI") { bp17 = true; }
                            if (keyName == "kO") { bp18 = true; }if (keyName == "kP") { bp19 = true; }if (keyName == "kA") { bp20 = true; }
                            if (keyName == "kS") { bp21 = true; }if (keyName == "kD") { bp22 = true; }if (keyName == "kF") { bp23 = true; }
                            if (keyName == "kG") { bp24 = true; }if (keyName == "kH") { bp25 = true; }if (keyName == "kJ") { bp26 = true; }
                            if (keyName == "kK") { bp27 = true; }if (keyName == "kL") { bp28 = true; }if (keyName == "kZ") { bp29 = true; }
                            if (keyName == "kX") { bp30 = true; }if (keyName == "kC") { bp31 = true; }if (keyName == "kV") { bp32 = true; }
                            if (keyName == "kB") { bp33 = true; }if (keyName == "kN") { bp34 = true; }if (keyName == "kM") { bp35 = true; }
                            //
                            if (keyName != "k1") { bp0 = false; }if (keyName != "k4") { bp3 = false; }if (keyName != "k7") { bp6 = false; }
                            if (keyName != "k2") { bp1 = false; }if (keyName != "k5") { bp4 = false; }if (keyName != "k8") { bp7 = false; }
                            if (keyName != "k3") { bp2 = false; }if (keyName != "k6") { bp5 = false; }if (keyName != "k9") { bp8 = false; }
                            if (keyName != "k0") { bp9 = false; }if (keyName != "kQ") { bp10 = false; }if (keyName != "kW") { bp11 = false; }
                            if (keyName != "kE") { bp12 = false; }if (keyName != "kR") { bp13 = false; }if (keyName != "kT") { bp14 = false; }
                            if (keyName != "kY") { bp15 = false; }if (keyName != "kU") { bp16 = false; }if (keyName != "kI") { bp17 = false; }
                            if (keyName != "kO") { bp18 = false; }if (keyName != "kP") { bp19 = false; }if (keyName != "kA") { bp20 = false; }
                            if (keyName != "kS") { bp21 = false; }if (keyName != "kD") { bp22 = false; }if (keyName != "kF") { bp23 = false; }
                            if (keyName != "kG") { bp24 = false; }if (keyName != "kH") { bp25 = false; }if (keyName != "kJ") { bp26 = false; }
                            if (keyName != "kK") { bp27 = false; }if (keyName != "kL") { bp28 = false; }if (keyName != "kZ") { bp29 = false; }
                            if (keyName != "kX") { bp30 = false; }if (keyName != "kC") { bp31 = false; }if (keyName != "kV") { bp32 = false; }
                            if (keyName != "kB") { bp33 = false; }if (keyName != "kN") { bp34 = false; }if (keyName != "kM") { bp35 = false; }
                            break; // Прерываем цикл, если клавиша найдена
       
                        }
                    }

                    ImGui::End();

                }
                if (!fJEFrame)
                {
                    ImGui::PushFont(font2);
                    ImGui::Text("\nWELLCOME TO JOYSTICKTEST!!");
                    ImGui::PopFont();
                    ImGui::Text("\nCREATED BY HCPP\n");

                }
              // ImGui::Text(("_____________________________\n\nCONTROLLER_1: " + bStrStatus + "\nTYPE : " + std::to_string(b_type) + "\n_____________________________").c_str());
                // GLuint gl_id;
               //  ImLoadImageForGL("Test.jpg", &gl_id, 30, 30);
                if (xController1->IsConnected() || C_XinputControllerState)
                {
                    ImGui::Text("CONTROLLER CONNECTED!!\n\n");
                    C_XinputControllerState = true;
                }
                else
                {
                    ImGui::Text("PLEASE PLUG YOUR CONTROLLER!!\n");
                    C_XinputControllerState = false;
                    //fSndMsg(1);
                }
                if (!bShowButtons)
                {
                    ImGui::Checkbox("Enable Supported All Gamepads", &Gamepad_enable);
                    if (ImGui::Button("\tJOYSTICKTEST", ImVec2(170.0f, 50.0f)))
                    {
                        fJEFrame = true;
                        bShowButtons = true;
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("\tVisit Github", ImVec2(170.0f, 50.0f)))
                    {
                        std::system("start https://github.com/hcpp20334");
                    }
                    ImGui::Text(("BULID: 1.1 (x64) (OpenGL3.3SSE4.2(C++20 GCC)) \nGPU:" + (fD_gpuModel)+" FPS:" + std::to_string((int64_t)io.Framerate) + " \n MEM : " + std::to_string((int64_t)(fDataMemUsage() / 1024) / 1024) + "MiB]").c_str());
                }
                //
               // ImGui::ColorButton("JoyStickTest", ImVec4(0.90f, 0.65f, 0.65f, 0.45f),1,ImVec2(100.0f,50.0f));
                
                uint64_t InLatency = fLTime(3);
                std::string fGPURating[] = {"SHIT","OFFICE DICK","Nice Card","Very Good","Wtf man!! You GPU quantum ?"};
                static float64_t af = 5.5f;
                if (bGPUTest) {
                    InLatency = fLTime(3);
                    uint64_t fps_count = io.Framerate;
                    JEApp.ClearFreeMemory();
                    ImGui::Begin("GPU TEST", &bGPUTest);
                    ImGui::PushFont(font2);
                    ImGui::SetCursorPosX(30.0f);
                    ImGui::Text("GPU TEST OpenGL");
                    ImGui::PopFont();//
                    if (stopBench)
                    {
                        ImGui::PushFont(font2);
                        ImGui::SetCursorPosX(30.0f);
                        ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), ("score:" + std::to_string((14 * fps_count))).c_str()); ImGui::SameLine();
                        ImGui::PopFont();
                        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.33f, 1.0f), (" " + fGPURating[id]).c_str());

                    }
                    ImGui::SetCursorPosX(30.0f);
                    ImGui::SetCursorPosY((ImGui::GetWindowHeight() - 40) / 2);
                    if (ImGui::Button("BENCH", ImVec2(130.0f, 40.0f)))
                    {
                        renderFrame = true;
                        stopBench = false;
                        
                    }
         
                    uint64_t imgLoaded = 0;
                    ImGui::SliderInt("Count:", &imgCountToRender, 100, 100000, NULL, 1);
                    ImGui::Text("Resolution");
                    ImGui::PushItemWidth(100.0f);
                    ImGui::InputInt("SizeX:", &Ix, 10, 1); ImGui::SameLine(); ImGui::InputInt("SizeY:", &Iy, 10, 1);
                    ImGui::PopItemWidth();
                    if (renderFrame) {
                        ImGui::Begin("Render", &renderFrame);
                        fps_count = io.Framerate;
                        if (fps_count == 15) {
                            id = 2;
                        }
                        if (fps_count < 15) {
                            id = 2;
                        }
                        if (fps_count <= 5) {
                            id = 0;
                        }
                        if (fps_count >= 30) {
                            id = 3;
                        }
                        if (fps_count >= 60) {
                            id = 4;
                        }
                        
                        ImGui::SetWindowSize(ImVec2(800.0f, 480.0f));
                        ImGui::Text(("GPU:[" + GPU.E_Model+"]\t fps_count:"+std::to_string(fps_count) +"loaded:"+std::to_string(imgLoaded)).c_str());
                       // ImGui::Text(("AMD AGS Device info:" + std::to_string(device.localMemoryInBytes / (1024 * 1024)) + std::to_string(device.memoryBandwidth / 1024.0f) + std::to_string(device.sharedMemoryInBytes / (1024 * 1024))).c_str());
                        for (uint64_t imgBufferOffset = 0; imgBufferOffset < imgCountToRender; imgBufferOffset++) {
                            imgLoaded = (imgBufferOffset) * 14;
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));//
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            OutLatency = fLTime(3);
                            if (!stopBench) {
                                fGPUScore = OutLatency - InLatency;
                            }
                       }
                        stopBench = true;
                        fGPUScore = fGPUScore;
                        //renderFrame = false;
                        ImGui::End();
                    }
                    ImGui::End();
                } 
                if (fJEUpdate)
                {
                    JEApp.ClearFreeMemory();
                    // LPBINDSTATUSCALLBACK st_b;
                    const TCHAR dURL[] = _T("https://github.com/HCPP20334/JoyStickTest/releases/download/JoyStickTest_x64_OpenGL_1.1/JoyStickTest_x64_OpenGL3SSE4.2.zip");
                    const TCHAR dFllePath[] = _T("JoyStickTest_x64_OpenGL3SSE4.2.zip");
                    int64_t fDwChannel_0 = URLDownloadToFile(NULL, NULL, dFllePath, 0, NULL);
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
                if (Gamepad_enable)
                {
                  
                }
                if (!Gamepad_enable)
                {
                    //button
                    //  detector
                    fLX = (xController1->GetState().Gamepad.sThumbLX / 100);
                    fLY = (xController1->GetState().Gamepad.sThumbLY / 100);
                    fRX = (xController1->GetState().Gamepad.sThumbRX / 100);
                    fRY = (xController1->GetState().Gamepad.sThumbRY / 100);
                    fLT = (xController1->GetState().Gamepad.bLeftTrigger);
                    fRT = (xController1->GetState().Gamepad.bRightTrigger);
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
                    if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START) { b_Start = true; }
                    if (xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK) { b_Back = true; }
                    //
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B) { fB_b = fB_b - 0.1f; if (fB_b < 0.1f) { fB_b = 0.0f; } }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_A) { fB_a = fB_a - 0.1f; if (fB_a < 0.1f) { fB_a = 0.0f; } }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_X) { fB_x = fB_x - 0.1f; if (fB_x < 0.1f) { fB_x = 0.0f; } }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_Y) { fB_y = fB_y - 0.1f; if (fB_y < 0.1f) { fB_y = 0.0f; } }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_RIGHT_SHOULDER) {
                        fB_rs = fB_rs - 0.1f; if (fB_rs < 0.1f) {
                            fB_rs = 0.0f;
                        }
                    }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_LEFT_SHOULDER) {
                        fB_ls = fB_ls - 0.1f; if (fB_ls < 0.1f) {
                            fB_ls = 0.0f;
                        }
                    }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_UP) {
                        fB_du = fB_du - 0.1f; if (fB_du < 0.1f) {
                            fB_du = 0.0f;
                        }
                    }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_DOWN) {
                        fB_dd = fB_dd - 0.1f; if (fB_dd < 0.1f) {
                            fB_dd = 0.0f;
                        }
                    }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_LEFT) {
                        fB_dl = fB_dl - 0.1f; if (fB_dl < 0.1f) {
                            fB_dl = 0.0f;
                        }
                    }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_RIGHT) { fB_dr = fB_dr - 0.1f; if (fB_dr < 0.1f) { fB_dr = 0.0f; } }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_START) { b_Start = false; }
                    if (xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_BACK) { b_Back = false; }
                }
                //
                if (fJEFrame)
                {

                    //
                    if (GetAsyncKeyState((char)VK_LEFT))
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
                    ImGui::MenuItem("START", "", &b_Start, b_Start);
                    ImGui::SameLine();
                    ImGui::MenuItem("BACK", "", &b_Back, b_Back);
                    ImGui::PushItemWidth(200.0f);
                    ImGui::SliderFloat("A \t", &fB_a, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("\tLY", &fLY, -327.0f, 327.0f);
                    ImGui::SliderFloat("X \t", &fB_x, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("\tRY", &fRY, -327.0f, 327.0f);
                    ImGui::SliderFloat("Y \t", &fB_y, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("\tRX", &fRX, -327.0f, 327.0f);
                    ImGui::SliderFloat("B \t", &fB_b, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("\tLX", &fLX, -327.0f, 327.0f);
                    ImGui::SliderFloat("RB\t", &fB_rs, 0.0f, 1.0f); ImGui::SameLine(); ImGui::SliderFloat("\tRT", &fRT, 0.0f, 255.0f);
                    ImGui::SliderFloat("LB\t", &fB_ls, 0.0f, 1.0f); ImGui::SameLine(); ImGui::SliderFloat("\tLT", &fLT, 0.0f, 255.0f);
                    ImGui::SliderFloat("UP\t", &fB_du, 0.0f, 1.0f); ImGui::SameLine(); ImGui::SliderFloat("\t L", &fB_dl, 0.0f, 1.0f);
                    ImGui::SliderFloat("D \t", &fB_dd, 0.0f, 1.0f); ImGui::SameLine();ImGui::SliderFloat("\t R", &fB_dr, 0.0f, 1.0f);
                    ImGui::PopItemWidth();
                    ImGui::Checkbox("Lmotor", &fL_motor);
                    ImGui::SameLine();
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
                        // ImGui::InputInt("Rduration", &v_Rmotor, 1, 100);
                        ImGui::PushItemWidth(200.0f);
                        ImGui::SliderInt("Rduration", &v_Rmotor, 0.0f, 1000.0f);
                        ImGui::SameLine();
                        ImGui::PopItemWidth();
                    }
                    if (fL_motor)
                    {
                        ImGui::PushItemWidth(200.0f);
                        ImGui::SliderInt("Lduration", &v_Lmotor, 0.0f, 1000.0f);
                        ImGui::PopItemWidth();
                        //ImGui::InputInt("Lduration", &v_Lmotor, 1, 100);
                    }
                    if (!fL_motor || !fR_motor)
                    {
                        v_Lmotor = 0;
                        v_Rmotor = 0;
                    }
                    if (ImGui::Button("Back to menu", ImVec2(150.0f, 60.0f)))                           // Buttons return true when clicked (most widgets return true when edited/activated)
                    {
                        fJEFrame = false;
                        bShowButtons = false;
                    }
                }
                // static bool bCPUTest = false;
                 //ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
                 // io.Fonts->AddFontFromFileTTF("./WhiteRabbit.ttf", 15.0f);
                
           
                ImGui::End();
            
        }
        if (fCAboutW)
        {
            ImGui::Begin("\tAbout", &fCAboutW, ImGuiWindowFlags_NoCollapse);  
            ImGui::PushFont(font2);
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f,1.0f), "JOYSTICKTEST");//Build 1.1\n
            ImGui::PopFont();
            ImGui::PushFont(font3);
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), "Build 1.1\n");//Build 1.1\n
            ImGui::PopFont();
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f),"COMPILED C++20 (GCC) Visual Studio 2022 x64\nBackendAPI: OpenGL3.3\nInstruction Set:SSE4.2,x64,IA-64");
          
            
           // std::cout << &fJ_vendor << &fJ_rendered << "\n";
            if (ImGui::Button("OK")){ fCAboutW = false; }
            ImGui::Text("Optimized"); ImGui::SameLine();
            ImGui::Image((void*)(intptr_t)GLArrayBuffer_1, ImVec2(128.0f, 64.0f));
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
            std::string fDebugData;
            ImGui::Begin("\tCPU Test", &bCPUTest, ImGuiWindowFlags_NoCollapse);

            // ImGui::Text(("cores: " + std::to_string(dDataCPU(3)) + "\nThreads: " + std::to_string(dDataCPU(4))).c_str());
            ImGui::TextColored(ImVec4(0.118f, 0.881f, 0.43f, 1.10f), "Test CPU");
            ImGui::PushFont(font2);
            ImGui::Text(("\t\t" + fBuffer_data).c_str());
            ImGui::PopFont();
            ImGui::Text(("\ninfo:\n" + fDebugData).c_str());
            //std::cout << "Cycle:" << fT_cpuSpeed << "Score" << v_Cscore << std::endl;
            ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 130) / 2);
            if (ImGui::Button("BENCH", ImVec2(130.0f, 40.0f)))
            {
                v_Cscore = ld_V(&fBuffer_data, &fDebugData);

            }
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
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menuS
            return 0;
        break;
    case WM_DESTROY:
        exit(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
