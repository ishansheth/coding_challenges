//https://www.hackerrank.com/challenges/tree-top-view/problem

void levelOrder(node * root) {
    if(!root)
        return;
    std::queue<node*> myqueue;
    myqueue.push(root);
    while(!myqueue.empty())
    {
        node* current = myqueue.front();
        std::cout<<current->data<<" ";
        if(current->left != NULL)
            myqueue.push(current->left);
        if(current->right != NULL)
            myqueue.push(current->right);
        myqueue.pop();
        
    }  
}
