#include <iostream>
#include <vector>
using namespace std;
int get_change(int m) {
  //write your code here
  vector<int> F(1001);
  F[1] = 1;
  F[2] = 2;
  F[3] = 1;
  F[4] = 1;
  for (int i = 5; i <= m; i++){
    F[i] = min(F[i - 1] + 1, min(F[i - 3] + 1, F[i - 4] + 1));
  }
  return F[m];
  //return m / 4;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
