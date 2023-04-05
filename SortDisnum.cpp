#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int size = 10;
const int length = 20;
const int mmr = 100;

template <class T>
void BubbleSort(T arr[], int length,int i) {
	switch (i) {
	case 0:
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		break;
	case 1:
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - 1; j++)
			{
				if (arr[j] < arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		break;
	default:
		cout << "Error";
		break;
	}
}
void MINMAX(int arr[],int length) {
	int min = 0;
	int max = -20;
	int temp; int temp2;
	int buffer;
	for (int i = 0; i < length; i++) {
		if (min > arr[i]) {
			min = arr[i];
			temp = i;
		}
	}
	for (int i = 0; i < length; i++) {
		if (max < arr[i] && arr[i] < 0 && i > temp || max == arr[i]) {
			max = arr[i];
			temp2 = i;
		}
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (j > temp && j < temp2) {

				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}

			}

		}
	}

}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");

	int arr[::size] = {};

	for (int i = 0; i < ::size; i++) {
		arr[i] = 1 + rand() % 10;
	}
	cout << "Задание 1\n";
	cout << "Изначальный Массив: ";
	for (int i = 0; i < ::size; i++) {
		cout << arr[i] << " ";
	}

	cout << endl << "\nСортировка: ";
	BubbleSort(arr, ::size, 0);
	for (int i = 0; i < ::size; i++) {
		cout << arr[i] << " ";
	}


	cout << "\n\nЗадание 2\n";
	int arr2[length] = {};
	for (int i = 0; i < length; i++) {
		arr2[i] = -20 + rand() % 20;
	}
	cout << "Изначальный Массив: ";
	for (int i = 0; i < length; i++) {
		cout << arr2[i] << " ";
	}

	MINMAX(arr2,length);

	cout << endl << "\nСортировка: ";
	for (int i = 0; i < length; i++) {
		cout << arr2[i] << " ";
	}

}
