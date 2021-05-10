#ifndef mMatrix_h
#define mMatrix_h

#include <vector>
#include <math.h>
#include <cstdlib>
#include <algorithm>

// Class that represents a mathematical matrix
class MMatrix
{
public:
	// constructors
	MMatrix() : nRows(0), nCols(0) {}
	MMatrix(int n, int m, double x = 0) : nRows(n), nCols(m), A(n * m, x) {}
	
	// set all matrix entries equal to a double
	MMatrix &operator=(double x)
	{
		for (unsigned i = 0; i < nRows * nCols; i++) A[i] = x;
		return *this;
	}
	
	// access element, indexed by (row, column) [rvalue]
	double operator()(int i, int j) const
	{
		if(i+1 > nRows || j+1 > nCols || i < 0 || j < 0 ){
			std::cout << "Error: Index outside range" << std::endl;
			exit(-1);
		}
		else{
			return A[j + i * nCols];
		}
		
	}
	
	// access element, indexed by (row, column) [lvalue]
	double &operator()(int i, int j)
	{
		if(i+1 > nRows || j+1 > nCols || i < 0 || j < 0 ){
			std::cout << "Error: Index outside range" << std::endl;
			exit(-1);
		}
		else{
			return A[j + i * nCols];
		}
	}
	
	// size of matrix
	int Rows() const { return nRows; }
	int Cols() const { return nCols; }
	
	
	//Transpose a matrix
	MMatrix transpose() const {
		MMatrix returnMatrix(nCols, nRows);
		
		for(int i = 0; i < nCols; i++){
			for(int j = 0; j < nRows; j++){
				returnMatrix(i,j) = A[i+j*nCols];
			}
		}
		return returnMatrix;
	}
	
	//Initialise Matrix with normally distributed entries of mean zero, variable 1/m
	MMatrix initialise_normal() {
		MMatrix returnMatrix(nRows, nCols);
		
		for(int i = 0; i < nRows; i++){
			for(int j = 0; j < nCols; j++){
				returnMatrix(i,j) = rand_normal() / sqrt(nRows);
			}
		}
		return returnMatrix;
	}
	
	
private:
	unsigned int nRows, nCols;
	std::vector<double> A;
};


// Overload the << operator to output MMatrix to screen or file
std::ostream& operator<<(std::ostream& os, const MMatrix& m){
	int rowsize = m.Rows();
	int columnsize = m.Cols();
	
	for(int i = 0; i < rowsize; i++){
		for(int j = 0; j < columnsize; j++){
			std::cout.width(10);
			os << m(i,j);
		}
		os << std::endl;
	}
	return os;
}



#endif /* mMatrix_h */
