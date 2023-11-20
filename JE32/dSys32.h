//GetSySInfo Lib by HCPP 2023
#include <windows.h>
#include <sysinfoapi.h>
#include <stdint.h>//-
#include <string>
int32_t ps_apiL(int64_t fps_count);
int32_t fPerfomanceInfo(int64_t fPdataId);
int32_t fMemStatus(int64_t fMData_0);
int32_t fLTime(int64_t fLtData);
int32_t CPUArch();
string fCPUType();

/*
 * C++11 MinGW Compiler
 * for work add to Projects libpsapi.a & VS -> add #pragma comment(lib, "psapi.lib");
  func ps_apiL - send Faulting Pc and Faulting Va
  func fPerfomanceInfo return Perf Call Info
  func fMemStatus return call mem data's 
  func fLTTime sen Local Time
  func CPUArch send call cpu_bit's
  func fCPUType return cpu_type ('AMD x64','Intel x86')
 */
int32_t ps_apiL(int32_t fps_count)
{
	PSAPI_WS_WATCH_INFORMATION fPs_data;
	GetWsChanges(GetCurrentProcess(),&fPs_data,sizeof(fPs_data));
	if(!fps_count){
		fPs_data.FaultingPc;
	}
	if(fps_count){
		fPs_data.FaultingVa;
	}
}
int32_t fPerfomanceInfo(int32_t fPdataId)
{
    PERFORMANCE_INFORMATION	fPdata0A;
    fPdata0A.cb = sizeof(fPdata0A);
	GetPerformanceInfo(&fPdata0A,sizeof(fPdata0A));
	if(fPdataId == 1){
		return fPdata0A.CommitLimit;
	}
	if(fPdataId == 2){
		return fPdata0A.CommitPeak;
	}
	if(fPdataId == 3){
		return fPdata0A.CommitTotal;
	}
	if(fPdataId == 4){
		return fPdata0A.KernelNonpaged;
	}
	if(fPdataId == 5){
		return fPdata0A.KernelPaged;
	}
	if(fPdataId == 6){
		return fPdata0A.KernelTotal;
	}
	if(fPdataId == 7){
		return fPdata0A.PageSize;
	}
	if(fPdataId == 8){
		return fPdata0A.PhysicalAvailable;
	}
	if(fPdataId == 9){
		return fPdata0A.PhysicalTotal;
	}
	if(fPdataId == 10){
		return fPdata0A.ProcessCount;
	}
	if(fPdataId == 11){
		return fPdata0A.SystemCache;
	}
	if(fPdataId == 12){
		return fPdata0A.ThreadCount;
	}
}
int32_t fMemStatus(int32_t fMData_0)
{
	MEMORYSTATUSEX fMemState_0A;
	GlobalMemoryStatusEx(&fMemState_0A);
	if(fMData_0 == 0){
	return fMemState_0A.dwLength;
	}
	if(fMData_0 == 1){
	return fMemState_0A.dwMemoryLoad;
	}
	if(fMData_0 == 2){
	return fMemState_0A.ullAvailExtendedVirtual;
	}
	if(fMData_0 == 3){
	return fMemState_0A.ullAvailPageFile;
	}
	if(fMData_0 == 4){
	return fMemState_0A.ullAvailPhys;
	}
	if(fMData_0 == 5){
	return fMemState_0A.ullAvailVirtual;
	}
	if(fMData_0 == 6){
	return fMemState_0A.ullTotalPageFile;
	}
	if(fMData_0 == 7){
	return fMemState_0A.ullTotalPhys;
	}
	if(fMData_0 == 8){
	return fMemState_0A.ullTotalVirtual;
	}
}
int32_t fLTime(int32_t fLtData)
{
	SYSTEMTIME  fSys_time;
	GetLocalTime(&fSys_time);
	if(fLtData == 0){
	return fSys_time.wHour;
	}
	if(fLtData == 1){
	return fSys_time.wMinute;
	}
	if(fLtData == 2){
	return fSys_time.wSecond;
	}
	
}
int32_t CPUArch()
{
	SYSTEM_INFO h_sys;
	GetSystemInfo(&h_sys);
	if(h_sys.wProcessorArchitecture == 9){
		return 64;
	}
	if(h_sys.wProcessorArchitecture == 6){
		return 32;
	}
}
string fCPUType()
{
	SYSTEM_INFO cpu;
	GetSystemInfo(&cpu);
	if(cpu.dwProcessorType == PROCESSOR_AMD_X8664){
		return "AMD x64";
	}
	if(cpu.dwProcessorType == PROCESSOR_INTEL_486){
		return "Intel x86";
	}
	else
	{
		return to_string(cpu.dwProcessorType);
	}
}
