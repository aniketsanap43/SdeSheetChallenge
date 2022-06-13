//codestudios

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    BinaryTreeNode<int> *temp = root;
    while(temp){
        BinaryTreeNode<int> *curr = temp;
        //cout<<temp<<endl;
        while(curr){
            if(!curr->left && !curr->right){
                curr=curr->next;
                continue;
            }
            if(curr->left) curr->left->next = curr->right;
            BinaryTreeNode<int> * prev = curr->right;
            if(!curr->right) prev = curr->left;
            BinaryTreeNode<int> * demo = curr->next;
            if(curr->next){
                while(demo && demo->left==NULL && demo->right==NULL){
                    demo = demo->next;
                    if(!demo) break;
                }
                if(demo && demo->left) prev->next = demo->left;
                else if(demo && demo->right) prev->next = demo->right;
            }
            curr = demo;
        }
       if(temp->left) temp = temp->left;
        else temp = temp->right;
    }
}
