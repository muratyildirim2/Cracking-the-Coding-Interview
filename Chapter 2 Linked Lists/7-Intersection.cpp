
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*

AUTHOR : Murat Yıldırım

Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
node. Note that the intersection is defined based on reference, not value. That is, if the kth
node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting.
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

int listLen( node * head )
{
  int count = 0;
  while( head ) {
    head = head->next;
    count++;
  }
  return count;
}

  node * intersectionPoint( node * head1, node * head2 )
{
  int len1 = listLen(head1);
  int len2 = listLen(head2);

  node * ptr1 = ( len1 > len2 ) ? head1 : head2;
  node * ptr2 = ( len1 > len2 ) ? head2 : head1;
  int i = 0;
  while ( i < abs(len1 - len2) && ptr1 ) {
    ptr1 = ptr1->next;
    ++i;
  }

  while( ptr1 && ptr2 ) {
    if ( ptr1 == ptr2 ) {
      return ptr1;
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return nullptr;
}



int main()
{
    node *head = new node();
    head = NULL;
    node *head2 = new node();
    head2 = NULL;
    node *inter = new node();
    inter = NULL;
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



    inter=intersectionPoint(head,head2);
     print_list(inter);

    if(inter)
    {
        cout<<"Intersection node of lists is : "<<inter->data<<"\n";
        
        }
    
    else
    {
        cout<<"List do not interset \n";
        }
        
    return 0;
}
