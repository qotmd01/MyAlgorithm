/*
https://velog.io/@qotmd01/PS-백준-6549-히스토그램에서-가장-큰-직사각형
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (true){
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long ans = 0, w;
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            // 건물의 높이가 오름차순으로 스택에 저장 되어야 한다.
            while (!s.empty() && a[s.top()] > a[i]){
                long long cur_h = a[s.top()];
                s.pop();
                w = i;
                // 스택이 비어 있지 않으면
                // 현재 높이보다 낮은 높이는 직사각형에 포함 할 수 없다.
                // w를 수정한다.
                if (!s.empty()) w = i - s.top() - 1;
                ans = max(ans, cur_h * w);
            }
            s.push(i);
        }

        // 스택에 남아있는 건물 처리
        while (!s.empty()){
            long long cur_h = a[s.top()];
            s.pop();
            w = n;
            if (!s.empty()) w = n - s.top() - 1;
            ans = max(ans, cur_h * w);
        }
        cout << ans << "\n";
    }
    return 0;
}
