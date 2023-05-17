#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int src, dest, weight;
};

struct DisjointSet {
  int *parent;
  int *rank;
  int n;

  DisjointSet(int n) {
    this->n = n;
    parent = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = find(parent[x]);
  }

  void unionSet(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
};

void kruskal(vector<Edge> &edges, int n) {
  DisjointSet dsu(n);
  sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
    return a.weight < b.weight;
  });
  vector<Edge> mst;
  for (Edge edge : edges) {
    if (dsu.find(edge.src) != dsu.find(edge.dest)) {
      dsu.unionSet(edge.src, edge.dest);
      mst.push_back(edge);
    }
  }
  cout << "Minimum spanning tree: " << endl;
  for (Edge edge : mst) {
    cout << edge.src << " " << edge.dest << " " << edge.weight << endl;
  }
}

int main() {
  vector<Edge> edges = {
    {0, 1, 5},
    {0, 2, 10},
    {1, 2, 2},
    {1, 3, 9},
    {2, 3, 7}
  };

  kruskal(edges, 4);

  return 0;
}