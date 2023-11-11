#include <iostream>
#include <string>
#include <windows.h>
#include <urlmon.h>
#include <clocale>
#include "Colors.h"
#include <tchar.h>
using namespace std;

int64_t SzWindow(int64_t fSzX,int64_t fSzY)
{
	HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r);
    MoveWindow(hWindowConsole, r.left, r.top, fSzX, fSzY, TRUE);
}
int main (int argc, char *argv[])
{
	int64_t dBuffer = 0;
	int64_t dTimeout = 0;
	int64_t dSizeOnePkg = 0;
	const TCHAR dURL[] = _T("https://github.com/HCPP20334/JoyStickTest/releases/download/JE/JE.exe");
    const TCHAR dFllePath[] = _T("./JE.exe");
    bool bDebugST = false;
	// 
	SzWindow(460,200);-
	   SetFontA(L"Consolas",5,20);
	   SetColorAMD64(249);
		cout<<":: JE Updater                                  "<<endl;
		SetColorAMD64(143);
		cout<<"                                               "<<endl;
		cout<<"  Download:./releases/download/JE/JE.exe       "<<endl;
		cout<<"  File:"<<dFllePath<<"                                "<<endl;
		cout<<"                                               "<<endl;
		SetColorAMD64(249);
		cout<<":: by HCPP                                     "<<endl;
		SetColorAMD64(15);
       if(!bDebugST)
       {
       				 HRESULT fDwChannel_0 = URLDownloadToFile(NULL,dURL,dFllePath,0,NULL );
	 if(SUCCEEDED(fDwChannel_0))
	 {
	 	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	 	SetColorAMD64(143);
	 	cout<<"\t";
	 	SetColorAMD64(159);
	 	cout<<"                                      "<<endl;
	 	SetColorAMD64(143);
	 	cout<<"\t";
	 	SetColorAMD64(159);
	 	cout<<"             Download:OK!!            "<<endl;
	 	SetColorAMD64(143);
	 	cout<<"\t";
	 	SetColorAMD64(159);
	 	cout<<"                                      "<<endl;
	 	SetColorAMD64(143);
	 	cout<<"\t";
	 	SetColorAMD64(15);
	 	Sleep(1000);
	 }
	 if(FAILED(fDwChannel_0))
	 {
	 		cls(GetStdHandle(STD_OUTPUT_HANDLE));
	 	SetColorAMD64(143);
	 	cout<<"\n\n\t\t";
	 	SetColorAMD64(71);
	 	cout<<"                                      "<<endl;
	 	SetColorAMD64(143);
	 	cout<<"\t\t";
	 	SetColorAMD64(71);
	 	cout<<"   Error connection to Server         "<<endl;
	 	SetColorAMD64(143);
	 	cout<<"\t\t";
	 	SetColorAMD64(71);
	 	cout<<"                                      "<<endl;
	 	SetColorAMD64(15);
	 	Sleep(1000);
	 }
	   }
}
