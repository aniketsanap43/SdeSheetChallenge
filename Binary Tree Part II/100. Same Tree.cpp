bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
        if((p && q==NULL) || (p==NULL && q))
            return false;
        
        if(!(isSameTree(p->left,q->left))) return false;
        if(!(isSameTree(p->right,q->right))) return false;
        
        if(p->val == q->val)
            return true;
        
        return false;
}
