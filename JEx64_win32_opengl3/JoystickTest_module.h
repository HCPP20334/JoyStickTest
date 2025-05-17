
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
#include <cstdarg>
#include "imgui_internal.h"
#include <random>
#include "imgui_stdlib.h"
#include <winhttp.h>
#pragma comment(lib, "winhttp.lib")
bool DownloadFileWinHTTP() {
    const TCHAR dURL[] = _T("https://raw.githubusercontent.com/HCPP20334/JoyStickTest/refs/heads/main/README.md");
    const TCHAR dFllePath[] = _T("readme.md");
    int64_t fDwChannel_0 = URLDownloadToFile(NULL, NULL, dFllePath, 0, NULL);
    static bool v_bDown = false;
    static bool v_bStatus = false;
    static bool WindowReadBool = false;
    static  std::string btn_name;
    std::string strdata;
    fDwChannel_0 = URLDownloadToFile(NULL, dURL, dFllePath, 0, NULL);
    return SUCCEEDED(fDwChannel_0) ? true & URLDownloadToFile(NULL, NULL, dFllePath, 0, NULL) : false;
}
class rd {
public:
    float    frand(float in_v);
    double   drand(double in_v);
    uint64_t randU64(uint64_t in_v);
    uint32_t randU32(uint32_t in_v);
    uint16_t randU16(uint16_t in_v);
    uint8_t  randU8(uint8_t in_v);
};
float  rd::frand(float in_v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, in_v);
    return dis(gen);
}
double  rd::drand(double in_v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis((double)0, in_v);
    return dis(gen);
}
uint64_t  rd::randU64(uint64_t in_v) {
    return static_cast<uint64_t>(rand() % in_v);
} 
uint32_t  rd::randU32(uint32_t in_v) {
    return static_cast<uint32_t>(rand() % in_v);
}
uint16_t  rd::randU16(uint16_t in_v) {
    return static_cast<uint16_t>(rand() % in_v);
}
uint8_t  rd::randU8(uint8_t in_v) {
    return static_cast<uint8_t>(rand() % in_v);
}
rd *RD = new rd;
namespace ImGui {
   
};
class AppModule {
public:
	ImVec4 RGBA2IV4(uint64_t rx, uint64_t gx, uint64_t bx, uint64_t ax);
    bool OpenMDRelease(std::string* out);
	
};
bool AppModule::OpenMDRelease(std::string* out) {
    std::string str;
    std::string d;
    static int64_t ln = 0;
    if (DownloadFileWinHTTP()) {
        std::ifstream mdread("readme.md");
        while (getline(mdread, str)) {
            d += str;
            ln++;
            if (ln >= 1) {
                d += "\n";
                ln = 0;
            }
        }
        *out = d;
    }
    else {
        MessageBoxA(NULL, "Fatal Error!!", ("README.md"), 1);
    }
    return true;
}
class JT
{
public:
     float fB_a = 0.0f;
     float fB_b = 0.0f;
     float fB_x = 0.0f;
     float fB_y = 0.0f;
     float fB_rt = 0.0f;
     float fB_rb = 0.0f;
     float fB_lb = 0.0f;
     float fB_lt = 0.0f;
     float fB_du = 0.0f;
     float fB_dd = 0.0f;
     float fB_dl = 0.0f;
     float fB_dr = 0.0f;
     float fB_ls = 0.0f;
     float fB_rs = 0.0f;
     int counter = 0;
     bool fJEFrame = false;
    bool fLoadingFrame = true;
     float fC_Rcol = 0.0f;
     float fC_Gcol = 0.0f;
     float fC_Bcol = 0.0f;
     bool bShowButtons = false;
     bool b_Start = false;
     bool b_Back = false;
     bool bkb_emuFrame = false;
     bool fWFrame = true;
    //
     float df = 0.0f;
    bool C_XinputControllerState = false;
    bool C_XinputControllerStateError = false;
     float  fByteArray = 0;
     float fLX = 0;
     float fLY = 0;
     float fRX = 0;
     float fRY = 0;
    //
     float fLT = 0;
     float fRT = 0;
    //
   // ShowWindow(GetConsoleWindow(), 2);
     bool b_vsync = false;
     bool fL_motor = false;
     bool fR_motor = false;
     bool v_flagClMemory = false;
     bool v_bExit = false;
     int  v_Rmotor = 0;
     int v_Lmotor = 0;
     bool v_bSettings = false;
     bool v_bSettingsCh_b = false;
     bool v_bInvertVibValue = false;
     bool rd_text;
     bool v_Penis = false;
     bool fFontsState = true;
     bool v_bThemeJE;
     bool Gamepad_enable;
     bool fExitWindow = false;
     bool fInvertYBool = false;
    //
     std::string filestr;
     std::string fStrMsgBuf;
     std::string fBuffer_data;
      std::string bStrStatus;
    //
     int64_t fThemeId = 0;
     int64_t b_data = 0;
     int64_t b_type = 0;
     int64_t fDelay = 0;
     int64_t fGPUScore = 0;
     int64_t fGPUScore0 = 0;
    //

    uint64_t OutLatency = 0;
    int imgCountToRender = 0;
     int th_bar = 1000;
    //

    //
    char fInputBuffer;
    bool stopBench = false;
    std::string buf_0;
    int64_t Val = 0;
     bool bCPUTest = false;
     bool ts_window = true;
     bool bGPUTest = false;
     bool bKbTest = false;
    bool renderFrame = false;
    ImDrawListSplitter JEApp;
     bool fCAboutW = false;
    ImVec4 clear_color = ImVec4(0.01f, 0.01f, 0.02f, 0.80f);
    ImVec2 fJ_size;
    JoyStickAPI* xController1 = new JoyStickAPI(1);
    JoyStickAPI* xController2 = new JoyStickAPI(2);
};
JT* JTModule = new JT;
ImVec4 AppModule::RGBA2IV4(uint64_t rx, uint64_t gx, uint64_t bx, uint64_t ax) {
	uint64_t rnw = rx / 255;
	uint64_t gnw = gx / 255;
	uint64_t bnw = bx / 255;
	uint64_t anw = ax / 255;
	return ImVec4(rnw, gnw, bnw, anw);
}
AppModule* GUI = new AppModule;
#pragma once
