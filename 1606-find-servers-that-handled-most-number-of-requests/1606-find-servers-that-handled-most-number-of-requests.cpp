class Solution {
        struct BUSY {
        long long time;
        int server;
    };
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> servers(k,0);
        set<int> free;
        auto cmp1 = [](BUSY& a, BUSY& b) { return a.time > b.time; };
        priority_queue<BUSY, std::vector<BUSY>, decltype(cmp1)> busy;
        for (int i = 0; i < k; i++)
            free.insert(i);
        long long time = 0;
        vector<int> ans;
        int maxi=0;
        int task = 0;
        while (task < n) {
            time = arrival[task];

            while (!busy.empty() && (time >= busy.top().time)) {
                int server = busy.top().server;
                busy.pop();
                free.insert(server);
            }
            if (!free.empty()) {
                auto pr = free.lower_bound(task%k);
                if (pr==free.end()) pr=free.begin();
                int server = *pr;
                free.erase(server);
                busy.push({time + load[task], server});
                if(servers[server]++ == maxi) maxi++;
            }
            task++;
        }
        for(int i=0; i<k; i++) if(servers[i]==maxi) ans.push_back(i);
        return ans;
    }
};