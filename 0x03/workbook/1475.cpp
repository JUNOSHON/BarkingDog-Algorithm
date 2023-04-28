#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  /*
    다솜이의 방번호 N에서 각 숫자가 몇 번 나왔는지 검사한다. 제일 많이 나온 방 번호만큼의 숫자
    세트가 필요할 것이다. 6과 9를 뒤집어 사용할 수 있는건 나중에 생각하자

  */

  int N;
  int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int occur[10] = {}; // 다솜이의 방 숫자 번호가 몇 번 등장했나
  cin >> N;
  int max = 0;

  while (N != 0)
  {
    occur[N % 10] += 1;
    N /= 10;
  }

  int sixnine = (occur[6] + occur[9] + 1) / 2;
  occur[6] = sixnine;
  occur[9] = sixnine;

  for (int i = 0; i < 10; i++)
  {
    if (occur[max] < occur[i])
    {
      max = i;
    }
  }
  cout << occur[max] << '\n';
}