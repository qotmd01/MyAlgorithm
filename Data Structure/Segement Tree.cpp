/*https://velog.io/@qotmd01/%EC%9E%90%EB%A3%8C-%EA%B5%AC%EC%A1%B0-Segement-Tree-%EC%84%B8%EA%B7%B8-%EB%A8%BC%ED%8A%B8-%ED%8A%B8%EB%A6%AC*/
struct segtree{
	int N;        // 배열 혹은 수열의 크기 
    vector<long long> tree; // Segtree ( 구간을 저장할 배열 )
    long long eval(long long left, long long right){
        return left + right;
    } // 구간에 기본 연산을 처리하는 함수.
	void init(vector<long long>& a, int size){
        N = size;
        tree.resize(N * 4);
        buildseg(a, 1, 0, N-1);
    }
    //node = 세그트리의 노드 번호, nodeLeft, nodeRight = 이 노드가 실제 배열(수열)에서 커버하는 범위. 
    long long buildseg(vector<long long>& a, int node, int nodeLeft, int nodeRight){
        if (nodeLeft == nodeRight) return tree[node] = a[nodeLeft]; // 자식 노드 인 경우
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long left = buildseg(a, 2 * node , nodeLeft , mid);      
        long long right = buildseg(a, 2 * node + 1, mid + 1, nodeRight);
        
        return tree[node] = eval(left, right);
    }
    // left , right = 쿼리를 요청한 구간   node = 세그트리의 노드 번호, nodeLeft, nodeRight = 이 노드가 실제 배열(수열)에서 커버하는 범위.
    long long querySeg(int left, int right, int node, int nodeLeft, int nodeRight){
        if (right < nodeLeft || nodeRight < left) return 0; // 구간에 포함되지 않는 경우
        if(left <= nodeLeft && nodeRight <= right) return tree[node]; // 구간에 완전히 들어간 경우
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long leftVal = querySeg(left, right, 2 * node, nodeLeft , mid);
        long long rightVal = querySeg(left, right, 2 * node + 1, mid + 1, nodeRight);
        return eval(leftVal, rightVal);
        
    }
    long long query(int left, int right){
        return querySeg(left, right, 1, 0, N-1);
    }
    // idx = 변경하고 싶은 배열의 인덱스, newVal = 변경하고 싶은 값. //node = 세그트리의 노드 번호, nodeLeft, nodeRight = 이 노드가 실제 배열(수열)에서 커버하는 범위.
    long long updateSeg(int index, long long newVal, int node, int nodeLeft, int nodeRight){
        if(index < nodeLeft || nodeRight < index) return tree[node]; // 인덱스가 세그 트리의 노드가 커버하는 구간에 포함안됌
        if(nodeLeft == nodeRight) return tree[node] = newVal; // 맞는 idx를 찾음
        int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
        long long leftVal = updateSeg(index, newVal, 2 * node, nodeLeft , mid);
        long long rightVal = updateSeg(index, newVal, 2 * node + 1, mid + 1, nodeRight);
        return tree[node] = eval(leftVal, rightVal);
    }
    long long update(int index, long long newVal){
        return updateSeg(index, newVal, 1, 0 , N - 1);
    }
};
