/* Minimized Maximum of Products Distributed to Any Store */


class Solution {
public:
    int minimizedMaximum(int n, vector<int>& vec) {
        long long low = 1, high = *max_element(vec.begin(), vec.end());
        long long res = -1;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            long long sum = 0;
            for(auto x : vec) {
                sum += (x/mid) + (x%mid != 0);
            }
            
            if(sum <= n) {
                res = mid;
                high = mid-1;
            }
            else { low = mid+1; }
        }
        return res;
    }
};