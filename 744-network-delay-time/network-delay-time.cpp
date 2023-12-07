class Solution {
public:
    void dijkstra(vector<int>& signal, int n, int k, vector<vector<pair<int, int>>>& adj){
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({0, k});

      signal[k] = 0;

      while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        int curnode = t.second;
        int curtime = t.first;

        if (curtime > signal[curnode]) continue;
        for (pair<int, int> edge : adj[curnode]) {
          int time = edge.first;
          int nei = edge.second;

          if (signal[nei] > curtime + time) {
            signal[nei] = curtime + time;
            pq.push({signal[nei], nei});
          }
        }
      }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto t : times) {
          adj[t[0]].push_back({t[2], t[1]});
        }
        vector<int> signal(n + 1, INT_MAX);
        dijkstra(signal, n, k, adj);

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {
          ans = max(ans, signal[i]);
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
