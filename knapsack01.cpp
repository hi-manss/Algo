#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> profits, vector<int> weights, int capacity) {
  int table[profits.size() + 1][capacity + 1];

  for (int i = 0; i <= profits.size(); i++) {
    for (int j = 0; j <= capacity; j++) {
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else {
        table[i][j] = table[i - 1][j];
        if (weights[i - 1] <= j) {
          table[i][j] = max(table[i][j], table[i - 1][j - weights[i - 1]] + profits[i - 1]);
        }
      }
    }
  }

  return table[profits.size()][capacity];
}

int main() {
  vector<int> profits = {10, 4, 7, 2, 9};
  vector<int> weights = {2, 1, 3, 2, 5};

  int capacity = 10;

  int maxProfit = knapsack(profits, weights, capacity);

  cout << "The maximum profit is: " << maxProfit << endl;

  return 0;
}