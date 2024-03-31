//
// header's
#include <iostream>
#include <string>
//#include <clocale>
#include "Colors.h"
#include <Windows.h>
#include "JoyStick.h"
#include <conio.h>
#include <psapi.h>
#include "fs_std.h"
#include <math.h>
#include <time.h>
//#include "int128.h"//Not..
#include <thread>//
#include "dSys.h"///-
//
  int64_t fLX = 0;
  int64_t fLY = 0;
  int64_t fRX = 0;
  int64_t fRY = 0;
  //
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
   "ллллллллллллллл             ",//
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
   string fBarV2[] = 
   {
   "*                           ",
   "**                          ",
   "***                         ",
   "****                        ",
   "*****                       ",
   "******                      ",
   "*******                     ",
   "********                    ",
   "*********                   ",
   "**********                  ",
   "***********                 ",
   "************                ",
   "*************               ",
   "**************              ",
   "***************             ",
   "****************            ",
   "*****************           ",
   "******************          ",
   "*******************         ",
   "********************        ",
   "*********************       ",
   "**********************      ",
   "***********************     ",
   "************************    ",
   "***************************"
   };
   //
int64_t fVErev1(HWND hwnd);
struct fPrint
{
int64_t FillBuffer(int64_t fXpos,int64_t fYpos,int64_t r,int64_t g,int64_t b,HWND fHwnd)
{
	SetPixel(GetDC(fHwnd),fXpos,fYpos,RGB(r,g,b));
};
};

fPrint fConsole;
int64_t SzWindow(int64_t fSzX,int64_t fSzY)
{
	HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r);
    MoveWindow(hWindowConsole, r.left, r.top, fSzX, fSzY, TRUE);//
}
int64_t fVErev1(HWND hwnd)
{
	int64_t fRandCL = 0;
int64_t fTimer = 0;
int64_t c_0 = 0;
SetFontA(L"Consolas",1,1);
  //	SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   for(int64_t fRandomVec = 1;fRandomVec <= 1000;fRandomVec++)
   {
   	c_0++;
   	SzWindow(480,680);
   	if(c_0 == 0){
   		fRandCL = 139;
	   }
	if(c_0 == 1){
   		fRandCL = 240;
	   }
	if(c_0 == 2){
   		fRandCL = 15;
	   }
	if(c_0 > 2){
   		c_0 = 0;
	   }
   	SetColorAMD64(fRandCL);
   	cout<<" ";
   	fTimer++;
   	    if(GetAsyncKeyState(VK_ESCAPE))
   	    {
   	    	fRandomVec = -1;
		}
		if(fTimer > 100000)
		{
			fRandomVec = -1;
			
		}
   }
   system("cls");
   //SetWindowText(fGetWindow,"Paint(VE) by HCPP");
   //ShowWindowAsync(fGetWindow,1);
  // GetStarted(fGetWindow);
}
int64_t APInfo(HANDLE hWindow)
{
	SetFontA(L"Consolas",5,20);
SzWindow(710,660);
					for(int64_t fAPIinfo = 1;fAPIinfo > 0;fAPIinfo++)
					{
						cls(hWindow);
			SetColorAMD64(143);
  cout<<" :: JoyStickAPI  Doc                                      (ESC) - back       "<<endl;
  SetColorAMD64(159);
  cout<<" Author: HCPP Writtein C++                                                   "<<endl;
  cout<<"Join Header #-include 'JoyStick.h'                                           "<<endl;
  cout<<"Join Lib to  Project (DevC++ libxinput_1.4.a)                                "<<endl;
  cout<<"Visual Studio #pragma comment('xinput_1.4.lib'');                            "<<endl;
  cout<<"JoyStickAPI* xController1; - add to Controller  1                            "<<endl;
  cout<<"JoyStickAPI* xController2; - add to Controller  1                            "<<endl;

  cout<<" xController1 = new JoyStickAPI(1); - call to Controller  1                  "<<endl;
  cout<<"xController2 = new JoyStickAPI(2); - call to Controller  2                   "<<endl;
  //?????????????
  cout<<"if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) - Check btn "<<endl;
  cout<<"{                                                                            "<<endl;
  // ???
  cout<<" your code                                                                   "<<endl;
  cout<<"}                                                                            "<<endl;
  //???????
  cout<<"xController1->GetState().Gamepad.sThumbLX // return axis LeftX               "<<endl;
  cout<<"xController1->GetState().Gamepad.sThumbLY // return axis LeftY               "<<endl;
  cout<<"xController1->GetState().Gamepad.sThumbRX //   return axis RightX            "<<endl;
  cout<<"xController1->GetState().Gamepad.sThumbRY // return axis RightY              "<<endl;
  //
  //????????
  cout<<"xController1->GetState().Gamepad.bLeftTrigger // return LT range or 0 to 255 "<<endl;
  cout<<" xController1->GetState().Gamepad.bRightTrigger //return RT range or 0 to 255"<<endl;
  //???????? ???????????
  cout<<"if(xController1->IsConnected()) - check connection controller                "<<endl;
  cout<<"{                                                                            "<<endl;
  //?????????? 1 ?????????
  cout<<" return true;                                                                "<<endl;
  cout<<"}                                                                            "<<endl;
  cout<<"if(!xController1->IsConnected())                                             "<<endl;
  cout<<"{                                                                            "<<endl;
  cout<<" return false;                                                               "<<endl;
  cout<<"}                                                                            "<<endl;
  SetColorAMD64(15);
  if(GetAsyncKeyState(VK_ESCAPE))
  {
  	fAPIinfo = -1;
  	system("cls");
  }
}
}
int64_t AboutWdw(HANDLE hWindow)
{
SetFontA(L"Consolas",5,20);
SzWindow(710,560);
	 for(int64_t fRdAbout = 1; fRdAbout > 0;fRdAbout++)
	 {
	 							cls(hWindow);
			 	SetColorAMD64(143);
       cout<<" :: JE About                                          (ESC) - back           "<<endl;
       	SetColorAMD64(159);
       cout<<" --------------------------------------------------------------------------- "<<endl;
       cout<<"   Techical information                                                      "<<endl;
	   cout<<" --------------------------------------------------------------------------- "<<endl;
       cout<<"   JE build 1.1.5.1                                                          "<<endl;
       cout<<"                                                                             "<<endl;
       cout<<"   JoyStickAPI build 1.0.1                                                   "<<endl;
	   cout<<"   C++11 , Compiler (MinGW)TDM-GCC 4.9.2 Release                             "<<endl;
	   cout<<"                                                                             "<<endl;
	   cout<<" --------------------------------------------------------------------------- "<<endl;
	   cout<<"   Project information                                                       "<<endl;
	   cout<<" --------------------------------------------------------------------------- "<<endl;
	   cout<<"                                                                             "<<endl;
       cout<<"   JE - Gamepad2keyBoard emulator and Test Gamepads!!                        "<<endl;
       cout<<"   Used My API 'JoyStickAPI'                                                 "<<endl;
       cout<<"                                                                             "<<endl;
       cout<<"                                                                             "<<endl;
       cout<<" --------------------------------------------------------------------------- "<<endl;
       cout<<"   Author information                                                        "<<endl;
	   cout<<" --------------------------------------------------------------------------- "<<endl;
       cout<<"                                                                             "<<endl;
       cout<<"   Programmer HCPP 2022-2023                                                 "<<endl;
       cout<<"   Writtein Programs only C++ my lovest Lang Program                         "<<endl;
       cout<<"   Github: https://github.com/HCPP20334                                      "<<endl;
       cout<<"   Youtube: https://youtube.com/@HackerC                                     "<<endl;
       cout<<"                                                                             "<<endl;
       cout<<"                                                                             "<<endl;
       SetColorAMD64(15);
       if(GetAsyncKeyState(VK_ESCAPE))
       {
  	    fRdAbout = -1;
  	    system("cls");
       }
	 }
}
int64_t JEException(HANDLE hWindow)
{
	SzWindow(1100,560);
	  	system("cls");
	ofstream JElog("JECrash.log");
	JElog.is_open();
  SetColorAMD64(71);
JElog<<" --  JE application crashed!                                                  "<<endl;  
JElog<<" ** JE.exe  **Address:"<<GetCurrentProcess()<<"                      "<<endl;
JElog<<" ** Error Address : "<<&fLX<<" xController1->GetState().Gamepad.sThumbLX"<<endl;
JElog<<" ** Error Address : "<<&fRX<<" xController1->GetState().Gamepad.sThumbRX"<<endl;
JElog<<" ** Error Address : "<<&fRY<<" xController1->GetState().Gamepad.sThumbRY"<<endl;
JElog<<" ** Error Address : "<<&fLY<<" xController1->GetState().Gamepad.sThumbLY"<<endl;
JElog<<"fCpu_id:"<<fCPUType()<<" cpu_tick:"<<GetTickCount()<<" "<<fLTime(0)<<":"<<fLTime(1)<<":"<<fLTime(2)<<endl;//
JElog<<"---------------------------------------------"<<endl;
JElog<<"mem_dwLength:"<<fMemStatus(0)<<" "<<"mem_dwMemoryLoad:"<<fMemStatus(1)<<endl;
JElog<<"mem_ullAvailExtendedVirtual:"<<fMemStatus(2)<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"mem_ullAvailPageFile:"<<fMemStatus(3)<<" mem_ullAvailPhys:"<<fMemStatus(4)<<endl;
JElog<<"mem_ullAvailVirtual:"<<fMemStatus(5)<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"mem_ullTotalPageFile:"<<fMemStatus(6)<<" mem_ullTotalPhys:"<<fMemStatus(7)<<endl;
JElog<<"mem_ullTotalVirtual:"<<fMemStatus(8)<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"CommitLimit:"<<fPerfomanceInfo(1)<<" CommitTotal:"<<fPerfomanceInfo(2)<<endl;
JElog<<"CommitPeak:"<<fPerfomanceInfo(3)<<" KernelNonpaged:"<<fPerfomanceInfo(4)<<" "<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"KernelPaged:"<<fPerfomanceInfo(5)<<" KernelTotal:"<<fPerfomanceInfo(6)<<endl;
JElog<<" PageSize:"<<fPerfomanceInfo(7)<<" "<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"PhysicalAvailable:"<<fPerfomanceInfo(8)<<" PhysicalTotal:"<<fPerfomanceInfo(9)<<endl;
JElog<<" ProcessCount:"<<fPerfomanceInfo(10)<<" "<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<"SystemCache:"<<fPerfomanceInfo(11)<<" ThreadCount:"<<fPerfomanceInfo(12)<<endl;
JElog<<"---------------------------------------------"<<endl;
JElog<<" FaultingPc:"<<ps_apiL(0)<<" FaultingVa:"<<ps_apiL(1)<<endl;
    SetColorAMD64(71);
					for(int64_t fAPIinfo = 1;fAPIinfo > 0;fAPIinfo++) 
					{
						SetFontA(L"Consolas",5,20);
							SzWindow(1100,560);
						cls(hWindow);
			SetColorAMD64(143);
  cout<<" :: JE Exception                                          (ESC) - back   "<<endl;
  SetColorAMD64(71);
  cout<<" --  JE application crashed!                                             "<<endl;    
  cout<<" ** JE-.exe  **Address:"<<GetCurrentProcess()<<"                 "<<endl;
  cout<<" ** Error Address : "<<&fLX<<" xController1->GetState().Gamepad.sThumbLX"<<endl;
  cout<<" ** Error Address : "<<&fRX<<" xController1->GetState().Gamepad.sThumbRX"<<endl;
  cout<<" ** Error Address : "<<&fRY<<" xController1->GetState().Gamepad.sThumbRY"<<endl;
  cout<<" ** Error Address : "<<&fLY<<" xController1->GetState().Gamepad.sThumbLY"<<endl;
  cout<<"fCpu_id:"<<fCPUType()<<" cpu_tick:"<<GetTickCount()<<" "<<fLTime(0)<<":"<<fLTime(1)<<":"<<fLTime(2)<<endl;//
				cout<<"---------------------------------------------"<<endl;
				cout<<"fMemory_info:"<<fMemStatus(0)<<"/"<<(float)((fMemStatus(4) / 1024) / 1024)<<""<<endl;
    SetColorAMD64(71);
 // JElog
  SetColorAMD64(15);
  if(GetAsyncKeyState(VK_ESCAPE))
  {
  	JElog.close();
  	fAPIinfo = -1;
  	system("cls");
  	Sleep(80);
  	system("taskkill /im JoyStickEmu.exe \t /f>nul");                                                                                                                                                                                                                                                                                                                                  
  }
}
}
int64_t fSndMsg(int64_t fJEid_snd)
{
	int64_t fSnd00 = 0xFFFFFFF;
	int64_t fSnd01 = 0x00000010L;
	int64_t fSnd02 = 0x00000040L;
	int64_t fSnd03 = 0x00000030L;
	//
	int64_t fSoundThread = 0;
	switch(fJEid_snd)
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
int64_t JEMessageT(string fStrText,string fStrTitle,int64_t fMaxLen )
{
	int64_t fsnd_out = fSndMsg(3);
	HANDLE hOutJE = GetStdHandle(STD_OUTPUT_HANDLE);
	string fStrFreeSpace_00;
	string fStrFreeSpace_01;
	int64_t fLineBuffer = 0;
	int64_t fLineSize = fStrText.size();
	fLineBuffer = 16 + fLineSize;
	for(int64_t fMsz_0 = 1; fMsz_0 <= fMaxLen; fMsz_0++)
	{
			if(fLineSize < fLineBuffer)
			{
			fStrFreeSpace_00 = fStrFreeSpace_00 + " ";	
			}
			if((fStrFreeSpace_00.size() + 16) > fLineSize)
			{
				fStrFreeSpace_01 = "   ";
			}
	}
		SzWindow(800,610);
	SetFontA(L"Consolas",5,20);
	cls(hOutJE);
	SetColorAMD64(113);
	cout<<":: "<<fStrTitle<<"  "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(159);
	cout<<"               "<<fStrFreeSpace_00<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(159);
	cout<<fStrText<<fStrFreeSpace_01<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(15);
	cout<<"snd_addr:"<<(void*)(char*)fsnd_out<<endl;
	Sleep(2000);
}
int64_t JEMessage(string fStrText,int64_t fMaxLen )
{
	int64_t fsnd_out = fSndMsg(1);
	HANDLE hOutJE = GetStdHandle(STD_OUTPUT_HANDLE);
	string fStrFreeSpace_00;
	string fStrFreeSpace_01;
	int64_t fLineBuffer = 0;
	int64_t fLineSize = fStrText.size();
	fLineBuffer = 16 + fLineSize;
	for(int64_t fMsz_0 = 1; fMsz_0 <= fMaxLen; fMsz_0++)
	{
			if(fLineSize < fLineBuffer)
			{
			fStrFreeSpace_00 = fStrFreeSpace_00 + " ";	
			}
			if((fStrFreeSpace_00.size() + 16) > fLineSize)
			{
				fStrFreeSpace_01 = "   ";
			}
	}
		SzWindow(800,610);
	SetFontA(L"Consolas",5,20);
	cls(hOutJE);
	SetColorAMD64(113);
	cout<<":: JE Message  "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(159);
	cout<<"               "<<fStrFreeSpace_00<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(159);
	cout<<fStrText<<fStrFreeSpace_01<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	cout<<"               "<<fStrFreeSpace_00<<endl;
	SetColorAMD64(15);
	cout<<"snd_addr:"<<(void*)(char*)fsnd_out<<endl;
	Sleep(2000);
}
uint64_t fDataMemUsage()
{
	PROCESS_MEMORY_COUNTERS pmc;//
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
}//

string fEnString()
{
	string fVersion = "1.1.5.2";
	string fCharBufferSet = "Build:"+fVersion;
	return fCharBufferSet;
}
int64_t EmuCPU(int64_t fCPUType_a)
{
	if(fCPUType_a == 0){
		return 1;
	}else{
		return 0;
	}
}
int64_t  fLdWin()
{
	SetColorAMD64(113);
	SetFontA(L"Consolas",20,60);
	SzWindow(420,580);
	cls(GetStdHandle(STD_OUTPUT_HANDLE)); 
	SetColorAMD64(113);
	cout<<"\n\n\nHCPP Studio"<<endl;//
	Sleep(1000);
	system("cls");
	SzWindow(420,580);
}
int64_t  fErrText(string fStrTxt,int64_t fColor_id)
{
	SzWindow(480,610);
	system("cls");
	SetColorAMD64(fColor_id);
	SetFontA(L"Consolas",20,60);
	cls(GetStdHandle(STD_OUTPUT_HANDLE)); 
	SetColorAMD64(fColor_id);
	cout<<"\n\n\n"<<fStrTxt<<endl;//
	Sleep(1000);
	system("cls");
}
int64_t ld_V()
{
	int64_t fBr = 0;
	int64_t fV = 0;
	int64_t fto_tick = 0;
	int64_t fto_tick_out = 0;
	int64_t fRcpu = 0;
	string fTcpu;
	//
	fto_tick = GetTickCount();
	//
	
	for(int64_t fG = 1; fG > 0;fG++)
	{
	//	Sleep(1);
			fRcpu = fto_tick_out - fto_tick;
			    if(fRcpu > 800)
			    {
			        fTcpu = "Very Powerful CPU!!    ";	
				}
				if(fRcpu <= 500)
				{
					fTcpu = "Very Fast               ";
				}
				if(fRcpu <= 200)
				{
					fTcpu = "Fast                    ";
				}
				if(fRcpu <=  100)
				{
					fTcpu = "Very Slow CPU!!    ";
				}
		fV++;
		if(fV > 30)
		{
			fV = 0;
		}
		if(fV == 30)
		{
			fBr++;
			if(fBr == 24)
			{
				fG = -1;
				JEMessageT("cpu_score: "+ to_string(fto_tick_out - fto_tick)+"Your CPU:"+fTcpu   ,"JE 1.1.5.2",20);
			}
			
		}
		fto_tick_out = GetTickCount();
		cls(GetStdHandle(STD_OUTPUT_HANDLE));
		SetColorAMD64(113);
		cout<<"    Test Speed CPU            "<<endl;
		SetColorAMD64(116);
		cout<<" "<<fBar[fBr]<<" "<<endl;
		cout<<"                              "<<endl;
		SetColorAMD64(15);
		cout<<"Sz_0:"<<fBar[fBr].size()<<endl;
	}
}
//
int64_t status(string text)
{
	HWND fW_hwnd = GetConsoleWindow();
	cout<<text<<endl;
	fVErev1(GetConsoleWindow());
}
