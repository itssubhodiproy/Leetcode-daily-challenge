class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //initializad visited array
        vector<int>vis(n);
        for(int i=0;i<n;i++)
            vis[i]=-1;
        int ele;
        queue<int>q;
        q.push(0);
        vis[0]=1;
        int i=0;
        while(i!=n){
            if(q.empty()) q.push(i);
            int top=q.front();
            q.pop();
            for(int j=0;j<graph[top].size();j++){
                if(vis[graph[top][j]]==-1){
                    vis[graph[top][j]]=1-vis[top];
                    q.push(graph[top][j]);
                }
                    
                 else if(vis[graph[top][j]]==vis[top])
                     return false;            
        }
        i++;
}
        return true;
        
    }
};
