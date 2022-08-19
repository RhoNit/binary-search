class Solution {
public:
    bool checkFunc(vector<int> &weights, int days, int mid) {
        int add = 0, d = 1;
        for(int i = 0; i < weights.size(); i++) {
            if(add+weights[i] <= mid) { add += weights[i]; }
            else {
                d++;
                add = weights[i];
            }
        }
        if(d <= days) { return true; }
        return false;
    }
        
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, maxi = 0;
        for(int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if(weights[i] > maxi) { maxi = weights[i]; }
        }
        int start = maxi;
        int end = sum;
        int res = 0;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(checkFunc(weights, days, mid)) {
                res = mid;
                end = mid-1;
            }
            else { start = mid+1; }
        }
        return res;
    }
};