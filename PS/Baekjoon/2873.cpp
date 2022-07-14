/*
https://velog.io/@qotmd01/PS-백준-2873-롤러코스터
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int r,c;

string move(string a, int cnt, char dir){
    for (int i = 0; i < cnt; ++i) {
        a += dir;
    }
    return a;
}

int main(){
    string ans;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>( c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }

    // 행이 홀수 - > ㄹ자로 모든 칸 방문 가능.
    if (r % 2 == 1){
        for (int i = 0; i < r; ++i) {
            if (i % 2 == 0){
                ans = move(ans, c - 1, 'R');
                if (i != r - 1) ans += 'D';
            }
            else{
                ans = move(ans, c - 1, 'L');
                ans += 'D';
            }
        }
    }
    else if( c % 2 == 1){
        // 행이 짝수 - > 열이 홀수 -> ㄹ자와 비슷한 형식으로 모든 칸 방문가능
        if (c % 2 == 1){
            for (int i = 0; i < c; ++i) {
                if (i % 2 == 0){
                    ans = move(ans, r - 1, 'D');
                    if (i != c - 1) ans += 'R';
                }
                else{
                    ans = move(ans, r - 1, 'U');
                    ans += 'R';
                }
            }
        }
    }
    // 한간빼고 전부 방문 가능.
    else{
        int min_r = 0, min_c = 1;

        // 방문하지 않을 가장 작은 기쁨의 칸 탐색
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i + j) % 2 == 1 && a[i][j] < a[min_r][min_c]){
                    min_r = i;
                    min_c = j;
                }
            }
        }

        int start_r = 0, start_c = 0, end_r = r - 1, end_c = c - 1;
        string start,end;
        // 행부터 기준을 맞춘다.
        while (end_r - start_r > 1){
            if (start_r / 2 < min_r / 2){
                start = move(start, c - 1, 'R');
                start += 'D';
                start  = move( start, c - 1, 'L');
                start += 'D';
                start_r += 2;
            }
            if (min_r / 2 < end_r / 2){
                end = move( end, c - 1, 'R');
                end += 'D';
                end = move(end, c - 1, 'L');
                end += 'D';
                end_r -= 2;
            }

        }
        // 열을 맞춘다.
        while (end_c - start_c > 1){
            if (start_c / 2  < min_c / 2){
                start += "DRUR";
                start_c += 2;
            }
            if (min_c / 2 < end_c / 2){
                end += "DRUR";
                end_c -= 2;
            }
        }

        if (start_c == min_c) start += "RD";
        else start += "DR";

        reverse(end.begin(),end.end());
        ans = start + end;

    }

    cout << ans << "\n";
    return 0;
}
