<<<<<<<-------------------------------------------------------------- DFS --------------------------------------------------------------->>>>>>

void mapping(TreeNode* root,map<int,vector<int>,greater<int>>&m,int level){
    if(!root) return;
    m[level].push_back(root->val);
    mapping(root->left,m,level+1);
    mapping(root->right,m,level+1);    
}

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        map<int,vector<int>,greater<int>>m;
        mapping(root,m,1);
        vector<int>v;
        for(auto it: m){
            v=it.second;break;
        }
        int sum=accumulate(v.begin(),v.end(),0);
        return sum;
    }
};

<<<<<<<<<<<<<<<-------------------------------------------------------BFS---------------------------------------------------------->>>>>>>>>>>>>>>

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int sz=q.size();
            sum=0;
            while(sz--){
                auto node=q.front();q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                sum+=node->val;
            }
        }
        return sum;
    }
};
