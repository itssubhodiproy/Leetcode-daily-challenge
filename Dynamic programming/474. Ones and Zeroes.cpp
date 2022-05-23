----------------------------------------------------MEMOIZATION----------------------------------------------------------------------------
int zeros(string &s){
    int count=0;
    for(auto it: s)
        if(it=='0')
            count++;
    return count;
}
int dp[601][101][101];
int knapsack(vector<string>& str,int m,int n,int i){
    if(i==-1) return 0;
    if(m==0 && n==0)return 0;
    if(dp[i][m][n]!=-1) return dp[i][m][n];
    int zero=zeros(str[i]);
    int one =str[i].length()-zero;
    if(m>=zero&&n>=one) return dp[i][m][n]=max(1+knapsack(str,m-zero,n-one,i-1),knapsack(str,m,n,i-1));
    return dp[i][m][n]= knapsack(str,m,n,i-1);
}

class Solution {
public:
    int findMaxForm(vector<string>& str, int m, int n) {
       
       //  return knapsack(str,m,n,str.size()-1);
int dp[m+1][n+1];
memset(dp,0,sizeof dp);
    ----------------------------------------------------TABULATION----------------------------------------------------------------------------
for(auto &it: str){
    int zero=count(it.begin(),it.end(),'0');
    int one =it.length()-zero;
    for(int i=m;i>=zero;i--){
        for(int j=n;j>=one;j--){
            dp[i][j]=max(1+dp[i-zero][j-one],dp[i][j]);
           }
      }
  }
      return dp[m][n];
  }
};
