class Solution {
public:
int dp[200][200]; // constraints are small enough that we can just set them to MAX
int cnt, n, m;
vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
int longestIncreasingPath(vector<vector<int>>& matrix) {
	cnt = 0, n = size(matrix), m = size(matrix[0]);
    memset(dp,-1,sizeof dp);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cnt = max(cnt, solve(matrix, i, j, -1));            
	return cnt;
}
int solve(vector<vector<int>>& mat, int i, int j, int prev){
	if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] <= prev) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
    for(auto it: directions){
        int demoi=i+it[0],demoj=j+it[1];
        dp[i][j] = max(dp[i][j],1+solve(mat, demoi, demoj, mat[i][j]) );
    }
	return dp[i][j];      
}
};
