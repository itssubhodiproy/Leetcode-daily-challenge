<<-----------------------------------------------------------MEMOIZATION------------------------------------------------------------------------------->>
int dp[101][101];
int knapsack(int i,int j,int m,int n,vector<vector<int>>v){
    if(i==m||j==n||v[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=knapsack(i,j+1,m,n,v)+knapsack(i+1,j,m,n,v);
}

<<-----------------------------------------------------------TABULATION-------------------------------------------------------------------------------->>
int tabu(int m,int n,vector<vector<int>>v){
    int mat[m][n];
    for(int i=0; i<m ;i++){
      for(int j=0; j<n; j++){
        //obstacle base condition
          if(v[i][j]==1){
              mat[i][j]=0;
              continue;
          } 
          //base condition
          if(i==0 && j==0){
              mat[i][j]=1;
              continue;
          } 
          int up=0,left = 0;
          if(i>0) // Boundary check
            up = mat[i-1][j];
          if(j>0) // Boundary check
            left = mat[i][j-1];
          mat[i][j] = up+left;
      }
  }  
  return mat[m-1][n-1];
}
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size();
        int n=v[0].size();
        memset(dp,-1,sizeof dp);
        return tabu(m,n,v);
    }
};
