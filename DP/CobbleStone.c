
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 3
#define WIDTH 8

#define TRUE 1
#define FALSE 0

#define PATTERN_COUNT 4

//	���̺��� ��Ÿ���� ������ �迭
int g_Table[HEIGHT][WIDTH] =
    {
        {6, 7, 12, -5, 5, 3, 11, 3},
        {-8, 10, 14, 9, 7, 13, 8, 5},
        {11, 12, 7, 4, 8, -2, 9, 4}};

int g_DT[WIDTH][PATTERN_COUNT + 1];

int PebbleDT(void);

int Together(int curPattern, int nextPattern);
int PebbleDT(void)
{
  int curPattern;
  int prevPattern;

  int high = 0;

  int value;

  int i;

  int maxPoint;

  for (curPattern = 1; curPattern <= 4; curPattern++)
    g_DT[0][curPattern] = PatternPoint(0, curPattern);

  for (i = 1; i < WIDTH; i++)
  {
    for (curPattern = 1; curPattern <= 4; curPattern++)
    {
      for (prevPattern = 1; prevPattern <= 4; prevPattern++)
      {

        if (Together(curPattern, prevPattern) == TRUE)
        {

          value = g_DT[i - 1][prevPattern] + PatternPoint(i, curPattern);

          if (value > high)
            high = value;
        }
      }
      g_DT[i][curPattern] = high;
    }
  }

  maxPoint = g_DT[WIDTH - 1][1];
  for (int col = 1; col <= 4; col++)
  {
    if (g_DT[WIDTH - 1][col] > maxPoint)
      maxPoint = g_DT[WIDTH - 1][col];
  }

  return maxPoint;
}

int Together(int curPattern, int nextPattern)
{

  if (curPattern == nextPattern)
    return FALSE;

  if (curPattern == 4)
  {
    if (nextPattern == 2)
      return TRUE;
  }
  else if (curPattern == 3)
  {
    if (nextPattern == 1 || nextPattern == 2)
      return TRUE;
  }
  else if (curPattern == 2)
  {
    if (nextPattern != 2)
      return TRUE;
  }
  else if (curPattern == 1)
  {
    if (nextPattern == 3 || nextPattern == 2)
      return TRUE;
  }

  return FALSE;
}
int PatternPoint(int i, int curPattern)
{
  if (curPattern == 1)
    return g_Table[0][i];

  else if (curPattern == 2)
    return g_Table[1][i];

  else if (curPattern == 3)
    return g_Table[2][i];

  else if (curPattern == 4)
    return g_Table[0][i] + g_Table[2][i];

  return 0;
}

int main(void)
{
  int high;

  high = PebbleDT();

  printf("MAX =   %d\n", high);

  return 0;
}
