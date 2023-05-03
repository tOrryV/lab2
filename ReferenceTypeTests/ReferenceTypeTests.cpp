#include <cassert>

class CustomClass {
public:
	CustomClass(int value) : value(value) {}
	int getValue() const {
		return value;
	}

	void increment() {
		value++;
	}
private:
	int value;
};

void incrementEach(int* array, const int length) {
	for (int i = 0; i < length; i++) {
		array[i]++;
	}
}

void increment(CustomClass& customClass) {
	customClass.increment();
}

int main() {
	int array[] = { 1, 2, 3 };
	incrementEach(array, 3);
	assert(array[0] == 2);
	assert(array[1] == 3);
	assert(array[2] == 4);
	CustomClass customClass(10);
	increment(customClass);
	assert(customClass.getValue() == 11);

	return 0;
}