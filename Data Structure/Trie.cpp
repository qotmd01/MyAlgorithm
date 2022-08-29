/*
https://velog.io/@qotmd01/자료-구조-Trie-트라이
*/

#include <string>
#include <vector>

using namespace std;

struct Trie{
    struct Node{
        // 저장된 단어를 나타내는 vaild 값.
        // Vaild == True 이면 현재 노드의 문자가 문자열의 마지막 문자임을 나타냄.
        bool vaild;
        // 다음 문자 노드(자식)로 가는 포인터(노드번호)를 저장. 기본값 -1
        int child[26];
        Node(){
            vaild = false;
            for (int i = 0; i < 26; ++i) {
                child[i] = -1;
            }
        }
    };

    // 노드하나하나는 벡터에 저장해서 관리. 노드는 벡터 인덱스로 구분
    vector<Node> trie;
    int root;

    // 새로운 노드를 생성하는 함수
    int initNode(){
        Node new_node;
        trie.push_back(new_node);
        return trie.size() - 1;
    }

    Trie(){
        root = initNode();
    }

    // s의 인덱스번 문자를 트라이에 추가하는 함수
    void add(int cur_node, string s, int idx){
        // 모든 문자를 추가한 경우.
        if (idx == s.length()){
            trie[cur_node].vaild = true;
            return;
        }

        int cur_c = s[idx] - 'a';
        // 현재 문자를 추가할 다음 노드가 없는 경우 ( 겹치는 prefix x ), 새로 생성
        if (trie[cur_node].child[cur_c] == -1){
            int nxt = initNode();
            trie[cur_node].child[cur_c] = nxt;
        }
        // 재귀함수로 나머지 문자들을 추가
        add(trie[cur_node].child[cur_c] , s, idx + 1);
    }

    void addString(string s){
        add(root, s, 0);
    }

    // 문자열 s가 트라이에 속하는지 탐색하는 함수
    bool search(int cur_node, string s, int idx){
        // 존재하지 않는 경우
        if (cur_node == -1) return false;
        if (idx == s.length()) return trie[cur_node].vaild;

        int cur_c = s[idx] - 'a';
        // 재귀적으로 탐색
        return search(trie[cur_node].child[cur_c],s,idx + 1);
    }

    bool searchString(string s){
        return search(root, s, 0);
    }

};




