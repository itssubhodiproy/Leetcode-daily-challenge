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
       return f(cloned,target); 
    }
};
