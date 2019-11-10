#include <iostream>
#include <random>
#include <time.h>
#include <functional>
#include "heap.h"

//void printer(int const a)
//{
//	std::cout << a << ", ";
//}

void printer(int const a)
{
	std::cout << a << ", ";
}

bool cmp2(int const a, int const b)
{
	return a < b;
}

int main()
{
	//heap<int> moj;
	//srand(NULL);

	//for (short i = 0; i < 20; i++)
	//{
	//	moj.insert(rand() % 30, cmp2);
	//}

	//moj.print_(printer);
	//std::cout << std::endl;

	//std::cout << moj.pop(cmp2) << " | ";

	//moj.print_(printer);
	//std::cout << std::endl;

	//std::cout << moj.pop(cmp2) << " | ";

	//moj.print_(printer);
	//std::cout << std::endl;

	//std::cout << moj.pop(cmp2) << " | ";

	//moj.print_(printer);
	//std::cout << std::endl;
	//moj.erase_();


	const int MAX_ORDER = 4;
	heap<int> heapp;
	clock_t t1, t2;
	srand(NULL);

	for (int o = 0; o <= MAX_ORDER; o++)
	{
		const int n = pow(10, o);
		

		t1 = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % 100000;
			heapp.insert(a, cmp2);
		}
		t2 = clock();

		heapp.print(printer, 4);
		std::cout << std::endl << "  Czas dodawania: " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << std::endl;

		t1 = clock();
		for (int i = 0; i < n; i++)
		{
			heapp.pop(cmp2);
		}
		t2 = clock();
		heapp.print(printer, 4);
		std::cout << std::endl << "  Czas pobierania: " << (double(t2) - double(t1)) / CLOCKS_PER_SEC << std::endl;
		heapp.erase();
		std::cout << "----------------------------------------------------------" << std::endl;
	}
	return 0;
}
