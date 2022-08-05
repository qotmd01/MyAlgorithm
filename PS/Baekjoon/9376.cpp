/*
https://velog.io/@qotmd01/PS-백준-9376-탈옥
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dir_i[4] = {-1,1,0,0};
int dir_j[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--){
        int h,w;
        cin >> h >> w;
        vector<pair<int,int>> s;
        vector<vector<char>> board ( h + 2, vector<char>(w + 2, '.'));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> board[i][j];
                if (board[i][j] == '$'){
                    s.push_back({i,j});
                    board[i][j] = '.';
                }
            }
        }

        vector<vector<int>> cnt0(h + 2, vector<int> (w + 2,-1));
        vector<vector<int>> cnt1(h + 2, vector<int> (w + 2, -1));
        vector<vector<int>> cnt2(h + 2, vector<int> ( w + 2, -1));

        deque<pair<int,int>> q;
        // 밖에서 cnt
        cnt0[0][0] = 0;
        q.push_front({0,0});
        while (!q.empty()){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop_front();

            for (int dir = 0; dir < 4; ++dir) {
                int new_i = cur_i + dir_i[dir];
                int new_j = cur_j + dir_j[dir];

                if (new_i < 0 || new_i >= h + 2 || new_j < 0 || new_j >= w + 2) continue;
                if (board[new_i][new_j] == '.' && cnt0[new_i][new_j] == -1){
                    cnt0[new_i][new_j] = cnt0[cur_i][cur_j];
                    q.push_front({new_i, new_j});
                }
                else if (board[new_i][new_j] == '#' && cnt0[new_i][new_j] == -1){
                    cnt0[new_i][new_j] = cnt0[cur_i][cur_j] + 1;
                    q.push_back({new_i,new_j});
                }
            }
        }

        // 첫번째 탈옥수
        cnt1[s[0].first][s[0].second] = 0;
        q.push_front({s[0].first, s[0].second});
        while (!q.empty()){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop_front();

            for (int dir = 0; dir < 4; ++dir) {
                int new_i = cur_i + dir_i[dir];
                int new_j = cur_j + dir_j[dir];

                if (new_i < 0 || new_i >= h + 2 || new_j < 0 || new_j >= w + 2) continue;
                if (board[new_i][new_j] == '.' && cnt1[new_i][new_j] == -1){
                    cnt1[new_i][new_j] = cnt1[cur_i][cur_j];
                    q.push_front({new_i, new_j});
                }
                else if (board[new_i][new_j] == '#' && cnt1[new_i][new_j] == -1){
                    cnt1[new_i][new_j] = cnt1[cur_i][cur_j] + 1;
                    q.push_back({new_i,new_j});
                }
            }
        }

        // 두번째 탈옥수
        cnt2[s[1].first][s[1].second] = 0;
        q.push_front({s[1].first , s[1].second});
        while (!q.empty()){
            int cur_i = q.front().first;
            int cur_j = q.front().second;
            q.pop_front();

            for (int dir = 0; dir < 4; ++dir) {
                int new_i = cur_i + dir_i[dir];
                int new_j = cur_j + dir_j[dir];

                if (new_i < 0 || new_i >= h + 2 || new_j < 0 || new_j >= w + 2) continue;
                if (board[new_i][new_j] == '.' && cnt2[new_i][new_j] == -1){
                    cnt2[new_i][new_j] = cnt2[cur_i][cur_j];
                    q.push_front({new_i, new_j});
                }
                else if (board[new_i][new_j] == '#' && cnt2[new_i][new_j] == -1){
                    cnt2[new_i][new_j] = cnt2[cur_i][cur_j] + 1;
                    q.push_back({new_i,new_j});
                }
            }
        }


        int ans = w * h;
        for (int i = 0; i < h + 2; ++i) {
            for (int j = 0; j < w + 2; ++j) {
                if (cnt0[i][j] == -1 || cnt1[i][j] == -1 || cnt2[i][j] == - 1) continue;
                int cur = (cnt0[i][j] + cnt1[i][j] + cnt2[i][j]);
                if (board[i][j] == '#') cur -= 2;
                ans = min(ans,cur);
            }
        }
        cout << ans << "\n";

    }
}
