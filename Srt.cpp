#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Creates an array - Sorted(0-n), Reversed(n-0) or mixed values of 0-n.
int* arrMaker(int n, string type);

//Will sort an array using bubble sort and keep a counter for the steps that it takes to sort the array.
void bubbleSortCounter(int n, string type);


void bubbleSortClock(int n, string type);

int main()
{
	string sorted = "Sorted";
	string reversed = "Reversed";
	string random = "Random";

	bubbleSortCounter(100, sorted);
	bubbleSortClock(100, sorted);
	return 0;
}

//Array creator
int* arrMaker(int n, string type)
{
	int* arr = new int[n];

	//Creates an array with numbers in order 1, 2, 3, ... n.
	if (type == "Sorted")
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i + 1;
		}
	}
	//Creates an array with numbers reversed n, n-1, ... 3, 2 , 1;
	else if (type == "Reversed")
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = n - 1;
		}
	}
	//Creates a sorted array and then mixes ro create a random array.
	else if (type == "Random")
	{
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}
		for (int i = 0; i < n; i++)
		{
			int j = rand() % n;
			swap(arr[i], arr[j]);
		}
	}
	else
	{
		cout << "Error type not recognized";
	}
	return arr;
}

//Bubble sort with integer counter
void bubbleSortCounter(int n, string type)
{
	int steps = 0;
	int* arr = arrMaker(n, type);

	int iteration = 1;
	steps++;

	while (iteration < n - 1)
	{
		steps++;
		for (int i = 0; i < n - iteration; i++)
		{
			steps++;
			if (arr[i] > arr[++i])
			{
				steps++;
				swap(arr[i], arr[++i]);
				steps++;
			}
		}
		iteration++;
	}

	cout << setw(10) << steps << endl;
}

//Bubble sort with clock
void bubbleSortClock(int n, string type)
{
	int* arr = arrMaker(n, type);
	
	high_resolution_clock::time_point start = high_resolution_clock::now();
	int iteration = 1;
	while (iteration < n - 1)
	{
		for (int i = 0; i < n - iteration; i++)
		{
			if (arr[i] > arr[++i])
			{
				swap(arr[i], arr[++i]);
			}
		}
		iteration++;
	}
	high_resolution_clock::time_point end = high_resolution_clock::now();
	high_resolution_clock::duration timeElapsed = end - start;
	cout << setw(10) << timeElapsed.count() << endl;
}
