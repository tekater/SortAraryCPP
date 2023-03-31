#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int length = 100;

template <class T>
void _selectsort(T arr[], int length) {
	int i, j, k; // i - номер текущего шага
	T x;
	for (i = 0; i < length; i++)
	{
		k = i;		// Сохраняем номер текущего шага
		x = arr[i]; // Сохраняем текущую переменную

		// Цикл для выбора min элемента.
		for (j = i + 1; j < length; j++) {
			if (arr[j] < x) {
				k = j;// k - Индекс наименьшего элемента.
				x = arr[j];
			}
		}

		if (k != i) {
			arr[k] = arr[i];
			arr[i] = x;
		}
	}
}

template <class T>
void _selectsort2(T arr[], int length) {
	int min = 0;
	int temp = 0;

	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i+1; j < length; j++)
		{
			min = (arr[j] < arr[min]) ? j : min;
		}
		if (i != min) {
			swap(arr[i], arr[min]);
		}

	}
}

template <class T>
void BubbleSort(T arr[], int length) {
	//int temp = 0;
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				//temp = arr[j];
				//arr[j] = arr[j + 1];
				//arr[j + 1] = temp;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	system("color B5");

	int arr[length] = { 1,0,0,0,1 };
	for (int i = 0; i < length; i++) {
		arr[i] = 1 + rand() % 100;
	}
	//_selectsort(arr,length);
	//_selectsort2(arr,length);
	BubbleSort(arr, length);

	for (int i = 0; i < length; i++) {
		cout << arr[i] << " "; Sleep(100);// красивое
	}
}
