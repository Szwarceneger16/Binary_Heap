#include <cstdio>
#include <string>


class DynamicArray_exceptions
{
	short i;
public:
	explicit DynamicArray_exceptions(short ii) :i(ii) {};
	std::string get_info(void)
	{
		switch (this->i)
		{
		case 1:
			return "Error! Heap is empty!";
			break;
		case 2:
			return "Error! You passed down value out of range!!!";
			break;
		case 3:
			return "Error! You pass value smaller than 0! Please Kill yoursefl";
			break;
		default:
			return "I don't recognize this error";
			break;
		}
	}
};

template <class T>
class DynamicArray {
	inline void twice_max() { this->max != 0 ? this->max *= 2: this->max = 1; }
	long current;
	long max;
	T* array_pointer;

protected:
	

	T* get_pointer(long pos)
	{
		return (this->array_pointer + pos);
	}
	
	T& get_element(long pos)
	{
		return (*(this->array_pointer + pos));
	}

public:
	DynamicArray() :DynamicArray(NULL,1) {};
	DynamicArray(T* array_arg,long size) :array_pointer(array_arg),current(0),max(size) 
	{
		
	};

	void add(T val) 
	{
		if (this->array_pointer == NULL)
		{
			this->array_pointer = new T[1];
			this->array_pointer[this->current++] = val;
		}
		else if (current < max)
		{
			this->array_pointer[this->current++] = val;
		}
		else
		{
			
			T* tmp = this->array_pointer;
			this->array_pointer = new T[(max*2)];
			for (long i = 0; i < max; i++)
			{
				this->array_pointer[i] = tmp[i];
			}
			twice_max();
			this->array_pointer[this->current++] = val;

			delete[] tmp;
		}
	}

	T& operator [](long pos)
	{
		if (pos < 0 || pos >= current) { throw DynamicArray_exceptions(2); }
		else return get_element(pos);
	}

	T pop_back(void)
	{
		if (this->array_pointer == NULL)
		{
			throw DynamicArray_exceptions(1);
		}
		else
		{
			this->current--;
			return this->array_pointer[current+1];
		}
	}

	void print(void (*funkcja) (const T  a),long dlugosc = current)
	{
		for (long i = 0; i < dlugosc; i++)
		{
			funkcja(this->array_pointer[i]);
		}
	};

	long get_current(void) { return (this->current)-1; }
	long get_max(void) const { return this->max; }

	void erase(void)
	{
		delete[] this->array_pointer;
		this->array_pointer = NULL;
	}
	void erase_ptr(void)
	{
		for (size_t i = 0; i < current; i++)
		{
			delete this->array_pointer[i];
		}
		delete[] this->array_pointer;
		this->array_pointer = NULL;
	}

	~DynamicArray() { if (array_pointer != NULL) { delete[] array_pointer; } }
};
