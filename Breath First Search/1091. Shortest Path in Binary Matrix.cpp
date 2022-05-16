
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1]==1) return -1;      
        vector<vector<int>>directions={{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        queue<pair<int,int>>q;
        grid[0][0]=1;
        q.push({0,0});
        while(!q.empty()){
            auto top=q.front();
            int i=top.first, j=top.second;
            if(i==n-1 && j==n-1) return grid[i][j];
            for(auto it: directions){
                int di=i+it[0];
                int dj=j+it[1];
                if(di>=0 && di<n && dj>=0 && dj<n && grid[di][dj]==0){
                    grid[di][dj]=grid[i][j]+1;
                    q.push({di,dj});
                }
            }
            q.pop();
    }
        return -1;
    }
};
