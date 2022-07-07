/*
https://velog.io/@qotmd01/PS-백준-2261-가장-가까운-두점
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define DIST_MAX 800000001

using namespace std;

vector<pair<int,int>> points;

 bool is_zero = false;
// 두점간의 거리의 제곱을 리턴
int distdist(pair<int,int> a, pair<int,int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int solv(int start , int end){
    if (is_zero) return 0;
    // 점의 개수가 3개 이하일 경우에는 직접 구한다.
    if (end - start + 1 <= 3){
        int res = DIST_MAX;
        for (int i = start; i <= end-1; ++i) {
            for (int j = i + 1; j <= end; ++j) {
                res = min(res, distdist(points[i],points[j]));
            }
        }

        if (res == 0) is_zero = true;

        return res;
    }

    int mid = (start + end) / 2;
    int d = min(solv(start, mid), solv(mid + 1, end));   /// d = 오른쪽영역의 점끼리의 최단 거리와 왼쪽영역의 점끼리의 최단거리중 더 짧은 값

    if (d == 0 || is_zero){
        is_zero = true;
        return 0;
    }

    vector<pair<int,int>> less_than_d;  // mid 기준으로 x좌표가 d 이하인 점들
    for (int i = start; i <= end; ++i) {
        int dist_x = points[mid].first - points[i].first;
        if (dist_x * dist_x < d)  less_than_d.push_back(points[i]);
    }

    sort(less_than_d.begin(), less_than_d.end() , [](pair<int,int> &a, pair<int,int> &b){
        return a.second < b.second;
    });

    for (int i = 0; i < less_than_d.size() - 1; ++i) {
        for (int j = i + 1; j < less_than_d.size(); ++j) {
            int dist_y = less_than_d[i].second - less_than_d[j].second;
            if (dist_y * dist_y < d){
                d = min(d, distdist(less_than_d[i],less_than_d[j]));
            }
            else{
                break;
            }
        }
    }

    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    points.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    cout << solv(0,n-1) << "\n";

    return 0;

}
