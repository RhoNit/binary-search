class Solution {
public:   
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        if(n == 1) { return nums[0]; }
        if(nums[start] < nums[end]) { return nums[start]; }
        
        while(start < end) {
            int mid = start + (end-start)/2;
    
            if(nums[mid] > nums[end]) { start++; }
            else { end--; }
        }
        return min(nums[start],nums[end]);
    }
};