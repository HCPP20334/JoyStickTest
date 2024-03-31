#include <string>
#include<iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include<sstream>
using namespace std;

bool gRenderText(char *File,uint64_t gLines)
{
	string gTitle;
	int64_t gLine = 0;
   ifstream bTitleFile(File);
   bTitleFile.is_open();
   if(!bTitleFile)
   {
   	cout<<"No such File Directory ->"<<File<<endl;
   }
   while(getline(bTitleFile,gTitle))
   {
   	gLine++;
   	if(gLine > gLines)
   	{
   	return 0;	
	}
   	cout<<"\t\t"<<gTitle<<endl;
   }
}
string GetFileFormat(string file)
{
  
	string s1;
	string s2;
	string s3;
	string s4;
	string FileFormat;
	string m_format;
    s1 = file[file.size() - 3];
    s2 = file[file.size() - 2];
    s3 = file[file.size() - 1];
    FileFormat = (s1 + s2 + s3).c_str();
    if(s1 != ".")
    {
      FileFormat = ("."+s1 + s2 + s3).c_str();
	}
   return FileFormat;
}
bool GetRollText(string text)
{
	
	size_t sym; // formula  
	size_t s_min = 0;
	int64_t tick =0 ;
	size_t Errors;
    sym = text.size()  - s_min ;
  for(int k = 1;  k > 0 ;k++)
  {
   	tick++;
return text[sym + s_min--];
  if(text == "")
   { 
    Errors++;
   }
  if(tick == text.size() + 1) 
  { 
  cout<<"\n";
  return TRUE;
  }
 }
}
bool GetFileSize(string FileName) /// Must errors 
{
	uint64_t m_memFile = 0 ;
    uint64_t m_memFile1 =0 ;
	uint64_t  po = 0;
string m_file_text;
ifstream file(FileName);
file.is_open();
while(getline(file,m_file_text))
{
m_memFile = FileName.size();
m_memFile1=m_file_text.size();
po++;
cout<<m_memFile + m_memFile1<<"Bytes"<<endl;
if(po == m_file_text.size())
{
return 1;
}
}

}
bool intSize(const int num)
{
stringstream s_text;
string text;
s_text << num;
s_text >> text;
cout<<text.size();
}
bool DoubleSize(const double num)
{
stringstream s_text;
string text;
s_text << num;
s_text >> text;
cout<<text.size();
}
bool floatSize(const float num)
{
stringstream s_text;
string text;
s_text << num;
s_text >> text;
cout<<text.size();
}

//ffff.c  

