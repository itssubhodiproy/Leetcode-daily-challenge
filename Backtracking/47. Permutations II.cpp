class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms;
        permute(nums, 0, perms);
        vector<vector<int>> ans;
        for(auto it: perms)
            ans.push_back(it);
        return ans;
    }
private:
    void permute(vector<int> nums, int i, set<vector<int>>& perms) {
        if (i == nums.size()) 
            perms.insert(nums);
            for (int j = i; j < nums.size(); j++) {
                    swap(nums[i], nums[j]);
                    permute(nums, i + 1, perms);
                    swap(nums[i], nums[j]);   
            }    
    }
};

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        ans.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
            ans.push_back(nums);
        return ans;
    }
};
