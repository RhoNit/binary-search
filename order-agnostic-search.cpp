#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
	bool isAsc = arr[0] < arr[1];
	while(start <= end) {
		int mid = start + (end-start)/2;
		if(arr[mid] == target) { return mid; }

		// Ascending order
		if(isAsc == true) {
			if(arr[mid] < target) { start = mid+1; }
			else { end = mid-1; }
		}

		// Descending order
		else {
			if(arr[mid] > target) { start = mid+1; }
			else { end = mid-1; }
		}
	}

	// Element is not present
	return -1;
}

int main()
{
	int arr[] = { 40, 10, 5, 2, 1 };
	int target = 10;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << binarySearch(arr, 0, n-1, target);

	return 0;
}
