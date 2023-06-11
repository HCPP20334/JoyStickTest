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
	system("mode con cols=108 lines=37");
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
  int64_t fColor_00 = 158;
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
	//string
	string fBuffer0;
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
  //
  HDC fDC = GetDC(GetConsoleWindow());
  string fXinput_Status;
  char *fFileText0 = "R/Text0.txt";
  //char *fFileText1 = "R/Text1.txt"; 
  CXBOXController* xController1;
  CXBOXController* xController2;
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
  HANDLE fGetWindow = GetStdHandle(STD_OUTPUT_HANDLE);
  HWND fHwcon = GetConsoleWindow();
  xController1 = new CXBOXController(1);
  xController2 = new CXBOXController(2);
  xControllerState = (xController1->IsConnected());
  SetWindowLong(fHwcon, GWL_STYLE, GetWindowLong(fHwcon, GWL_STYLE) & WS_VISIBLE);
  	 ifstream fCheckFiles0(fFileText0);
  while(getline(fCheckFiles0,fBuffer0))
  {
  	 	if(fBuffer0.size() > 2160)
  	 	{
  	 			fCheckFiles = true;
		   }
  	 	cls(fGetWindow);
  	 	cout<<"Check Files..."<<endl;
      if(fCheckFiles0.is_open())
  	  {
  		fFiles0 = 1;
  		cout<<"File0:OK"<<endl;
	  }
	  if(!fCheckFiles0.is_open())
  	  {
  		fCheckFiles = false;
  		cout<<"File0:Error"<<endl;
	  }
	  	fAllSize = fAllSize + fBuffer0.size();
	  cout<<"File0:Size:"<<fAllSize<<"/2098"<<endl;
	   }
	    if(fCheckFiles)
	  {
	  	fCheckFiles0.close();
	  	cout<<"Size: "<<fAllSize<<endl;
	  	cout<<"Tab any Key!!"<<endl;
	  	_getch();
	  }
  system("cls");
  for(int64_t fTextLoad = 1;fTextLoad <= 100; fTextLoad++)
  {
  	fAnimPoint = (fTextLoad / 10) - 1;
  	if(xController1->IsConnected())
  	{
  		fXCon = true;
  		fXinput_Status = "Controller 1 is Connected!!";
  		fJEText = fStatus[2];
  		fColorStatus = 10;
	}
	else
  	{
  		fXCon = false;
  		fXinput_Status = "Controller 1 not Connected!!";
  		fDebugMode = false;
  		fColorStatus = 12;
  		
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
	   cout<<fL1;
  	SetColorAMD64(fColorText);
 fLoadMemA(fFileText0,18);
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
   if(!fDebugMode)
 {
 	 	SetColorAMD64(15);
 	 //(fFileText1,11);
	cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
	cout<<fL1<<" Loading Libs...            "<<fL1<<endl;
 cout<<fL1;
  SetColorAMD64(131);
 cout<<fBar[c1];
 SetColorAMD64(15);
 cout<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 	SetColorAMD64(15);
 	 cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 cout<<fL1;
 SetColorAMD64(fColorStatus);
 cout<<fJEText;
 SetColorAMD64(15);
 cout<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 	if(fTextLoad > 100)
 	{
 		fTextLoad = 100;
	}
 }
  if(fDebugMode)
 {
 	//fXCon = true;
 	fJEText = fStatus[2];
 	 	SetColorAMD64(15);
 	 //(fFileText1,11);
	cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
	cout<<fL1<<" Debugger....               "<<fL1<<endl;
 cout<<fL1;
  SetColorAMD64(131);
 cout<<fBar[c1];
 SetColorAMD64(15);
 cout<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 	SetColorAMD64(15);
 	if(fTextLoad > 100)
 	{
 		fTextLoad = 100;
	}
 }
 if(GetKeyState('J') > 0)
 {
 	fXCon = true;
 	fDebugMode = true;
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
 if(fJEColorSetMenu)
 {
  for(fColorsMSet = 1; fColorsMSet > 0;fColorsMSet++)
 	{
 	fRv0++;
  	if(fRv0 == 6)
  	{
  		fRv0 = 0;
  		fRv1++;
  		fColorSet = fRv1;
	}
  	if(fRv1 > 9)
  	{
  		fRv1 = 0;
	}
 		if(fCMlPoint == 0)
 		{
 			 fCMl0A = 130;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl0;
		 }
		 if(fCMlPoint == 1)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 130;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl1;
		 }
		 if(fCMlPoint == 2)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 130;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl2;
		 }
		 if(fCMlPoint == 3)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 130;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl3;
		 }
		 if(fCMlPoint == 4)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 130;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl4;
		 }
		  if(fCMlPoint == 5)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 130;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl5;
		 }
		 if(fCMlPoint == 6)
 		{	
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 130;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl6;
		 }
		 if(fCMlPoint == 7)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 130;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl7;
			
		 }
		 if(fCMlPoint == 8)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 130;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl8;
		 }
		  if(fCMlPoint == 9)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 130;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl9;
		 }
		  if(fCMlPoint == 10)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 130;
			 fCMlBA = 139;
			 fColorText = fCMlA;
		 }
		  if(fCMlPoint == 11)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 130;
			 fColorText = fCMlB;
		 }

 		cls(fGetWindow);
 		SetColorAMD64(135);  
 		cout<<"       Color Settings         "<<endl;
 		SetColorAMD64(130 + fColorSet);  
 		cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl0A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl0);
 		cout<<" Green-white  ";
 		SetColorAMD64(fCMl0A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl1A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl1);
 		cout<<" Blue-white   ";
 		SetColorAMD64(fCMl1A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl2A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl2);
 		cout<<" Red-white    ";
 		SetColorAMD64(fCMl2A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl3A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl3);
 		cout<<" L-Gray-black ";
 		SetColorAMD64(fCMl3A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl4A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl4);
 		cout<<" L-Gray-blue  ";
 		SetColorAMD64(fCMl4A);
 		cout<<"   л   ";
 		SetColorAMD64(240);
 	    SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl5A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl5);
 		cout<<" D-Gray-green ";
 		SetColorAMD64(fCMl5A);
 		cout<<"   л   ";
 	    SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl6A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl6);
 		cout<<" D-Gray-cyan  ";
 		SetColorAMD64(fCMl6A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl7A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl7);
 		cout<<" D-Gray-blue  ";
 		SetColorAMD64(fCMl7A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); ;
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl8A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl8);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMl8A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMl9A);
 		cout<<"   л   ";
 		SetColorAMD64(fCMl9);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMl9A);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMlAA);
 		cout<<"   л   ";
 		SetColorAMD64(fCMlA);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMlAA);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1;
 		SetColorAMD64(fCMlBA);
 		cout<<"   л   ";
 		SetColorAMD64(fCMlB);
 		cout<<" White-black  ";
 		SetColorAMD64(fCMlBA);
 		cout<<"   л   ";
 		SetColorAMD64(130 + fColorSet); 
 		cout<<fL1<<endl;
 		cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
 		SetColorAMD64(134);                //
 		cout<<"       [ENTER]/(A) - OK       "<<endl;
		cout<<"       [W]/(UP) - UP          "<<endl;
		cout<<"       [S]/(DOWN) - Down      "<<endl;
		cout<<"       [R]/(B) - Random       "<<endl;//
		SetColorAMD64(15);
		cout<<"fStack=0x"<<fRegister<<endl;
		cout<<(char)fRegister<<endl;
		if(GetAsyncKeyState('A'))
		{
			Sleep(40);
			fRegister++;
		}
		if(GetAsyncKeyState('D'))
		{
			Sleep(40);
			fRegister--;
		}
 		if(GetAsyncKeyState('R'))
 		{
 			srand(time(0));
 			fCMlPoint = rand() % 11;
		 }
 		if(GetAsyncKeyState(VK_RETURN) || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
 		{
 			system("cls");
 			fColorsMSet = -1;
 			fJEColorSetMenu = false;	
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
 }
 if(GetAsyncKeyState('L'))
 {
 	system("cls");
 	cout<<" Debug Enable..."<<endl;
 	fJEText = fStatus[2];
 	fDebugMode = true;
 	fXCon = true;
 	
 }
 cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 cout<<fL1<<"Build 1.0.9"<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
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
  system("cls");
    for(int64_t fTextLoad1 = 1;fTextLoad1 <= 10000; fTextLoad1++)
  {
  	 if(fJEColorSetMenu)
 {
 for(fColorsMSet = 1; fColorsMSet > 0;fColorsMSet++)
 	{
 			 if(fCMlPoint == 0)
 		{
 			 fCMl0A = 132;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl0;
		 }
		 if(fCMlPoint == 1)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 132;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl1;
		 }
		 if(fCMlPoint == 2)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 132;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl2;
		 }
		 if(fCMlPoint == 3)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 132;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl3;
		 }
		 if(fCMlPoint == 4)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 132;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl4;
		 }
		  if(fCMlPoint == 5)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 132;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl5;
		 }
		 if(fCMlPoint == 6)
 		{	
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 132;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl6;
		 }
		 if(fCMlPoint == 7)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 132;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl7;
			
		 }
		 if(fCMlPoint == 8)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 132;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl8;
		 }
		  if(fCMlPoint == 9)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 132;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl9;
		 }
		  if(fCMlPoint == 10)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 132;
			 fCMlBA = 139;
			 fColorText = fCMlA;
		 }
		  if(fCMlPoint == 11)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 132;
			 fColorText = fCMlB;
		 }

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
 		SetColorAMD64(134);                //
 		cout<<"       [ENTER]/(A) - OK       "<<endl;
		cout<<"       [W]/(UP) - UP          "<<endl;
		cout<<"       [S]/(DOWN) - Down      "<<endl;
		cout<<"       [R]/(B) - Random       "<<endl;//
		SetColorAMD64(15);
		cout<<"fStack=0x"<<fRegister<<endl;
		cout<<(char)fRegister<<endl;
		if(GetAsyncKeyState('A'))
		{
			Sleep(40);
			fRegister++;
		}
		if(GetAsyncKeyState('D'))
		{
			Sleep(40);
			fRegister--;
		}
 		if(GetAsyncKeyState('R'))
 		{
 			srand(time(0));
 			fCMlPoint = rand() % 11;
		 }
 		if(GetAsyncKeyState(VK_RETURN) || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
 		{
 			system("cls");
 			fColorsMSet = -1;
 			fJEColorSetMenu = false;	
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
	     
}
		  if(fTestYBar == 0){fP0 = 0;fP1 = 0;fP2 = 0;fP3 = 0;fP4 = 0;fP5 = 0;fP6 = 0;}    
          if(fTestYBar == 1){fP0 = 0;fP1 = 0;fP2 = 0;fP3 = 0;fP4 = 0;fP5 = 0;fP6 = 1;}
 	      if(fTestYBar == 2){fP0 = 0;fP1 = 0;fP2 = 0;fP3 = 0;fP4 = 0;fP5 = 1;fP6 = 1;}
	  	  if(fTestYBar == 3){fP0 = 0;fP1 = 0;fP2 = 0;fP3 = 0;fP4 = 1;fP5 = 1;fP6 = 1;}
		  if(fTestYBar == 4){fP0 = 0;fP1 = 0;fP2 = 0;fP3 = 1;fP4 = 1;fP5 = 1;fP6 = 1;}    
          if(fTestYBar == 5){fP0 = 0;fP1 = 0;fP2 = 1;fP3 = 1;fP4 = 1;fP5 = 1;fP6 = 1;}
 	      if(fTestYBar == 6){fP0 = 0;fP1 = 1;fP2 = 1;fP3 = 1;fP4 = 1;fP5 = 1;fP6 = 1;}
	  	  if(fTestYBar == 7){fP0 = 1;fP1 = 1;fP2 = 1;fP3 = 1;fP4 = 1;fP5 = 1;fP6 = 1;}
  		cls(fGetWindow);//
  	SetColorAMD64(15);
  	cout<<"\n\n\n";
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"  JoyTest by HCPP                                      "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"  Program to License GNU OpenSource                    "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"  Writtein C++ ->std=c++11 release                     "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"   Press Button ";
  	SetColorAMD64(158);
	  cout<<"(A)";
	  SetColorAMD64(fColorText);
	  cout<<" to Skip                            "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"                                                       "<<endl;
  		SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  			SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(fColorText);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	SetColorAMD64(11);
 SetColorAMD64(15);
 	cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
	cout<<fL1<<"     Test Bar   "<<fL1<<endl;
	SetColorAMD64(15);
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5];
SetColorAMD64(15);
cout<<fL1<<endl;
cout<<fL1;
	SetColorAMD64(138);
cout<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6];
SetColorAMD64(15);
cout<<fL1<<endl;
SetColorAMD64(15);
	cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
	cout<<"Press (B) to test bar"<<endl;
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
  if(GetAsyncKeyState(VK_F6) || xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
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
 	/// XInputEnable(true);
  if(xController1->IsConnected())
  {
  	fRv3++;
  	if(fRv3 > 4)
  	{
  		fRv3 = 0;
  		fRv2++;
  		if(fRv2 > 1) 
  		{
  			fRv2 = 0;
		}
		if(fRv2 == 0)
		{
			fCv0 = 15;
		}
		if(fRv2 == 1)
		{
			fCv0 = 0;
		} 
	  }
  	SetColorAMD64(fCv0);
  	cout<<" Press Button (A) to Skip"<<endl;
  	 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
     {
                fTextLoad1 = fTextLoad1 + 2000;
     }
  }
  else
  {
  	cout<<" Skip [SPACE]"<<endl;
  	cout<<" Color REF:"<<RGB(30,30,30)<<endl;
  	 if(GetAsyncKeyState(VK_SPACE))
     {
 	fTextLoad1 = fTextLoad1 + 1000;
     }
  }
  }
  system("cls");
	for(int64_t fClocksCPU = 1;fClocksCPU > 0;fClocksCPU++)
	{
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
		fLX = fLXPos / 100;
		fLY = fLYPos / 100;
		fRX = fRXPos / 100;
		fRY = fRYPos / 100;
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
			fErrorColor = 158;
			cout<<(char)10<<endl;
	  	SetColorAMD64(15);
  	cout<<"\n\n\n";
  	SetColorAMD64(15);
  	cout<<"\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t";
  	SetColorAMD64(158);
  	cout<<"      Please plug to Xbox360 Controller!!               "<<endl;
  	SetColorAMD64(15);
  	SetColorAMD64(15);
  	cout<<"\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	SetColorAMD64(15);
  	cout<<"\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	cout<<"AnimPoint:"<<fAnimDuration0<<endl;
		}
		SetColorAMD64(15);
		cout<<"\n\n";
		SetColorAMD64(15);
		if(fXCon)
		{
	if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER && xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
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
 			 if(fCMlPoint == 0)
 		{
 			 fCMl0A = 132;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl0;
		 }
		 if(fCMlPoint == 1)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 132;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl1;
		 }
		 if(fCMlPoint == 2)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 132;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl2;
		 }
		 if(fCMlPoint == 3)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 132;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl3;
		 }
		 if(fCMlPoint == 4)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 132;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl4;
		 }
		  if(fCMlPoint == 5)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 132;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl5;
		 }
		 if(fCMlPoint == 6)
 		{	
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 132;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl6;
		 }
		 if(fCMlPoint == 7)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 132;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl7;
			
		 }
		 if(fCMlPoint == 8)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 132;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl8;
		 }
		  if(fCMlPoint == 9)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 132;
			 fCMlAA = 139;
			 fCMlBA = 139;
			 fColorText = fCMl9;
		 }
		  if(fCMlPoint == 10)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 132;
			 fCMlBA = 139;
			 fColorText = fCMlA;
		 }
		  if(fCMlPoint == 11)
 		{
 			 fCMl0A = 139;
			 fCMl1A = 139;
			 fCMl2A = 139;
			 fCMl3A = 139;
			 fCMl4A = 139;
			 fCMl5A = 139;
			 fCMl6A = 139;
			 fCMl7A = 139;
			 fCMl8A = 139;
			 fCMl9A = 139;
			 fCMlAA = 139;
			 fCMlBA = 132;
			 fColorText = fCMlB;
		 }

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
 		SetColorAMD64(134);                //
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
 if(fCR_Error)
		{
			Beep(60,1000);
		//	system("cls");
			for(int64_t fRenderWindow_Error = 1;fRenderWindow_Error > 0; fRenderWindow_Error++)
			{
				SetColorAMD64(71);
				cls(fGetWindow);
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fY<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fX<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fA<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fB<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fU<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fD<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fR<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fL<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fRBPoint<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fLBPoint<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fLY<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fRY<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fLX<<endl;
				cout<<"Occured Value!! Exception: Stack_frame:"<<&fRX<<endl;
				SetColorAMD64(15);
				cout<<" Press [ENTER] To Restart   [SPACE]  - Continue [Z + X] - Continue and Fix         "<<endl;
				if(GetAsyncKeyState(VK_RETURN))
				{
					main(0,(char**)"JE");
				}
				if(GetAsyncKeyState(VK_SPACE))
				{
					fCR_Error = false;
					fRenderWindow_Error = -1;
					
				}
				if(GetAsyncKeyState('Z') && GetAsyncKeyState('X'))
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
			system("cls");
		}
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
		if(fLY > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fRY > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fLX > 24){fCR_Error = true;} else{fCR_Error = false;}
		if(fRX > 24){fCR_Error = true;} else{fCR_Error = false;}
		cout<<"Time Used:"<<fTimeStr<<endl;
		cout<<"FPS:"<<fGetFrames<<endl;
		SetColorAMD64(139);
		cout<<"Program->RAM:"<<fDataMemUsage()<<"block memory: Address="<<&fClocksCPU<<endl;
	       xController1->Vibrate(fLTPos * 100,fRTPos * 100);
			fErrorColor = 0;
		SetColorAMD64(fColor_00);
	    cout<<" Button Up                               Button (A)                "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fU];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(fColorBar);
		cout<<fBar[fA]<<endl;
			SetColorAMD64(fColor_00);
	    cout<<" Button Down                             Button (X)                "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fD];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(fColorBar);
		cout<<fBar[fX]<<endl;
			SetColorAMD64(fColor_00);
	    cout<<" Button Left                             Button (Y)                "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fL];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(fColorBar);
		cout<<fBar[fY]<<endl;
			SetColorAMD64(fColor_00);
	    cout<<" Button Right                            Button (B)                "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fR];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(fColorBar);
		cout<<fBar[fB]<<endl;
			SetColorAMD64(fColor_00);
	    cout<<" axis LT                                 axis (RT)                 "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fLTPoint];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(fColorBar);
		cout<<fBar[fRTPoint]<<endl;
			SetColorAMD64(fColor_00);
	    cout<<" Button LB                              Button RB                "<<endl;
		SetColorAMD64(fColorBar);
		cout<<fBar[fLBPoint];
		SetColorAMD64(fColor_00);
		cout<<"         ";
		SetColorAMD64(139);
		cout<<fBar[fRBPoint]<<endl;
		SetColorAMD64(15);
		cout<<"LX+:"<<fLX<<" LY+:"<<fLY<<" RX+:"<<fRX<<" RY+:"<<fRY<<endl;
		cout<<"LX-:"<<fLXAxisPoint<<" LY-:"<<fLYAxisPoint<<" RX-:"<<fRXAxisPoint<<" RY-:"<<fRYAxisPoint<<endl;
		cout<<"LT:"<<fLTPos<<" RT:"<<fRTPos<<" LT Point:"<<(fLTPos / 10)<<" RT Point:"<<(fRTPos / 10)<<endl;
		cout<<fL1<<"Xbox ";
		SetColorAMD64(10);
		cout<<"(A)";
		SetColorAMD64(15);
		cout<<" -> (";
		SetColorAMD64(11);
		cout<<"X";
		SetColorAMD64(15);
		cout<<") DualShock "<<fL1<<endl;
			cout<<fL1<<"Xbox ";
			SetColorAMD64(3);
		cout<<"(X)";
		cout<<" -> (";
		SetColorAMD64(4);
		cout<<(char)254;
		SetColorAMD64(15);
		cout<<") DualShock "<<fL1<<endl;
			cout<<fL1<<"Xbox ";
			SetColorAMD64(14);
		cout<<"(Y)";
		cout<<" -> (";
		SetColorAMD64(11);
		cout<<(char)30;
		SetColorAMD64(15);
		cout<<") DualShock "<<fL1<<endl;
				cout<<fL1<<"Xbox ";
				SetColorAMD64(4);
		cout<<"(B)";
		SetColorAMD64(15);
		cout<<" -> (";
		SetColorAMD64(4);
		cout<<"O";
		SetColorAMD64(15);
		cout<<") DualShock "<<fL1<<endl;
	    }
	    SetColorAMD64(15);
 cout<<fL2<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL3<<endl;
 cout<<fL1<<"Build 1.0.9 | (LS) + (RS) - Color Settings  "<<fL1<<endl;
 cout<<fL1<<" F1 - RESET PROGRAM (BACK)/[ESC]- Exit Press"<<fL1<<endl;
 cout<<fL1<<"("<<fChUp<<") + LX axis to 32 - to DevMode            "<<fL1<<endl;
 cout<<fL4<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL0<<fL5<<endl;
	    if(fAxisTest)
	    {
	    	if(fLY > 24)
	    	{
	    		fLY = 24;
			}
			if(fLX > 24)
	    	{
	    		fLX = 24;
			}
			if(fLX < 0)
			{
				fLXM = fLX * (-1);
				SetColorAMD64(fLXM + 100);
				cout<<"-X"<<fBar[fLXM]<<endl;
				SetColorAMD64(15);
			}
			if(fLX < 0)
			{
				fLXM = fLX * (-1);
				cout<<"-Y"<<fBar[fLYM]<<endl;
			}
	    	if(fLX > 0)
	    	{
	    	cout<<"Y"<<fBar[fLY]<<endl;
	        cout<<"X"<<fBar[fLX]<<endl;
	        TextOut(fDC,fLX,fLY," ",1);
			}
		}
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
		if(fDebugger)
		{
			fDebugColorMode0 = fColor_00;
			fDebugColorMode = 0;
			SetColorAMD64(7 - fDebugColorMode);
			cout<<"("<<fChUp<<")";
			SetColorAMD64(15 - fDebugColorMode);
			cout<<" + ";
			SetColorAMD64(10 - fDebugColorMode);
			cout<<"(A)";
			SetColorAMD64(15 - fDebugColorMode);
			cout<<" - to Color++"<<endl;
			SetColorAMD64(7 - fDebugColorMode);
			cout<<"("<<fChDn<<")";
			SetColorAMD64(15 - fDebugColorMode);
			cout<<" + ";
			SetColorAMD64(10 - fDebugColorMode);
			cout<<"(A)";
			SetColorAMD64(15 - fDebugColorMode);
			cout<<" - to Color--"<<endl;
			cout<<"ColorOffset:"<<fColor_00<<endl;
			if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
       	    {
		    	if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
       	        {
       	        	Sleep(50);
		    		fColorBar++;
				}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
       	        {
       	        	Sleep(50);
		    		fColorBar--;
				}
		   }
		}
		if(GetAsyncKeyState('P'))
		{
		MessageBox(GetConsoleWindow(),(fErrors[1].c_str()),"JE:Error!! Bulid: 1.0.9",MB_ICONWARNING);
		cout<<"Exception Error ->fStack_frame0="<<GetConsoleWindow()<<endl;
		cout<<"Exception Error ->fStack_frame1="<<GetDC(GetConsoleWindow())<<endl;
		cout<<"Exception Error ->fStack_frame2="<<&xController1<<"->JoyStick.h"<<endl;
		}
		if(GetAsyncKeyState('O'))
		{
			for(int64_t fkbEmuAccept = 1;fkbEmuAccept > 0;fkbEmuAccept++)
			{
				cls(fGetWindow);
				cout<<"  Function Joy2KeyBd not stable!!"<<endl;
				cout<<" [ Yes](A)                 [No](B)"<<endl;
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
				{
					kbEmu = true;
					cout<<"Emulator Enable!!"<<endl;
					fkbEmuAccept = -1;
				}
				if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B)
				{
					kbEmu = false;
					cout<<"Emulator Disable!!"<<endl;
					fkbEmuAccept = -1;
				}
			}
			system("cls");
		}
				cout<<"Frames:"<<fFrames<<endl;
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
