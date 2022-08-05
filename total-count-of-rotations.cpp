/*  https://practice.geeksforgeeks.org/problems/rotation4723/1  */

class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int start = 0, end = n-1;
	    while(start <= end) {
	        int mid = start + (end-start)/2;
	        int next = (mid+1)%n;
	        int prev = (mid+n-1)%n;
	        
	        //if(arr[mid] <= arr[next] and arr[mid] <= arr[prev]) { return mid; }
	        if(arr[mid] > arr[next]) { return mid+1; }
	        if(arr[mid] < arr[prev]) { return mid; }
	        
	        if(arr[start] <= arr[mid]) { start = mid+1; }
	        if(arr[mid] <= arr[end]) { end = mid-1; }
	    }
	    return 0;
	}
};