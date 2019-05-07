// CPSC5042_Iverson_HW2_PThread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 3

int averageVal = 0;
int maxVal = 0;
int minVal = 0;


void *Average(vector<int> numbers);
void *Max(vector<int> numbers);
void *Min(vector<int> numbers);


int main()
{
	vector<int> my_vector;
	pthread_t threads[NUM_THREADS];

	pthread_create(&threads[0], NULL, Average, my_vector);
	pthread_create(&threads[1], NULL, Min, my_vector);
	pthread_create(&threads[2], NULL, Max, my_vector);


	my_vector = { 2, 4, 16, 1, 10 };
	cout << "AVERAGE: " << averageVal;
	cout << "Max: " << maxVal;
	cout << "Min: " << minVal;

	return 0;
}

void *Average(vector<int> numbers)
{
	// initial variable to hold the sum in.
	int sum = 0;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		sum += numbers[i];
	}
	averageVal = sum / numbers.size();
	pthread.exit(0);
}

void *Max(vector<int> numbers)
{
	int currentMax = numbers[0];

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (currentMax < numbers[i]) {
			currentMax = numbers[i];
		}
	}
	maxVal = currentMax;
	pthread.exit(0);
}

void *Min(vector<int> numbers)
{
	// initial variable to hold the sum in.
	int currentMin = numbers[0];

	for (size_t i = 0; i < numbers.size(); i++)
	{
		if (currentMin > numbers[i])
		{
			currentMin = numbers[i];
		}
	}
	minVal = currentMin;
	pthread.exit(0);
}
