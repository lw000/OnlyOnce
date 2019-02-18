#include "pch.h"
#include "OnlyOnce.h"
#include <iostream>
#include <thread>
#include <future>


void TestOnlyOnce() {
	static int i = 0;
	std::cout << "i = " << i++ << std::endl;
}

OnlyOnce Once;

int main()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::async(std::launch::async, []() {
			Once.Do(TestOnlyOnce);
		});
	}

	system("pause");
}