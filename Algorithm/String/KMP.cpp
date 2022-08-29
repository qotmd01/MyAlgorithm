/*
https://velog.io/@qotmd01/알고리즘-KMP-알고리즘
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> fail(string p){
    int m = p.size(), j = 0;
    vector<int> fi(m);
    fi[0] = 0;
    for (int i = 1; i < m; ++i) {
        while (j > 0 && p[i] != p[j]) j = fi[j-1];
        if (p[i] == p[j]) fi[i] = ++j;
        else fi[i] = 0;
    }

    return fi;
}

vector<int> kmp(string s, string p){
    vector<int> fi = fail(p);
    vector<int> ans;
    int n = s.size(), m = p.size(), j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != p[j]) j = fi[j - 1];
        if (s[i] == s[j]){
            if (j == m - 1){
                ans.push_back(i - m + 1);
                j = fi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}
