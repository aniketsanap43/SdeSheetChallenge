TreeNode<int> * p =NULL;
void flatten(TreeNode<int> *root){
    if(root==NULL)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    prev = NULL;
    flatten(root);
    return root;
}
