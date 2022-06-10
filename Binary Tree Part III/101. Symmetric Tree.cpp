bool solve(BinaryTreeNode<int>* lr, BinaryTreeNode<int>* rr){
    if(lr==NULL || rr==NULL)
        return lr==rr;
    if(lr->data!=rr->data) return false;
    
    return solve(lr->left, rr->right) && solve(lr->right, rr->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return root==NULL || solve(root->left, root->right);
    // Write your code here.    
}
