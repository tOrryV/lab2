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

TEST(MemoryFragmentationTests, MemoryFragmentationTest)
{
    const long long chunkSize = 1024 * 1024;
    char* mem[100];

    
    for (int i = 0; i < 100; ++i) {
        mem[i] = new char[chunkSize];
    }

    
    for (int i = 0; i < 100; i += 2) {
        delete[] mem[i];
        mem[i] = nullptr;
        
    }

    
    for (int i = 0; i < 100; i += 2) {
        mem[i] = new (std::nothrow) char[chunkSize * chunkSize];
        EXPECT_TRUE(mem[i] == nullptr);
        if (mem[i] == nullptr) 
        {
            EXPECT_TRUE(true);
        }
        else {
            EXPECT_TRUE(false);
        }
    }

    
    for (int i = 0; i < 100; i++) {
        delete[] mem[i];
    }
}