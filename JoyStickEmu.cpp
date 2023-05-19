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
	system("mode con cols=120 lines=35");
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
  int64_t fColorBar = 139;
  int64_t fExP = 0;
  int64_t fDebugIgnoreXiputError = 0;
  ///
  char fChUp = 24;
  char fChDn = 25;
  bool fDebugger = false;
  bool bKeyPresed;
  bool fXCon;
  bool fAxisTest = false;
  bool kbEmu = false;
  bool xControllerState = true;
  bool fClear = true;
  bool fExSh = false;
  bool fDebugMode = true;
  //
  HDC fDC = GetDC(GetConsoleWindow());
  string fXinput_Status;
  char *fFileText0 = "R/Text0.txt";
  char *fFileText1 = "R/Text1.txt"; 
  CXBOXController* xController1;
  CXBOXController* xController2;
  string fTimeStr;
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
  //Engine fBuffer;
  HANDLE fGetWindow = GetStdHandle(STD_OUTPUT_HANDLE);
  HWND fHwcon = GetConsoleWindow();
  xController1 = new CXBOXController(1);
  xController2 = new CXBOXController(2);
  xControllerState = (xController1->IsConnected());
  SetWindowLong(fHwcon, GWL_STYLE, GetWindowLong(fHwcon, GWL_STYLE) & WS_VISIBLE);
  for(int64_t fTextLoad = 1;fTextLoad <= 100; fTextLoad++)
  {
  	fAnimPoint = (fTextLoad / 10) - 1;
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
  	SetColorAMD64(11);
 gRenderText(fFileText0,18);
 SetColorAMD64(15);
 if(GetAsyncKeyState('1'))
 {
 	Sleep(80);
 	system("start https://github.io/HCPP20334/JoyStickTest");
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
 	cout<<"Error Xbox360 Controller not Connected!![error code:0x0F]"<<endl;
 	
 	fTextLoad  = 10;
 	if(fTextLoad > 10)
 	{
 		fTextLoad = 10;
	}
 }
  }
  if(fDebugMode)
 {
 	cout<<"Error Xbox360 Controller not Connected!![error code:0x0F]"<<endl;
 	
 	if(fTextLoad > 100)
 	{
 		fTextLoad = 100;
	}
 }
 if(GetAsyncKeyState('L'))
 {
 	cout<<" Debug Enable..."<<endl;
 	fDebugMode = true;
 	  fTextLoad = 1000;
 }
 if(!GetAsyncKeyState(VK_ESCAPE))
 {
 	fExP--;
 	if(fExP < 0)
 	{
 		fExP = 0;
	 }
 }
 if(GetAsyncKeyState(VK_ESCAPE))
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
       		cout<<"_______________________________________________________________"<<endl;
       		SetColorAMD64(71);
       		if(fExSh)
       		{
       			cout<<"                                                               "<<endl;
       		cout<<"                                                               "<<endl;
       		cout<<"               Thanks!! How to used my Program!!               "<<endl;
       		cout<<"                                                               "<<endl;
       		cout<<"                                                               "<<endl;
			   }
       		cout<<"_______________________________________________________________"<<endl;
       		SetColorAMD64(15);
       	       exit(0);  
	}
 }
cout<<" Xinput Status:"<<fXinput_Status<<endl;
cout<<" Battery Level:"<<fBatLevel<<endl;
cout<<"Exit Hold Esc";
 SetColorAMD64(131);
cout<<fBar[fExP]<<endl;
SetColorAMD64(15);
cout<<"             ";
 SetColorAMD64(131);
cout<<fBar[fExP]<<endl;
SetColorAMD64(15);
 cout<<"Loading Xinput.dll.. "<<fTextLoad<<"%"<<endl;
 SetColorAMD64(131);
 cout<<fBar[c1];
 SetColorAMD64(15);
 cout<<fTextLoad<<"%"<<endl;
  SetColorAMD64(131);
 cout<<fBar[c1]<<endl;
 SetColorAMD64(15);
 cout<<" Test Bar Press (B) and R key Mouse"<<endl;
SetColorAMD64(130);
cout<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<endl;
cout<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<endl;
cout<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<endl;
cout<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<endl;
cout<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<endl;
cout<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<endl;
cout<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<endl;
//
//<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]<<fBarY[fP0]
//<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]<<fBarY[fP1]
//<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]<<fBarY[fP2]
//<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]<<fBarY[fP3]
//<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]<<fBarY[fP4]
//<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]<<fBarY[fP5]
//<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]<<fBarY[fP6]
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
      if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B && GetAsyncKeyState(VK_RBUTTON))
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
     if(xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B && GetAsyncKeyState(VK_RBUTTON))
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
  		cls(fGetWindow);//
  	SetColorAMD64(15);
  	cout<<"\n\n\n";
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"  JoyTest by HCPP                                      "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"  Program to License GNU OpenSource                    "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"  Writtein C++ ->std=c++11 release                     "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"   Press Button (A) to Skip                            "<<endl;
  	SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  		SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  			SetColorAMD64(15);
  	cout<<"\t\t\t";
  	SetColorAMD64(158);
  	cout<<"                                                       "<<endl;
  	SetColorAMD64(15);
  	SetColorAMD64(11);
 SetColorAMD64(15);
 	/// XInputEnable(true);
  if(xController1->IsConnected())
  {
  	cout<<" Press Button (A) to Skip"<<endl;
  	 if(xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A)
     {
                fTextLoad1 = fTextLoad1 + 1000;
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
		cout<<"Time Used:"<<fTimeStr<<endl;
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
		cout<<"Xbox ";
		SetColorAMD64(10);
		cout<<"(A)";
		SetColorAMD64(15);
		cout<<" -> (";
		SetColorAMD64(11);
		cout<<"X";
		SetColorAMD64(15);
		cout<<") DualShock "<<endl;
			cout<<"Xbox ";
			SetColorAMD64(3);
		cout<<"(X)";
		cout<<" -> (";
		SetColorAMD64(4);
		cout<<(char)254;
		SetColorAMD64(15);
		cout<<") DualShock "<<endl;
			cout<<"Xbox ";
			SetColorAMD64(14);
		cout<<"(Y)";
		cout<<" -> (";
		SetColorAMD64(11);
		cout<<(char)30;
		SetColorAMD64(15);
		cout<<") DualShock "<<endl;
				cout<<"Xbox ";
				SetColorAMD64(4);
		cout<<"(B)";
		SetColorAMD64(15);
		cout<<" -> (";
		SetColorAMD64(4);
		cout<<"O";
		SetColorAMD64(15);
		cout<<") DualShock "<<endl;
	    }
	    SetColorAMD64(15);
	    cout<<" F1 - RESET PROGRAM (BACK)/[ESC]- Exit Press ("<<fChUp<<") + LX axis to 32 - to DevMode "<<endl;
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
				Sleep(50);
			fChUp++;
			cout<<(int)fChUp<<endl;
			fAxisTest = true;
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
