#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;

  cin >> T;
  vector<int> vA(T);
  vector<int> vB(T);
  fill(vA.begin(), vB.end(), 0);
  fill(vA.begin(), vB.end(), 0);

  for (int i = 1; i <= T; i++)
  {
    cin >> vA[i] >> vB[i];
  }

  for (int i = 1; i <= T; i++)
  {
    cout << vA[i] + vB[i] << "\n";
  }
}