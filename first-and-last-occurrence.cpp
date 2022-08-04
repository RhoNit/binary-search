class Solution {
public:
    int getOccurrence(vector<int>& nums, int target, int firstOrLast) {
        int start = 0, end = nums.size()-1;
        int posn = -1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(target == nums[mid]) {
                posn = mid;
                if(firstOrLast == -10) { end = mid-1; }
                else if(firstOrLast == -20) { start = mid+1; }
            }
            else if(target < nums[mid]) { end = mid-1; }
            else if(target > nums[mid]) { start = mid+1; }
        }
        
        return posn;
    }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        int first, last;
        
        first = getOccurrence(nums, target, -10);
        last = getOccurrence(nums, target, -20);
        
        nums.clear();
        nums.push_back(first);
        nums.push_back(last);
        
        return nums;
    }
};