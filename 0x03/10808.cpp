#include <bits/stdc++.h>
using namespace std;

int main()
{

  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  cin >> s;

  for (char alpabet = 'a'; alpabet <= 'z'; alpabet++)
  {
    int count = 0;
    for (auto find : s)
    {
      if (alpabet == find)
      {
        count++;
      }
    }
    cout << count << " ";
  }
}