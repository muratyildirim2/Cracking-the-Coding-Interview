#include<bits/stdc++.h>

using namespace std;
#define N 4 
/*
Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4
bytes, write a method to rotate the image by 90 degrees. Can you do this in place?
*/

void rotate_matrix(int mat[][N])
{
 
    for (int x = 0; x < N / 2; x++) { 
  
        for (int y = x; y < N - x - 1; y++) { 
           
            int temp = mat[x][y]; 
  
           
            mat[x][y] = mat[y][N - 1 - x]; 
  
           
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
        
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
          
            mat[N - 1 - y][x] = temp; 
        } 
    } 

}

void print_matrix(int mat[][N])
{
cout<<endl<<"**************************"<<endl;
   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}




int main()
{

    int mat[N][N];


    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mat[i][j];
        }
    }


    rotate_matrix(mat);

    print_matrix(mat);


}