#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, X;
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> X;
  vector<int> v(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i];
  }
  for (int i = 0; i < N; i++)
  {
    if (v[i] < X)
    {
      cout << v[i] << " ";
    }
  }
}