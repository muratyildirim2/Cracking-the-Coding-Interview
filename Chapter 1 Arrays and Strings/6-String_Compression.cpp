#include<bits/stdc++.h>

using namespace std;
/*
String Compression: Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
"compressed" string would not become smaller than the original string, your method should return
the original string. You can assume the string has only uppercase and lowercase letters (a - z).
*/

string compress(string s)
{
string out="";
int counter=1;
int i;
for( i=1;i<s.length();i++)
{


    if(s[i]==s[i-1])
    counter++;

else
{
out+=s[i-1];
out+=to_string(counter);

counter=1;

}



}


out+=s[i-1];
out+=to_string(counter);
return out;

}

int main()
{
string s="aabcccccaaa";  // Output should be "a2b1c5a3"

string answer=compress(s);

if(answer.length()<s.length())
cout<<answer<<endl;

else
cout<<s<<endl;


}