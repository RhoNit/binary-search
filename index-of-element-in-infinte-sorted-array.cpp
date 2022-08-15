#include<bits/stdc++.h>
using namespace std;
 
int binarySearch(int arr[], int s, int e, int key) {
    while(s <= e) {
        int mid = s + (e - s)/2;
        if(arr[mid] == key) { return mid; }
        if(arr[mid] > key) { e = mid-1; }
        if(arr[mid] < key) { s = mid+1; }
    }
    return -1;
}

int findPos(int arr[], int key) {
    int start = 0, end = 1;

    while (arr[end] < key) {
        start = end;
        end = 2*end;
    }
    return binarySearch(arr, start, end, key);
}