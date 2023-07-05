#include <iostream>
#include <string>
//#include <clocale>
#include "Colors.h"
#include <Windows.h>
#include "JoyStick.h"
#include <conio.h>
#include <psapi.h>
#include "FileInfo.h"
#include <math.h>
#include <time.h>
#include "int128.h"
#include <thread>
using namespace std;
struct fPrint
{
int64_t FillBuffer(int64_t fXpos,int64_t fYpos,int64_t r,int64_t g,int64_t b,HWND fHwnd)
{
	SetPixel(GetDC(fHwnd),fXpos,fYpos,RGB(r,g,b));
};
};

fPrint fConsole;
uint64_t fDataMemUsage()
{
	PROCESS_MEMORY_COUNTERS pmc;
	pmc.cb = sizeof(pmc);
	GetProcessMemoryInfo(GetCurrentProcess(),&pmc,sizeof(pmc));
	return pmc.WorkingSetSize / 1024;
}
bool Asleep(int64_t Value)
{
	int64_t fCurrentPointDelay = 0;
	fCurrentPointDelay++;
	if(fCurrentPointDelay == Value)
	{
		fCurrentPointDelay = 0;
		return true;
	}
}

string fEnString()
{
	float fVersion = 1.000012;
	string fCharBufferSet = "version:"+to_string(fVersion);
	return fCharBufferSet;
}

int main(int argc, char *argv[])
{
	system("mode con cols=44 lines=32");
  //data_t 
  int64_t fMemory = 0;
  int64_t fKeyWin = 0;
  int64_t fKeyXbox = 0;
  int64_t fKeyCode = 0;
  int64_t fMaxByteToKey = 0;
  int64_t fSizeStrBuffer = 0;
  int64_t fColDebug = 0;
  int64_t fPointSettingsKeyboard = 0; 
  int64_t fXinputStatusCodeW = 0;
  int64_t fU = 0;
  int64_t fL = 0;
  int64_t fD = 0;
  int64_t fR = 0;
  int64_t fY = 0;
  int64_t fX = 0;
  int64_t fA = 0;
  int64_t fB = 0;
  int64_t fColorLine_00 = 113;
  int64_t fTime_00 = 0;
  int64_t fColor_00 = 138;
  int64_t fBatLevel = 0; 
  int64_t xLXBuffer = 0;
  int64_t fLXPos = 0;//
  int64_t fLYPos = 0;//
  int64_t fRXPos = 0;//
  int64_t fRYPos = 0;// 
  int64_t fLX = 0;
  int64_t fLY = 0;
  int64_t fRX = 0;
  int64_t fRY = 0;
  int64_t fTestYBar = 0;
  int64_t fAnimDuration = 0;
  int64_t fAnimPoint = 0;
  int64_t fErrorColor = 71;
  int64_t fDebugColorMode0 = 0;
  int64_t fDebugColorMode = 15;
  int64_t fAnimDuration0 = 0;
  int64_t fAnimPoint0 = 0;
  int64_t fRTPos = 0;
  int64_t fLTPos = 0;
  int64_t fLTPoint = 0;
  int64_t fRTPoint = 0;
  int64_t fLBPoint = 0;
  int64_t fRBPoint = 0;
  int64_t fLXAxisPoint = 0;
  int64_t fLYAxisPoint = 0;
  int64_t fRXAxisPoint = 0;
  int64_t fRYAxisPoint = 0;
  int64_t fLXM = 0;
  int64_t fLYM = 0;
  int64_t c1 = 0;
  int64_t fP0 = 0;
  int64_t fP1 = 0;
  int64_t fP2 = 0;
  int64_t fP3 = 0;
  int64_t fP4 = 0;
  int64_t fP5 = 0;
  int64_t fP6 = 0;
  int64_t fTimeUsed = 1;
  int64_t fHour = 0;
  int64_t fColorBar = 138;
  int64_t fExP = 0;
  int64_t fDebugIgnoreXiputError = 0;
  int64_t fBPoint = 0;
  int64_t fMaxErrors = 6;
  int64_t fMaxCountStatus = 3;
  int64_t fMouseCountClicks = 0;
  int64_t fColorText = 0;
  int64_t fJEColorIntro = fColorText = 138;
  int64_t fJEColorSettings = 0;
  int64_t fRegister = 199;
  int64_t fJEYSize  = 30;
  int64_t fColorStatus = 12;
  int64_t fDgFreq = 0;
  int64_t fJEAxis2MouseCoordLX = 0;
  int64_t fJEAxis2MouseCoordLY = 0;
  //Main Cycles
  int64_t fTextLoad1 = 1;
  int64_t fTextLoad = 1;
  //
  // Color Modes Menu
  int64_t fColorsMSet = 1;
  int64_t fCMl0 = 47;
  int64_t fCMl1 = 30;
  int64_t fCMl2 = 71;
  int64_t fCMl3 = 112;
  int64_t fCMl4 = 113;
  int64_t fCMl5 = 138;
  int64_t fCMl6 = 139;
  int64_t fCMl7 = 137;
  int64_t fCMl8 = 240;
  int64_t fCMl9 = 137;
  int64_t fCMlA = 249;
  int64_t fCMlB = 132;
  //
  int64_t fCMl0A = 113;
  int64_t fCMl1A = 113;
  int64_t fCMl2A = 113;
  int64_t fCMl3A = 113;
  int64_t fCMl4A = 113;
  int64_t fCMl5A = 113;
  int64_t fCMl6A = 113;
  int64_t fCMl7A = 113;
  int64_t fCMl8A = 113;
  int64_t fCMl9A = 113;
  int64_t fCMlAA = 113;
  int64_t fCMlBA = 113;
  int64_t fCMlPoint = 0;
  int64_t fClA = 0;
  ///
  //Test Rand Bars
    int64_t fRv0 = 0;
	int64_t fRv1 = 0;
	int64_t fRv2 = 0;
	int64_t fRv3 = 0;
//	int64_t fRv4 = 0;
//	int64_t fRv5 = 0;
	int64_t fColorSet = 0;
	int64_t fCv0 = 0;
	//
	//CheckFiles
	int64_t fFiles0 = 0;
	int64_t fFiles1 = 0;
	int64_t fAllSize = 0;
	int64_t fLoadStackFrame = 0;
	int64_t GetLatencyToFrame = 0;
	int64_t fFrames = 0;
	int64_t fGetFrames = 0;
	// JE DEBUGGER
	int64_t fJE_Menu = 0;
	int64_t fJEDebCol_0 = 0;
	int64_t fJEDebCol_1 = 0;
	int64_t fJEDebCol_2 = 0;
	int64_t fJEKeyDelay = 0;
	int64_t fThread_0 = 0;
	int64_t fCpuCode = 0;
	int64_t f_rnd  = 0;
	int64_t f_Kb0 = 0;
	int64_t f_Kb1 = 0;
	int64_t f_Kb2 = 0;
	int64_t f_Kb3 = 0;
	int64_t fJEKbDelayD = 0;
	int64_t fJEKbDelay = 0;
	//
	//string
	string fBuffer0;
	string fStrLX = "   ";
	string fStrLY = "   ";
	string fStrRX = "   ";
	string fStrRY = "   ";
	string fSLx;
	string fSLy;
	string fSRx;
	string fSRy;
	//
	
  char fChUp = 24;
  char fChDn = 25;
  bool fDebugger = false;
  bool bKeyPresed;
  bool fXCon;
  bool fAxisTest = false;
  bool kbEmu = false;
  bool xControllerState = false;
  bool fClear = true;
  bool fExSh = false;
  bool fDebugMode = false;
  bool fBarS;
  bool fJEColorSetMenu = false;
  bool fTestBars = false;
  bool fCheckFiles  = false;
  bool fCR_Error = false;
  bool fJEInfoF = false;
  //
  HDC fDC = GetDC(GetConsoleWindow());
  string fXinput_Status;
  JoyStickAPI* xController1;
  JoyStickAPI* xController2;
  string fTimeStr;
  string fJEText;
  string fBar[] = 
   {
   "л                           ",
   "лл                          ",
   "ллл                         ",
   "лллл                        ",
   "ллллл                       ",
   "лллллл                      ",
   "ллллллл                     ",
   "лллллллл                    ",
   "ллллллллл                   ",
   "лллллллллл                  ",
   "ллллллллллл                 ",
   "лллллллллллл                ",
   "ллллллллллллл               ",
   "лллллллллллллл              ",
   "ллллллллллллллл             ",
   "лллллллллллллллл            ",
   "ллллллллллллллллл           ",
   "лллллллллллллллллл          ",
   "ллллллллллллллллллл         ",
   "лллллллллллллллллллл        ",
   "ллллллллллллллллллллл       ",
   "лллллллллллллллллллллл      ",
   "ллллллллллллллллллллллл     ",
   "лллллллллллллллллллллллл    ",
   "лллллллллллллллллллллллллллл"
   };
   string fLoadingBar[] = 
   {
   	"л                    ",
   	"    л                ",
   	"        л            ",
   	"            л        ",
   	"                л    ",
   	"                    л"
   };
   string fBarY[] = 
   {
   " ",
   "л"
   	
   };
   string fErrorText = "                                                                                         ";
   string fErrors[] = 
   {
   	"Error:Xbox360 Controller not Connected!!",//0
   	"Error:Out of Memory!!                   ",//1
   	"Error:Vibrarion Error                   ",//2
   	"Error:D-pad Controllers not Support!    ",//3
   	"Error:RT: BYTE fRTValue (-100 != 255)   ",//4
   	"Error:Battery Low!!                     ",//5
   	"Debug:Debug mode enable..               " //6
   };
   string fStatus[] = 
   {
   	"JE:Controller 1 Connected!!             ",//0
   	"JE:Controller 2 Connected!!             ",//1
   	"JE:Loading..                            ",//2
   };
  //Engine fBuffer;
  //Symbols ANCI
  char fL0 = 196; //Line
  char fL1 = 179; // Vert-line
  char fL2 = 218;//angleL Left
  char fL3 = 191;//angleL right
  char fL4 = 192;//angleR left
  char fL5 = 217;// angle Rght
  //
  string fCM_0 = "-debug";
  string fVperfMode = "high";
  HANDLE fGetWindow = GetStdHandle(STD_OUTPUT_HANDLE);
  HWND fHwcon = GetConsoleWindow();
  xController1 = new JoyStickAPI(1);
  xController2 = new JoyStickAPI(2);
  xControllerState = (xController1->IsConnected());
  SetWindowLong(fHwcon, GWL_STYLE, GetWindowLong(fHwcon, GWL_STYLE) & WS_VISIBLE);
    	       fCpuCode = fCPUinfo();
  string fStrCA;
  string f_FrSpace;
  if(fCpuCode == 1){ fStrCA = "Intel x86";}
  if(fCpuCode == 2){ fStrCA = "Intel x64";}
  if(fCpuCode == 3){ fStrCA = "AMD x64";}
  if(fCpuCode == 4){ fStrCA = "AMD x86";}
  	cout<<" Warning!! Flash Colors"<<endl;
	Sleep(1000);
  for(int64_t fLoadFInfr = 1;fLoadFInfr <= 20;fLoadFInfr++)
  {
  		system("mode con cols=120 lines=32");
  	 f_rnd = rand() & 143-130;
  	cls(GetStdHandle(STD_OUTPUT_HANDLE));
  	SetColorAMD64(f_rnd);
  	fLoadMemA("R/Text0.txt",12);
  	cout<<f_rnd<<endl;
  		SetColorAMD64(15);
				cout<<" :::          CPU            :::: "<<endl;
				cout<< "Arch:"<<fStrCA<<f_FrSpace<<endl;
				cout<<" Cores:"<<fCPUCores()<<endl;
				cout<<" Size Buffer: "<<fdwPageSize()<<endl;
				cout<<" Allocation Granularity:"<<fdwAllocationGranularity()<<endl;
				cout<<" Revision:"<<fwProcessorInfo(2)<<endl;
				cout<<" RAM :"<<fM_Offset()<<endl;
				cout<<" Cycles :"<<fLoadFInfr<<endl;
  }//
  	system("mode con cols=44 lines=32");
  system("cls");
  for(fTextLoad = 1;fTextLoad <= 100; fTextLoad++)
  {
  	fAnimPoint = (fTextLoad / 10) - 1;
  	if(xController1->IsConnected())
  	{
  		fXCon = true;
  		fXinput_Status = "Controller 1 is Connected!!";
  		fJEText = fStatus[2];
  		fColorStatus = 138;
	}
	else
  	{
  		fXCon = false;
  		fXinput_Status = "Controller 1 not Connected!!";
  		fDebugMode = false;
  		fColorStatus = 140;
  		
	}
  	//Sleep(16);
  	//system("mode con cols=160 lines=60");
  	cls(fGetWindow);//
  	if(fTestYBar == 0)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 0;
  		fP3 = 0;
  		fP4 = 0;
  		fP5 = 0;
  		fP6 = 0;
	  }
	  if(fTestYBar == 1)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 0;
  		fP3 = 0;
  		fP4 = 0;
  		fP5 = 0;
  		fP6 = 1;
	  }
	  if(fTestYBar == 2)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 0;//
  		fP3 = 0;
  		fP4 = 0;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  if(fTestYBar == 3)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 0;
  		fP3 = 0;
  		fP4 = 1;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  if(fTestYBar == 4)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 0;
  		fP3 = 1;
  		fP4 = 1;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  if(fTestYBar == 5)
  	{
  		fP0 = 0;
  		fP1 = 0;
  		fP2 = 1;
  		fP3 = 1;
  		fP4 = 1;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  if(fTestYBar == 6)
  	{
  		fP0 = 0;
  		fP1 = 1;
  		fP2 = 1;
  		fP3 = 1;
  		fP4 = 1;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  	  if(fTestYBar == 7)
  	{
  		fP0 = 1;
  		fP1 = 1;
  		fP2 = 1;
  		fP3 = 1;
  		fP4 = 1;
  		fP5 = 1;
  		fP6 = 1;
	  }
	  SetColorAMD64(15);
	   srand(time(0));
  	SetColorAMD64(10);
 //fLoadMemA(fFileText0,18);
 SetColorAMD64(15);
 if(GetAsyncKeyState('1'))
 {
 	Sleep(80);
 	system("start https://github.com/HCPP20334/JoyStickTest");
 }
 if(GetAsyncKeyState('2'))
 {
 	Sleep(80);
 	system("start https://hcpp20334.github.io");
 }
 c1 = (fTextLoad  / 4);
 if(c1 > 24)
 {
 	c1 = 24;
 }
  if(!fDebugMode)
  {
  	if(!fXCon)
 {
    fErrorText = fErrors[0];
    fJEText = fErrors[0];
 	
 	fTextLoad  = 10;
 	if(fTextLoad > 10)
 	{
 		fTextLoad = 10;
	}
 }
}
  if(fDebugMode)
  {
  	if(fXCon)
 {
    fErrorText = fErrors[0];
    fJEText = fErrors[0];
 	
 	fTextLoad  = 10;
 	if(fTextLoad > 100)
 	{
 		fTextLoad = 100;
	}
 }
}
 if(GetAsyncKeyState('L'))
 {
 	fTextLoad = 100;
    fXCon = true;
 }
 if(GetKeyState('J') > 0)
 {
 	fXCon = true;
 	fDebugMode = true;
 	//	fJEText = fErrors[6];
 		if(fTextLoad > 100)
 	{
 		fTextLoad = 100;
    }
 }
 if(GetKeyState('J') < 0)
 {
 	fXCon = false;
 	fDebugMode = false;
 }
 if(GetAsyncKeyState(VK_F6))
 {
 	if(fJEColorSettings > 1)
 	{
 		fJEColorSettings = 0;
	 }
 	fJEColorSettings++;
 	if(fJEColorSettings == 0)
 	{
 		fJEColorSetMenu = false;
 		fColorsMSet = -1;
	}
	if(fJEColorSettings == 1)
 	{
 		fJEColorSetMenu = true;
 		fColorsMSet = 1;
	}
 }
 if(GetAsyncKeyState('L'))
 {
 	system("cls");
 	cout<<" Debug Enable..."<<endl;
 	fJEText = fStatus[2];
 	fDebugMode = true;
 	fXCon = true;
 	
 }
  if(fVperfMode == "min")
  {
  	f_rnd = 15;
  }
   if(fVperfMode == "Rand")
  {
  	f_rnd = rand() & 13;
  }
   if(fVperfMode == "High")
  {
  	f_rnd = 143;
  }
  f_rnd = 143;
	cls(fGetWindow);
	            SetColorAMD64(f_rnd);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                 JE v1.1.2                  "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                                            "<<endl;
				cout<<"                                            "<<endl;
				cout<<"                                            "<<endl;
			    cout<<" JoySTickEmu Build 1.1.2 28.06.23 21:35     "<<endl;
			    cout<<" Writtein in C++ // By HCPP                 "<<endl;
			    cout<<" Files Main - JoyStick.cpp [2374]           "<<endl;
			    cout<<" Header JoyStick.h and Colors.h             "<<endl;
			    cout<<" Uses Lib Xinput  1.4                       "<<endl;
			    cout<<"     Check...                               "<<endl;
			    cout<<"  "<<fBar[c1]<<"              "<<endl;
			    cout<<"   HCPP Studio 2021-2023                    "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"               Log's'                       "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(fColorStatus);
				cout<<"    "<<fJEText<<endl;
				SetColorAMD64(f_rnd);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB CPU"<<fStrCA<<f_FrSpace<<endl;//
				SetColorAMD64(15);
				cout<<" Press (A)/[ENTER]  [Q] - Update Screen                       "<<endl;
				if(GetAsyncKeyState('Q'))
				{
					system("cls");
				}
    if(GetAsyncKeyState('B'))
	{
		fBPoint++; 
		if(fBPoint > 1)
		{
			fBPoint = 0;
		}
		if(fBPoint == 0)
		{
			fBarS = false;
		}
		if(fBPoint == 1)
		{
			fBarS = true;
		}
	}
 if(!GetAsyncKeyState(VK_ESCAPE) || !xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
 {
 	fExP--;
 	if(fExP < 0)
 	{
 		fExP = 0;
	 }
 }
 if(GetAsyncKeyState(VK_ESCAPE) || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK )
 {
 	SetColorAMD64(15);
 	fExP++;
 	if(fExP > 24)
 	{
 		fExSh = true;
 		fExP = 24;
	 }
    if(fExP == 24)
    {
    	system("mode con cols=58 lines=7");
    		system("cls");
    	   	//	xController1->Vibrate(10000,10000);
    	   		SetColorAMD64(15);
    	   		
       	cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
       		if(fExSh)
       		{
       	    cout<<fL1<<"                                                        "<<fL1<<endl;
       		cout<<fL1<<"                                                        "<<fL1<<endl;
       		cout<<fL1<<"          Thanks!! How to used my Program!!             "<<fL1<<endl;
       		cout<<fL1<<"                                                        "<<fL1<<endl;
       		cout<<fL1<<"                                                        "<<fL1<<endl;
       	 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
       		SetColorAMD64(15);
       	       exit(0);  
       	    }
	}
 }
//cout<<" Xinput Status:"<<fXinput_Status<<endl;
//cout<<" Battery Level:"<<fBatLevel<<endl;
cout<<"Exit Hold Esc";
 SetColorAMD64(131);
cout<<fBar[fExP]<<endl;
SetColorAMD64(15);
cout<<"             ";
 SetColorAMD64(131);
cout<<fBar[fExP]<<endl;
SetColorAMD64(15);
 SetColorAMD64(15);
 cout<<" Test Bar Press (B) and R key Mouse"<<endl;
 cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 cout<<fL1<<"  "<<fP6<<fP5<<fP4<<fP3<<fP2<<fP1<<fP0<<"  "<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
//
if(GetAsyncKeyState(VK_DOWN))
{
	fJEYSize++;
	system(("mode con lines="+to_string(fJEYSize)).c_str());
}
if(GetAsyncKeyState(VK_UP))
{
	fJEYSize--;
	system(("mode con lines="+to_string(fJEYSize)).c_str());
}
if(fTestBars)
{
	if(!fBarS)
{
	cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
	cout<<fL1<<"            Test Bar "<<fL1<<endl;
	SetColorAMD64(138);
cout<<fL1<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fL1<<endl;
cout<<fL1<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fL1<<endl;
cout<<fL1<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fL1<<endl;
cout<<fL1<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fL1<<endl;
cout<<fL1<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fL1<<endl;
cout<<fL1<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fL1<<endl;
cout<<fL1<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fL1<<endl;
cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
}
if(fBarS)
{
		SetColorAMD64(138);
cout<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<endl;
cout<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<endl;
cout<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<endl;
cout<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<endl;
cout<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<fBarY[fP2]<<fBarY[fP4]<<endl;
cout<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<fBarY[fP1]<<fBarY[fP5]<<endl;
cout<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<fBarY[fP0]<<fBarY[fP6]<<endl;

}
}
if(GetAsyncKeyState('4'))
{
	srand(time(0));
fTestYBar = rand() % 8;
cout<<"Random Mode.."<<endl;
fExP = rand() % 8;
}
SetColorAMD64(15);
cout<<"Mouse Clicks:"<<fMouseCountClicks<<endl;
SetColorAMD64(15);
 if(fXCon)
 {
 	cout<<" Press (A) to skip Loading"<<endl;
 }
  if(!xController1->IsConnected())
  {
  	if(GetAsyncKeyState(VK_RBUTTON))
  	{
  		   		fAnimDuration++;
 	if(fAnimDuration == 1)
 	{
 		  fTestYBar++;
 		  fMouseCountClicks++;
               if(fTestYBar >= 8)
               {
               	fTestYBar = 8;
			   }
			   fAnimDuration = 0;
	 }
	  }
	  if(!GetAsyncKeyState(VK_RBUTTON))
	  {
	  	fTestYBar--;
               if(fTestYBar < 0)
               {
               	fTestYBar = 0;
			   }
	  }
  }
  if(xController1->IsConnected())
  {
  	 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
     {
                fTextLoad = 1000;
     }
      if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B || GetAsyncKeyState(VK_RBUTTON))
     {
     		fAnimDuration++;
 	if(fAnimDuration == 1)
 	{
 		  fTestYBar++;
               if(fTestYBar >= 8)
               {
               	fTestYBar = 8;
			   }
			   fAnimDuration = 0;
	 }

			    
     }
     if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B || GetAsyncKeyState(VK_RBUTTON))
     {
               fTestYBar--;
               if(fTestYBar < 0)
               {
               	fTestYBar = 0;
			   }
     }
  }
  }
  system("cls");//
	for(int64_t fClocksCPU = 1;fClocksCPU > 0;fClocksCPU++)
	{
		 fClocksCPU = fThread_0;
		if(fClocksCPU == 60){fClocksCPU = 1;fTimeUsed++;}
		if(fTimeUsed == 60)
		{
			fHour++;
			fTimeUsed = 1;
		}
		fTimeStr = to_string(fHour)+":"+to_string(fTimeUsed)+":"+to_string(fClocksCPU);
	
        if(!fDebugMode)
        {
        	if(xController1->IsConnected())
  	        {
  		        fXCon = true;
  	        	fXinput_Status = "Controller 1 is Connected!!";
  	        	fStrLX = "0000";
		        fStrLY = "0000";
		        fStrRX = "0000";
		        fStrRY = "0000";
	    }
	    else
  	    {
  		        fXCon = false;
  		        fXinput_Status = "Controller 1 not Connected!!";
	    }
		}
		if(fDebugMode)
        {
        	fXCon = true;
        }
		fLXPos = (xController1->GetState().Gamepad.sThumbLX) ;
		fLYPos = (xController1->GetState().Gamepad.sThumbLY) ;
		fRXPos = (xController1->GetState().Gamepad.sThumbRX) ;
		fRYPos = (xController1->GetState().Gamepad.sThumbRY) ;
		fLTPos = (xController1->GetState().Gamepad.bLeftTrigger);
		fRTPos = (xController1->GetState().Gamepad.bRightTrigger);
		fJEAxis2MouseCoordLX = fLXPos / 10;
		fJEAxis2MouseCoordLY = (fLYPos / 10) * -1;
		fLX = fLXPos / 100;
		fLY = fLYPos / 100;
		fRX = fRXPos / 100;
		fRY = fRYPos / 100;
		fStrLX = to_string(fLX);
		fStrLY = to_string(fLY);
		fStrRX = to_string(fRX);
		fStrRY = to_string(fRY);
		if(fLX < 0)
		{
			fLXAxisPoint = (fLXPos * (-1)) / 100;
		}
		if(fLY < 0)
		{
			fLYAxisPoint = (fLXPos * (-1)) / 100;
		}
		fLTPoint = (fLTPos / 10);
		fRTPoint = (fRTPos / 10);
		if(fLTPoint > 24)
		{
			fLTPoint = 24;
		}
		if(fRTPoint > 24)
		{
			fRTPoint = 24;
		}
		SetWindowText(fHwcon,("Time Used:"+fTimeStr+"UnitRAM:"+to_string(fDataMemUsage())+" Xinput:"+fXinput_Status).c_str());
		//ip
		fTime_00++;
		//fColorLine_00 = 113 + fTime_00;
		if(fTime_00 == fTime_00 * 10)
		{
			fColorLine_00 = 113;
		}
		if(fTime_00 != 60)
		{
			fColorLine_00 = 113;
		}
		if(fTime_00 > 60)
		{
			fColorLine_00 = 15;
			fTime_00 = 0;
		}
		//GetAsyncButtonState('F');
		if(GetAsyncKeyState('L'))
     {
     	system("cls");
     	fDebugIgnoreXiputError++;
     	if(fDebugIgnoreXiputError == 0)
     	{
     	fXCon = true;
     	system("cls");
        }
        if(fDebugIgnoreXiputError == 1)
        {
     	fXCon = false;
        }
     }
		cls(fGetWindow);//
		if(!fXCon)
		{
		if(	fAnimDuration0 < 13)
		{
				fAnimDuration0++;
		}
  	    if(fAnimDuration0 > 13)
  	    {
  		fAnimDuration0--;
        }
//        	fAnimPoint0++;
//  		if(fAnimPoint0 < 0)
//  		{
//  			fAnimPoint0++;
//		  }
//  		if(fAnimPoint0 == 5)
//  		{
//  			fAnimPoint0--;
//		  }
//	    }
     cls(fGetWindow);//
	SetColorAMD64(15);
  	cout<<"\n\n\n";
  	SetColorAMD64(71);
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	SetColorAMD64(71);
  	cout<<"      Please plug to Xbox360 Controller!!   "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
    cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
  	cout<<"                                            "<<endl;
		}
		SetColorAMD64(15);
		cout<<"\n\n";
		SetColorAMD64(15);
		if(fXCon)
		{
	if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER || GetAsyncKeyState(VK_F6))
 {
 	if(fJEColorSettings > 1)
 	{
 		fJEColorSettings = 0;
	 }
 		fJEColorSettings++;
 	if(fJEColorSettings == 0)
 	{
 		fJEColorSetMenu = false;
 		fColorsMSet = -1;
	}
	if(fJEColorSettings == 1)
 	{
 		fJEColorSetMenu = true;
 		fColorsMSet = 1;
	}
 }
  if(fJEColorSetMenu)
 {
 	for(fColorsMSet = 1; fColorsMSet > 0;fColorsMSet++)
 	{
 		if(fCMlPoint == 0){fCMl0A = 132;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl0;}
		if(fCMlPoint == 1){fCMl0A = 139;fCMl1A = 132;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl1;}
		if(fCMlPoint == 2){fCMl0A = 139;fCMl1A = 139;fCMl2A = 132;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl2;}
		if(fCMlPoint == 3){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 132;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl3;}
		if(fCMlPoint == 4){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 132;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl4;}
		if(fCMlPoint == 5){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 132;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl5;}
		if(fCMlPoint == 6){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 132;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl6;}
		if(fCMlPoint == 7){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 132;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl7;}
		if(fCMlPoint == 8){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 132;fCMl9A = 139;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl8;}
		if(fCMlPoint == 9){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 132;fCMlAA = 139;fCMlBA = 139;fColorText = fCMl9;}
		if(fCMlPoint == 10){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 132;fCMlBA = 139;fColorText = fCMlA;}
		if(fCMlPoint == 11){fCMl0A = 139;fCMl1A = 139;fCMl2A = 139;fCMl3A = 139;fCMl4A = 139;fCMl5A = 139;fCMl6A = 139;fCMl7A = 139;fCMl8A = 139;fCMl9A = 139;fCMlAA = 139;fCMlBA = 132;fColorText = fCMlB;}

 		cls(fGetWindow);
 		SetColorAMD64(135);  
 		cout<<"       Color Settings         "<<endl;
 		SetColorAMD64(138);  
 		cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl0A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl0);
 		cout<<" Green-white  ";
 		SetColorAMD64(fCMl0A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl1A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl1);
 		cout<<" Blue-white   ";
 		SetColorAMD64(fCMl1A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl2A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl2);
 		cout<<" Red-white    ";
 		SetColorAMD64(fCMl2A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl3A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl3);
 		cout<<" L-Gray-black ";
 		SetColorAMD64(fCMl3A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl4A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl4);
 		cout<<" L-Gray-blue  ";
 		SetColorAMD64(fCMl4A);
 		cout<<"   л   ";
 		SetColorAMD64(240);
 	    SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl5A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl5);
 		cout<<" D-Gray-green ";
 		SetColorAMD64(fCMl5A);
 		cout<<"   л   ";
 	    SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl6A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl6);
 		cout<<" D-Gray-cyan  ";
 		SetColorAMD64(fCMl6A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl7A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl7);
 		cout<<" D-Gray-blue  ";
 		SetColorAMD64(fCMl7A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl8A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl8);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMl8A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMl9A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl9);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMl9A);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMlAA);
 		cout<<"   л   ";
 		SetColorAMD64(fCMlA);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMlAA);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		SetColorAMD64(138);
 		cout<<fL1;
 		SetColorAMD64(fCMlBA);
 		cout<<"   л   ";
 		SetColorAMD64(fCMlB);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMlBA);
 		cout<<"   л   ";
 		SetColorAMD64(138);
 		cout<<fL1<<endl;
 		cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 		SetColorAMD64(143);                //
 		cout<<"       [ENTER]/(A) - OK       "<<endl;
		cout<<"       [W]/(UP) - UP          "<<endl;
		cout<<"       [S]/(DOWN) - Down      "<<endl;
		cout<<"       [R]/(B) - Random       "<<endl;//
		SetColorAMD64(15);
			if(GetAsyncKeyState('N'))
		{
			fCR_Error = true;
		}
 		if(GetAsyncKeyState('R'))
 		{
 			srand(time(0));
 			fCMlPoint = rand() % 11;
		 }
 		if(GetAsyncKeyState(VK_RETURN) || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
 		{
 			cls(fGetWindow);
 				 SetColorAMD64(30);
			    	cout<<"\n";
			    	SetColorAMD64(30);
			    cout<<fL2<<"                     "<<fL3<<endl;
			    SetColorAMD64(30);
			    cout<<fL1<<"                     "<<fL1<<endl;
			    SetColorAMD64(30);
			    cout<<fL1<<"      LOADING..      "<<fL1<<endl;
			    SetColorAMD64(30);
			    cout<<fL1<<"                     "<<fL1<<endl;
			    SetColorAMD64(30);
			    cout<<fL4<<"                     "<<fL5<<endl;
			    SetColorAMD64(15);
					Sleep(1000);
 			system("cls");
 			fColorsMSet = -1;
 			fJEColorSetMenu = false;	
 			fColor_00 = fColorText;
		 }
 		if(GetAsyncKeyState('W') || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
 		{
 			fClA++;
 			if(fClA > 3)
 			{
 				fClA = 0;
			 }
 			if(fClA  == 3)
 			{
 				fCMlPoint--;
 			}
 			if(fCMlPoint < 0)
 			{
 				fCMlPoint = 11;
			 }
		}
		if(GetAsyncKeyState('S') || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
 		{
 			fClA++;
 			if(fClA > 3)
 			{
 				fClA = 0;
			 }
 			if(fClA  == 3)
 			{
 				fCMlPoint++;
 			}
 			if(fCMlPoint > 11)
 			{
 				fCMlPoint = 0;
			 }
		}
		
	 }
	 system("cls");
 }
 if(fJEInfoF)
 {
 	system("cls");
 	for(int64_t fJEInfo = 1;fJEInfo > 0; fJEInfo++)
 	{
 		cls(fGetWindow);
 		SetColorAMD64(143);
 		cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"    Xbox "<<fL1<<" DS4/3                           "<<endl;
				cout<<"     (A) "<<fL1<<" (X)                              "<<endl;
				cout<<"     (B) "<<fL1<<" (O)                              "<<endl;
				cout<<"     (Y) "<<fL1<<" (Triagle)                        "<<endl;
				cout<<"     (X) "<<fL1<<" (Square)                         "<<endl;
				cout<<"                                            "<<endl;
				cout<<"                                            "<<endl;
				cout<<"     (A) - Back                             "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(15);
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
				{
					fJEInfo = -1;
					fJEInfoF = false;
					system("cls");
				}
				
	 }
 }
 if(fCR_Error)
		{
			Beep(60,1000);
		//	system("cls");
			for(int64_t fRenderWindow_Error = 1;fRenderWindow_Error > 0; fRenderWindow_Error++)
			{
				if(fJE_Menu == 0)
				{
					fJEDebCol_0 = 97;
					fJEDebCol_1 = 0;
					fJEDebCol_2 = 0;
					
				}
				if(fJE_Menu == 1)
				{
					fJEDebCol_0 = 0;
					fJEDebCol_1 = 97;
					fJEDebCol_2 = 0;
					
				}
				if(fJE_Menu == 2)
				{
					fJEDebCol_0 = 0;
					fJEDebCol_1 = 0;
					fJEDebCol_2 = 97;
					
				}
			
				SetColorAMD64(143);
				cls(fGetWindow);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"         JE Runtime Debugger v1.0           "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(143+fJEDebCol_0);
				cout<<"          Restart                           "<<endl;
				SetColorAMD64(143);
				cout<<"                                            "<<endl;
				SetColorAMD64(143+fJEDebCol_1);
				cout<<"          Continue                          "<<endl;
				SetColorAMD64(143);
				cout<<"                                            "<<endl;
				SetColorAMD64(143+fJEDebCol_2);
				cout<<"          Continue and Fix                  "<<endl;
				SetColorAMD64(143);
				cout<<"                                            "<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"          Occured Registers                  "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(140);
				cout<<" Exception: Stack_frame:"<<&fY<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fX<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fA<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fB<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fU<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fD<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fR<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fL<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fRBPoint<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fLBPoint<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fLY<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fRY<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fLX<<"            "<<endl;
				cout<<" Exception: Stack_frame:"<<&fRX<<"            "<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(15);
				
				 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP || GetAsyncKeyState('W'))
				 {
				 	fJEKeyDelay++;
				 	if(fJEKeyDelay > 2)
				 	{
				 		fJE_Menu--;
				 		fJEKeyDelay = 0;
					 }
				 	if(fJE_Menu < 0)
				 	{
				 		fJE_Menu = 2;
					 }
				 }
				 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN || GetAsyncKeyState('S'))
				 {
				 	fJEKeyDelay++;
				 	if(fJEKeyDelay > 2)
				 	{
				 		fJE_Menu++;
				 		fJEKeyDelay = 0;
					 }
				 	if(fJE_Menu > 2)
				 	{
				 		fJE_Menu = 0;
					 }
				 }
			    if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A || GetAsyncKeyState(VK_RETURN))
			    {
			    	cls(fGetWindow);
			    	 SetColorAMD64(30);
			    	cout<<"\n\n\n\t";
			    	SetColorAMD64(30);
			    cout<<fL2<<"                     "<<fL3<<endl;
			     SetColorAMD64(15);
			    cout<<"\t";
			    SetColorAMD64(30);
			    cout<<fL1<<"                     "<<fL1<<endl;
			     SetColorAMD64(15);
			    cout<<"\t";
			    SetColorAMD64(30);
			    cout<<fL1<<"      LOADING..      "<<fL1<<endl;
			     SetColorAMD64(15);
			    cout<<"\t";
			    SetColorAMD64(30);
			    cout<<fL1<<"                     "<<fL1<<endl;
			     SetColorAMD64(15);
			    cout<<"\t";
			    SetColorAMD64(30);
			    cout<<fL4<<"                     "<<fL5<<endl;
			    SetColorAMD64(15);
					Sleep(1000);
			    if(fJE_Menu == 0)
			    {
					main(0,(char**)"JE");
				}
				if(fJE_Menu == 1)
				{
					fCR_Error = false;
					fRenderWindow_Error = -1;
					
				}
				if(fJE_Menu == 2)
				{
					fCR_Error = false;
					fRenderWindow_Error = -1;
					fY = 24;
					fB = 24;
					fX = 24;
					fA = 24;
					fU = 24;
					fD = 24;
					fL = 24;
					fR = 24;
					fLY = 24;
					fRY = 24;
					fLX = 24;
					fRX = 24;
					fLBPoint = 24;
					fRBPoint = 24;
					cout<<" Loading.."<<endl;
					Sleep(100);
				}
				}
			}
			system("cls");
		}
		// if == 1
		if(fStrLX.size() == 1){fSLx = "   ";}if(fStrRX.size() == 1){fSRx = "   ";}
		if(fStrLY.size() == 1){fSLy = "   ";}if(fStrRY.size() == 1){fSRy = "   ";}
		// if == 2
		if(fStrLX.size() == 2){fSLx = "  ";}if(fStrRX.size() == 2){fSRx = "  ";}
		if(fStrLY.size() == 2){fSLy = "  ";}if(fStrRY.size() == 2){fSRy = "  ";}
		// if == 3
		if(fStrLX.size() == 3){fSLx = " ";}if(fStrRX.size() == 3){fSRx = " ";}
		if(fStrLY.size() == 3){fSLy = " ";}if(fStrRY.size() == 3){fSRy = " ";}
		//if == 4
		if(fStrLX.size() == 4){fSLx = "";}if(fStrRX.size() == 4){fSRx = "";}
		if(fStrLY.size() == 4){fSLy = "";}if(fStrRY.size() == 4){fSRy = "";}
		//
		if(fY > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fB > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fX > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fA > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fU > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fD > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fL > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fR > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fRBPoint > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fLBPoint > 24){fCR_Error = true;} else{fCR_Error = false;}
		SetColorAMD64(143);
				cls(fGetWindow);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                  JE v 1.1.2                "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(143);
				cout<<" A  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fA]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" B  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fB]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" X  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fX]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" Y  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fY]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" U  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fU]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" D  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fD]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" R  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fR]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" L  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fL]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" RB ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fRBPoint]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" LB ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fLBPoint]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" RT ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fRTPoint]<<"            "<<endl;
				SetColorAMD64(143);
				cout<<" LT ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fLTPoint]<<"            "<<endl;
				SetColorAMD64(fColor_00);
				cout<<"                                            "<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"            Axis LX,LY,RX,RY                "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(143);
				cout<<" LX Value:"<<fStrLX<<"                              "<<fSLx<<endl;
				cout<<" LY Value:"<<fStrLY<<"                              "<<fSLy<<endl;
				cout<<" RX Value:"<<fStrRX<<"                              "<<fSRx<<endl;
				cout<<" RY Value:"<<fStrRY<<"                              "<<fSRy<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                 HotKeys                    "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"    (F8)   Show Controls                    "<<endl;
				cout<<"F1 - RESET PROGRAM (BACK)/[ESC]- Exit Press "<<endl;
				cout<<"Build 1.1.2 | (LB) + (RB) - Color Settings  "<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
	    }
	    if(GetAsyncKeyState(VK_F8))
	    {
	    	fJEInfoF = true;
	    	system("cls");
		}
	    SetColorAMD64(15);
	    
	     if(GetAsyncKeyState('N'))
	     {
	     	fCR_Error = true;
	     	fA = 256;
		 }
		 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
		 {
		 		    fY = 24;
					fB = 24;
					fX = 24;
					fA = 24;
					fU = 24;
					fD = 24;
					fL = 24;
					fR = 24;
					fLY = 24;
					fRY = 24;
					fLX = 24;
					fRX = 24;
					fLBPoint = 24;
					fRBPoint = 24;
		 }
		if(GetAsyncKeyState('P'))
		{
		MessageBox(GetConsoleWindow(),(fErrors[1].c_str()),"JE:Error!! Bulid: 1.0.9",MB_ICONWARNING);
		cout<<"Exception Error ->fStack_frame0="<<GetConsoleWindow()<<endl;
		cout<<"Exception Error ->fStack_frame1="<<GetDC(GetConsoleWindow())<<endl;
		cout<<"Exception Error ->fStack_frame2="<<&xController1<<"->JoyStick.h"<<endl;
		fCR_Error = true;
		}
		if(GetAsyncKeyState('O'))
		{
			system("cls");
			f_Kb0 = 113;
			f_Kb1 = 113;
			f_Kb2 = 113;
			f_Kb3 = 113;
			for(int64_t fkbEmuAccept = 1;fkbEmuAccept > 0;fkbEmuAccept++)
			{
				cls(fGetWindow);
						SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                 Settings JE                "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
			    cout<<"Button (A) ->:"<<(char)f_Kb0<<"                             "<<endl;
			    cout<<"Button (B) ->:"<<(char)f_Kb1<<"                             "<<endl;
			    cout<<"Button (X) ->:"<<(char)f_Kb2<<"                             "<<endl;
			    cout<<"Button (Y) ->:"<<(char)f_Kb3<<"                             "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"         Press Button on Bind !!            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
			    cout<<"                Controls                    "<<endl;
		        cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
			    cout<<"      [ENTER] - Disable JE                  "<<endl;
			    cout<<"     [ESC] - Save end Enable JE             "<<endl;
				SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
				SetColorAMD64(15);
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A){f_Kb0 = getch();cout<<"Edit (A)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B){f_Kb1 = getch();cout<<"Edit (B)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X){f_Kb2 = getch();cout<<"Edit (X)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y){f_Kb3 = getch();cout<<"Edit (Y)?.."<<endl;}
				if(GetAsyncKeyState(VK_SPACE))
				{
					kbEmu = true;
					cout<<"Emulator Enable!!"<<endl;
					fkbEmuAccept = -1;
				}
				if(GetAsyncKeyState(VK_RETURN))
				{
					kbEmu = false;
					cout<<"Emulator Disable!!"<<endl;                                          
					fkbEmuAccept = -1;
				}
			}
			system("cls");
		}

			if(kbEmu)
			{
			//	SetCursorPos(fJEAxis2MouseCoordLX,fJEAxis2MouseCoordLY);
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A){fJEKbDelay++;if(fJEKbDelay == 2){keybd_event((char)f_Kb0,0,0,KEYEVENTF_KEYUP);fJEKbDelay = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B){fJEKbDelay++;if(fJEKbDelay == 2){keybd_event((char)VK_LBUTTON,0,0,KEYEVENTF_KEYUP);fJEKbDelay = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y){fJEKbDelay++;if(fJEKbDelay == 2){keybd_event((char)f_Kb2,0,0,KEYEVENTF_KEYUP);fJEKbDelay = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X){fJEKbDelay++;if(fJEKbDelay == 2){keybd_event((char)f_Kb3,0,0,KEYEVENTF_KEYUP);fJEKbDelay = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP){fJEKbDelayD++;if(fJEKbDelayD == 2){keybd_event((char)'W',0,0,KEYEVENTF_KEYUP);fJEKbDelayD = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN){fJEKbDelayD++;if(fJEKbDelayD == 2){keybd_event((char)'S',0,0,KEYEVENTF_KEYUP);fJEKbDelayD = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT){fJEKbDelayD++;if(fJEKbDelayD == 2){keybd_event((char)'D',0,0,KEYEVENTF_KEYUP);fJEKbDelayD = 0;}}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT){fJEKbDelayD++;if(fJEKbDelayD == 2){keybd_event((char)'A',0,0,KEYEVENTF_KEYUP);fJEKbDelayD = 0;}}
			}
		
		if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK || GetAsyncKeyState(VK_ESCAPE))
       	{
       		system("cls");
       		xController1->Vibrate(10000,10000);
       		cout<<"_______________________________________________________________\n\n"<<endl;
       		cout<<"               Thanks!! How to used my Program!!               \n\n"<<endl;
       		cout<<"Time Used:"<<fHour<<fTimeUsed<<":"<<fClocksCPU<<" "<<endl;
       		cout<<"_______________________________________________________________"<<endl;
       	       exit(0);  	
       	}
		if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
       	{
			if(fLX == 327)
			{
				fDebugger = true;
			xController1->Vibrate(10000,10000);
			}
			if(kbEmu)
			{
				Sleep(40);
				keybd_event('W',0,KEYEVENTF_KEYUP,0);
			}
		}
		if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
       	{
			if(fLX < 0)
			{
				fDebugger = false;
			fDebugColorMode = 15;
	    	fDebugColorMode0 = 0;
			//xController1->Vibrate(10000,10000);
			}
		}
		if(GetAsyncKeyState('M'))
		{
			fB = fA = fY = fX = 0;
			fLBPoint = fRBPoint = 0;
			
		}

		if(xController1->IsConnected())
       {
       	
	       if(GetAsyncKeyState(VK_F1))
	       {
	       	system("cls");
	       	main(0,NULL);
		   }
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
          {
                fB++;
			if(fB > 24)
			{
				fB = 24;
			}

          } 
          if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
          {
                fA++;
			if(fA > 24)
			{
				fA = 24;
			}

          }
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X)
          {
                fX++;
			if(fX > 24)
			{
				fX = 24;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
          {
                fY++;
			if(fY > 24)
			{
				fY = 24;
			}
          } 
       }
       if(fLBPoint + fRBPoint == 510)
       {
       	fAxisTest = true;
	   }
		if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
		{
			fLBPoint++;
			if(fLBPoint > 24)
			{
				fLBPoint = 24;
			}
		}
		if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_LEFT_SHOULDER)
		{
			fLBPoint--;
			if(fLBPoint < 0)
			{
				fLBPoint = 0;
			}
		}
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
		{
			fRBPoint++;
			if(fRBPoint > 24)
			{
				fRBPoint = 24;
			}
		}
		if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_RIGHT_SHOULDER)
		{
			fRBPoint--;
			if(fRBPoint < 0)
			{
				fRBPoint = 0;
			}
		}
		if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_A)
          {
                fA--;;
			if(fA < 0)
			{
				fA = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B)
          {
                fB--;
			if(fB < 0)
			{
				fB = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_Y)
          {
                fY--;
			if(fY < 0)
			{
				fY = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_X)
          {
                fX--;
			if(fX < 0)
			{
				fX = 0;
			}
          }
  	      if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
          {
                fU++;
			if(fU > 24)
			{
				fU = 24;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
          {
                fD++;
			if(fD > 24)
			{
				fD = 24;
			}
			
          } 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
          {
          	//xController1->Vibrate(60000,0);
                fL++;
			if(fL > 24)
			{
				fL = 24;
			}
			if(kbEmu)
			{
				Sleep(40);
				keybd_event('A',0,0,0);
			}
          } 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
          {
          	//xController1->Vibrate(0,60000);
                fR++;
			if(fR > 24)
			{
				fR = 24;
			}
			if(kbEmu)
			{
				Sleep(40);
				keybd_event('D',0,0,0);
			}
          } 
		if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_UP)
          {
                fU--;;
			if(fU < 0)
			{
				fU = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_DOWN)
          {
                fD--;
			if(fD < 0)
			{
				fD = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_LEFT)
          {
          	//xController1->Vibrate(0,0);
                fL--;
			if(fL < 0)
			{
				fL = 0;
			}
          } 
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_RIGHT)
          {
          		//xController1->Vibrate(0,0);
                fR--;
			if(fR < 0)
			{
				fR = 0;
			}
          }
	      }
}
