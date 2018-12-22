#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int D=10;
void printboard(int board[D][D],int n)
{
    for(int i=0;i<n;i++)
    {for(int j=0;j<n;j++)
    {
        cout<<setw(3)<<board[i][j]<<" ";   /*setw is used for proper allignment and <iomanip> library is used */
    }cout<<"\n";
}
}

bool canplace(int board[D][D],int n,int row,int col,int cur)
{
    if(board[row][col]!=0)
    return false;
    for(int i=0;i<n;i++)
    {
        if(board[row][i]==cur) /* element in same row */
        return false;
        if(board[i][col]==cur)
        return false;
    }
    int sqn=sqrt(n);
    int boxrow=row/sqn;
    int boxcol=col/sqn;
    int startingboxrow=boxrow*sqn;
    int startingboxcol=boxcol*sqn;
    for(int i=startingboxrow;i<startingboxrow+sqn;i++)
    {for(int j=startingboxcol;j<startingboxcol+sqn;j++)
    {
        if(board[i][j]==cur)
        return false;}}return true;}
    

bool sudoku(int board[D][D],int n,int row,int col)
{if(col==n)
{return sudoku(board,n,row+1,0);}
if(row==n)
{return true;}
if(board[row][col]!=0)
{
    return sudoku(board,n,row,col+1);
}

for(int curno=1;curno<=n;curno++)
    {
        if(canplace(board,n,row,col,curno)==true)
        {board[row][col]=curno;
        bool nextno=sudoku(board,n,row,col+1);
        if(nextno==true)
        return true;
        board[row][col]=0;     /*backtracking step*/
    }}
    return false;
}
int main()
{
    int board[D][D]={
        {0,0,1,0,7,0,0,9,0},
        {0,0,3,0,0,8,1,0,0},
        {9,7,0,3,0,0,6,0,0},
        {0,1,0,0,8,6,0,0,0},
        {4, 0,5,0,0,0,8,0,2},
        {0,0,0,4,9,0,0,1,0},
        {0,0,4,0,0,3,0,7,9},
        {0,0,8,6,0,0,3,0,0},
        {0,5,0,0,1,0,2,0,0}
    };

    int n;
    cin>>n;
    bool ans=sudoku(board,n,0,0);
    if(ans==true)
    {
        printboard(board,n);
    }
    else
    {
        cout<<"sorry Bro!! solve it urself";
    }
}