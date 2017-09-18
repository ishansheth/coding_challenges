//https://www.hackerrank.com/challenges/30-linked-list-deletion
Node* removeDuplicates(Node *head)
          {
            //Write your code here
              Node *n = head;
              while(n->next){
                  if(n->data == n->next->data){
                      n->next = n->next->next;
                  }else{
                      n = n->next;
                  }
              }
              return head;
          }
