class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n<=3) return 0;
        sort(nums.begin(), nums.end());
        int ans = min(nums[n-1]-nums[2], nums[n-3]-nums[0]);
        ans = min(ans, nums[n-2] - nums[1]);
        return ans;
    }
};
//three cases
//case1 - 
//reduce the high by incrementing the lowest two to third lowest

//case2 -
//reduce the low by decrementing the highest two to third highest

//case3-
//reduce both by decrementing highest to second highest and incrementing lowest to second lowest
