/*  https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1  */

class Solution{
public:	
    int getOccurrence(int *arr, int size, int target, bool flag) {
        int start = 0, end = size-1;
        int posn = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] == target) {
                posn = mid;
                if(flag == true) { end = mid-1; }
                else if(flag == false) { start = mid+1; }
            }
            else if(arr[mid] > target) { end = mid-1; }
            else if(arr[mid] < target) { start = mid+1; } 
        }
        return posn;
    }
    
	int count(int arr[], int n, int x) {
	    int left, right;
	    left = getOccurrence(arr, n, x, true);
	    right = getOccurrence(arr, n, x, false);
	    
	    if(left != -1 and right != -1) {
	        return right-left+1;
	    }
	    return 0;
	}
};