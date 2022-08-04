class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start <= end) {
            if(nums[start] < nums[end]) { return nums[start]; }
            int mid = start + (end-start)/2;
            int next = (mid+1)%n, prev = (mid+n-1)%n;
            
            if(nums[mid] <= nums[next] and nums[mid] <= nums[prev]) { return nums[mid]; }
            else if(nums[start] <= nums[mid]) { start = mid+1; }
            else if(nums[mid] <= nums[end]) { end = mid-1; }
        }
        return -1;
    }
};