/*
https://velog.io/@qotmd01/알고리즘-다익스트라우선순위큐-벨만-포드-알고리즘
*/

//// Dijkstra
// 시작노드, 인접리스트
void dijkstra(int start, vector<pair<int,int>> adj[]){
	vector<int> d(N,INF);           // 시작노드에서부터 각 노드까지의 최단 거리를 저장.
	priority_queue<pair<int,int>> pq; // 우선순위 큐  (거리, 노드)
    
    pq.push({0,start});
    d[start] = 0; 
    
    while(!pq.empty()){
    	int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(d[cur] < dist) continue; // 이미 더 짧은거리를 알고 있는 경우
        
        for(int i = 0; i < adj[cur].size(); i++){
        	int nxt = adj[cur][i].first;
            int cost = adj[cur][i].second;
            if(dist + cost < d[nxt]){ // cur를 거쳐 nxt로 가는 경우가 더 짧은 경우
            	d[nxt] = dist + cost;
                pq.push({-cost,nxt});
            }
       	}
   }
            	
}   



//// Belman Ford
struct edge{
	int here,to,dist;
}Edge;
void belman_ford(int start, vector<Edge> adj;){ // 시작노드 , // 간선정보.
	vector<int> dist(N,INF);    // 최단 거리 배열 무한대로 초기화
    dist[start] = 0;            // 시작 노드 방문처리
    
    for(int i = 0; i < N - 1; i++){ // N-1번 반복
    	for(int j = 0; j < adj.size(); i++){
        	int here = adj[j].here;
            int to = adj[j].to;
            int cost = adj[j].dist;
            
            if(d[here] == INF) continue; // 한번이라도 계산되지 않은 경우
            if(dist[to] > dist[here] + cost) dist[to] = dist[here] + cost;
        }
    }
    
} 


