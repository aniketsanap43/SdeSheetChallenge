TreeNode* solve(vector<int> nums, int i, int j){
        
        if(i>j)
            return NULL;
        int mid = i + (j-i)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(nums, i,mid-1);
        root->right = solve(nums, mid+1, j);
        return root;
}

TreeNode* sortedArrayToBST(vector<int>& num) {
    return solve(nums, 0, nums.size()-1);
    }
