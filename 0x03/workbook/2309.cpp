#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int fakesum = 0;
  int sum = 0;
  int realdwarp[9];
  int ans[9];
  int idx1, idx2;
  int temp1, temp2;
  int dwarp[10] = {};

  for (int i = 0; i < 9; i++)
  {
    cin >> dwarp[i];
    sum += dwarp[i];
  }

  fakesum = sum - 100;

  for (int i = 0; i < 9; i++)
  {
    for (int j = 1; j < 9; j++)
    {
      if (dwarp[i] + dwarp[j] == fakesum) // 여기서 i랑 j가 fakedwarp
      {
        temp1 = dwarp[i];
        temp2 = dwarp[j];
      }
    }
  }

  sort(dwarp, dwarp + 9);
  for (int i = 0; i < 9; i++)
  {

    if (temp1 == dwarp[i] || temp2 == dwarp[i])
    {
      continue;
    }
    cout << dwarp[i] << "\n";
  }
}
