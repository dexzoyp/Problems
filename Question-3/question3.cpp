#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


void PrintMatrix(vector<vector<int>> matrix,int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            cout<<right<<setw(5)<<matrix[i][j];
        }
        cout<<"\n";
    }
}
void FillMatrix(int size)
{
    vector<vector<int>> matrix(size, vector<int>(size,0));

    int row1=0;
    int row2=size-1;
    int col1=0;
    int col2=size-1;

    int number=1;

    while(number<=(size*size))
    {
        //n-th row ->
        for(int i=col1;i<=col2;i++)
        {
            matrix[row1][i]=number++;
        }
        //n-th col ->
        for(int j=row1+1;j<=row2;j++)
        {
            matrix[j][col2]=number++;
        }
        //n-th row <-
        for(int i=col2-1;i>=col1;i--)
        {
            matrix[row2][i]=number++;
        }
        //n-th col <-
        for(int j=row2-1;j>=row1+1;j--)
        {
            matrix[j][col1]=number++;
        }

        //Moving the iterators inside
        row1++;
        row2--;
        col1++;
        col2--;
    }    
    PrintMatrix(matrix,size);
    cout<<endl;
}
int main()
{
    int size=1;
    while (size != 0)
    {
        std::cout<<"Enter dimensions of the matrix: ";
        std::cin>>size;
        FillMatrix(size);
    } 
}