#include "mpekey_Pekey_Mert_hw5.h";

//Mert Pekey 23646

Matrix::Matrix()	//Default Constructor
{
	rowNumber=0;
	columnNumber=0;
	elements=NULL;
}


Matrix::Matrix(int rowNum, int columnNum,int init)	//Constructor: Takes the row and column number and the initial value of the elements inside the matrix
{
	if (rowNum > 0 && columnNum >0)
	{
		rowNumber=rowNum;
		columnNumber=columnNum;
		elements = new int* [rowNum]; 

		for (int i = 0; i<rowNumber; i++) 
			elements[i] = new int[columnNumber];

		for(int j=0; j<rowNumber; j++)
			for (int m = 0; m < columnNumber; m++)
				elements[j][m]=init;
	}
	else
	{
		rowNumber=0;
		columnNumber=0;
		elements=NULL;
	}

}

Matrix::Matrix(const Matrix & copy)	//Deep Copy Constructor which creates a new matrix in a new memory location and it is same with the other one.
{
	if (copy.rowNumber>0 && copy.columnNumber>0)
	{
		rowNumber=copy.rowNumber;
		columnNumber=copy.columnNumber;
		elements=new int* [rowNumber];

		for (int i = 0; i<rowNumber; i++) 
			elements[i] = new int[columnNumber];

		for (int i = 0; i < rowNumber; i++)
		{
			for (int j = 0; j < columnNumber; j++)
			{
				elements[i][j]=copy.elements[i][j];
			}
		}

	}
	else
	{
		rowNumber=0;
		columnNumber=0;
		elements=NULL;
	}
}


int Matrix::getRowNumber() const
{
	return rowNumber;
}

int Matrix::getColumnNumber() const
{
	return columnNumber;
}

int Matrix::getElementAt(const int &r, const int &c) const
{
	return elements[r][c];
}

void Matrix::setElementAt(int r, int c, int val)
{
	elements[r][c]=val;
}

Matrix::~Matrix()	//Destructor calls deleteArrays function and makes other things 0
{
	deleteArrays();
	rowNumber=0;
	columnNumber=0;

}

const Matrix & Matrix::operator= (const Matrix & rhs)	// Delete the lhs and makes it same with the rhs if they are not same at the beginning
{
	if (this!=&rhs)
	{	
		deleteArrays();

		elements = new int* [rhs.rowNumber]; 
		for (int i = 0; i<rhs.rowNumber; i++) 
			elements[i] = new int[rhs.columnNumber];

		rowNumber=rhs.rowNumber;
		columnNumber=rhs.columnNumber;
		for (int i = 0; i < rowNumber; i++)
		{
			for (int j = 0; j < columnNumber; j++)
			{
				elements[i][j]=rhs.elements[i][j];
			}
		}
	}
	return *this;
}

Matrix Matrix::operator+ (const Matrix & rhs) //Sum of lhs and rhs and return the result which is a new matrix
{
	Matrix result(rhs);

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			result.elements[i][j] += elements[i][j];
		}
	}

	return result;
}

Matrix Matrix::operator- (const Matrix & rhs) //return new matrix result which is the difference between lhs and rhs
{
	Matrix result(rhs);

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			result.elements[i][j] = elements[i][j] - result.elements[i][j];
		}
	}

	return result;
}

const bool & Matrix::operator == (const Matrix & rhs) //return true if lhs and rhs are equal
{
	if(rowNumber!=rhs.rowNumber || columnNumber!=rhs.columnNumber)
		return false;

	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			if (elements[i][j] != rhs.elements[i][j])
				return false;
		}
	}

	return true;
}

Matrix Matrix::operator !() //Transpose of the matrix
{
	Matrix transpose(columnNumber,rowNumber,0);

	for (int i = 0; i < columnNumber; i++)
	{
		for (int j = 0; j < rowNumber; j++)
		{
			transpose.elements[i][j] = elements[j][i];
		}
	}

	return transpose;
}

void Matrix::print()	//Show the Matrix on the console
{
	for (int i = 0; i < rowNumber; i++)
	{
		for (int j = 0; j < columnNumber; j++)
		{
			cout<<elements[i][j]<<" ";
		}
		cout<<endl;
	}
}

void Matrix::deleteArrays()	//delete the matrix and free memory
{
	for (int i = 0; i < rowNumber; i++)
		delete [] elements[i];

	delete [] elements;
}