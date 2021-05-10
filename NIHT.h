
#ifndef NIHT_h
#define NIHT_h


//Normalised Iterative Thresholding Algorithm
int NIHT(const MMatrix& A, const MVector& b, MVector&x, int k, int maxIterations, double tol){
	int CurrentIter = 1;
	double alpha = 0.0;
	double rNormPrev = 0.0;
	
	// Initialise starting vector
	x = A.transpose()*b;
	x.threshold(k);   // Get k largest values
	
	MVector r = A.transpose() * (b - A * x);
	
	
	while(r.VectNorm() > tol && CurrentIter <= maxIterations){
		rNormPrev = r.VectNorm();
		alpha = (r * r) / (r * A.transpose() * A * r);
		x = x + alpha * r;
		x.threshold(k);
		r = A.transpose() * (b - A * x);
		
		//Tests convergence of successive vector norms
		if(abs(r.VectNorm() - rNormPrev) < 1e-7){
			return 0;
		}
		
		CurrentIter = CurrentIter + 1;
	}
	
	if(CurrentIter == maxIterations+1){
		//std::cout << "Max iterations reached without solution found" << std::endl;
		return 0;
	}
	else{
		return 1;
	}
}

#endif /* NIHT_h */
