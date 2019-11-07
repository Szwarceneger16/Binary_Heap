#include <iostream>
#include <random>
#include <functional>
#include "heap.h"

void print(int const a)
{
	std::cout << a << ", ";
}

bool cmp2(int const a, int const b)
{
	return a < b;
}

int main()
{
	heap<int> moj;

	for (short i = 0; i < 7; i++)
	{
		moj.insert(rand() % 30, cmp2);

	}

	moj.print(print);
}
