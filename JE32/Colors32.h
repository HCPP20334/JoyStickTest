//Colors C++ for console by HCPP20334
#pragma comment(lib , winmm.lib)
#include<iostream>
#include <windows.h>
#include <Wincon.h>
#include <Winbase.h>
using namespace std;

void cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
    SetConsoleCursorPosition(hConsole, coordScreen);
}
enum ConsoleColor
{
	Black       =0,
	Blue        =1,
	Green       =2,
	Cyan        =3,
	Red         =4,
	Magenta     =5,
	Brown       =6,
	White       =15,
	Lightblue   =9,
	Yellow      =14,
	Lightgreen  =10
};
int64_t GetFontA()
{
	CONSOLE_FONT_INFOEX fFontInfo;
	if(GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&fFontInfo))
	{
		MessageBox(GetConsoleWindow(),"Error: Font mr_White RabbitG not Found!!","::::::::::::::::JE:::::::::::::::::::::::",0);
		return 1;
	}
	else
	{
		return 0;
	}
}
int32_t SetFontA(const wchar_t* fNameFont , int32_t fSizeFontX , int32_t fSizeFontY)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX fFontInfo;
    fFontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    fFontInfo.dwFontSize.X = fSizeFontX;
    fFontInfo.dwFontSize.Y = fSizeFontY;
    fFontInfo.FontFamily = TMPF_TRUETYPE;
    wcscpy(fFontInfo.FaceName, fNameFont);
    if(!SetCurrentConsoleFontEx(hCon, FALSE, &fFontInfo))
    {
    	MessageBox(GetConsoleWindow(),("Error!!Font address:"+to_string(GetLastError())).c_str(),"JE->SetFont()",0);//
	}
}

int32_t E_call(COLORREF fColorId)
{
cout<<"E_call"<<endl;
}

string SetColorAMD64(int text)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD) text);
			size_t bCPU_Bit = sizeof(text);
	string bVersion;
	if(bCPU_Bit == 8)
	{
		bVersion = "CPU:AMD64";
	}
	if(bCPU_Bit == 4)
	{
		bVersion = "CPU:X86";
	}
	return bVersion;
}
bool ConsoleFullScreen(HWND bConsoleD , int sizeWindow)
{
	//HWND "Handle Console window" = GetConsoleWindows(); 
	bConsoleD = GetConsoleWindow();//Handle Window
  SetWindowLong(bConsoleD, GWL_STYLE, GetWindowLong(bConsoleD, GWL_STYLE) & WS_CAPTION); 
  ShowWindow(bConsoleD, sizeWindow);
}


