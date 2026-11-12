class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int len = 0, cnt = 1, prev = nums[0], ans = INT_MIN;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]>prev) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
            prev = nums[i];
        }
        ans = max(ans, cnt);
        prev = 51; cnt = 1; prev = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]<prev) cnt++;
            else{
                ans = max(ans, cnt);
                cnt = 1;
            }
            prev = nums[i];
        }
        ans = max(ans, cnt);
        return ans;
    }
};
