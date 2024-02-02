#include <iostream>
using namespace std;

int isPresent(int arr[], int val, int n) {
	int low = 0, high = n - 1, mid;
	while (low <= high) {
		mid = (low + high)/2;
		if (arr[mid] == val) return 1;
		else if (arr[mid] < val) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return 0;
}

int main() {
	int size = 14;
	int arr[size] = {18, 20, 23, 31, 37, 42, 47, 51, 79, 82, 85, 94, 96, 97};

	for (int i=0; i <= (size - 1); i += 3) {
		int result = isPresent(arr, arr[i], size);
		if (result == 1) {
			cout << "Element = "<< arr[i] << ", Index = " << i << endl;
		} else {
			cout << "Element is not present in the array" << endl;
		}
	}
	return 0;
}