/*
Author : Murat yıldırım

Partition: Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. If x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.


 */
#include<bits/stdc++.h>

using namespace std;
using namespace  std;

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

node *partition( node *listhead, int x )
{
    node *head = nullptr;

    node *headInitial = nullptr;    //The initial node of list head

    node *tail = nullptr;

    node *tailInitial = nullptr;    //The initial node of list tail

    node *curr = listhead;

    while( curr != nullptr )
    {
        node *nextNode = curr->next;
        if ( curr->data < x )
        {
            if (head == nullptr)
            {
                head = curr;
                headInitial = head;
            }
            //insert curr node to head list
            head->next = curr;
            head = curr;
        }
        else
        {
            if (tail == nullptr)
            {
                tail = curr;
                tailInitial = tail;
            }
            // insert curr node to tail list
            tail->next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    head->next = tailInitial;  //Now, we connect the head list to tail list.(Combine two lists.)
    tail->next = nullptr;
    return headInitial;
}







int main()
{

    node *head = new node();
    head = NULL;
    int inp;
    int n ; // number of elements
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> inp;   // elements..
        insert(&head, inp);
    }
    int x;
    cin >> x; // x value
    cout << "Given list\n";
    print_list(head);

    cout << "After Partition... \n";
    print_list(partition(head, x));

}
