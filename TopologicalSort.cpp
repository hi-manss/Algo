#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge
{
    int src, dest;
};

struct Graph
{
    int n;
    vector<Edge> edges;

    Graph(int n)
    {
        this->n = n;
        edges = vector<Edge>();
    }

    void addEdge(int src, int dest)
    {
        edges.push_back({src, dest});
    }
};

void topologicalSort(Graph &g)
{
    vector<int> indegrees(g.n);
    for (Edge edge : g.edges)
    {
        indegrees[edge.dest]++;
    }

    queue<int> q;
    for (int i = 0; i < g.n; i++)
    {
        if (indegrees[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (Edge edge : g.edges)
        {
            if (edge.src == u)
            {
                indegrees[edge.dest]--;
                if (indegrees[edge.dest] == 0)
                {
                    q.push(edge.dest);
                }
            }
        }
    }

    for (int i = 0; i < order.size(); i++)
    {
        cout << order[i] << " ";
    }
    cout << endl;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    topologicalSort(g);

    return 0;
}