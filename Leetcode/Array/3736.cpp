class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, maxm = INT_MIN;
        for(int i : nums){
            maxm = max(i, maxm);
        }
        for(int i : nums){
            ans += maxm-i;
        }
        return ans;
    }
};
