#include<bits/stdc++.h>
using namespace std;
/*
 Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words
 
 
 */




bool any_palindrome(string s)
{

    int hash[128];
    memset(hash,0,sizeof(hash));
    
    int odd_count=0;
    
    for(char a : s)
    {
        hash[a]++;   //we count how many odd characters. 
    }

     
    for(char a : s)
    {
        if(hash[a]%2==1 && a>='A' && a<='z'){ //We cannot count ' '.
            odd_count++;  
          
        }
    }

    
    
    if(odd_count>1)  // if count of odd character bigger than 1
        return 0;    // return 0;
    
    else
        return 1;
    
    
}



int main()
{

    
    string str="Tact Coa";
    string str1="";
    
    for (char a : str)
    {
        str1+=tolower(a);  // All chacters should be lowercase.
    }
    
  
    
    if(any_palindrome(str1))
        cout<<"YES"<<endl;

    else
        cout<<"NO"<<endl;
}