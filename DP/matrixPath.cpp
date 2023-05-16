#include <bits/stdc++.h>
using namespace std;
int maxvalue(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

int dp(int **arr, int **table, int n, int *count2)
{
  table[0][0] = arr[0][0];
  (*count2)++;

  for (int i = 1; i < n; i++)
  {
    table[0][i] = arr[0][i] + table[0][i - 1]; // 1열일 경우 행의 값  누산
    (*count2)++;
  }

  for (int i = 1; i < n; i++)
  {
    table[i][0] = arr[i][0] + table[i - 1][0]; // 1행일 경우 열의 값 누산
    (*count2)++;
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      table[i][j] = maxvalue(arr[i][j] + table[i - 1], arr[i][j] + table[i][j - 1]);

      (*count2)++;
    }
  }
  return table[n - 1][n - 1];
}

int main()
{
}