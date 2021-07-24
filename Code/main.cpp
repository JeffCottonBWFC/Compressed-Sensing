
#include <iostream>
#include <fstream>
#include "mVector.h"
#include "mMatrix.h"
#include "OperatorOverloads.h"
#include "SDLS.h"
#include "NIHT.h"

			
int main() {
	std::srand(std::time(NULL));
	
	//SDLS TEST CODE
	//Initialise the values of A, x and b and employ the steepest descent algorithm, with the number of iterations taken to find a solution returned
	/*
	int Iterations = 0;

	MVector x(2);
			x[0] = 0;
			x[1] = 0;

	MMatrix A(3,2);
			A(0,0) = 1;
			A(0,1) = 2;
			A(1,0) = 2;
			A(1,1) = 1;
			A(2,0) = 1.8;
			A(2,1) = -2;

	MVector b(3);
			b[0] = 10;
			b[1] = -1;
			b[2] = 0;

	Iterations = SDLS(A,b,x,100,1e-6);
	std::cout << "Number of iterations to find solution: " << Iterations << std::endl;
	*/
		
			
			
			
	//NIHT TEST CODE
	//Select values of m and n (the size of the matrix A) and k (the sparsity of the vector x) and MaxNumber (the number of recovery attempts). Then randomly populate x and A and evaluate the number of times the solution is correctly reached.
	/*
	double Success = 0;
	double Failure = 0;
	
	int m = 50;
	int n = 100;
	int k = 10;
	int MaxNumber = 100;
	
	for(int i = 0; i < MaxNumber; i++){
		int Val = 0;
		MMatrix A(m,n);
		MVector b(m);
		MVector x(n);
			
		x = x.initialise_normal(k);
		A = A.initialise_normal();
		b = A * x;
		
		Val = NIHT(A, b, x, k, 1000, 1e-6);
	
		if(Val == 1){
			//std::cout << "Success" << std::endl;
			Success = Success + 1;
		}else{
			//std::cout << "Failure" << std::endl;
			Failure = Failure + 1;
		}
		std::cout << i << std::endl;
	}
	
	std::cout << "Successes: " << Success << std::endl;
	std::cout << "Failures: " << Failure << std::endl;
	std::cout << "p = " << Success / MaxNumber << std::endl;
	*/
	
	
	
	//As above but varying the number of rows (m) of matrix A to investigate the phase transition phenomenon
	/*
	std::ofstream Filestream;
	 Filestream.open("PhaseTransitionk10NEW.txt");
	if (!Filestream) return 1;
	
	double SuccessRate = 0.0;
	int n = 200;
	int k = 10;
	
	for(int m = 4; m <= 199; m+= 5){
		
		double Val = 0;
		double SuccessCounter = 0;
		
		for(int t = 0; t < 50; t++){
			
			MVector x(n);
			x = x.initialise_normal(k);
			
			MMatrix A(m,n);
			A = A.initialise_normal();
			
			MVector b(m);
			b = A * x;
			
			Val = NIHT(A,b,x,k,1000,1e-6);
			
			SuccessCounter = SuccessCounter + Val;
			
		}
		
		SuccessRate = SuccessCounter/50;
	 Filestream << SuccessRate << std::endl;
		std::cout << m << std::endl;
	}
	
	
	 Filestream.close();
	*/

	
}
