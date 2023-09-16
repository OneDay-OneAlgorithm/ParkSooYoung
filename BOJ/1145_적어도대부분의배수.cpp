#include <iostream>
using namespace std;

int gcd(int a, int b)
{
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int lcm(int a, int b)
{
  return (a * b) / gcd(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int num[5];
  for (int i = 0; i < 5; i++) {
    cin >> num[i];
  }

  int ans = 987654321;
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      int tmp = lcm(num[i], num[j]);
      for (int k = j + 1; k < 5; k++) {
        int multiple = lcm(tmp, num[k]);
        ans = min(ans, multiple);
      }
    }
  }

  cout << ans << '\n';
}
