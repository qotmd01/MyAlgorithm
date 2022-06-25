/*
https://velog.io/@qotmd01/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EC%88%98%EC%97%B4%EC%9D%98-%EB%B9%A0%EB%A5%B8-%ED%95%A9
*/

int fastSum(int n){
	//기저 사례
    if(n == 1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;
    return 2 * fastSum(n/2) + (n/2)*(n/2);
}
