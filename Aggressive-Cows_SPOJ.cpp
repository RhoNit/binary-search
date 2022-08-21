/*  https://www.spoj.com/problems/AGGRCOW/  */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
long long n;
long long cows;
int arr[N];

bool isSpaceForCowsEnough(long long minDist) {
	int lastCowPos = arr[0], countCows = 1;
	
	for(long long i = 1; i < n; i++) {
		if(arr[i] - lastCowPos >= minDist) {
			countCows++;
			lastCowPos = arr[i];
		}
		if(countCows == cows) { return true; }
	}
	return false;
}

int main() {
	int t; 
	cin >> t;
	while(t--) {
		cin >> n >> cows;
		for(long long i = 0; i < n; i++) { cin >> arr[i]; }
		
		sort(arr, arr+n);
		
		long long low = 0, high = 1e9;
		long long res = -1;
		while(low <= high) {
			long long mid = low + (high-low)/2;
			
			if(isSpaceForCowsEnough(mid)) {
				res = mid;
				low = mid+1;
			}
			else { high = mid-1; }
		}
		cout << res << endl;
	}
	return 0;
}