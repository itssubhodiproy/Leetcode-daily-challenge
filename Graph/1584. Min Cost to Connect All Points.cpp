//if we use krushkal algo, we'll need to know the concept of Disjoint set union

class Solution {
public:
    int find(vector<int> &ds, int i) {
      return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
     int spanningTree(int n, vector<array<int, 3>> &arr)
    {
        int res=0;vector<int> ds(n, -1);
        make_heap(begin(arr), end(arr), greater<array<int, 3>>());   
    while (!arr.empty()) {
        pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
        auto [dist, i, j] = arr.back();
        arr.pop_back();
        i = find(ds, i), j = find(ds, j);
        if (i != j) {
            res += dist;
            ds[i] += ds[j];
            ds[j] = i;
            if (ds[i] == -n)
                break;
        }
    }
    return res;
}
      
    int minCostConnectPoints(vector<vector<int>>& ps) {
    vector<array<int, 3>> arr;
    for (auto i = 0; i < n; ++i)
        for (auto j = i + 1; j < n; ++j) {
            arr.push_back({abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j});
        }
        return spanningTree(ps.size(),arr);
    }
};
