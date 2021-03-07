#include <bits/stdc++.h>

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
void removeDuplicates( node * head ) {
	if ( head == NULL || ( head && (head->next == NULL))) {
		return;
	}
	node * curr = head;
	while(curr) {
		node * temp = curr;
		while (temp->next != NULL) {
			if (temp->next->data == curr->data) {
				temp->next = temp->next->next;
			} else {
				temp = temp->next;
			}
		}
		curr = curr->next;
	}
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
cout<<"Linked list length : ";
cin>>n;   //linked list length

int inp;
    for (int i=0;i<n;i++)
    {
        cin>>inp;
        insert(&head,inp);
       
    }
  removeDuplicates(head);
    print_list(head);


}