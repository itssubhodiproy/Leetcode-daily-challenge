// time complexity O(n) and space O(n)
unordered_map<int,int>m;
        int count=0;
        for(auto it: nums){
            int reqnum=k-it;
            if(m[reqnum]>0) {m[reqnum]--;count++;}
            else m[it]++;
        }
return count;

//space complexity O(nlogn) and space O(1)
sort(nums.begin(),nums.end());
        int count=0;int i=0,j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==k)
                {i++;j--;count++;}
            else if(nums[i]+nums[j]>k)
                j--;
            else 
                i++;
        }
        return count;
