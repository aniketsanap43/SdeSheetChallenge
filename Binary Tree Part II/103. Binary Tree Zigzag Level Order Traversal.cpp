vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> vt;
            for(int i=0;i<size;i++){
                auto curr = q.front();
                vt.push_back(curr->val);
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(cnt%2!=0)
                reverse(vt.begin(),vt.end());
            ans.push_back(vt);
            cnt++;
        }
        return ans;
    }
