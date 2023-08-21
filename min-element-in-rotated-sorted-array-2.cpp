class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int ans = INT_MAX;
        
        while(start <= end) {
            int mid = start + (end-start)/2;

            if(nums[start] == nums[mid] and nums[mid] == nums[end]) {
                ans = min(ans, nums[end]);
                start += 1;
                end -= 1;
                continue;
            }

            // if left part of the mid is sorted, take the smallest element and compare it with the right part i.e. sorted part
            if(nums[start] <= nums[mid]) {
                ans = min(ans, nums[start]);
                start = mid+1;
            }

            // if right part of the mid is sorted, take the smallest element and compare it with the left part i.e. sorted part
            else {
                ans = min(ans, nums[mid]);
                end = mid-1;
            }
        }
        return ans;
    }
};

//2nd approach
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