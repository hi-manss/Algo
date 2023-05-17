#include <iostream>
#include <vector>

using namespace std;
bool findSubset(vector<int> &set, int sum)
{
    int n = set.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }
    if (!dp[n][sum])
        return false;
    int i = n, j = sum;
    while (j > 0)
    {
        if (dp[i - 1][j])
            i--;
        else
        {
            cout << set[i - 1] << " ";
            j -= set[i - 1];
            i--;
        }
    }
    cout << endl;
    return true;
}

int main()
{
    vector<int> set = {1, 2, 3, 4, 5};
    int sum = 8;
    if (!findSubset(set, sum))
        cout << "No subset found with the required sum." << endl;
    return 0;
}