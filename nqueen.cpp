#include <iostream>
using namespace std;
int n;
bool board[10][10];
bool is_valid(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] || board[row][i] || board[row - i][col] || board[row][col - i])
        {
            return false;
        }
    }
    return true;
}
void backtrack(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (board[i][j] ? 'Q' : '.');
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (is_valid(row, col))
        {
            board[row][col] = true;
            backtrack(row + 1);
            board[row][col] = false;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = false;
        }
    }
    backtrack(0);
    return 0;
}
