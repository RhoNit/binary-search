// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

class Solution 
{
    public:
    
    bool isMinAllocationPossible(int arr[], int n, int stu, int mid) {
        int stuCount = 1, sum = 0;
        for(int i = 0; i < n; i++) {
            if(sum+arr[i] <= mid) { sum += arr[i]; }
            else {
                stuCount++;
                sum = arr[i];
                if(stuCount > stu) { return false; }
            }
        }
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) {
        if(m > n) { return -1; }  //corner case
        
        int start = 0, end = 0;
        for(int i = 0; i < n; i++) {
            end += arr[i];
            if(arr[i] > start) { start = arr[i]; }
        }
        
        int res = -1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(isMinAllocationPossible(arr, n, m, mid)) {
                res = mid;
                end = mid-1;
            }
            else { start = mid+1; }
        }
        return res;
    }
};