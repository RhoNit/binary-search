class Solution {
public:
    bool check(vector<int>& nums, int &m, int &mid) {
        int add = 0, numOfSubArr = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(add+nums[i] <= mid) { add += nums[i]; }
            else {
                numOfSubArr++;
                add = nums[i];
            }
        }
        
        if(numOfSubArr <= m) { return true; }
        return false;
    }
        
    int splitArray(vector<int>& nums, int m) {
        int sum = 0, max = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(nums[i] > max) { max = nums[i]; }
        }
        
        int start = max, end = sum;
        int res = 0;
        
        while(start <= end) {
            int mid  = start + (end-start)/2;
            if(check(nums, m, mid)) {
                res = mid;
                end = mid-1;
            }
            else { start = mid+1; }
        }
        return res;
    }
};