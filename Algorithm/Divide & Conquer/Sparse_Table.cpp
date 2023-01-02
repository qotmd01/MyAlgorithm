/*
https://velog.io/@qotmd01/알고리즘-Sparse-Table희소-행렬
*/


#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m,q,n,x; cin >> m; vector<vector<int> > des(max_n, vector<int>(m+1));
    for (int i = 1; i <= m; i++)
    {
        cin >> des[0][i]; # 간선 정보를 입력.
    }
    
    #Sparse Table 구성.
    for (int i = 1; i < max_n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            des[i][j] = des[i-1][dp[i-1][j]];
        }
    }
    
    # n번 정점에서 x번 이동한 결과를 출력.
    cin >> n >> x;
    int node = x;
    for (int i = max_n; i >= 0; --i)
    {
       if(n & (1 << i)) node = dp[i][node];
    }
    cout << node << "\n";
    return 0;
}
