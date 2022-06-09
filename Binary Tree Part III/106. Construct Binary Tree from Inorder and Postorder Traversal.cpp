class Solution {
public:
    
    TreeNode* solve(vector<int> &postorder,int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd){
        
        if(postStart>postEnd) return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int index;
        for(int i = inStart; i <= inEnd; i++){
            if(inorder[i] == root->val){
                index = i;
                break;
            }
        }
        int numsLeft = inEnd - index;
        root->left = solve(postorder,postStart, postEnd - numsLeft - 1, inorder, inStart, index-1);
        root->right = solve(postorder, postEnd - numsLeft, postEnd - 1, inorder, index+1, inEnd);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        return solve(postorder,0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
