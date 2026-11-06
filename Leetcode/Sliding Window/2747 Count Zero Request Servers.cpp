class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        //sort by second element
        for(int i = 0; i<logs.size(); i++){
            int a = logs[i][0];
            int b = logs[i][1];
            logs[i][0] = b;
            logs[i][1] = a;
        }
        sort(logs.begin(), logs.end());

        //keep the idx of query before sorting
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++)
            q.push_back({queries[i], i});
        sort(q.begin(), q.end());

        vector<int> ans(queries.size(), 0);
        unordered_map<int,int> mp; //server, count
        int l = 0, r = 0; //pointers are on logs
        for(int i = 0; i<queries.size(); i++){
            while(l<logs.size() && logs[l][0]<q[i].first-x){
                if(!mp.empty()){
                    mp[logs[l][1]]--; //map theke ber korlam
                    if(mp[logs[l][1]]==0) mp.erase(logs[l][1]); //count 0 hoye gele erase kor dilam
                }
                l++;
            }
            while(r<logs.size() && logs[r][0] <= q[i].first){
                if(r<l) r++; //to get at initial starting point
                else{
                    mp[logs[r][1]]++;
                    r++;
                }
            }
            ans[q[i].second] = (n-mp.size());
        }
        return ans;
    }
};
