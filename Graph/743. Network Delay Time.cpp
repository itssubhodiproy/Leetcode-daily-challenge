typedef vector<int> vi;
typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k){
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto t : times)
        adj[t[0]].push_back({t[1], t[2]});
    vi dis(n + 1, 1e9);
    dis[0]=0;
    dis[k] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto it : adj[u])
        {
            int v = it.first, w = it.second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    int ans = *max_element(dis.begin(), dis.end());
    return ans == 1e9 ? -1 : ans;
}
};
