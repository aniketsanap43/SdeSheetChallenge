pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    stack< BinaryTreeNode<int>* > st;
    pair<int, int> p;
    p.first = -1;
    p.second = -1;
    BinaryTreeNode<int>* prev = new BinaryTreeNode<int>(-1);
    int i = 0;
    while(root!=NULL || !st.empty()){
        //cout<<"r: "<<root->data<<endl;
        if(root!=NULL){
            st.push(root);
            root = root->left;
            continue;
        }
        BinaryTreeNode<int>* curr = st.top();
        st.pop();
        //cout<<curr->data<<endl;
        if(i==1){
            //cout<<"here2"<<endl;
            p.second = curr->data;
            break;
        }
        if(curr->data == key){
            //cout<<"here"<<endl;
            if(prev) p.first = prev->data;
            i++;
        }
        prev = curr;
        root = curr->right;
    }
    return p;
}
