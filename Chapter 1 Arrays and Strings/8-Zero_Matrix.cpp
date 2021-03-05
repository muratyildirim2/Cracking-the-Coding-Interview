#include<bits/stdc++.h>

using namespace std;

/*
Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0.
*/

void zero_matrix(int **mat,int M,int N)
{
bool row[M];    
bool column [N]; 


   for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
           if(mat[i][j]==0)
           {
               row[i]=true;
               column[j]=true;
           }
        }
    
    }




    for (int i=0;i<M;i++)
    {

        if(row[i]==true)
        {

          for(int j=0;j<N;j++)
          {
             mat[i][j]=0;
          }

        }



    }
    for (int i=0;i<N;i++)
    {

        if(column[i]==true)
        {

          for(int j=0;j<M;j++)
          {
             mat[j][i]=0;
          }

        }



    }




}

void print_matrix(int **mat,int M,int N)
{
cout<<endl<<"**************************"<<endl;
   for(int i=0;i<M;i++)
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

int M,N;
cin>>M>>N;

    int ** mat = new int*[M];
	for ( int i =0; i < M; ++i ) {
		mat[i] = new int[N];
	}

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>mat[i][j];
        }
    }


    zero_matrix(mat,M,N);

    print_matrix(mat,M,N);


}