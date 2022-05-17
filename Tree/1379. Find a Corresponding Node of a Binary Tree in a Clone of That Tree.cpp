TreeNode* f(TreeNode* root,TreeNode* target){
    if(!root) return NULL;
    if(root->val==target->val) return root;
    if(f(root->right,target)!=NULL) return f(root->right,target);
    if(f(root->left,target)!=NULL) return f(root->left,target);
    return NULL;
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       return f(cloned,target); //DFS
        
        //BFS
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
        int sz=q.size();
            while(sz--){
                TreeNode* top=q.front();q.pop();
                if(top->val==target->val) return top;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
        }
        return NULL;
    }
};
