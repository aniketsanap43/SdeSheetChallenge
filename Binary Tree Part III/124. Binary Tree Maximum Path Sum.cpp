int solve(TreeNode<int> *root, int &maxa){
    if(root==NULL) return 0;
    int lr = max(0, solve(root->left,maxa));
    int rr = max(0, solve(root->right,maxa));
    maxa = max(maxa,  lr+ rr + root->val);
    return root->val + max(lr,rr);
}

int findMaxSumPath(TreeNode<int> *root)
{
    int maxa = INT_MIN;
    solve(root,maxa);
    return maxa;
    // Write your code here.
}
