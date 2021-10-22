#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;


void PrintMatrix(vector<vector<int>> matrix,int size)
{
    bool color=false;
    const std::string magenta("\033[2;35m");
    const std::string green("\033[0;32m");
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(color)
            {
                cout<<green<<right<<setw(5)<<matrix[i][j]<<right<<setw(5);
                color=!color;
            }
            else
            {
                cout<<magenta<<right<<setw(5)<<matrix[i][j]<<right<<setw(5);
                color=!color;
            }
        }
        cout<<"\n";
        if(size%2==0)
        {
        color=!color;
        }
    }
}
void FillMatrix(int size)
{
    vector<vector<int>> matrix(size, vector<int>(size,0));

    int number= 1;
	for (int k = 0; k < size; k++) 
    {
        int row = 0; 
        int col = k;
        while (col >= 0) 
        {
            matrix[row][col]=number;
            number++,row++, col--;
        }
	}
	for (int j = 1; j < size; j++) 
    {
		int col = size - 1;
        int row = j;
		while (row < size) 
        {
			matrix[row][col]=number;
			number++,row++, col--;
		}
	}
    PrintMatrix(matrix,size);
    cout<<endl;
}
int main()
{
    int size=1;
    while (size != 0)
    {
        const std::string red("\033[2;31m");
        std::cout<<red<<"Enter dimensions of the matrix: ";
        std::cin>>size;
        FillMatrix(size);
    } 
}


