/*
https://velog.io/@qotmd01/PS-백준-1201-NMK
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    if (n >= m + k - 1 && n <= m * k){
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }

        vector<int> idx; // 그룹이 나눠지는 인덱스를 저장하는 배열
        // 미리 앞에서 k개의 그룹을 만들고 시작 - > 뒤에는 상관할 필요 없음
        idx.push_back(0);
        idx.push_back(k);

        n -= k;
        m -= 1;

        int group_size, r;
        if (m == 0) group_size = 1;
        else group_size = n / m;

        if (m == 0) r = 0;
        else r = n % m;

        for (int i = 0; i < m; ++i) {
            idx.push_back(idx.back() + group_size + ( r > 0? 1 : 0));
            if (r > 0) r--;
        }

        for (int i = 0; i < idx.size() -1; ++i) {
            reverse(a.begin() + idx[i] , a.begin() + idx[i + 1]);
        }

        for (int i = 0; i < a.size(); ++i) {
            cout << a[i] <<  " ";
        }
        cout << "\n";
    }
    else{
        cout << -1 << "\n";
    }

    return 0;
}
