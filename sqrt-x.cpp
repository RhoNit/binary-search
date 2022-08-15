class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 or x == 1) { return x;}
        long start = 0, end = x;
        long res;
        while(start <= end) {
            long mid = start + (end-start)/2;
            long sqr = mid*mid;
            if(sqr == x) { return mid; }
            else if(sqr > x) { end = mid-1; }
            else if(sqr < x) {
                res = mid;
                start = mid+1;
            }
        }
        return res;
    }
};