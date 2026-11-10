class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i<costs.size(); i++){
            if(i+1<n+1) dp[i+1] = min(dp[i+1], dp[i]+costs[i]+(1));
            if(i+2<n+1) dp[i+2] = min(dp[i+2], dp[i]+costs[i+1]+(2*2));
            if(i+3<n+1) dp[i+3] = min(dp[i+3], dp[i]+costs[i+2]+(3*3));
        }
        return dp[n];
    }
};
