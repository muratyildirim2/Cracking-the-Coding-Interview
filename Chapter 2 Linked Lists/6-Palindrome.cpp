
#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*

AUTHOR : Murat Yıldırım

Palindrome: Implement a function to check if a linked list is a palindrome.
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
node *reverse(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

 bool isPalindromeRecurHelper( node * & left, node * right ) {

  if ( right == nullptr ) {
    return true;
  }


  bool isPalindrome = isPalindromeRecurHelper(left, right->next);
  if (!isPalindrome) {
    return false;
  }


  isPalindrome = ( left->data == right->data );


  left = left->next;

  return isPalindrome;
}

bool isPalindromeRecur( node * head ) {
  return isPalindromeRecurHelper(head, head);
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
   
             print_list(head);
            
             if(isPalindromeRecur(head))
             cout<<"Yes\n";
             
             else
             cout<<"No\n";
            

    return 0;
}
