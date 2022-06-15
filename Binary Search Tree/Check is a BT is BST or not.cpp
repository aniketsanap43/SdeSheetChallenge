bool solve(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev){
    if(root==NULL) return true;
    if(!solve(root->left,prev)) return false;
    if(prev!=NULL && prev->data>=root->data) return false;
    prev = root;
    return solve(root->right, prev);
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    BinaryTreeNode<int> * prev = NULL;
    return solve(root, prev);
}
