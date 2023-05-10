//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <chrono>
#include <Windows.h>
#include <psapi.h>

struct CustomStruct
{
	int value;
};

void increment(int arg);
void increment(CustomStruct arg);

void increment_ref(CustomStruct& arg);
void increment_arr(int arr[], const unsigned int size);

unsigned long long getTotalSystemMemory();
size_t getCurrentMemoryUsage();