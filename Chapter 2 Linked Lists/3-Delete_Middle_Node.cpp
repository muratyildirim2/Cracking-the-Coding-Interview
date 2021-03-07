#include <bits/stdc++.h>
/*
Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but
the first and last node, not necessarily the exact middle) of a singly linked list, given only access to
that node.

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
void deleteNode( node **head_ref,int position ) {
 
   if (*head_ref == NULL) 
      return; 
  

   node* temp = *head_ref; 
  

    if (position == 0) 
    { 
        *head_ref = temp->next; 
        free(temp);              
        return; 
    } 
  

    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  

    if (temp == NULL || temp->next == NULL) 
         return; 

  node *next = temp->next->next; 
  

    free(temp->next);  
    temp->next = next;  

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
cout<<"Enter the Linked list length (Should be odd even)  : ";
cin>>n;   //linked list length
int counter=n;
int inp;
    for (int i=0;i<n;i++)
    {
        cin>>inp;
        insert(&head,inp);
     
    }


int middle = counter/2; 
deleteNode(&head,middle);

    print_list(head);


}