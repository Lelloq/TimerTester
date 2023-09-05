// TimerTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <cstddef>
#include <iostream>
#include <numeric>
#include "Timer.h"

void iterateElements()
{
    int c = 0;
    for(int i = 0; i <= 100000; i++)
    {
        c++;
    }
}

void iterateElements(int a, int b)
{
	int c = 0;
	for (int i = a; i <= b; i++)
	{
		c++;
	}
}

const int g_arrayElements{ 10000 };
void sortArray(std::array<int, g_arrayElements>& array)
{

	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (std::size_t startIndex{ 0 }; startIndex < (g_arrayElements - 1); ++startIndex)
	{
		// smallestIndex is the index of the smallest element we¡¯ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		std::size_t smallestIndex{ startIndex };

		// Then look for a smaller element in the rest of the array
		for (std::size_t currentIndex{ startIndex + 1 }; currentIndex < g_arrayElements; ++currentIndex)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
			{
				// then keep track of it
				smallestIndex = currentIndex;
			}
		}

		// smallestIndex is now the smallest element in the remaining array
		// swap our start element with our smallest element (this sorts it into the correct place)
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
    std::cout << "Hello World!\n";
    Timer t;

	std::array<int, g_arrayElements> array;
	std::iota(array.rbegin(), array.rend(), 1);

    t.measure<void>(sortArray, array);
}