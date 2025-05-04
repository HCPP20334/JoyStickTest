
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

class AppModule {
public:
	ImVec4 RGBA2IV4(uint64_t rx, uint64_t gx, uint64_t bx, uint64_t ax);
	
};
ImVec4 AppModule::RGBA2IV4(uint64_t rx, uint64_t gx, uint64_t bx, uint64_t ax) {
	uint64_t rnw = rx / 255;
	uint64_t gnw = gx / 255;
	uint64_t bnw = bx / 255;
	uint64_t anw = ax / 255;
	return ImVec4(rnw, gnw, bnw, anw);
}
AppModule* GUI = new AppModule;
#pragma once
