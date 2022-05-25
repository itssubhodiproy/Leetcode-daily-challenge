// // some type of compiler issue happening in this logic
int dp[10001][10001];
int knapsack(vector<vector<int>>& env, int prevL, int prevR, int i){
    if(i==env.size()) return 0;
    int l=env[i][0];
    int r=env[i][1];
    if(dp[prevL][prevR]!=-1) return dp[prevL][prevR];
    if(l>prevL && r>prevR)
        return dp[prevL][prevR]=max(1+knapsack(env,l,r,i+1),knapsack(env,prevL,prevR,i+1));
    return dp[prevL][prevR]=knapsack(env,prevL,prevR,i+1);
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end());
        memset(dp,-1,sizeof dp);
        return knapsack(env,0,0,0);
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : E) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};
