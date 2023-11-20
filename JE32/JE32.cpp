#include <iostream>
#include <string>
//#include <clocale>
#include "Colors32.h"
#include <Windows.h>
#include "JoyStick32.h"
#include <conio.h>
#include <psapi.h>
//#include "FileInfo.h"
#include <math.h>
#include <time.h>
#include <thread>
#include "dSys32.h"///-
int32_t  fErrText(string fStrTxt,int64_t fColor_id);
int32_t fRusCh[] = 
{
  0xE0,0xE1,0xE2,
  0xE3,0xE4,0xE5,
  0xB8,0xE6,0xE7,
  0xE8,0xEA,0xEB,
  0xEC,0xED,0xEE,
  0xEF,0xF0,0xF1,
  0xF2,0xE9,0xF3,
  0xFE,0xFC,0xFA,
  0xF5,0xFD,0xE6,
  0xE7,0xF8,0xF9
};
using namespace std;
//
  int32_t fLX = 0;
  int32_t fLY = 0;
  int32_t fRX = 0;
  int32_t fRY = 0;
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
   string fBarV3[] = 
   {
   "л                           ",
   " л                          ",
   "  л                         ",
   "   л                        ",
   "    л                       ",
   "     л                      ",
   "      л                     ",
   "       л                    ",
   "        л                   ",
   "         л                  ",
   "          л                 ",
   "           л                ",
   "            л               ",
   "             л              ",
   "              л             ",
   "               л            ",
   "                л           ",
   "                 л          ",
   "                  л         ",
   "                   л        ",
   "                    л       ",
   "                     л      ",
   "                      л     ",
   "                       л    ",
   "                        л   "
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
int32_t fVErev1(HWND hwnd);
int32_t SzWindow(int32_t fSzX,int32_t fSzY)
{
	HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r);
    MoveWindow(hWindowConsole, r.left, r.top, fSzX, fSzY, TRUE);//
}
int32_t fVErev1(HWND hwnd)
{
	int32_t fRandCL = 0;
int32_t fTimer = 0;
SetFontA(L"Consolas",1,1);
  //	SetPixel(fDC,fX,fY,RGB(fRandR,fRandG,fRandB));
   for(int32_t fRandomVec = 1;fRandomVec > 0;fRandomVec++)
   {
   	SzWindow(640,320);
   	srand(time(0));
   	fRandCL++;
   	if(fRandCL > 255){fRandCL = 1;
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
int32_t APInfo(HANDLE hWindow)
{
	SetFontA(L"Consolas",5,20);
SzWindow(710,660);
					for(int32_t fAPIinfo = 1;fAPIinfo > 0;fAPIinfo++)
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
	 for(int32_t fRdAbout = 1; fRdAbout > 0;fRdAbout++)
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
int32_t JEException(HANDLE hWindow)
{
	SzWindow(1100,560);
	  	system("cls");
//	ofstream JElog("JECrash.log");
//	JElog.is_open();
//  SetColorAMD64(71);
//JElog<<" --  JE application crashed!                                                  "<<endl;  
//JElog<<" ** JE.exe  **Address:"<<GetCurrentProcess()<<"                      "<<endl;
//JElog<<" ** Error Address : "<<&fLX<<" xController1->GetState().Gamepad.sThumbLX"<<endl;
//JElog<<" ** Error Address : "<<&fRX<<" xController1->GetState().Gamepad.sThumbRX"<<endl;
//JElog<<" ** Error Address : "<<&fRY<<" xController1->GetState().Gamepad.sThumbRY"<<endl;
//JElog<<" ** Error Address : "<<&fLY<<" xController1->GetState().Gamepad.sThumbLY"<<endl;
//JElog<<"fCpu_id:"<<fCPUType()<<" cpu_tick:"<<GetTickCount()<<" "<<fLTime(0)<<":"<<fLTime(1)<<":"<<fLTime(2)<<endl;//
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"mem_dwLength:"<<fMemStatus(0)<<" "<<"mem_dwMemoryLoad:"<<fMemStatus(1)<<endl;
//JElog<<"mem_ullAvailExtendedVirtual:"<<fMemStatus(2)<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"mem_ullAvailPageFile:"<<fMemStatus(3)<<" mem_ullAvailPhys:"<<fMemStatus(4)<<endl;
//JElog<<"mem_ullAvailVirtual:"<<fMemStatus(5)<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"mem_ullTotalPageFile:"<<fMemStatus(6)<<" mem_ullTotalPhys:"<<fMemStatus(7)<<endl;
//JElog<<"mem_ullTotalVirtual:"<<fMemStatus(8)<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"CommitLimit:"<<fPerfomanceInfo(1)<<" CommitTotal:"<<fPerfomanceInfo(2)<<endl;
//JElog<<"CommitPeak:"<<fPerfomanceInfo(3)<<" KernelNonpaged:"<<fPerfomanceInfo(4)<<" "<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"KernelPaged:"<<fPerfomanceInfo(5)<<" KernelTotal:"<<fPerfomanceInfo(6)<<endl;
//JElog<<" PageSize:"<<fPerfomanceInfo(7)<<" "<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"PhysicalAvailable:"<<fPerfomanceInfo(8)<<" PhysicalTotal:"<<fPerfomanceInfo(9)<<endl;
//JElog<<" ProcessCount:"<<fPerfomanceInfo(10)<<" "<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<"SystemCache:"<<fPerfomanceInfo(11)<<" ThreadCount:"<<fPerfomanceInfo(12)<<endl;
//JElog<<"---------------------------------------------"<<endl;
//JElog<<" FaultingPc:"<<ps_apiL(0)<<" FaultingVa:"<<ps_apiL(1)<<endl;
//    SetColorAMD64(71);
					for(int32_t fAPIinfo = 1;fAPIinfo > 0;fAPIinfo++) 
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
   //JElog.close();
  	fAPIinfo = -1;
  	system("cls");
  	Sleep(80);
  	system("taskkill /im JoyStickEmu.exe \t /f>nul");                                                                                                                                                                                                                                                                                                                                  
  }
}
}
int32_t fSndMsg(int32_t fJEid_snd)
{
	int32_t fSnd00 = 0xFFFFFFF;
	int32_t fSnd01 = 0x00000010L;
	int32_t fSnd02 = 0x00000040L;
	int32_t fSnd03 = 0x00000030L;
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
int32_t JEMessageT(string fStrText,string fStrTitle,int32_t fMaxLen )
{
	int32_t fsnd_out = fSndMsg(3);
	HANDLE hOutJE = GetStdHandle(STD_OUTPUT_HANDLE);
	string fStrFreeSpace_00;
	string fStrFreeSpace_01;
	int32_t fLineBuffer = 0;
	int32_t fLineSize = fStrText.size();
	fLineBuffer = 16 + fLineSize;
	for(int32_t fMsz_0 = 1; fMsz_0 <= fMaxLen; fMsz_0++)
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
int32_t JEMessage(string fStrText,int64_t fMaxLen )
{
	int32_t fsnd_out = fSndMsg(1);
	HANDLE hOutJE = GetStdHandle(STD_OUTPUT_HANDLE);
	string fStrFreeSpace_00;
	string fStrFreeSpace_01;
	int32_t fLineBuffer = 0;
	int32_t fLineSize = fStrText.size();
	fLineBuffer = 16 + fLineSize;
	for(int32_t fMsz_0 = 1; fMsz_0 <= fMaxLen; fMsz_0++)
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
int32_t fDataMemUsage()
{
	PROCESS_MEMORY_COUNTERS pmc;//
	pmc.cb = sizeof(pmc);
	GetProcessMemoryInfo(GetCurrentProcess(),&pmc,sizeof(pmc));
	return pmc.WorkingSetSize / 1024;
}

bool Asleep(int32_t Value)
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
int32_t EmuCPU(int32_t fCPUType_a)
{
	if(fCPUType_a == 0){
		return 1;
	}else{
		return 0;
	}
}
int32_t  fLdWin()
{
	SetColorAMD64(113);
	SetFontA(L"Consolas",20,60);
	SzWindow(480,610);
	cls(GetStdHandle(STD_OUTPUT_HANDLE)); 
	SetColorAMD64(113);
	cout<<"\n\n\nHCPP Studio"<<endl;//
	Sleep(1000);
	system("cls");
	SzWindow(480,610);
}
int32_t  fErrText(string fStrTxt,int64_t fColor_id)
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
int32_t ld_V()
{
	int32_t fBr = 0;
	int32_t fV = 0;
	int32_t fto_tick = 0;
	int32_t fto_tick_out = 0;
	int32_t fRcpu = 0;
	string fTcpu;
	//
	fto_tick = GetTickCount();
	//
	
	for(int32_t fG = 1; fG > 0;fG++)
	{
			fRcpu = fto_tick_out - fto_tick;
			    if(fRcpu > 800)
			    {
			        fTcpu = " Slow                   ";	
				}
				if(fRcpu <= 500)
				{
					fTcpu = "Fast                    ";
				}
				if(fRcpu <= 200)
				{
					fTcpu = "Very Fast               ";
				}
				if(fRcpu <=  100)
				{
					fTcpu = "Very Very Powerful CPU!!";
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
		SetColorAMD64(241);
		cout<<"    Test Speed CPU            "<<endl;
		SetColorAMD64(244);
		cout<<" "<<fBar[fBr]<<" "<<endl;
		cout<<"                              "<<endl;
		SetColorAMD64(15);
		cout<<"Sz_0:"<<fBar[fBr].size()<<endl;
	}
}
//
string  Scan(int32_t fcc_11)
{
	string fBuf_0;
	string fBuf_1;
		fBuf_0 = fBuf_0 + ((char)221);  //
		switch(fcc_11)
		{
			case 1:
				fBuf_1 = fBuf_0 + "                           ";return fBuf_1;
			case 2:
				fBuf_1 = " "+fBuf_0 +fBuf_0 +"                 ";return fBuf_1;
			case 3:
				fBuf_1 = "  " +fBuf_0 +fBuf_0 + "             ";return fBuf_1;
			case 4:
				fBuf_1 = "     "+fBuf_0 +fBuf_0 +"            ";return fBuf_1;
			case 5:
				fBuf_1 = "       "+fBuf_0 +fBuf_0 +"          ";return fBuf_1;
			case 6:
				fBuf_1 = "         " +fBuf_0 +fBuf_0 +"       ";return fBuf_1;
			case 7:
				fBuf_1 = "               "+fBuf_0 +fBuf_0 + " ";return fBuf_1;
			case 8:
				fBuf_1 = "             " +fBuf_0 +fBuf_0;return fBuf_1;
			case 9:
				fBuf_1 ="             "+fBuf_0 +fBuf_0 +"      ";return fBuf_1;
			case 10:
				fBuf_1 = "         "+fBuf_0 +fBuf_0 +"         ";return fBuf_1;
			case 11:
				fBuf_1 ="   "+fBuf_0 +fBuf_0 +"                " ;return fBuf_1;
			break;
		}
		if(GetKeyState('E'))
		{
			fBuf_1  = (" fcc_11:"+to_string(fcc_11)+ "len:"+to_string(fBuf_1.size()));
		}
		return fBuf_1;
}
int main(int argc, char *argv[])
{
	int32_t fg = 0;
	GetFontA();
	 fLdWin();
		SetFontA(L"Consolas",5,20);
	SetColorAMD64(15);
	SzWindow(800,610);
cout<<"JE "<< fEnString()<<" github.com/HCPP20334/JoyStickTest"<<endl;
cout<<"for JE min SSE 4A instruction\nWinXPx64 and more..\n Visual Studio C++ 2011 x64 runtime \n"<<endl;
cout<<"fCpu_id:"<<fCPUType()<<" cpu_tick:"<<GetTickCount()<<" "<<fLTime(0)<<":"<<fLTime(1)<<":"<<fLTime(2)<<endl;//
cout<<"---------------------------------------------"<<endl;
cout<<"mem_dwLength:"<<fMemStatus(0)<<" "<<"mem_dwMemoryLoad:"<<fMemStatus(1)<<" "<<"mem_ullAvailExtendedVirtual:"<<fMemStatus(2)<<endl;
cout<<"---------------------------------------------"<<endl;
//	ld_V();
Sleep(2000);
system("cls");
  //data_t 
  int32_t fMemory = 0;
  int32_t fKeyWin = 0;//-
  int32_t fKeyXbox = 0;
  int32_t fKeyCode = 0;
  int32_t fMaxByteToKey = 0;
  int32_t fSizeStrBuffer = 0;
  int32_t fColDebug = 0;
  int32_t fPointSettingsKeyboard = 0; 
  int32_t fXinputStatusCodeW = 0;//
  int32_t fU = 0;
  int32_t fL = 0;
  int32_t fD = 0;
  int32_t fR = 0;
  int32_t fY = 0;
  int32_t fX = 0;
  int32_t fA = 0;
  int32_t fB = 0;
  int32_t fColorLine_00 = 113;
  int32_t fTime_00 = 0;
  int32_t fColor_00 = 138;
  int32_t fBatLevel = 0; 
  int32_t xLXBuffer = 0;
  int32_t fLXPos = 0;//
  int32_t fLYPos = 0;//
  int32_t fRXPos = 0;//
  int32_t fRYPos = 0;// 
  int32_t fTestYBar = 0;
  int32_t fAnimDuration = 0;
  int32_t fAnimPoint = 0;
  int32_t fErrorColor = 71;
  int32_t fDebugColorMode0 = 0;
  int32_t fDebugColorMode = 15;
  int32_t fAnimDuration0 = 0;
  int32_t fAnimPoint0 = 0;
  int32_t fRTPos = 0;
  int32_t fLTPos = 0;
  int32_t fLTPoint = 0;
  int32_t fRTPoint = 0;
  int32_t fLBPoint = 0;
  int32_t fRBPoint = 0;
  int32_t fLXAxisPoint = 0;
  int32_t fLYAxisPoint = 0;
  int32_t fRXAxisPoint = 0;
  int32_t fRYAxisPoint = 0;
  int32_t fLXM = 0;
  int32_t fLYM = 0;
  int32_t c1 = 0;
  int32_t fP0 = 0;
  int32_t fP1 = 0;
  int32_t fP2 = 0;
  int32_t fP3 = 0;
  int32_t fP4 = 0;
  int32_t fP5 = 0;
  int32_t fP6 = 0;
  int32_t fTimeUsed = 1;
  int32_t fHour = 0;
  int32_t fColorBar = 138;
  int32_t fExP = 0;
  int32_t fDebugIgnoreXiputError = 0;
  int32_t fBPoint = 0;
  int32_t fMaxErrors = 6;
  int32_t fMaxCountStatus = 3;
  int32_t fMouseCountClicks = 0;
  int32_t fColorText = 0;
  int32_t fJEColorIntro = fColorText = 138;
  int32_t fJEColorSettings = 0;
  int32_t fRegister = 199;
  int32_t fJEYSize  = 30;
  int32_t fJEXSize = 0;
  int32_t fColorStatus = 12;
  int32_t fDgFreq = 0;
  int32_t fJEAxis2MouseCoordLX = 0;
  int32_t fJEAxis2MouseCoordLY = 0;
  //Main Cycles
  int32_t fTextLoad1 = 1;
  int32_t fTextLoad = 1;
  //
  // Color Modes Menu
  int32_t fColorsMSet = 1;
  int32_t fCMlPoint = 0;
  int32_t fC_00 = 0;
  int32_t fC_01 = 0;
  int32_t fClA = 0;
  ///
  //Test Rand Bars
    int32_t fRv0 = 0;
	int32_t fRv1 = 0;
	int32_t fRv2 = 0;
	int32_t fRv3 = 0;
//	int64_t fRv4 = 0;
//	int64_t fRv5 = 0;
	int32_t fColorSet = 0;
	int32_t fCv0 = 0;
	//
	//CheckFiles
	int32_t fFiles0 = 0;
	int32_t fFiles1 = 0;
	int32_t fAllSize = 0;
	int32_t fLoadStackFrame = 0;
	int32_t GetLatencyToFrame = 0;
	int32_t fFrames = 0;
	int32_t fGetFrames = 0;
	// JE DEBUGGER
	int32_t fJE_Menu = 0;
	int32_t fJEDebCol_0 = 0;
	int32_t fJEDebCol_1 = 0;
	int32_t fJEDebCol_2 = 0;
	int32_t fJEKeyDelay = 0;
	int32_t fThread_0 = 0;
	int32_t fCpuCode = 0;
	int32_t f_rnd  = 0;
	int32_t f_rndT = 0;
	int32_t f_Kb0 = 0;
	int32_t f_Kb1 = 0;
	int32_t f_Kb2 = 0;
	int32_t f_Kb3 = 0;
	int32_t fJEKbDelayD = 0;
	int32_t fJEKbDelay = 0;
	int32_t fJEColorBack = 143;
	int32_t fDelayN = -0;
	int32_t fPrBtn_00 = 143;
	int32_t fDlPrbtn = 0;
	int32_t c2 = 0;
	int32_t fScGd = 0;
	//
	int32_t fMenuC0 = 0;
	int32_t fMenuC1 = 0;
	int32_t fMenuC2 = 0;
	int32_t fMenuC3 = 0;
	int32_t fMnItSel = 0;
	int32_t fDelayMnSel = 0;
	int32_t fDly_0 = 0;
	int32_t fItm_0 = 0;
	int32_t fClr_0a = 0;
	int32_t fClr_0b = 0;
	int32_t fDgCPUPoint = 0;
	int32_t fc_0 = 0;
    int32_t fcc_12 = 0;

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
	string fJEMode;
	//
	int32_t fAn_0a = 0;
	//
	string fStr_0;
	string fStr_1;
	string fStr_2;
	string fStr_3;
	string fStr_4;
	string fStr_5;
	string fStr_6;
	string fStr_7;
	string fStr_8;
	string fStr_9;
	string fStr_1A;
	string fStr_1B;
	string fStr_1C;
	string fStr_1D;
	string fStr_1E;
	string fStr_1F;
	string fStr_21;
	string fStr_22;
	string fStr_23;
	//
	
  char fChUp = 24;
  char fChDn = 25;
  bool fDebugger = false;
  bool bKeyPresed;
  bool fXCon = false;
  bool fAxisTest = false;
  bool kbEmu = false;
  bool xControllerState = false;
  bool fClear = true;
  bool fExSh = false;
  bool fDebugMode = false;
  bool fBarS = false;
  bool fJEColorSetMenu = false;
  bool fTestBars = false;
  bool fCheckFiles  = false;
  bool fCR_Error = false;
  bool fJEInfoF = false;
  bool fPrevWindow = true;
  bool fCL_RwMem = false;
  bool BoolDb = false;
  bool fd0 = false;
  bool fCPUDebug = false;
  bool fColTable = false;
  //
  HDC fDC = GetDC(GetConsoleWindow());
  string fXinput_Status;
  JoyStickAPI* xController1;
  JoyStickAPI* xController2;
  string fTimeStr;
  string fJEText;
  string fStrCPUinfo;
   string fLoadingBar[] = 
   {
   	"л                    ",
   	"    л                ",
   	"        л            ",
   	"            л        ",
   	"                л    ",
   	"                    л"
   };
    string fLoadingBarV2[] = 
   {
   	"[*                  ]",
   	"[   *               ]",
   	"[        *          ]",
    "[           *       ]",
   	"[              *    ]",
   	"[                 * ]",
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
  int32_t fVperfMode = 2;
  HANDLE fGetWindow = GetStdHandle(STD_OUTPUT_HANDLE);
  HWND fHwcon = GetConsoleWindow();
  xController1 = new JoyStickAPI(1);
  xController2 = new JoyStickAPI(2);
  xControllerState = (xController1->IsConnected());
  SetWindowLong(fHwcon, GWL_STYLE, GetWindowLong(fHwcon, GWL_STYLE) & WS_VISIBLE);
    	       fCpuCode = 4;
    	       
  string fStrCA;
  string f_FrSpace;
  HWND hBtn;
  if(fCpuCode == 1){ fStrCA = "Intel x86";}
  if(fCpuCode == 2){ fStrCA = "Intel x64";}
  if(fCpuCode == 3){ fStrCA = "AMD x64";}
  if(fCpuCode == 4){ fStrCA = "AMD x86";}
  //-ofstream fW_filw("JEConfig.je");

  system("cls");
   fd0 = true;
   fExP = 10;
 // fVErev1(fHwcon);
 SetFontA(L"Consolas",5,20);
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
  if(fVperfMode == 0)
  {
    f_rnd = 15;
  	f_rndT = 143;
  }
   if(fVperfMode == 1)
  {
  	f_rndT = 143;
  	f_rnd = 159;
  }
   if(fVperfMode == 2)
  {
  	f_rnd = 143;
  	f_rndT = 159;
  }
  if(fd0)
  {
  	system("cls");
  	fd0 = false;
  }
// if( strcmp(argv[1],"-fDebugSkip"))
// {
// 	fJEText = "Skip Enable!!";
// }
BoolDb = false;
                     if(BoolDb)
                     {
                     	BoolDb = true;
						cls(fGetWindow);
						cout<<"bool fDebugger:"<<fDebugger<<endl;
                        cout<<"bool bKeyPresed:"<<bKeyPresed<<endl;
                        cout<<"bool fXCon:"<<fXCon<<endl;
                        cout<<"bool xControllerState:"<<xControllerState<<endl;
                        cout<<"bool fClear:"<<fClear<<endl;
                        cout<<"bool fExSh:"<<fExSh<<endl;
                        cout<<"bool fDebugMode:"<<fDebugMode<<endl;
                        cout<<"bool fBarS:"<<fBarS<<endl;
                        cout<<"bool fJEColorSetMenu:"<<fJEColorSetMenu<<endl;
                        cout<<"bool fExSh:"<<fExSh<<endl;
                        cout<<"bool fTestBars:"<<fTestBars<<endl;
                        cout<<"bool fCheckFiles:"<<fCheckFiles<<endl;
                        cout<<"bool fCR_Error:"<<fCR_Error<<endl;
                        cout<<"bool fJEInfoF:"<<fJEInfoF<<endl;//
                        cout<<"bool fPrevWindow:"<<fPrevWindow<<endl;
                        cout<<"bool fCL_RwMem:"<<fCL_RwMem<<endl;
                        if(GetAsyncKeyState(VK_ESCAPE))
				        {
				        	BoolDb = false;
				        	system("cls");
				        }
					}
					if(fCPUDebug)
					{
						 SzWindow(550,620);
						 SetFontA(L"Zector",10,20);
						fStrCPUinfo = "cpu_type:"+fCPUType()+" cpu_tick:"+ to_string(GetTickCount())+" Errors:0x"+to_string(GetLastError())+"\n"+"loop_count:"+to_string(fTextLoad);	
					}
					if(!fCPUDebug)
					{
						 SzWindow(490,620);
						 SetFontA(L"Consolas",5,20);
						fStrCPUinfo = "Press Debug to cpu_info";
					}
					if(fColTable)
					{
						system("cls");
						for(int64_t fd_0 = 1;fd_0 <= 20;fd_0++)
						{
							cls(fGetWindow);
							fc_0++;
							if(fc_0 > 20)
							{
								fc_0 = 0;
							}
						SetColorAMD64(230+fc_0);
						cout<<230+fc_0<<" ";
					    }
					    _getch();//
					    fColTable = false;
					}
					SetFontA(L"Consolas",5,20);
	cls(fGetWindow); 
	            SetColorAMD64(f_rndT);
	            cout<<"::: JE Build 1.1.5 Hold (ESC) to exit("<<fExP<<"/24)"<<endl;
	            SetColorAMD64(241-fMenuC0);
	            cout<<" Theme";
	            SetColorAMD64(241-fMenuC1);
	            cout<<" About";
	            SetColorAMD64(241-fMenuC2);
	            cout<<" Debug";
	            SetColorAMD64(241);
				cout<<"   <- -> Select "<<fLTime(0)<<":"<<fLTime(1)<<":"<<fLTime(2)<<"  "<<endl;
	            SetColorAMD64(f_rnd);                                       
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
	            cout<<"                                            "<<endl;
	            cout<<"                                            "<<endl;
			    cout<<"   [] [][][]                                "<<endl;
			    cout<<"   [] []                                    "<<endl;
			    cout<<"   [] [][][]    Powered JoyStickAPI by HCPP "<<endl;
			    cout<<"   [] [][][]    JoYStickAPI Writein C++     "<<endl;
			    cout<<"   [] []       GNU Project                  "<<endl;
			    cout<<"[][][ [][][]                                "<<endl;
			    cout<<"                                            "<<endl;
	            cout<<"                                            "<<endl;
			    cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
			    cout<<"     Scanning Gamepads...                   "<<endl;
			    SetColorAMD64(131);
			    cout<<"  "<<fBarV3[fcc_12]<<"                     "<<endl;
			    SetColorAMD64(f_rnd);
			    cout<<"   HCPP Studio 2021-2023                    "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(142);
				cout<<" ::Events                                   "<<endl;
				SetColorAMD64(fColorStatus);
				cout<<"                                            "<<endl;
				cout<<"    "<<fJEText<<endl;
				cout<<"                                            "<<endl;
				SetColorAMD64(f_rnd);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<" (L) - Debug (A)/[ENTER] - Skip             "<<endl;
				cout<<" (C) - About to My API (JoyStickAPI)        "<<endl;
				cout<<" (T) - Theme Sel                            "<<endl;
				SetColorAMD64(240);
				cout<<"JE mem_usage:";
					SetColorAMD64(159);
				cout<<(float)fDataMemUsage() / 1024<<":MiB";
					SetColorAMD64(240);
				cout<<"    Address="<<&fTextLoad<<endl;
				SetColorAMD64(15);
			    cout<<fStrCPUinfo<<endl;
				cout<<"---------------------------------------------"<<endl;
				if(GetAsyncKeyState(VK_F3))
				{
					system("cls");//
					WinExec("JEUpdate.exe",1);
				}
				if(GetAsyncKeyState('Q'))
				{
					fColTable = true;
				}
				if(GetAsyncKeyState('T'))
				{
					cout<<"TEST!!E_call:"<<CreateSolidBrush(RGB(255,100,30))<<endl;
					fVperfMode++;
					if(fVperfMode > 2)
					{
						fVperfMode = 0;
					}
				}
				if(GetKeyState('V'))
				{
						BoolDb = true;
				}
				    if(fMnItSel == 0)
					{
						fMenuC0 = 98;
						fMenuC1 = 0;
						fMenuC2 = 0;
					}
					if(fMnItSel == 1)
					{
						fMenuC0 = 0;
						fMenuC1 = 98;
						fMenuC2 = 0;
					}
					if(fMnItSel == 2)
					{
						fMenuC0 = 0;
						fMenuC1 = 0;
						fMenuC2 = 98;
					}
				if(GetAsyncKeyState(VK_RETURN))
				{
					if(fMnItSel == 0)
					{
						cls(fGetWindow);
						fVperfMode++;
					if(fVperfMode > 2)
					{
						fVperfMode = 0;
					}
					}
					if(fMnItSel == 1)
					{
						cout<<"JE Build 1.1.5(beta) by HCPP"<<endl;
//						AboutWdw(fGetWindow);
//						APInfo(fGetWindow);
                        for(int64_t fab_sel = 1;fab_sel > 0; fab_sel++)
                        {
                        	cls(fGetWindow);
                        	SetColorAMD64(159);
                        cout<<" :: JE Select item  [ESC] - exit           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(fClr_0a);
                        cout<<"    JoyStickAPI Doc  [1]                   "<<endl;
                        SetColorAMD64(fClr_0b);
                        cout<<"    About all        [2]                   "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(30);
                        cout<<"                                           "<<endl;
                        SetColorAMD64(159);
                        cout<<" W,S - Select, SPACE - OK                  "<<endl;
                        SetColorAMD64(15);
                        cout<<&fab_sel<<"->"<<fab_sel<<endl;
                        if(fItm_0 == 0){fClr_0a = 143;fClr_0b = 30;}
                        if(fItm_0 == 1){fClr_0b = 143;fClr_0a = 30;}
                        if(GetAsyncKeyState('1'))
                        {
                        	fItm_0 = 0;
						}
						if(GetAsyncKeyState('2'))
                        {
                        	fItm_0 = 1;
						}
                        if(GetAsyncKeyState('S'))
                        {
                          Sleep(80);
                        		fItm_0++;
                        		if(fItm_0 > 1)
                        		{
                        			fItm_0 = 0;
								}
						}
                        if(GetAsyncKeyState('W'))
                        {
                        Sleep(80);
                        		fItm_0--;
                        		if(fItm_0 < 0)
                        		{
                        			fItm_0 = 1;
								}
						}
                        if(GetAsyncKeyState(VK_SPACE))
                        {
                        	if(fItm_0 == 0)
                            {
                        	APInfo(fGetWindow);
						    }
						    if(fItm_0 == 1)
                            {
                        	AboutWdw(fGetWindow);
						    }
						}
						if(GetAsyncKeyState(VK_ESCAPE))
						{
							fab_sel = -1;
							system("cls");
							
						}
						}
					}
					if(fMnItSel == 2)
					{
						Sleep(80);
						fDgCPUPoint++;
						if(fDgCPUPoint > 1)
						{
							fDgCPUPoint = 0;
						}
						if(fDgCPUPoint == 0)
						{
							fCPUDebug = false;
						}
						if(fDgCPUPoint == 1)
						{
							fCPUDebug = true;
						}
						Sleep(80);
						system("cls");
						
						
					}
				}
				if(GetAsyncKeyState(VK_RIGHT))
				{
					fDelayMnSel++;
					if(fDelayMnSel == 5)
					{
						fMnItSel++;
						fDelayMnSel = 0;
					}
					if(fMnItSel > 2)
					{
						fMnItSel = 0;
					}
				}
				if(GetAsyncKeyState(VK_LEFT))
				{
					fDelayMnSel++;
					if(fDelayMnSel == 5)
					{
						fMnItSel--;
						fDelayMnSel = 0;
					}
					if(fMnItSel < 0)
					{
						fMnItSel = 2;
					}
				}
				if(!fXCon)
				{
					fScGd++;
					if(fScGd == 1)
					{
						fcc_12++;
						fScGd = 0;
					}
					if(fcc_12 > 24)
					{
						fcc_12 = 0;
					}
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
    SzWindow(400,580);
    		system("cls");
    	   	//	xController1->Vibrate(10000,10000);//-
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
SetColorAMD64(15);
// SetColorAMD64(15);
// cout<<" Test Bar Press (B) and R key Mouse"<<endl;
// cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
// cout<<fL1<<"  "<<fP6<<fP5<<fP4<<fP3<<fP2<<fP1<<fP0<<"  "<<fL1<<endl;
// cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
//
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
			SetFontA(L"Consolas",5,20);
		fTimeStr = to_string(fLTime(0))+":"+to_string(fLTime(1))+":"+to_string(fLTime(2));
	
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
			fRTPoint = 24;//
		}
		//SetWindowText(fHwcon,("Time Used:"+fTimeStr+"UnitRAM:"+to_string(fDataMemUsage())+" Xinput:"+fXinput_Status).c_str());
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
//		  } SzWindow(430,610);
//	    }
//-fVectorEngine();
     cls(fGetWindow);//
	SetColorAMD64(15); SzWindow(640,610);
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
  	cout<<"   Press N to Debugger!!                    "<<endl;
  	cout<<"                                            "<<endl;
if(GetAsyncKeyState(VK_DOWN))
{
	fJEYSize = fJEYSize + 10;
	 SzWindow( 200,fJEYSize);
}
if(GetAsyncKeyState(VK_UP))
{
	fJEYSize = fJEYSize - 10;
	SzWindow( 200,fJEYSize);
}
if(GetAsyncKeyState(VK_LEFT))
{
	fJEXSize = fJEXSize - 10;
	SzWindow( fJEXSize,fJEYSize);
}
if(GetAsyncKeyState(VK_RIGHT))
{
	fJEXSize = fJEXSize + 10;
	SzWindow( fJEXSize,fJEYSize);
}
		}
		SetColorAMD64(15);
		cout<<"\n\n";
		SetColorAMD64(15);
		if(GetAsyncKeyState('N'))
		{
			fXCon = true;
			fCR_Error = true;
		}
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
 fVErev1(fHwcon);
 	for(fColorsMSet = 1; fColorsMSet > 0;fColorsMSet++)
 	{
 	fCL_RwMem = false;
        if(fCMlPoint == 0)
        {
        	fC_00 = 225;
        	fC_01 = 0;
		}
		 if(fCMlPoint == 1)
        {
        	fC_00 = 0;
        	fC_01 = 225;
		}
 		cls(fGetWindow); SzWindow(430,610);
 		SetColorAMD64(14);  
 		cout<<"       Color Settings         "<<endl;
 		SetColorAMD64(14);  
 		cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 		cout<<"                            "<<endl;
 			SetColorAMD64(15+fC_00);
 	    cout<<" Bar Color  :"<<fColor_00<<endl;
 	    	SetColorAMD64(15);
 	    cout<<"                            "<<endl;
 	    	SetColorAMD64(15+fC_01);
 	    cout<<" Backg Color:"<<fColor_00<<endl;
 	    	SetColorAMD64(15);
 	    cout<<"Item:"<<fCMlPoint<<endl;
 	    cout<<"KbDelay:"<<fClA<<endl;
 	    cout<<"                            "<<endl;
 		cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 		cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 			SetColorAMD64(14);                //
 		cout<<fL1<<"      [ENTER]/(A) - OK      "<<fL1<<endl;
		cout<<fL1<<"      [W]/(UP) - UP         "<<fL1<<endl;
		cout<<fL1<<"      [S]/(DOWN) - Down     "<<fL1<<endl;
		cout<<fL1<<"      [R]/(B) - Random      "<<fL1<<endl;//
 		cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 		SetColorAMD64(240);
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fJEColorSetMenu<<endl;
				SetColorAMD64(15);
		SetColorAMD64(15);
			if(GetAsyncKeyState('N'))
		{
			fCR_Error = true;
		}
 		if(GetAsyncKeyState('R'))
 		{
 			srand(time(0));
 			fCMlPoint = rand() % 1;
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
             fVErev1(fHwcon);
 			fColorsMSet = -1;
 			fJEColorSetMenu = false;	
 			fColor_00 = fColorText;
 			if(fCMlPoint == 0)
 			{
 				
			 }
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
 				fCMlPoint = 1;
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
 			if(fCMlPoint > 1)
 			{
 				fCMlPoint = 0;
			 }
		}
		  	if(GetAsyncKeyState('D') || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
		  	{
		  		fColor_00 = 130;
		  		fColor_00++;
		  		if(fColor_00 > 143)
		  		{
		  			fColor_00 = 130;
				  }
			  }
			  if(GetAsyncKeyState('A') || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
		  	{
		  		fColor_00 = 130;
		  		fColor_00++;
		  		if(fColor_00 > 143)
		  		{
		  			fColor_00 = 130;
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
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A || GetAsyncKeyState(VK_RETURN))//test JE  Build 1.1.3
				{
					fJEInfo = -1;
					fJEInfoF = false;
					system("cls");
				}
				
	 }
 }
 if(fCR_Error)
		{
		//	system("cls");
	//fVErev1(fHwcon);
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
			 SzWindow(640,680);
				SetColorAMD64(143);
				cls(fGetWindow);
				 SetColorAMD64(159);
	               cout<<"::: JE Build 1.1.5  (Debugger)            "<<endl;
				SetColorAMD64(143);
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
				cout<<"          Occured Registers                 "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;///
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
				SetColorAMD64(240);
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
				SetColorAMD64(15);
				SetColorAMD64(15);
				 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B || GetAsyncKeyState('B'))
				 {
				 	cout<<"JE.exe return:"<<to_string(GetLastError())<<endl;//
				 }
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
				SzWindow(640,680);
			    	cls(fGetWindow);
			      for(int64_t fLdBar = 1;fLdBar <= 2000;fLdBar++)
			      {
			      	cls(fGetWindow);
			      	SetColorAMD64(159);
			      	cout<<"\n\n\n"<<endl;
			      	SetColorAMD64(159);
			      	cout<<"  Loading...                  "<<endl;
			      	cout<<" "<<fBar[fLdBar / 100]<<" "<<endl;
			      	cout<<"                              "<<endl;
			      	SetColorAMD64(15);
				  }
			    if(fJE_Menu == 0)
			    {
					main(0,(char**)"JE");
				}
				if(fJE_Menu == 1)
				{
						fErrText("Error!!",12);
					fCR_Error = false;
					fRenderWindow_Error = -1;
					SetColorAMD64(159);
					SzWindow(640,680);
	            JEMessage("Crash!!!'Memory to out of range !!'",20);
	           //- MessageBox(GetConsoleWindow(),("Error!!Font address:"+to_string(GetLastError())).c_str(),"JEErrors",0);//
	            	JEException(fGetWindow);
				SetColorAMD64(143);
					
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
					xControllerState  = true;
					fXCon = true;
				}
				}
			}
			system("cls");
		}
		SzWindow(640,680);
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
		//143
	//-	fJEMode = " Normal ";
		SetFontA(L"Consolas",5,20);//
				cls(fGetWindow);
				cout<<"JE.exe return:"<<to_string(GetLastError())<<endl;//
				 SetColorAMD64(f_rndT);
	            cout<<":::   JE Build 1.1.5                        "<<endl;
	            SetColorAMD64(143);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(f_rnd);
				cout<<" A  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fA]<<"            "<<endl;
				SetColorAMD64(f_rnd);
				cout<<" B  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fB]<<"            "<<endl;
				SetColorAMD64(f_rnd);
				cout<<" X  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fX]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" Y  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fY]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" U  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fU]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" D  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fD]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" R  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fR]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" L  ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fL]<<"            "<<endl;
				SetColorAMD64(f_rnd);
				cout<<" RB ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fRBPoint]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" LB ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fLBPoint]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" RT ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fRTPoint]<<"            "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<" LT ";
				SetColorAMD64(fColor_00);
				cout<<fBar[fLTPoint]<<"            "<<endl;
				SetColorAMD64(fColor_00);
				SetColorAMD64(240);
				cout<<" JE Mode:"<<fJEMode<<"       (K) - Random Mode   "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"            Axis LX,LY,RX,RY                "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;//-
				SetColorAMD64(fJEColorBack);
				cout<<" LX Value:"<<fStrLX<<"                              "<<fSLx<<endl;
				cout<<" LY Value:"<<fStrLY<<"                              "<<fSLy<<endl;
				cout<<" RX Value:"<<fStrRX<<"                              "<<fSRx<<endl;
				cout<<" RY Value:"<<fStrRY<<"                              "<<fSRy<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"                 HotKeys                    "<<endl;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"(F8) Gamepad Info , [O] - Settings Emulator "<<endl;
				cout<<"F1 - RESET PROGRAM (BACK)/[ESC]- Exit Press "<<endl;
				SetColorAMD64(fJEColorBack);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				SetColorAMD64(240);
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
				SetColorAMD64(15);
	    }
	    if(GetAsyncKeyState('X'))
	    {
	    	fXCon = true;
		
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
		 
		 if(GetKeyState('K'))
		 {
		 	fColor_00 = rand() % 255;
		 	fJEMode = " Random ";
		 	fDelayN++;
		 	srand(time(0));
		 	if(fDelayN == 0)
		 	{
		 		fY = rand() % 24;
			}
			if(fDelayN == 1)
		 	{
			   fB = rand() % 24;
		    }
		    if(fDelayN == 2)
		 	{
			   fX = rand() % 24;
		    }
		    if(fDelayN == 3)
		 	{
			   fA = rand() % 24;
		    }
		    if(fDelayN == 4)
		 	{
			   fU = rand() % 24;
		    }
		    if(fDelayN == 5)
		 	{
			   fD = rand() % 24;
		    }
		    if(fDelayN == 6)
		 	{
			   fL = rand() % 24;
		    }
		    if(fDelayN == 7)
		 	{
		    }
		    if(fDelayN == 8)
		 	{
			   fLBPoint = rand() % 24;
		    }
			if(fDelayN == 9)
		 	{
			   fRBPoint = rand() % 24;
		    }
		    if(fDelayN > 9)
		    {
		    	fDelayN = 0;
			}
		 }
		 else
		 {
		 	fJEMode = " Normal ";
		 	fColor_00 = 138;
		 }
		 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B || GetAsyncKeyState('V'))
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
					fY--;fB--;fA--;fU--;fL--;fR--;fD--;
		 }
	 fY--;fB--;fA--;fU--;fL--;fR--;fD--;fLBPoint--;fRBPoint--;fX--;
if(fY < 0){fY = 0;}
if(fB < 1){fB = 0;}
if(fU < 0){fU = 0;}
if(fL < 0){fL = 0;}
if(fR < 0){fR = 0;}
if(fD < 0){fD = 0;}
if(fA < 0){fA = 0;}
if(fX < 0){fX = 0;}
if(fLBPoint < 0){fLBPoint = 0;}
if(fRBPoint < 0){fRBPoint = 0;}
		if(GetAsyncKeyState('P'))
		{
			JEMessage(fErrors[1],20);
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
				fDlPrbtn++;
				if(fDlPrbtn == 40)
				{
					fPrBtn_00 = 131;
				}
				if(fDlPrbtn < 20)
				{
					fPrBtn_00 = 143;
				}
				if(fDlPrbtn > 40)
				{
					fDlPrbtn = 0;
				}
				cls(fGetWindow);
				SetColorAMD64(159);
	            cout<<":::   JE Build 1.1.4 (Settings)             "<<endl;
	            SetColorAMD64(143);
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
			    SetColorAMD64(143);
			    cout<<"         ";
			    SetColorAMD64(fPrBtn_00);
				cout<<"Press Button on Bind !!";
				SetColorAMD64(143);
				cout<<"            "<<endl;
			     SetColorAMD64(143);
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"                                            "<<endl;
			    cout<<"   [X] - Path Error Gamepad!(debug)         "<<endl;
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
				SetColorAMD64(240);
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<endl;
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
				SetColorAMD64(15);
				cout<<"PrBtnDl="<<fDlPrbtn<<endl;
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A){f_Kb0 = getch();cout<<"Edit (A)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B){f_Kb1 = getch();cout<<"Edit (B)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X){f_Kb2 = getch();cout<<"Edit (X)?.."<<endl;}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y){f_Kb3 = getch();cout<<"Edit (Y)?.."<<endl;}
				if(GetKeyState('X'))
				{
					fXCon = true;
				}
				else
				{
					fXCon = false;
				}
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
       		
       			cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<"\n\n\n"<<endl;
       		cout<<" Thanks!! How to used my Program!!          \n\n"<<endl;
       		cout<<"Time Used:"<<fLTime(0)<<":"<<fLTime(0)<<":"<<fLTime(0)<<"\n\n "<<endl;
       		cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0;
				cout<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<"\n\n\n"<<endl;
				SetColorAMD64(240);
				cout<<"JE Used RAM:"<<(float)fDataMemUsage() / 1024<<":MiB     Address="<<&fClocksCPU<<endl;
				SetColorAMD64(15);
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
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B){fB++;if(fB > 24){fB = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A){fA++;if(fA > 24){fA = 24;}}
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X){fX++;if(fX > 24){fX = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y){fY++;if(fY > 24){fY = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER){fRBPoint++;if(fRBPoint > 24){fRBPoint = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER){fLBPoint++;if(fLBPoint > 24){fLBPoint = 24;}}
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP){fU++;if(fU > 24){fU = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN){fD++;if(fD > 24){fD = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT){fL++;if(fL > 24){fL = 24;}} 
           if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT){fR++;if(fR > 24){fR = 24;}}
           if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B){fB--;if(fB < 0){fB = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_A){fA--;if(fA < 0){fA = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_Y){fY--;if(fY < 0){fY = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B){fX--;if(fX < 0){fX = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_RIGHT_SHOULDER){fRBPoint--;if(fRBPoint < 0){fRBPoint = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_LEFT_SHOULDER){fLBPoint--;if(fLBPoint < 0){fLBPoint = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_UP){fU--;if(fU < 0){fU = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_DOWN){fD--;if(fD < 0){fD = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_LEFT){fL--;if(fL < 0){fL = 0;}}
		   if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_RIGHT){fR--;if(fR < 0){fR = 0;}}
		   }
	      }

}
