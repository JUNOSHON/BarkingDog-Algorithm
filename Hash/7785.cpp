#include <bits/stdc++.h>

#include <unordered_set>
using namespace std;

unordered_set<string> s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  int log;
  cin >> log;

  while (log--)
  {
    string name, enterOrLeave;
    cin >> name >> enterOrLeave;
    if (enterOrLeave == "enter")
    {
      s.insert(name);
    }
    else
    {
      s.erase(name);
    }
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());

  for (auto x : ans)
  {
    cout << x << '\n';
  }
}