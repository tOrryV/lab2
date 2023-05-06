#include "pch.h"

const unsigned int ALLOC_SIZE = 1 << 10;

TEST(AllocationTests, StackAllocationTest) {
	char stackAllocatedData[ALLOC_SIZE];
	ASSERT_EQ(sizeof(stackAllocatedData), ALLOC_SIZE);
}

TEST(AllocationTests, HeapAlocationTest)
{
	char* heapAllocatedData = new char[ALLOC_SIZE];
	ASSERT_EQ(sizeof(char*), sizeof(heapAllocatedData));
	delete[] heapAllocatedData;
}

TEST(ValueTypeTests, PrimitiveTypeTest)
{
	int var = 10;
	increment(var);
	ASSERT_EQ(var, 10);
}

TEST(ValueTypeTests, CompoundTypeTest)
{
	CustomStruct var {10};
	increment(var);
	ASSERT_EQ(var.value, 10);
}

TEST(ReferenceTypeTests, ArrayTypeTest)
{
	int arr[3] = {1, 2, 3};
	increment_arr(arr, 3);
	for (int i = 0; i < 3; i++)
	{
		ASSERT_EQ(arr[i], i + 2);
	}
}

TEST(ReferenceTypeTests, CompoundTypeTest)
{
	CustomStruct customStruct{ 10 };
	increment_ref(customStruct);
	ASSERT_EQ(customStruct.value, 11);
}

TEST(MemoryFragmentationTest, AllocateAndFree) {
	for (int i = 0; i < 1000; i++) {
		int* p = new int;
		EXPECT_TRUE(p != nullptr); 
		delete p;
	}
}

TEST(MemoryFragmentationTest, AllocateAndFreeArray) {
	for (int i = 0; i < 1000; i++) {
		int* p = new int[10];
		EXPECT_TRUE(p != nullptr); 
		delete[] p;
	}
}

TEST(MemoryFragmentationTest, AllocateAndFreeRandomSizes) {
	int sizes[1000];
	for (int i = 0; i < 1000; i++) {
		sizes[i] = rand() % 100 + 1; 
	}

	for (int i = 0; i < 1000; i++) {
		int* p = new int[sizes[i]];
		EXPECT_TRUE(p != nullptr);
		delete[] p;
	}
}
