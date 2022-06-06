//solved on coding ninjas

TreeNode<int>* solve(TreeNode<int> *root, int x, int y)
{
    if(root==NULL || root->data==x || root->data==y)
        return root;
    TreeNode<int> *lr = solve(root->left,x,y);
    TreeNode<int> *rr = solve(root->right,x,y);
    
    if(lr==NULL)
        return rr;
    else if(rr==NULL)
        return lr;
    else
        return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    TreeNode<int> *temp =  solve(root, x,y);
    return temp->data;
	//    Write your code here
}
