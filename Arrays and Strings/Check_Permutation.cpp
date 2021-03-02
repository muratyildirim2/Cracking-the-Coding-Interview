#include <bits/stdc++.h>

using namespace std;

/*
                  Problem : Given two strings, write a method to decide if one is a permutation of the
                  other.
*/
bool arePermutation(string str1, string str2)
{
    
 // Create a count array and initialize all
    // values as 0
    int NO_OF_CHARS=128;
    int count[NO_OF_CHARS] = {0};
    int i;
 
   
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;                      // For example "aabcd" and "bcaad"
        count[str2[i]]--;                      // if all characters are equal , all count array(string) indexes should be zero .
    }                                          // because when it see 'a' in first array increase count['a'] but
                                               // at the same time decrease count['a'] when it see 'a' in second array(string).

    if (str1[i] || str2[i])
      return false;
 
    // See if there is any non-zero value in 
    // count array
    for (i = 0; i < NO_OF_CHARS; i++)
    {
        
        if (count[i])                            // if there is a index that not equals to 0 , it returns false.
            return false;

            }
     return true;
}

int main()
{

string s1,s2;
cin>>s1>>s2;

if(arePermutation(s1,s2))
cout<<"YES"<<endl;

else
cout<<"NO"<<endl;

    
}