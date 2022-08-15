class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = size-1;
        if(size == 1) { return 0; }
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(mid > 0 and mid < size-1) {
                if(nums[mid-1] < nums[mid] and nums[mid+1] < nums[mid]) { return mid; }
                else if(nums[mid-1] > nums[mid]) { end = mid-1; }
                else if(nums[mid+1] > nums[mid]) { start = mid+1; }
            }
            
            else if(mid == 0) {
                if(nums[mid] > nums[mid+1]) { return 0; }
                else { start = mid+1; }
            }
            else if(mid == size-1) {
                if(nums[mid] > nums[mid-1]) { return size-1; }
                else { end = mid-1; }
            }
        }
        return -1;
    }
};