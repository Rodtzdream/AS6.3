#include <iostream>
#include <ctime>

void CreateArray(int arr[], int arr2[], int NUM)
{
	srand(1);
	for (int i = 0; i < NUM; i++)
		arr[i] = arr2[i] = rand();
}

void RestoreArray(int arr[], int arr2[], int NUM)
{
	for (int i = 0; i < NUM; i++)
		arr[i] = arr2[i];
}

void SortSelection(int arr[], int N)
{
	int lowindex, lowkey;

	for (int i = 0; i < N - 1; i++)
	{
		lowindex = i;
		lowkey = arr[i];
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < lowkey)
			{
				lowkey = arr[j];
				lowindex = j;
			}
		}
		std::swap(arr[i], arr[lowindex]);
	}
}

void QuickSort(int arr[], int first, int last)
{
	int middle = arr[(first + last) / 2];

	int i = first;
	int j = last;

	do
	{
		while (arr[i] < middle)
			i++;
		while (arr[j] > middle)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else
			break;
	} while (i <= j);

	if (i < last)
		QuickSort(arr, i, last);
	if (j > first)
		QuickSort(arr, first, j);

}

int main()
{
	const int N = 50000;
	int arr[N] = {};
	int arr2[N] = {};

	CreateArray(arr, arr2, N);

	std::cout << "SortSelection:\n" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		clock_t  begt, endt;
		begt = clock();
		SortSelection(arr, N);
		endt = clock();
		printf("time=%d\n", endt - begt);

		RestoreArray(arr, arr2, N);
	}

	std::cout << "\nSortFast:\n" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		RestoreArray(arr, arr2, N);

		clock_t  begt, endt;
		begt = clock();
		QuickSort(arr, 0, N - 1);
		endt = clock();
		printf("time=%d\n", endt - begt);
	}
}