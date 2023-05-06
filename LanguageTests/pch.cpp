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


