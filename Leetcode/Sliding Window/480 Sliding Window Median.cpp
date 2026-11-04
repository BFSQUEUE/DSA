class Solution {
public:
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> low;
        multiset<int> high;
        vector<double> median_arr;
        int i = 0;
        while(i<nums.size()){

            if(low.size()==0 || low.size()<=high.size()){ //as low will always have equal or +1 ele
            low.insert(nums[i]);
            }
            else high.insert(nums[i]);

            if((!high.empty()) && (*high.begin()<*low.rbegin())){
                int h = *high.begin(), l = *low.rbegin();
                high.erase(high.find(h)); low.erase(low.find(l)); //remove one instance
                high.insert(l); low.insert(h);
            }

            if(low.size()+high.size()==k){
                int start = i-k+1; //k=1, i=0 then..
                double median;
                if(k%2==0) median = ((double)*low.rbegin() + *high.begin()) / 2.0;
                else median = *low.rbegin();
                median_arr.push_back(median);

                auto it = high.find(nums[start]);
                if(it!=high.end()) high.erase(it);
                else low.erase(low.find(nums[start]));
            }

            i++;
        }
        return median_arr;
    }
};
