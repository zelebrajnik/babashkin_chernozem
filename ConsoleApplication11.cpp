#include <iostream>
using namespace std;
int pa(int arr[], int low, int high) {
	int pi = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] <= pi){
			i++;
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
	}
	int t = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = t;
	return i + 1;
}
void qs(int arr[], int low, int high) {
	if (low < high) {
		int p = pa(arr, low, high);
		qs(arr, low, p - 1);
		qs(arr, p + 1, high);
	}
}

int main()
{
	int arr[] = { 10, 2, 8 ,12, 4, 1 ,7, 3, 6, 5 };
	qs(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
