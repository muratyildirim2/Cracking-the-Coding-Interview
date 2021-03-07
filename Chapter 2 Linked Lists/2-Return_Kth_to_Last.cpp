#include <bits/stdc++.h>
/*
Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.

Author : Murat Yıldırım

*/
using namespace  std;

class node 
{
    public : 
int data;
 node *next;

};


void insert( node ** head_ref,int new_data)
{
     node* new_node = new  node();  
    

    node *last = *head_ref;  
    

    new_node->data = new_data;   
    

    new_node->next = NULL;   
   
    if (*head_ref == NULL)   
    {   
        *head_ref = new_node;   
        return;   
    }   
    
    while (last->next != NULL)   
        last = last->next;   
    
    last->next = new_node;   
    return;  


}
node*  returnKthtoLast( node * head,int k ) {
  if ( head == NULL ) {
    return head;
  }

  node * ptr1 = head;
  node * ptr2 = head;

  int i = 0;
  while( i < k && ptr1 ) {
    ptr1 = ptr1->next;
    ++i;
  }


  if ( i < k ) {
    return NULL;
  }

  while( ptr1 != NULL ) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  return ptr2;


	
}




void print_list(node *head)
{


while(head!=NULL)
{

cout<<head->data<<endl;

head=head->next;

}


}





int main()
{
    node *head=new node();
    head=NULL;

int n;
cout<<"Enter the Linked list length : ";
cin>>n;   //linked list length

int inp;
    for (int i=0;i<n;i++)
    {
        cin>>inp;
        insert(&head,inp);
       
    }

int k;
cout<<"Enter the K : ";
cin>>k;
node *newhead=new node();
  newhead=returnKthtoLast(head,k);
    print_list(newhead);


}