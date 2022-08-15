/* https://www.codingninjas.com/codestudio/problems/search-in-infinite-sorted-0-1-array_696193?leftPanelTab=0 */

/********************

    Use get function that returns the value at index i
    in the infinite sorted binary array.

    get(i)
    {

    }
    

********************/
#define ll long long

ll binarySearch(ll s, ll e) {
    ll res = -1;
    while(s <= e) {
        ll mid = s+(e-s)/2;
        if(get(mid) == 1) {
            res = mid;
            e = mid-1;
        }
        else { s = mid+1; }
    }
    return res;
}

ll firstOne() {
    ll start = 0, end = 1;
    while(get(end) < 1) {
        start = end;
        end = end*2;
    }
    return binarySearch(start, end);
}