#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int length = 25;

template <class T>
void SelSort(T arr[], int length) {
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
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <class T>
void LineSort(T arr[], int length,int ot,int Do) {
	for (int i = 0; i < Do; i++)
	{
		for (int j = ot; j < Do-1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <class T>
void fractsort(T arr[], int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
	}

	sum = sum / length;

	if (sum > 0) {
		for (int i = 0; i < (length / 3) * 2; i++)
		{
			for (int j = 0; j < ((length / 3) * 2) - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		for (int i = 0; i < (length / 3) * 2; i++) {
			cout << arr[i] << " "; Sleep(50);
		}
		cout << "\b|";
		for (int i = length-1; i >= (length / 3) * 2; i--) {
			cout << arr[i] << " "; Sleep(50);
		}
	}
	else {
		for (int i = 0; i < (length / 3); i++)
		{
			for (int j = 0; j < (length / 3) - 1; j++)
			{
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		for (int i = 0; i < (length / 3); i++) {
			cout << arr[i] << " "; Sleep(50);
		}
		cout << "\b|";
		for (int i = length-1; i >= (length / 3); i--) {
			cout << arr[i] << " "; Sleep(50);
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
	cout << "Задание 1\n";
	cout << "Массив:\t\t\b\b\b\b\b ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}

	cout << "\nСортировка: ";

	BubbleSort(arr, length);

	for (int i = 0; i < length; i++) {
		cout << arr[i] << " "; Sleep(50);// красивое
	}


	cout << "\n\nЗадание 2\n";
	for (int i = 0; i < length; i++) {
		arr[i] = 1 + rand() % 100;
	}
	cout << "Массив:\t\t\b\b\b\b\b ";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}

	cout << "\nСортировка: ";
	SelSort(arr, length);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " "; Sleep(50);
	}


	cout << "\n\nЗадание 3\n";
	const int size = 10;
	int Arr[size] = {};
	for (int i = 0; i < size; i++) {
		cout << "Введите " << i+1 << " оценку:\n";
		cin >> Arr[i];
	}
	int select; int z = 0; double mean = 0;
	select = 4;
	do {
		cout << "[1] - Вывод оценок.\n[2] - Пересдача экзамена.\n[3] - Результаты\n[4] - exit\n";
		cin >> select;
		switch (select) {
		case 1:
			system("cls");
			cout << "Оценки:\n";
			for (int i = 0; i < size; i++) {
				cout << i + 1 << ": " << Arr[i] << endl;
			}
			break;
		case 2:
			cout << "Какой экзамен вы хотите пересдать ? [1-10]\n";
			cin >> z;
			cout << "Введите оценку:\n";
			cin >> Arr[z-1];
			break;
		case 3:
			mean = 0;
			for (int i = 0; i < size; i++) {
				mean += Arr[i];
				
			}
			mean = mean / size;
			if (mean >= 10.7) {
				cout << "Экзамен сдан!\n" << mean << " Баллов.\n";
				select = 4;
				break;
			}
			else {
				cout << "Экзамен провален!\n" << mean << " Баллов.\n";
			}
			break;
		default:
			break;
		}
	} while (select < 4);


	cout << "\nЗадание 4\n";
	int arr2[length] = {};
	int ot = 5;
	int Do = 15;
	for (int i = 0; i < length; i++) {
		arr2[i] = 1 + rand() % 100;
	}
	cout << "Массив:\t\t\b\b\b\b\b ";
	for (int i = 0; i < length; i++) {
		cout << arr2[i] << " ";
	}

	cout << "\nСортировка: ";
	LineSort(arr2, length, ot,Do);
	for (int i = 0; i < ot; i++) {
		cout << arr2[i] << " "; Sleep(50);
	}
	cout << "\b|";
	for (int i = ot; i < Do; i++) {
		cout << arr2[i] << " "; Sleep(50);
	}
	cout << "\b|";
	for (int i = Do; i < length; i++) {
		cout << arr2[i] << " "; Sleep(50);
	}

	cout << "\n\nЗадание 5\n";
	int arr3[length] = {};
	for (int i = 0; i < length; i++) {
		arr3[i] = -100 + rand() % 100;
	}

	cout << "Массив:\t\t\b\b\b\b\b ";
	for (int i = 0; i < length; i++) {
		cout << arr3[i] << " ";
	}

	cout << "\nСортировка: ";
	fractsort(arr3, length);
}
