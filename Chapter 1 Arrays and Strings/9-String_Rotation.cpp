#include<bits/stdc++.h>

using namespace std;

/*
String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
*/

bool is_rotation(string s1,string s2)
{
    if(s1.length()!=s2.length() || s1.length()==0)
    {

        return false;
    }

   string control=s1+s1;


   if(control.find(s2)!=-1)
   {
       return true;
   }

   else
   return  false;



}



int main()
{
    string s1,s2;


cin>>s1>>s2;


if(is_rotation(s1,s2))
cout<<"YES"<<endl;

else
cout<<"NO"<<endl;




}