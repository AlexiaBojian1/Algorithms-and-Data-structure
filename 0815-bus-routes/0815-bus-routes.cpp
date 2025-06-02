class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int,vector<int>> stop2route;
        for(int r =0 ; r < routes.size(); r++) {
            for(int stop : routes[r]) {
                stop2route[stop].push_back(r);
            }
        }

        queue<int> q;
        vector<char> routeSeen(routes.size(), 0);
        unordered_set<int> stopSeen;

        for(int r : stop2route[source]) {
            q.push(r);
            routeSeen[r] = 1;
        }

        int buses = 1;
        while(!q.empty()) {
            int layer = q.size();
            while(layer--) {
                int r = q.front();
                q.pop();

                for(int stop : routes[r]) {
                    if(stop ==target) return buses;
                    if(stopSeen.insert(stop).second) {
                        for(int next : stop2route[stop]) {
                            if(!routeSeen[next]) {
                                routeSeen[next] = 1;
                                q.push(next);
                            }
                        }
                    }

                }
            }
            buses++;
        }
        return -1;
    }
};