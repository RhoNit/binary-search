/* https://www.spoj.com/problems/EKO/ */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n;
long long m;
long long height[N];

bool isEnoughWood(int maxH) {
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		if(height[i] >= maxH) { sum += height[i]-maxH; }
		if(sum >= m) { return true; }
	}
	return false;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> height[i];
	}
	
	long long low = 0, high = 1e9;
	long long res = -1;
	while(low <= high) {
		long long mid = low + (high-low)/2;
		if(isEnoughWood(mid)) {
			res = mid;
			low = mid+1;
		}
		else { high = mid-1; }
	}
	cout << res << endl;
}