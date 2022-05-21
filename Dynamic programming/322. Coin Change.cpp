// int dp[10000+5][12+5];

// int f(vector<int> coins,int amount,int n){
//     if(amount==0||n==0) 
//         return amount==0? 0:INT_MAX-1;   
// if(dp[amount][n]!=-1) return dp[amount][n];
// if(coins[n-1]>amount) return dp[amount][n]=f(coins,amount,n-1);
// return dp[amount][n]= min(1+f(coins,amount-coins[n-1],n),f(coins,amount,n-1));
// }

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//        memset(dp,-1,sizeof dp);
//        int val=f(coins,amount,coins.size());
//        return val==INT_MAX-1 ? -1:val;
//     }
// };
----------------------------------------------------------------------ONLY Reference can give TLE-------------------------------------------
int dp[10000+5][12+5];
int f(vector<int> &coins,int amount,int n){
    if(amount==0||n==0) 
        return amount==0? 0:INT_MAX-1;   
if(dp[amount][n]!=-1) return dp[amount][n];
if(coins[n-1]>amount) return dp[amount][n]=f(coins,amount,n-1);
return dp[amount][n]= min(1+f(coins,amount-coins[n-1],n),f(coins,amount,n-1));
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       memset(dp,-1,sizeof(dp));
       int val=f(coins,amount,coins.size());
       return val==INT_MAX-1 ? -1:val;
    }
};
