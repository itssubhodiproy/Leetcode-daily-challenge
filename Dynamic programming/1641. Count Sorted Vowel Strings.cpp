class Solution {
public:
    int countVowelStrings(int n) {
       vector<int>dp(5,1);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=4;++j){
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[4];
    }
};
