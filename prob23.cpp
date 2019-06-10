#include <iostream>
#include <vector>

void mergeTwoArrays(int arr1[], int arr2[],int n1, int n2){
  int* arr3 = new int[n1+n2];
  int i = 0,j=0,k=0;
  for(;i<n1 && j<n2;){
    if(arr1[i] < arr2[j]){
      arr3[k] = arr1[i];
      i++;
    }else{
      arr3[k] = arr2[j];
      j++;
    }
    k++;
  }

  while(i<n1)
    arr3[k++] = arr1[i++];

  while(j<n2)
    arr3[k++] = arr2[j++];

  for(int i = 0;i<(n1+n2);i++)
    std::cout<<arr3[i]<<std::endl;
}

std::vector<int> mergeTwoArrays(std::vector<int> arr1, std::vector<int> arr2){
  std::vector<int> arr3(arr1.size()+arr2.size());
  
  int i = 0,j=0,k=0;
  for(;i<arr1.size() && j<arr2.size();){
    if(arr1[i] < arr2[j]){
      arr3[k] = arr1[i];
      i++;
    }else{
      arr3[k] = arr2[j];
      j++;
    }
    k++;
  }

  while(i<arr1.size())
    arr3[k++] = arr1[i++];

  while(j<arr2.size())
    arr3[k++] = arr2[j++];

  return arr3;
}
/**
   Merge Sort algorithm
 **/
void mergeSort(int arr[], int n1){
  if(n1<2){
    return;
  }
  int l1 = n1/2;
  int left[l1];
  for(int i = 0;i<l1;i++)
    left[i] = arr[i];
  int l2 = n1 - (n1/2);
  int right[l2];
  for(int i = l1,j=0;i<n1;i++,j++)
    right[j] = arr[i];
  
  mergeSort(left,l1);
  mergeSort(right,l2);
  mergeTwoArrays(left,right,l1,l2);
}

void mergeArrays(int arr[][4],int k){

  if(k<2)
    return;

  mergeArrays(arr,k/2);

  int temp[k*4];
  int arr1[k*4/2];
  int arr2[k*4/2];
  for(int i = 0;i<k*4/2;i++){
    arr1[i] = arr[0][i];
    arr2[i] = arr[k/2][i];
  }
  for(int i = 0;i<(k*4)/2;i++){
    temp[i] = arr1[i];
  }
  for(int i = 0,j = (k*4)/2;i<(k*4)/2;i++,j++){
    temp[j] = arr2[i];
  }
  for(int i = 0;i<k*4;i++)
    std::cout<<"----->"<<temp[i]<<std::endl;

  std::cout<<"=============="<<std::endl;

}

void mergeArrays(std::vector<std::vector<int>> arr){

  
}



/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
**/

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
  ListNode* res = new ListNode(0);
  ListNode *head = res;
  int carry = 0;
  while(l1 != NULL && l2 != NULL){
    int sum = l1->val + l2->val + carry;
    if(sum >= 10){
      carry = sum / 10;
      int digit = sum % 10;
      res->val = digit;
    }else{
      carry = 0;
      res->val = sum;	    
    }
    l1 = l1->next;
    l2 = l2->next;

    if(l1 != NULL || l2 != NULL){
      if(res->next == NULL)
	res->next = new ListNode(0);    
      res = res->next;
    }
  }

  if(carry != 0 && l1 == NULL && l2 == NULL){
    if(res->next == NULL)
      res->next = new ListNode(carry);    
  }

  while(l1 != NULL){
    int sum = l1->val + carry;
    if(sum >= 10){
      res->val = sum % 10;
      carry = sum / 10;
    }else{
      res->val = sum;
      carry = 0;
    }
    l1 = l1->next;
    if(l1 != NULL){
      if(res->next == NULL)
	res->next = new ListNode(0);    
      res = res->next;
    }
  }

  while(l2 != NULL){
    int sum = l2->val + carry;
    if(sum >= 10){
      res->val = sum % 10;
      carry = sum / 10;
    }else{
      res->val = sum;
      carry = 0;
    }
    l2 = l2->next;
    if(l2 != NULL){
      if(res->next == NULL)
	res->next = new ListNode(0);    
      res = res->next;
    }
  }

  if(carry != 0 && l1 == NULL && l2 == NULL){
    if(res->next == NULL)
      res->next = new ListNode(carry);    
  }

  return head;
}

int main(){
  int arr1[] = {1,3,4,5};
  int arr2[] = {2,4,6,8};

  int size1 = sizeof(arr1)/sizeof(arr1[0]);
  int size2 = sizeof(arr2)/sizeof(arr2[0]);

  //  mergeArrays(arr1,arr2,size1,size2);

  //  mergeSort(arr1,size1);


  int twodarr[][4] = {{1,3,5,7},{2,4,6,8},{0,9,10,11},{11,14,15,16}};
  //  mergeArrays(twodarr,4);


  ListNode* a;
  a = new ListNode(9);
  a->next = new ListNode(9);
  a->next->next = new ListNode(3);
  a->next->next->next = new ListNode(2);
  a->next->next->next->next = new ListNode(1);
  
  ListNode* b;
  b = new ListNode(1);
  b->next = new ListNode(6);
  b->next->next = new ListNode(9);
  
  ListNode* res = addTwoNumbers(a,b);
  while(res != NULL){
    std::cout<<res->val<<std::endl;
    res = res->next;
  }

  
}
