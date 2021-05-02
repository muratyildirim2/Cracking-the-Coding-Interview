
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*

AUTHOR : Murat Yıldırım

Sum Lists: You have two numbers represented by a linked list, where each node contains a single
digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a
function that adds the two numbers and returns the sum as a linked list.
*/
class node
{
public :              //node class
    int data;
    node *next;

};

void insert( node **head_ref, int new_data)
{
    node *new_node = new  node();   // insert function


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

void print_list(node *head)
{
    //print all list


    while(head != NULL)
    {

        if(head->next != NULL)
            cout << head->data << "-->";

        else
            cout << head->data ;

        head = head->next;

    }

    cout << "\n";
}
  node* reverse(node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        node* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;
    }


node* calculate_sum(node* head,node* head2,node** sum)
{
    int remain=0;


    while(head!=NULL || head2!=NULL)
    {
       
            if((head->data+head2->data)%10+remain<10){
        insert(sum,(head->data+head2->data)%10+remain);
        remain=0;

    }

else
{
    insert(sum,(head->data+head2->data+remain)%10);
    remain=(head->data+head2->data+remain)/10;

}

        
 remain = (head->data+head2->data+remain)/10;
        head= head->next;
        head2=head2->next;

    }

    if(remain==1)
        insert(sum,1);

return *sum;


}

int main()
{
      node *head = new node();
    head = NULL;
      node *head2 = new node();
    head2 = NULL;
    node *sum = new node();
    sum = NULL;
    int inp;
    int n ; // number of elements
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> inp;   // elements..
        insert(&head, inp);
    }
       for(int i = 0; i < n; ++i)
    {
        cin >> inp;   // elements..
        insert(&head2, inp);
    }



sum = calculate_sum(head,head2,&sum);
sum = reverse(sum);
print_list(sum);

    return 0;
}
