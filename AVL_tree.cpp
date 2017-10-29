#include <iostream>
struct Node
{
    int i;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n)
{
    if(n == NULL)
        return 0;
    return n->height;
}

int getBalance(Node* n)
{
    if(n==NULL)
        return 0;
    return (height(n->left) - height(n->right));
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

Node* newNode(int val)
{
    Node* temp = new Node();
    temp->i = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

    return y;
}


Node* insert(Node* root, int val)
{
    if(root == NULL)
    {
        //allocate the memory for the Node and put the val into that memory
        return newNode(val);
    }

    if(val < root->i)
    {
        root->left = insert(root->left,val);
    }
    else if(val > root->i)
    {
        root->right = insert(root->right,val);
    }

    root->height = 1+max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if(balance > 1 && val < root->left->i)
        return rightRotate(root);

    if(balance < -1 && val > root->right->i)
        return leftRotate(root);

    if(balance > 1 && val > root->left->i)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && val < root->right->i)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void traverse(Node *root)
{
    if(root != NULL)
    {
        std::cout<<root->i<<std::endl;
        traverse(root->left);
        traverse(root->right);
    }
}


int main()
{
    Node* root;
    std::cout<<"AVL tree inserts"<<std::endl;
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,40);
    root = insert(root,50);
    root = insert(root,25);
    std::cout<<"Insertion complete....Now traversing"<<std::endl;
    traverse(root);

}
