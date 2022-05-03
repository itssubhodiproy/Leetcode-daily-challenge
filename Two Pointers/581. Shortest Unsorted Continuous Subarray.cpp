class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        //main code O(n)
        int first=0;
        int last=0;    
        vector<int>v=nums;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i]!=nums[i]){
                first=i;
            break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(v[i]!=nums[i]){
                last=i;
            break;
            }
        }
        if(first==0 && last==0)
            return 0;
        return last-first+1;
        
        
    }
};
