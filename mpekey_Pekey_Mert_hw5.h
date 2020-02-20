
#include<iostream>

using namespace std;

//Mert Pekey 23646

class Matrix
{
public:
	Matrix();
	~Matrix();
	Matrix(int rowNum, int columnNum,int init);
	Matrix(const Matrix &);
	const Matrix& operator=(const Matrix&);
	const bool& operator==(const Matrix&); 
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator!();
	int getRowNumber() const;
	int getColumnNumber() const; 
	int getElementAt(const int &, const int &) const;
	void setElementAt(int, int , int);
	void print();
	void deleteArrays();

private:

	int rowNumber;
	int columnNumber; 
	int **elements;



};