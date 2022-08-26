/*
https://velog.io/@qotmd01/PS-백준-1989-부분배열-고르기2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace::std;

int n , ans_i, ans_j;
long long ans = -1;

vector<long long> input(100001);

// 분할 정복으로 start ~ end 내의 최대 점수를 구합니다. 
long long func(int start, int end){
	// 원소가 하나인 경우
    if (start == end) {
        return input[start] * input[start];
    }
   
    int mid = (start + end) / 2;
 	//(1) , (2) 구간 점수를 구합니다. 
    long long a = func(start, mid) , b = func(mid + 1, end);
    long long temp = max(a, b);
    if (a > ans) {
        ans_i = start;
        ans_j = mid;
        ans = a;
    }
    
    if (b > ans) {
        ans_i = mid + 1;
        ans_j = end;
        ans = b;
    }
    
    //(3) mid에서 부터 시작하여 걸쳐진 구간의 최대 점수 구하기. 
    int i = mid, j = mid + 1;
    long long cur_sum = input[i] + input[j];
    long long  min_value = min(input[i],input[j]);
    
    long long max_value = min_value * cur_sum;
    if (max_value > ans) {
        ans = max_value;
        ans_i = i;
        ans_j = j;
    }
    
    // i, j 둘중 하나가 끝에 도달 -> 도달하지 않을 쪽으로 확장
    // 그 이외의 경우에는, 값이 더 큰 쪽으로 확장
    // 도중에 지속적으로 max_value를 갱신. 
    while (i > start || j < end ) {
        if (i  > start && ( j == end || input[i-1] >  input[j+1])) {
            min_value = min(min_value, input[--i]);
            cur_sum += input[i];
        }
        else{
            min_value = min(min_value , input[++j]);
            cur_sum += input[j];
        }
        if (min_value * cur_sum > ans) {
            ans = min_value * cur_sum;
            ans_i = i;
            ans_j = j;
        }

        max_value = max(max_value , min_value * cur_sum);
        
    }
    
    temp = max(temp,max_value);
    
    return temp;
}

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << func(0, n-1) << "\n";
    cout << ans_i + 1<< " " << ans_j + 1<< "\n";
    
    return 0;
    
}
