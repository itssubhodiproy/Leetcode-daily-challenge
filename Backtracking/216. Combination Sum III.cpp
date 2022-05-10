void helper(vector<vector<int>> &res,vector<int> sol,int k, int n){
    if(sol.size()==k && n==0) {res.push_back(sol);return;}
    if(sol.size()>k) return;
    for(int i=sol.empty()? 1:sol.back()+1;i<=9;++i){
        if(n-i<0) break;
        sol.push_back(i);
        helper(res,sol,k,n-i);
        sol.pop_back();
    }   
}
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        helper(res,sol,k,n);
        return res;
    }
};
