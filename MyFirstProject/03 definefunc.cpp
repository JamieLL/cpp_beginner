#include "func.h"

int add(int num1, int num2) {
	int sum = num1 + num2;
	cout << "sum = " << sum << endl;
	return sum;
}

void bubblesort(int* arr, int len) {
	for (int i = 0;i < len - 1;i++){
		for (int j = 0;j < len - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

void bubblesort_main() {
	int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr, len);
}