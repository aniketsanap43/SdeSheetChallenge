/*TreeNode* solve(TreeNode* root, int num, TreeNode* prev){
        if(root==NULL && prev){
            TreeNode* newNode = new TreeNode(num);
            if(num<prev->val)
                prev->left =  newNode;
            else
                prev->right = newNode;
            return prev;
        }
        if(root->val>num)
             return solve(root->left, num, root);
        return solve(root->right, num, root);
    }
    */
    TreeNode* solveUpperBound(int &ind, vector<int>& preorder, int maxa){
        if(ind==preorder.size() || preorder[ind]>maxa) return NULL;
        TreeNode* root = new TreeNode(preorder[ind++]);
        root->left = solveUpperBound(ind,preorder,root->val);
        root->right = solveUpperBound(ind,preorder,maxa);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        /*TreeNode* root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
            solve(root,preorder[i], NULL);
        return root;*/
        int ind = 0;
        return solveUpperBound(ind,preorder, INT_MAX);
    }
