#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int A, B, C;
  int multi;
  int occur[10] = {}; // 각 숫자가 몇 번 나오는지 저장하는 배열

  cin >> A;
  cin >> B;
  cin >> C;
  multi = A * B * C;

  while (1)
  {

    occur[multi % 10] += 1;
    multi = multi / 10;

    if (multi == 0)
      break;
  }

  for (int i = 0; i < 10; i++)
  {
    cout << occur[i] << '\n';
  }
}