// procedure BFS(graph, startNode)
//   queue = empty queue
//   queue.enqueue(startNode)
//   visited = empty set
//   visited.add(startNode)
//   while queue is not empty
//     node = queue.dequeue()
//     for each neighbor of node in graph
//       if neighbor is not in visited
//         queue.enqueue(neighbor)
//         visited.add(neighbor)
//   print all nodes in visited


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
  int id;
  vector<int> neighbors;
};

void BFS(vector<Node> &nodes, int startNode) {
  queue<int> queue;
  queue.push(startNode);
  vector<bool> visited(nodes.size(), false);
  visited[startNode] = true;

  while (!queue.empty()) {
    int node = queue.front();
    queue.pop();

    for (int neighbor : nodes[node].neighbors) {
      if (!visited[neighbor]) {
        queue.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }

  for (int i = 0; i < nodes.size(); i++) {
    if (visited[i]) {
      cout << nodes[i].id << " ";
    }
  }

  cout << endl;
}

int main() {
  vector<Node> nodes;

  for (int i = 0; i < 5; i++) {
    Node node;
    node.id = i;
    nodes.push_back(node);
  }

  nodes[0].neighbors.push_back(1);
  nodes[0].neighbors.push_back(3);
  nodes[1].neighbors.push_back(2);
  nodes[3].neighbors.push_back(4);

  BFS(nodes, 0);

  return 0;
}