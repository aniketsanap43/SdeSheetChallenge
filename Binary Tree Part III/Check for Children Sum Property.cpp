void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    
    if(root==NULL)
        return;
    int lData = root->left?root->left->data:0;
    int rData = root->right?root->right->data:0;
    if((lData + rData) < root->data){
        if(root->left) root->left->data =  root->data;
        else if(root->right) root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
      if (root -> left) tot += root -> left -> data;
      if (root -> right) tot += root -> right -> data;
      if (root -> left || root -> right) root -> data = tot;
}  
