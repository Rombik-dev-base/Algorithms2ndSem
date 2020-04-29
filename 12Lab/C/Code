#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int INF = INT_MAX;
 
struct Edge{
    int from, to, maxflow, flow, number;
};
 
vector<vector<int>> matrix;
vector<Edge> edges;
vector<int> ranges;
vector<int> cur;
vector<vector<int>> myans;
int first = 0;
int last = 0;
 
bool bfs(int &first ,int &last) {
    ranges.assign(ranges.size(), 0);
    queue<int> myqueue;
    myqueue.push(first);
    ranges[first] = 1;
    while(!myqueue.empty() && !ranges[last]){
        int x = myqueue.front();
        myqueue.pop();
        for(auto &j : matrix[x]){
            if(edges[j].maxflow - edges[j].flow <= 0)
                continue;
            if(!ranges[edges[j].to]){
                myqueue.push(edges[j].to);
                ranges[edges[j].to] = ranges[x] + 1;
            }
        }
    }
    return ranges[last];
}
 
 
void redirect_flow(int &pos,int &flow){
    edges[pos].flow += flow;
    edges[pos^1].flow -= flow;
}
 
 
int dfs(int maxflow, int curpos ){
    if(maxflow == 0) return 0;
    if(last == curpos) {
        return maxflow;
    }
    for(; cur[curpos] < matrix[curpos].size(); cur[curpos]++) {
        if (ranges[edges[matrix[curpos][cur[curpos]]].to] == ranges[curpos] + 1) {
            int result = dfs(min(maxflow, edges[matrix[curpos][cur[curpos]]].maxflow -
                                                edges[matrix[curpos][cur[curpos]]].flow),
                             edges[matrix[curpos][cur[curpos]]].to);
            if (result) {
                redirect_flow(matrix[curpos][cur[curpos]], result);
                return result;
            }
        }
    }
    return 0;
}
 
int dfsn2(int curpos, int f){
    if(curpos == last){
        myans.push_back(vector<int>());
        return f;
    }
    for(auto &i : matrix[curpos]){
        if(edges[i].flow > 0){
            int flow = dfsn2(edges[i].to,min(f,edges[i].flow));
            if(flow){
                myans.back().push_back(edges[i].number);
                if(curpos == first){
                    myans.back().push_back(myans[myans.size() - 1].size());
                    myans.back().push_back(flow);
                    reverse(myans.back().begin(),myans.back().end());
                }
                edges[i].flow -= flow;
                return flow;
            }
        }
    }
    return 0;
}
 
 
void new_edge(int from, int to, int weight, int numEdge){
     matrix[from].push_back(edges.size());
     edges.push_back({from, to, weight,0,numEdge});
     matrix[to].push_back(edges.size());
     edges.push_back({to, from, 0, 0, numEdge});
}
 
int main() {
    fstream inp("decomposition.in");
    int size, vertex;
    inp >> size;
    matrix.resize(size,vector<int>());
    ranges.resize(size,0);
    cur.resize(size,0);
 
    inp >> vertex;
    for(int i = 0; i < vertex; i++){
        int from, to, weight;
        inp >> from >> to >> weight;
        new_edge(from - 1, to - 1, weight, i + 1);
    }
    inp.close();
    first = 0;
    last = matrix.size() - 1;
    int ans = 0;
    while(bfs(first, last)){
        int curans = 0;
        while(curans = dfs(INF,first))
            ans += curans;
        cur.assign(size,0);
    }
    while(dfsn2(first,INF)){
        continue;
    }
    ofstream outp("decomposition.out");
    outp << myans.size() << '\n';
    for(auto &i : myans){
        for(auto &j : i){
            outp << j << ' ';
        }
        outp << '\n';
    }
    return 0;
}
