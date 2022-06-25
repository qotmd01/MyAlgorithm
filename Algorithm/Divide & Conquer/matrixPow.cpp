/*
https://velog.io/@qotmd01/알고리즘-행렬의-거듭-제곱
*/

// 정방행렬을 표현하는 SquareMatrix클래사가 있다고 가정
class SquareMatrix;

//n*n크기의 항등 행렬(identity matrix)을 반환하는 함수
SquareMatrix identity(int n);


// A^m을 반환한다. 
SquareMatrix pow(const SquareMatrix& A, int m){
	//기저사례: A^0 = 1
    if(m == 0) return identify(A.size());
    if(m % 2 > 0) return pow(A, m-1) * A;
    SquareMatrix half = pow(A, m / 2);
    return half * half;
 }
