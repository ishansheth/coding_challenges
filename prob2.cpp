//https://www.hackerrank.com/challenges/30-binary-search-trees
	int getHeight(Node* root){
          //Write your code here
              //Write your code here
          if(!root) {
              return -1;
          }
          int leftDepth = getHeight(root->left);
          int rightDepth = getHeight(root->right);
              
          return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;

        }
