#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A, B;
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  int aplusb = A + B;
  int aminusb = A - B;
  int amulb = A * B;
  int adivb = A / B;
  int alastb = A % B;

  cout << aplusb << "\n";
  cout << aminusb << "\n";
  cout << amulb << "\n";
  cout << adivb << "\n";
  cout << alastb << "\n";
}