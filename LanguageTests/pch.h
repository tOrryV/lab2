//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

struct CustomStruct
{
	int value;
};

void increment(int arg);
void increment(CustomStruct arg);

void increment_ref(CustomStruct& arg);
void increment_arr(int arr[], const unsigned int size);