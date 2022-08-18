class Solution {
public:
    bool totalTime(vector<int> &piles, int h, int mid) {
        long long t = 0;
        for(int i = 0; i < piles.size(); i++) {
            t += (piles[i]/mid) + (piles[i]%mid != 0);
            if(t > h) { return false; }
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = 0;
        
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > maxi) { maxi = piles[i]; }
        }
        
        int lowSpeed = 1, highSpeed = maxi;
        int res = -1;
        
        while(lowSpeed <= highSpeed) {
            int midSpeed = lowSpeed + (highSpeed-lowSpeed)/2;
            
            if(totalTime(piles, h, midSpeed)) {
                res = midSpeed;
                highSpeed = midSpeed-1;
            }
            else { lowSpeed = midSpeed+1; }
        }
        return res;
    }
};