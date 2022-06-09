TreeNode<int>* solve(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> hash){
    if(preStart> preEnd || inStart>inEnd) return NULL;
    
    int rootData = preorder[preStart];
    TreeNode<int> * root = new TreeNode<int>(rootData);
    
    int inRoot = hash[rootData];
    int numsLeft =inRoot - inStart;
    
    root->left =  solve(preorder, preStart+1, preStart + numsLeft, inorder, inStart, inRoot-1, hash);
    root->right = solve(preorder, preStart + numsLeft + 1, preEnd ,inorder ,inRoot+1,inEnd, hash);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int, int> hash;
    int size = inorder.size();
    for(int i=0;i<size;i++)
        hash[inorder[i]] = i;
    TreeNode<int> * root = solve(preorder, 0, preorder.size()-1, inorder, 0,inorder.size()-1, hash);
    return root;
    
}
