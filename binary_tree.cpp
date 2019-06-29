#include <iostream>
#include <list>

template<typename T>
struct Node{
  T i;
  Node* left;
  Node* right;
};

template<typename T>
class BST{

  Node<T>* head;

  void preOrderTraversal(Node<T>* n){
    if(n == nullptr)
      return;

    preOrderTraversal(n->left);
    std::cout<<n->i<<std::endl;
    preOrderTraversal(n->right);
    
  }

  void printLeafNodeHelper(Node<T>* n){
    if(n->left == nullptr && n->right == nullptr){
      std::cout<<n->i<<std::endl;
      return;
    }

    if(n->left != nullptr)
      printLeafNodeHelper(n->left);

    if(n->right != nullptr)
      printLeafNodeHelper(n->right);    
  }
  
public:
  
  BST():head(NULL)
  {}

  void addNode(T val){
    if(head == NULL){
      head = new Node<T>;
      head->i = val;
    }else{
      Node<T>* temp = head;
      while(temp){
	if(val < temp->i){
	  if(!temp->left){
	    temp->left = new Node<T>;
	    temp->left->i = val;
	    break;
	  }else{
	    temp = temp->left;
	  }
	}else{
	  if(!temp->right){
	    temp->right = new Node<T>;
	    temp->right->i = val;
	    break;
	  }else{
	    temp = temp->right;
	  }
	}
      }
    }
  }

  void traverse(){
    Node<T>* t = head;
    preOrderTraversal(t);
  }

  void printLeafNodes(){
    Node<T>* t = head;
    printLeafNodeHelper(t);
  }
  
  int levelOrderTraverse(){
    std::list<Node<T>*> queue;
    Node<T>* temp = head;
    queue.push_back(temp);

    int maxsize = 0;
    while(!queue.empty()){
      auto a = queue.front();
      //      std::cout<<a->i<<std::endl;
      queue.pop_front();

      if(a->left)
	queue.push_back(a->left);
      if(a->right)
	queue.push_back(a->right);

      if(queue.size() > maxsize)
	maxsize = queue.size();
    }

    // this max size will return max width of the tree
    return maxsize;
  }

};


int main(){
  BST<int> tree;
  tree.addNode(50);
  tree.addNode(30);
  tree.addNode(60);
  tree.addNode(10);
  tree.addNode(20);
  tree.addNode(55);
  tree.addNode(70);
  tree.addNode(45);
  tree.addNode(57);

  //  tree.traverse();
  //  tree.printLeafNodes();

  std::cout<<"Max tree width:"<<tree.levelOrderTraverse()<<std::endl;
}
