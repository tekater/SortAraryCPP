#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

const int length = 5;
void ShiftZero(int arr[],int length) {
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] != 0) {
			arr[j] = arr[i];
			j++;
		}
		
	}
	for (; j < length; j++) {
		arr[j] = -1;
	}
}
int main()
{
	setlocale(0, "");
	srand(time(NULL));
	system("color B5");
	int arr[length] = { 1,0,0,0,1 };
	ShiftZero(arr, length);
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	
}
