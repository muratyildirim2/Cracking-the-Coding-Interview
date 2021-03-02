#include<bits/stdc++.h>

using namespace std;

void urlify(char *str, int len)
{
    int numOfSpaces = 0;
    int i = 0, j = 0;
    for ( i = 0; i < len; ++i ) {
        if (str[i] == ' ') {
            numOfSpaces++;
        }
    }
    
    int newlength  = len + 2 * numOfSpaces;
    i = newlength - 1;
    for( j = len - 1; j >= 0; --j ) {
        if ( str[j] != ' ' ) {    // if character not equals to space , we not need to change character
           str[i--] = str[j];
        } else {
            str[i--] = '0';   // otherrwise we have to add three characters.
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}

string urlify2(char * str,int len)
{
string newstring="";

    for ( int i = 0; i < len; ++i ) {
        if (str[i] == ' ') {      // if there is a space, we have to add "%20" to newstring. 
           
               newstring+="%20";
            }

            else
            newstring+=str[i];   // else add normal character.
       
    }

return newstring;

}


int main()
{

   char str []  ="Mr John Smith ";
   int len=13;

   string answer= urlify2(str,len);


   urlify(str,13);


   cout<<"First Solution  :"<<answer<<endl;

   cout<<"Second Solution :"<<str<<endl;



}