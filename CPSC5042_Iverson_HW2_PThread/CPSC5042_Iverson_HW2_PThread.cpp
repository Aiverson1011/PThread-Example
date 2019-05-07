#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <vector>

using namespace std;

#define NUM_THREADS 3

int averageVal = 0;
int maxVal = 0;
int minVal = 0;

struct thread_data {
	int  thread_id;
	vector<int> numbers;
};

void *Average(void *threadarg) {

	// reference to my struct that is being passed by my thread
	struct thread_data *threadData;
	threadData = (struct thread_data *) threadarg;
	int sum = 0;

	vector<int> nums = threadData->numbers;

	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
	}


	cout << "SUM:" << sum << endl;
	cout << "SIZE: " << nums.size() << endl;

	averageVal = sum / nums.size();


	pthread_exit(NULL);
}


void *Max(void *threadarg)
{
	struct thread_data *threadData;
	threadData = (struct thread_data *) threadarg;

	vector<int> nums = threadData->numbers;
	int currentMax = nums[0];

	for (int i = 0; i < nums.size(); i++)
	{
		if (currentMax < nums[i]) {
			currentMax = nums[i];
		}
	}

	maxVal = currentMax;

	pthread_exit(NULL);
}

void *Min(void *threadarg)
{
	struct thread_data *threadData;
	threadData = (struct thread_data *) threadarg;

	vector<int> nums = threadData->numbers;
	int currentMin = nums[0];

	for (int i = 0; i < nums.size(); i++)
	{
		if (currentMin > nums[i])
		{
			currentMin = nums[i];
		}
	}

	minVal = currentMin;
	pthread_exit(NULL);
}


int main(int argc, char** argv) {

	if (argc <= 1)
	{
		cout << "ERROR: Please provide additional arguments" << endl;
		return -1;
	}

	for (int i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) < 0) {
			cout << "Cannot handle negative number: " << atoi(argv[i]) << endl;
			return -1;
		}
	}

	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	vector<int> vect;

	for (int i = 1; i < argc; i++)
	{
		vect.push_back(atoi(argv[i]));
	}

	td[0].thread_id = 0;
	td[0].numbers = vect;
	td[1].thread_id = 1;
	td[1].numbers = vect;
	td[2].thread_id = 2;
	td[2].numbers = vect;


	pthread_create(&threads[0], NULL, Average, (void *)&td[0]);
	pthread_create(&threads[1], NULL, Max, (void *)&td[1]);
	pthread_create(&threads[2], NULL, Min, (void *)&td[2]);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);

	cout << "Average Value: " << averageVal << endl;
	cout << "MAX Value: " << maxVal << endl;
	cout << "MIN Value: " << minVal << endl;



	pthread_exit(NULL);
}