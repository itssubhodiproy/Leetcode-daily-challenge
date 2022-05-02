class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int f1=0,f2=0;
        while(f2!=n){
            if(nums[f1]%2==0) f1++;
            else if(nums[f2]%2==0) swap(nums[f2],nums[f1++]);
            f2++;
        }
        return nums;
    }
};
