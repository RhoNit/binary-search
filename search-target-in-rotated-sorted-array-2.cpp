class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;

        while(start <= end) {
            int mid = start + (end-start)/2;

            if(target == nums[mid]) { return true; }

            if(nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start += 1;
                end -= 1;
                continue;
            }

            // if left of the mid is sorted and the right part is rotated
            if(nums[start] <= nums[mid]) {
                if(nums[start] <= target && target <= nums[mid]) {
                    end = mid-1;
                }
                else { start = mid+1; }
            }

            // if right of the mid is sorted and left part is rotated            
            else {
                if(nums[mid] <= target && target <= nums[end]) {
                    start = mid+1;
                }
                else { end = mid-1; }
            }
        }
        return false;
    }
};