/*
https://velog.io/@qotmd01/알고리즘-수열의-빠른-합
*/

int fastSum(int n){
	//기저 사례
    if(n == 1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;
    return 2 * fastSum(n/2) + (n/2)*(n/2);
}
