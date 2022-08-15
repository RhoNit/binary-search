class Solution {
public:
    bool isPerfectSquare(int num) {
        long start = 0, end = num;
        if(num == 1) { return true; }
        
        while(start <= end) {
            long mid = start + (end-start)/2;
            long sqr = mid*mid;
            
            if(num == sqr) { return true; }
            else if(num < sqr) { end = mid-1; }
            else if(num > sqr) { start = mid+1; }
        }
        return false;
    }
};