#include <bits/stdc++.h>

using namespace std;


// Problem : Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures? 

int sort_and_find(string s)
{



sort(s.begin(),s.end());

for (int i=1;i<s.length();i++)     // O(n log n)
{
   if(s[i]==s[i-1])
   return 0;

}

return 1;


}
const int MAX_CHAR = 256;
 
bool uniqueCharacters(string str)
{
 
    // If length is greater than 265,
    // some characters must have been repeated for this reeason return false
    if (str.length() > MAX_CHAR)
        return false;
 
    bool chars[MAX_CHAR] = { 0 };
    for (int i = 0; i < str.length(); i++) {      // O(n)
        if (chars[int(str[i])] == true)
            return false;
 
        chars[int(str[i])] = true;
    }
    return true;
}
bool areChractersUnique_without_DS(string str) 
{ 
    // An integer to store presence/absence 
    // of 26 characters using its 32 bits. 
    int checker = 0; 
  
    for (int i = 0; i < str.length(); ++i)             // O(n)
    { 
        int val = (str[i]-'a'); 
  
        // If bit corresponding to current 
        // character is already set 
        if ((checker & (1 << val)) > 0) 
            return false; 
  
        // set bit in checker 
        checker |=  (1 << val); 
    } 
  
    return true; 
} 


int main()
{




string s;
cin>>s;


int answer= sort_and_find (s);

if(answer)
cout<<"Solution 1 :Unique"<<endl;

else
cout<<"Solution 1 : Not Unique"<<endl;



bool answer2=uniqueCharacters(s);


if(answer2)
cout<<"Solution 2 :Unique"<<endl;

else
cout<<"Solution 2 : Not Unique"<<endl;


bool answer3=areChractersUnique_without_DS(s);


if(answer3)
cout<<"Solution 3 :Unique"<<endl;

else
cout<<"Solution 3 : Not Unique"<<endl;


}