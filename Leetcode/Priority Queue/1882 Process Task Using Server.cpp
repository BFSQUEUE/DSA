#define ll long long
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<servers.size(); i++){
            pq.push({servers[i],i});
        }

        ll curr_time = 0;
        pair<int,int> choosen_server;
        priority_queue<pair<ll,pair<int,int>>, vector<pair<ll,pair<int,int>>>, greater<pair<ll,pair<int,int>>>> busy; //ttl, (server, index)
        for(int j = 0; j<tasks.size(); j++){
            curr_time = max((ll)j, curr_time);
            while(!busy.empty() && busy.top().first<=curr_time){
                pq.push(busy.top().second);
                busy.pop();
            }
            if(!pq.empty()) choosen_server = pq.top();
            else{
                curr_time = busy.top().first;
                while(!busy.empty() && busy.top().first<=curr_time){
                    pq.push(busy.top().second);
                    busy.pop();
                }
                choosen_server = pq.top();
            }
            ll ttl = curr_time + tasks[j];
            pq.pop();
            busy.push({ttl, choosen_server});
            ans.push_back(choosen_server.second);
        }
        return ans;
    }
};
