// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

void BFS(vector<int> adj[], int s, int V) {
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    int distance[V];
    distance[s] = 0;

    while(q.empty() == false) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(visited[v] == false) {
                distance[v] = distance[u] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
    }

    for(int i = 0; i < V; i++)
        cout << distance[i] << " ";
}

int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    BFS(adj, 2, V);

    return 0;
}