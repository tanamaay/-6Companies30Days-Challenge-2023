class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int solve(TreeNode* root){
        //base case
        if(!root)return 0;
        if(mp.count(root))return mp[root];
        int l=solve(root->left);
        int r=solve(root->right);
        int ll=0,lr=0,rl=0,rr=0;
        if(root->left){
            ll=solve(root->left->left);
            lr=solve(root->left->right);
        }
        if(root->right){
            rl=solve(root->right->left);
            rr=solve(root->right->right);
        }
        int val=root->val;
        int lmx=ll+lr;
        int rmx=rl+rr;
        //if we take the root node
        int t1=val+lmx+rmx;
        //if we take the left child of root
        int t2=l+max(r,rmx);
        //if we take the right child of root
        int t3=r+max(l,lmx);
        //take maximum of all the cases and memoize
        mp[root]=max(t1,max(t2,t3));
        return mp[root];
    }
    int rob(TreeNode* root) {
        return solve(root);
    }
};
