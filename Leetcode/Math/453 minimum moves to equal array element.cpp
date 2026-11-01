class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minm = INT_MAX, ans = 0;
        for(int num : nums){
            minm = min(num, minm);
        }
        for(int i = 0; i<nums.size(); i++){
            nums[i] -= minm;
            ans += nums[i];
        }
        return ans;
    }
};
