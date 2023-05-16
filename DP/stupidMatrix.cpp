#include <bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
  if (x > y)
  {
    return x;
  }
  return y;
}

int dynamicProgramming(int (&arr)[4][4], int i, int j, int *count)
{
  (*count)++;
  if ((i == 0) && (j == 0))
  {
    return arr[i][j];
  }
  else if (i == 0)
  {
    return arr[0][j] + dynamicProgramming(arr, 0, j - 1, count);
  }
  else if (j == 0)
  {
    return arr[i][0] + dynamicProgramming(arr, i - 1, 0, count);
  }
  else
  {
    return arr[i][j] + max(dynamicProgramming(arr, i - 1, j, count), dynamicProgramming(arr, i, j - 1, count));
  }  
}

int main()
{
  int count = 0;

  int arr[4][4] = {
      6, 7, 12, 15,
      5, 3, 11, 18,
      7, 17, 3, 3,
      8, 10, 14, 9};

  printf("%d\n", dynamicProgramming(arr, 3, 3, &count));

  return 0;
}