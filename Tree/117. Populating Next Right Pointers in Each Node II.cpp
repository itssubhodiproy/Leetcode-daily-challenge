Two different type of Logic

void dfs(map<int,vector<Node*>>&m,Node* root,int level){
    if(!root) return;
    m[level].push_back(root);
    dfs(m,root->left,level+1);
    dfs(m,root->right,level+1);
}


class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>q;q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                Node* curr=q.front();q.pop();
                if(sz-1==0)
                    curr->next=NULL;
                else
                    curr->next=q.front();   
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};
