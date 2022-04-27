//rank compression
int findPar(int n,vector<int>&parent){
    if(n==parent[n]) return n;
    return parent[n]=findPar(parent[n],parent);
}

void unionn(int u,int v, vector<int>&parent, vector<int>&rank){
     u=findPar(u,parent);
     v=findPar(v,parent);
    if(rank[u]>=rank[v]){
        parent[v]=u;
        rank[u]++;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.length();
        
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++)
            parent[i]=i;
    
        for(auto it: pairs){
            int u=findPar(it[0],parent);
            int v=findPar(it[1],parent);
            if(parent[u]!=parent[v])
                // unionn(u,v,parent,rank);
                parent[v]=u;
        }
        
        /* Create separate vectors from the subsets */
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < s.size(); i++) m[findPar(i,parent)].push_back(i);
        
        /* Sort the vertices in each vector and change the original 
         * array based on the sorted results 
         */
        for (auto x : m) {
            string str = ""; int j = 0;
            for (auto i : x.second) { str += s[i]; }
            sort(str.begin(), str.end());
            for (auto i : x.second) { s[i] = str[j++]; }
        }
        
        return s;
        
    }
};
