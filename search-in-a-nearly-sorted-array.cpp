//Search an element in a nearly sorted array

class Solution {
    public:
    int modifiedBinarySearch(vector<int>&nums, int target) {
        int start = 0, end = nums.size()-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            
            if(target == nums[mid]) { return mid; }
            if(mid >= start and target == nums[mid-1]) { return mid-1; }
            if(mid <= end and target == nums[mid+1]) { return mid+1; }
            
            if(target < nums[mid]) { end = mid-2; }
            if(target > nums[mid]) { start = mid+2; }
        }
        return -1;
    }
};