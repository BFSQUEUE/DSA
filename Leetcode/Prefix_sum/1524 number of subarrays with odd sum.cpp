class Solution {
public:
    /*
    even - odd = odd and odd - even = odd
    1. so when sum is even that means if we subtract the subarray that has
    sum odd we will get a odd sum subarray since even - odd = odd; so we keep
    count of how many odd subarray we have encountered so far. so
    odd0, even1, odd2, odd3, even4
    - means subaraay from 3 to 4 must be odd since only odd+odd=even.
    - subarray from 1 to 2 must be odd since even+odd = odd;
    so when sum is odd we find how many previous was even cause odd minus
    that even part will result in odd.
    and when sum is even we find odd part as even - odd = odd;

    initially evn_cnt is taken as 1. as if we encounter odd first we need to
    take that in. and if odd encountered last still 2,4,1, e2, e6, o7 so 7-6=1
    =odd, 7-2=5=odd, 7-0=1=odd so ass you see if sum is oddd that means from 
    start to end total sum is odd so to encounter this from index 0 to that 
    index initially esum is taken as 1;
    */
    int numOfSubarrays(vector<int>& arr) {
        long long mod = 1e9+7;
        int odd_cnt = 0, evn_cnt = 1, sum = 0, ans = 0;
        for(int i = 0; i<arr.size(); i++){
            sum += arr[i];
            if(sum%2!=0){
                ans += evn_cnt;
                odd_cnt++;
            }
            else{
                ans += odd_cnt;
                evn_cnt++;
            }
            ans %= mod;
        }
        return ans;
    }
};
