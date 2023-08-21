class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        int ans = INT_MAX;
        
        while(start <= end) {
            int mid = start + (end-start)/2;

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




// 2nd approach


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
