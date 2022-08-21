class Solution {
public:
    bool isMinForceAchievable(vector<int> &vec, int balls, long long d) {
        long long lastBallPos = vec[0], countBalls = 1;
        for(long long i = 1; i < vec.size(); i++) {
            if(vec[i] - lastBallPos >= d) {
                countBalls++;
                lastBallPos = vec[i];
            }
            if(countBalls == balls) { return true; }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        long long n = 1e5;
        sort(position.begin(), position.end());
        
        long long low = 0, high = 1e9;
        long long res = -1;
        
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            if(isMinForceAchievable(position, m, mid)) {
                res = mid;
                low = mid+1;
            }
            else { high = mid-1; }
        }
        return res;
    }
};