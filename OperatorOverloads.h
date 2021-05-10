#ifndef OperatorOverloads_h
#define OperatorOverloads_h

//Overloading Matrix/Vector Product
MVector operator*(const MMatrix& A, const MVector& v){
	MVector returnVect(A.Rows());
	double temp = 0.0;
	
	for(int i = 0; i < A.Rows(); i++){
		temp = 0.0;
		for(int j = 0; j < v.size(); j++){
			temp  = temp + A(i,j) * v[j];
		}
		returnVect[i] = temp;
	}
	return returnVect;
}

//Overloading Vector/Matrix Product
MVector operator*(const MVector& v, const MMatrix& A){
	MVector returnVect(A.Cols());
	double temp = 0.0;
	
	for(int i = 0; i < A.Cols(); i++){
		temp = 0.0;
		for(int j = 0; j < v.size(); j++){
			temp  = temp + v[j] * A(j,i);
		}
		returnVect[i] = temp;
	}
	return returnVect;
}

//Overloading Matrix/Matrix product
MMatrix operator*(const MMatrix& A, const MMatrix& B){
	MMatrix returnMatrix(A.Rows(),B.Cols());
	double temp = 0.0;
	
	for(int i = 0; i < A.Rows(); i++){
		for(int j = 0; j < B.Cols(); j++){
			temp = 0.0;
			for(int k = 0; k < A.Cols(); k++){
				temp = temp + A(i,k) * B(k,j);
			}
			returnMatrix(i,j) = temp;
		}
	}
	return returnMatrix;
}


//Overloading subtraction of 2 vectors
MVector operator-(MVector Vect1, MVector Vect2){
	MVector returnVect(Vect1.size());
	if(Vect1.size() == Vect2.size()){
		for(int i = 0; i < Vect1.size(); i++){
			returnVect[i] = Vect1[i] - Vect2[i];
		}
	}
	return returnVect;
}


//Overloading dot product of 2 vectors
double operator*(MVector Vect1, MVector Vect2){
	double returnInt = 0;
	if(Vect1.size() == Vect2.size()){
		for(int i = 0; i < Vect1.size(); i++){
			returnInt = returnInt + (Vect1[i] * Vect2[i]);
		}
	}
	return returnInt;
}

//Overloading scalar/vector product
MVector operator*(double a, const MVector& v){
	MVector returnVector(v.size());
	
	for(int i = 0; i < v.size(); i++){
		returnVector[i] = a * v[i];
	}
	
	return returnVector;
}


//Overloading addition of 2 vectors
MVector operator+(MVector Vect1, MVector Vect2){
	MVector returnVect(Vect1.size());
	if(Vect1.size() == Vect2.size()){
		for(int i = 0; i < Vect1.size(); i++){
			returnVect[i] = Vect1[i] + Vect2[i];
		}
	}
	return returnVect;
}

//Overloading scalar/Matrix product
MMatrix operator*(double a, const MMatrix& A){
	MMatrix returnMatrix(A.Rows(),A.Cols());
	
	for(int i = 0; i < A.Rows(); i++){
		for(int j = 0; j < A.Cols(); j++){
			returnMatrix(i,j) = a * A(i,j);
		}
	}
	return returnMatrix;
}



#endif /* OperatorOverloads_h */
