#ifndef SDLS_h
#define SDLS_h

//Steepest Descent Algorithm
int SDLS(const MMatrix& A, const MVector& b, MVector& x, int maxIterations, double tol){
	int CurrentIter = 1;
	double alpha = 0.0;
	
	MVector xVals(maxIterations);
	MVector yVals(maxIterations);
	
	xVals[0] = 0;
	yVals[0] = 0;
	
	MVector r = A.transpose() * (b - A * x);
	
	while(r.VectNorm() > tol && CurrentIter <= maxIterations){
		alpha = (r * r) / (r * A.transpose() * A * r);
		x = x + alpha * r;
		r = r - alpha * A.transpose() * A * r;
		
		xVals[CurrentIter] = x[0];
		yVals[CurrentIter] = x[1];
		
		CurrentIter = CurrentIter + 1;
	}
	
	if(CurrentIter == maxIterations+1){
		std::cout << "Max iterations reached without solution found" << std::endl;
		return maxIterations;
	}
	else{
		return CurrentIter;
	}
}


#endif /* SDLS_h */
