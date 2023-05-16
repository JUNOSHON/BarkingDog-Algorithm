#include <bits/stdc++.h>

int max_path(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

int loop(int **arr, int *cnt, int i, int j)
{
  (*cnt)++;
  if (i == 0 && j == 0)
  {
    return arr[i][j];
  }
  else if (i == 0)
  {
    return loop(arr, cnt, i, j - 1) + arr[i][j];
  }
  else if (j == 0)
  {
    return loop(arr, cnt, i - 1, j) + arr[i][j];
  }
  else
  {
    return max_path(loop(arr, cnt, i, j - 1) + arr[i][j], loop(arr, cnt, i - 1, j) + arr[i][j]);
  }
}

int dp(int **arr, int **c, int n, int *cnt2)
{
  c[0][0] = arr[0][0];
  (*cnt2)++;

  for (int i = 1; i < n; i++)
  {
    c[0][i] = arr[0][i] + c[0][i - 1];
    (*cnt2)++;
  }
  for (int i = 1; i < n; i++)
  {
    c[i][0] = arr[i][0] + c[i - 1][0];
    (*cnt2)++;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      c[i][j] = max_path(arr[i][j] + c[i - 1][j], arr[i][j] + c[i][j - 1]);
      (*cnt2)++;
    }
  }
  return c[n - 1][n - 1];
}

int main()
{
  int n, cnt1 = 0, cnt2 = 0;
  scanf("%d", &n);

  int **arr = (int **)malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(sizeof(int) * n);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }

  int **c = (int **)malloc(sizeof(int *) * n);

  for (int i = 0; i < n; i++)
  {
    c[i] = (int *)malloc(sizeof(int) * n);
  }

  printf("재귀 최고점-> %d \n DP 최고점-> %d\n\n", loop(arr, &cnt1, n - 1, n - 1), dp(arr, c, n, &cnt2));

  printf("재귀 수행 횟수 -> %d\n DP 수행 횟수 -> %d", cnt1 + 1, cnt2);
}