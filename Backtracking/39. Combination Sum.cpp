class Solution {
public:
void findCombination(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int> ds){
        if(target==0 && ind<arr.size())
        {ans.push_back(ds);return;}
    if(target<0 || ind>=arr.size()) return;
      // pick up the element 
        ds.push_back(arr[ind]);
        findCombination(ind,target-arr[ind],arr,ans,ds);
        ds.pop_back();
    // Non-pick
      findCombination(ind+1,target,arr,ans,ds);
    }
  public:
    vector<vector<int>>combinationSum(vector<int>&candidates,int target){
      vector<vector<int>>ans;
      vector<int>ds;
      findCombination(0,target,candidates,ans,ds);
      return ans;
    }
};
