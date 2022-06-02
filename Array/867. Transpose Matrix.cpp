class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix){
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>copy(col,vector<int>(row));
        for(int i=0;i<col;++i)
            for(int j=0;j<row;++j)
                copy[i][j]=matrix[j][i];
        return copy;
    }
};
