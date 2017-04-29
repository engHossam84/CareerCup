#include <iostream>

using namespace std;




int** rotateImage( int **a, int rowSize)
{
	int** matrix = new int*[rowSize];
	for(int i = 0; i < rowSize; ++i)
		matrix[i] = new int[rowSize];

	for(int i = 0 ; i < rowSize ; i++)
		for(int j = 0 ; j < rowSize ; j++)
		{
			matrix[i][j] = a[rowSize - j - 1][i];
		}

		for(int i = 0 ; i < rowSize ; i++)
		{
			for(int j = 0 ; j < rowSize ; j++)
			{
				cout << matrix[i][j] << "   ";
			}
			cout  << endl <<endl;
		}
		return matrix;
}

int main()
{

	int size;
	cout<<"Enter matrix size";
	cin>>size;
	int count = 1;
	int** matrix = new int*[size];
	for(int i = 0; i < size; ++i)
		matrix[i] = new int[size];

	for(int i = 0 ; i < size ; i++)
		for(int j = 0 ; j < size ; j++)
		{
			matrix[i][j] = count++;
		}

		for(int i = 0 ; i < size ; i++)
		{
			for(int j = 0 ; j < size ; j++)
			{
				cout << matrix[i][j] << "   ";
			}
			cout  << endl <<endl;
		}

		rotateImage(matrix,size);

}
