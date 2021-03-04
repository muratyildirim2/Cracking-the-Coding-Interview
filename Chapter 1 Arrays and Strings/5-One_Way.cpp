#include<bits/stdc++.h>

using namespace std;
/*
One Away: There are three types of edits that can be performed on strings: insert a character,
remove a character, or replace a character. Given two strings, write a function to check if they are
one edit (or zero edits) away.
*/

bool check(string s1,string s2)
{


	string max1,min1;
	max1 = s1.length() >= s2.length() ? s1 : s2;  // which string is longer ?
	min1 = s1.length() < s2.length() ? s1 : s2;
	int len1, len2;
	len1 = max1.length();
	len2 = min1.length();
	if(abs(len1-len2)>1)   // if length diff bigger than 1 , return false.
		return false;
	
	bool flag = false;
	for(int i=0,j=0;i<len1 && j<len2;){
		if(max1[i]!=min1[j]){     // if this statement works two times , return false.
			if(flag)               
				return false;
			flag = true;
			if(len1 == len2)
				i++,j++;
			else
				i++;
		}
		else
			i++,j++;
	}
	return true;



}




int main()
{

string s1,s2;

cin>>s1>>s2;

if(check(s1,s2))
cout<<"True"<<endl;

else
cout<<"False"<<endl;


}