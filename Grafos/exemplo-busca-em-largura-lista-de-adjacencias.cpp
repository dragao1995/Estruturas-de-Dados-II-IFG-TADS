#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * A lista de adjacências representa o grafo em espaço O(|V|+|E|)
 * e possibilita busca em largura ou profundidade em tempo O(|V|+|E|)
 */

void bfs(vector<vector<int>>& g, int v){
    const int white = 0;
    const int grey = 1;
    const int black = 2;
    vector<int> color(g.size(),white);
    color[v]=grey;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        cout << "Nó visitado = " << u << endl;
        q.pop();
        for(size_t j=0;j<g[u].size();j++){
            int w = g[u][j];
            if(color[w]==white){
                color[w] = grey;
                q.push(w);
            }
        }
        color[u] = black;       
    }
}





int main(){
    vector<vector<int>> g;
    g.resize(5);
    g[0] = {1,4};
    g[1] = {2,3};
    g[2] = {3,4};
    g[3] = {3,3};
    g[4] = {0,1};
    bfs(g,4);
    return 0;
}
