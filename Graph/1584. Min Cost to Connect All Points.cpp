//if we use krushkal algo, we'll need to know the concept of Disjoint set union

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
    int minCostConnectPoints(vector<vector<int>>& ps) {
        int n=ps.size();
                   // wt,u,v
        vector<tuple<int,int,int>>v;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(ps[i][0]-ps[j][0])+abs(ps[i][1]-ps[j][1]);
                v.push_back(make_tuple(wt,i,j));
            }
        }
        
        sort(v.begin(),v.end());
        vector<int> parent(n),rank(n,0);
	    for(int i = 0;i<n;i++) 
	    parent[i] = i; 
	
	int cost = 0;
	for(auto it : v) {
        int ele1=findPar(get<1>(it),parent);
        int ele2=findPar(get<2>(it),parent);
	    if(ele1 != ele2) {
	        cost += get<0>(it); 
	        unionn(ele1,ele2,parent,rank); 
	    }
    }
	return cost;
    }
};
