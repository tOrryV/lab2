//
// pch.cpp
//

#include "pch.h"

void increment(int arg)
{
	arg++;
}

void increment(CustomStruct arg)
{
	arg.value++;
}

void increment_ref(CustomStruct& arg)
{
	arg.value++;
}

void increment_arr(int arr[], const unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i]++;
	}
}

unsigned long long getTotalSystemMemory()
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	return status.ullTotalPhys;
}



size_t getCurrentMemoryUsage() {
	HANDLE process = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(process, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
	return pmc.PrivateUsage;
}