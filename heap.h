#pragma once
#include "DynamicArray.h"
#include <algorithm>
#include <iostream>

//#define DEBUG


template <class T>
class heap :
	private DynamicArray<T>
{


public:
	heap() {};
	/*heap(T val) : max(1), array_pointer(new T[1]) { array_pointer[0] = val; }*/

	void insert(T val, bool (*fun)(T const, T const))
	{
		this->add(val);
		long i = this->get_current(),j=0;
		while (i > 0)
		{
			j = ((i - 1) / 2);
			if (fun(this->get_element(j), this->get_element(i)))
			{
				std::iter_swap(this->get_pointer(i), this->get_pointer(j));
				i = j;
			}
			else break;
		}
	}

	T pop(bool (*fun)(T const, T const))
	{
		T tmp = this->get_element(0);
		try
		{
			this->get_element(0) = this->pop_back();
		}
		catch (const DynamicArray_exceptions& e)
		{
			throw e;
		}
		
		auto cur = this->get_current();

		long lc = 0, rc = 0, max = 0,max_prev = 0;
		lc = 2 * max + 1; rc = 2 * max + 2;
		
		while (rc < cur)
		{
#ifdef DEBUG
			this->print(printer);
			std::cout << std::endl;
#endif // DEBUG
			fun(this->get_element(lc), this->get_element(rc)) ? max = rc : max = lc;
			if (fun(this->get_element(max_prev), this->get_element(max)))
			{
				std::iter_swap(this->get_pointer(max), this->get_pointer(max_prev));
			}
			else break;
			max_prev = max;
			lc = 2 * max + 1; rc = 2 * max + 2;

		}

		if (lc < cur)
		{
			if (fun(this->get_element(max_prev), this->get_element(lc)))
			{
				std::iter_swap(this->get_pointer(max), this->get_pointer(max_prev));
			}
		}

		return tmp;
	}

	void erase(void)
	{
		DynamicArray<T>::erase();
	}

	void erase_ptr(void)
	{
		DynamicArray<T>::erase_ptr();
	}

	void print(void (*fun)(T const))
	{
		DynamicArray<T>::print(fun);
	}
	void print(void (*fun)(T const),long dlg)
	{
		DynamicArray<T>::print(fun, dlg);
	}

};

