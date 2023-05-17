// procedure DFS(graph, startNode)
//   visited = empty set
//   visited.add(startNode)
//   for each neighbor of startNode in graph
//     if neighbor is not in visited
//       DFS(graph, neighbor)
//   if all nodes in graph are in visited
//     return true
//   else
//     return false



#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int id;
  vector<int> neighbors;
};

bool DFS(vector<Node> &nodes, int startNode) {
  vector<bool> visited(nodes.size(), false);
  visited[startNode] = true;

  for (int neighbor : nodes[startNode].neighbors) {
    if (!visited[neighbor]) {
      if (!DFS(nodes, neighbor)) {
        return false;
      }
    }
  }

  return true;
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

  if (DFS(nodes, 0)) {
    cout << "The graph is connected" << endl;
  } else {
    cout << "The graph is not connected" << endl;
  }

  return 0;
}

