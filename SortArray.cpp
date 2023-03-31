#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int length = 25;

template <class T>
void SelSort(T arr[], int length) {
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
void SelSort2(T arr[], int length) {
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

template <class T>
void InsertionSort(T arr[], int length) {
	int temp = 0;	  // Сохранение перемещаемого значения.
	int i, j;		  // Для циклов.
	for (i = 1; i < length; i++)
	{
		temp = arr[i];// Запоминаем элемент и начнем перемещение элемента, слева от него.
					  // до тех пор, пока запоминаемый элемент не окажется меньше, чем переменная.
		for (j = i - 1; j >= 0 && arr[j] > temp;j--) {
			arr[j + 1] = arr[j];
			arr[j] = temp; // Ставим элемент на его новое место.
		}
	}
}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");

	int arr[length] = { 1,0,0,0,1 };
	for (int i = 0; i < length; i++) {
		arr[i] = 1 + rand() % 100;
	}
	cout << "Изначальный Массив: ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << "\nСортировка: ";
	//SelSort(arr,length);
	//SelSort2(arr,length);
	//BubbleSort(arr, length);
	InsertionSort(arr, length);

	for (int i = 0; i < length; i++) {
		cout << arr[i] << " "; Sleep(100);// красивое
	}
}
