#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
 
using namespace std;
 
int INF = INT_MAX;
 
bool bfs(vector<vector<pair<int,int>>> &matrix,int &first ,int &last, vector<int> &ranges) {
    ranges.assign(ranges.size(), INF);
    queue<int> myqueue;
    myqueue.push(first);
    ranges[first] = 0;
    while(!myqueue.empty()){
        int x = myqueue.front();
        myqueue.pop();
        for(auto j : matrix[x]){
            if(ranges[j.first] == INF && j.second > 0){
                myqueue.push(j.first);
                ranges[j.first] = ranges[x] + 1;
            }
        }
    }
    return ranges[last] != INF;
}
 
 
int dfs(vector<vector<pair<int,int>>> &matrix, vector<int> &ranges, int &last,int maxflow, int curpos){
    if(maxflow == 0) return 0;
    if(last == curpos)
        return maxflow;
    for(int i = 0; i < matrix[curpos].size(); i++){
        if(ranges[matrix[curpos][i].first] != ranges[curpos] + 1 )
            continue;
        int result = dfs(matrix, ranges, last, min(maxflow,matrix[curpos][i].second),matrix[curpos][i].first);
        if(result){
            matrix[curpos][i].second -= result;
            for(auto &j : matrix[matrix[curpos][i].first]){
                if(j.first == curpos) {
                    j.second += result;
                    break;
                }
            }
            return result;
        }
    }
    return 0;
}
 
 
int main() {
    fstream inp("maxflow.in");
    int size, vertex;
    inp >> size;
    vector<vector<pair<int,int>>> matrix(size, vector<pair<int,int>>());
    vector<int> ranges(matrix.size(), INF);
    inp >> vertex;
    for(int i = 0; i < vertex; i++){
        int from, to, weight;
        inp >> from >> to >> weight;
        matrix[from - 1].push_back(make_pair(to - 1,weight));
        matrix[to-1].push_back(make_pair(from-1,0));
    }
    inp.close();
    int first = 0;
    int last = matrix.size() - 1;
    int ans = 0;
    while(bfs(matrix, first, last,ranges)){
        ans += dfs(matrix,ranges, last,INF,first);
    }
    ofstream outp("maxflow.out");
    outp << ans;
    return 0;
}
