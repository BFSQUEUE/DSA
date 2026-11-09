class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<pair<int, int>> server; // index, req handled
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            busy; // ttl, {index, req handled}

        for (int i = 0; i < k; i++) {
            server.insert({i, 0});
        }

        for (int i = 0; i < arrival.size(); i++) {
            int curr_time = arrival[i];

            while (!busy.empty() && busy.top().first <= curr_time) {
                server.insert(busy.top().second);
                busy.pop();
            }

            int server_idx = (i % k);
            if (!server.empty()) {
                auto it = server.lower_bound({server_idx, INT_MIN});
                if (it == server.end()) it = server.begin();

                auto p = *it;
                server.erase(it);

                p.second += 1;
                int ttl = curr_time + load[i];
                busy.push({ttl, p});
            }
        }

        while (!busy.empty()) {
                server.insert(busy.top().second);
                busy.pop();
        }
        
        int cnt = 0, maxm = INT_MIN;
        for (auto it = server.begin(); it != server.end(); it++) {
            if (it->second > maxm)
                maxm = it->second;
        }

        vector<int> ans;
        for (auto it = server.begin(); it != server.end(); it++) {
            if (it->second == maxm)
                ans.push_back(it->first);
        }
        return ans;
    }
};
