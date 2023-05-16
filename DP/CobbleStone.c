
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define HEIGHT 3 //
#define WIDTH 8  //	���̺��� ���� ����

#define TRUE 1
#define FALSE 0

#define PATTERN_COUNT 4

//	���̺��� ��Ÿ���� ������ �迭
int g_Table[HEIGHT][WIDTH] =
    {
        {6, 7, 12, -5, 5, 3, 11, 3},
        {-8, 10, 14, 9, 7, 13, 8, 5},
        {11, 12, 7, 4, 8, -2, 9, 4}};

/*
  �� ���� ���� ������ ������ �ְ������� ����� �迭
  �迭�� ���� ���̰� 5ĭ�� ������ 0��° ���� ���� ���� ���̴�.
  �� ������ ������ �迭�� ���� �ε����� ������ ������ ��Ÿ���� �����̴�. ������ 1���� 4������ ���̴�.
  �� 1���� 4������ ���� �迭�� �� �ε����� �� �� �̴�.
  ���� ���� �� ���� �ε����� �ǹ��Ѵ�. �� ������ �迭�� ������ ��, ���� �� �ε����� �� ���� �����̴�.
  �׸��� ���� ���̺��� ���� g_DT[1][3]�� 7�� ����Ǿ� �ִٴ� �ǹ̴�
  '0�� �� �ε����� ���� �ξ��� ���� �ְ������� ������ 1�� �� �ε����� ����3�� ���� �� ������ ��'�� 7���� �ǹ��Ѵ�.
*/
int g_DT[WIDTH][PATTERN_COUNT + 1];

/*
  ���� ���� ���� �ְ����� ���ϴ� �Լ��� Ž���� 0������ (WIDTH - 1)�� ���̴�.
*/
int PebbleDT(void);

/*
  �Ű������� �޴� �� ������ ���� �縳���������� �Ǵ��ϴ� �Լ���
  ���ϰ��� 1�̸� �縳 �����ϰ� 0�̸� �縳 �Ұ����ϴ�.
*/
int Together(int curPattern, int nextPattern);

/*
  Ž���� 0��° ������ �� ������ ��(WIDTH - 1)�� �����ϸ鼭 ���� �� �ְ����� �����ϴ� �Լ�
*/
int PatternPoint(int i, int curPattern);

int main(void)
{
  int high;

  high = PebbleDT();

  printf("MAX =   %d\n", high);

  return 0;
}

/*
  Ž���� 0��° ������ �� ������ ��(WIDTH - 1)�� �����ϸ鼭 ���� �� �ְ����� �����ϴ� �Լ�
*/
int PebbleDT(void)
{
  int curPattern;  //	Ž���� ������ ������ ���� ����
  int prevPattern; //	curPattern������ ������ ���� ����

  int high = 0;
  //	������ �ʱ�ȭ�� �������� ���� ���� ������ �ʱ�ȭ

  int value; //	0�� ������ �� ������ ���� Ž���ؼ� ���� ������, �ӽ÷� ������ ����

  int i; //	Ž���� �� �ε����� Ž���� 0��° ������ ������ ��(WIDTH - 1)�̴�.

  int maxPoint; //	���������� ������ �ְ�������

  //	0��° �������� �� ���ϵ��� ����� �� �� �ִ� �������� ���Ѵ�. �ʱ�ȭ �����̴�.
  for (curPattern = 1; curPattern <= 4; curPattern++)
    g_DT[0][curPattern] = PatternPoint(0, curPattern);

  //	0��° �������� �� ���ϵ��� ������ �������Ƿ�, 1��° ������ Ž���� �����Ѵ�.
  for (i = 1; i < WIDTH; i++)
  {
    for (curPattern = 1; curPattern <= 4; curPattern++)
    {
      for (prevPattern = 1; prevPattern <= 4; prevPattern++)
      {
        //	������ ������ curPattern�� �� ���� ������ prevPattern�� ���� �縳������ �����̸�
        if (Together(curPattern, prevPattern) == TRUE)
        {
          //	i��° �������� �ְ����� ������ ������ �� ������ ����� �ְ����� ���� ���̴�.
          value = g_DT[i - 1][prevPattern] + PatternPoint(i, curPattern);

          if (value > high)
            high = value;
        }
      }
      g_DT[i][curPattern] = high; //	�ְ����� ����
    }
  }

  //	4���� ���ϵ� �߿��� ���� ū ���� ���Ѵ�. �̴� �迭���� �ִ밪�� ���ϴ� ������ ����.
  maxPoint = g_DT[WIDTH - 1][1]; //	�ʱⰪ�� �迭�� 0��° ��ҷ� �ʱ�ȭ�� �� ���Ŀ� �ִ밪�� ���Ѵ�.
  for (int col = 1; col <= 4; col++)
  {
    if (g_DT[WIDTH - 1][col] > maxPoint)
      maxPoint = g_DT[WIDTH - 1][col];
  }

  return maxPoint;
}

/*
  �Ű������� �޴� �� ������ ���� �縳���������� �Ǵ��ϴ� �Լ���
  ���ϰ��� 1�̸� �縳 �����ϰ� 0�̸� �縳 �Ұ����ϴ�.
*/
int Together(int curPattern, int nextPattern)
{
  //	�� ������ ������ �縳 �Ұ����ϴ�.
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

/*
  i���� curPattern�������� ���� ��,
  i���� ���� ���� ���� �������� ��ȯ�ϴ� �Լ�
*/
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
