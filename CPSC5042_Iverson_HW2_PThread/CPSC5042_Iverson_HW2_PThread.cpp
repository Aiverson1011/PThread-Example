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


void *Average(void *numbers);
void *Max(void *numbers);
void *Min(void *numbers);

struct thread_data {
	vector<int> numbers;
};

int main()
{
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];

	vector<int> my_vector{ 10, 20, 30 };
	td[0].numbers = my_vector;

	pthread_create(&threads[0], NULL, Average, (void *)&td[0]);
	//pthread_create(&threads[1], NULL, Min, my_vector);
	//pthread_create(&threads[2], NULL, Max, my_vector);


	cout << "AVERAGE: " << averageVal;
	//cout << "Max: " << maxVal;
	//cout << "Min: " << minVal;

	return 0;
}

void *Average(void *numbers)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *) numbers;


	// initial variable to hold the sum in.
	int sum = 0;
	for (size_t i = 0; i < my_data->numbers.size(); i++)
	{
		sum += my_data->numbers[i];
	}
	averageVal = sum / my_data->numbers.size();
	pthread_exit(0);
}

//void *Max(void *numbers)
//{
//	int currentMax = numbers[0];
//
//	for (size_t i = 0; i < numbers.size(); i++)
//	{
//		if (currentMax < numbers[i]) {
//			currentMax = numbers[i];
//		}
//	}
//	maxVal = currentMax;
//	pthread.exit(0);
//}
//
//void *Min(void *numbers)
//{
//	// initial variable to hold the sum in.
//	int currentMin = numbers[0];
//
//	for (size_t i = 0; i < numbers.size(); i++)
//	{
//		if (currentMin > numbers[i])
//		{
//			currentMin = numbers[i];
//		}
//	}
//	minVal = currentMin;
//	pthread.exit(0);
//}
