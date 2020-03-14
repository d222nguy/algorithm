#include <iostream>
#include <vector>

using std::vector;
using namespace std;
long lcs2(vector<long> &a, vector<long> &b) {
  //write your code here
  long F[101][101];
  for (int i = 0; i <= a.size(); ++i){
    F[i][0] = 0;
  }
  for (int j = 0; j <= b.size(); ++j){
    F[0][j] = 0;
  }
  for (int i = 1; i <= a.size(); ++i){
    for (int j = 1; j <= b.size(); ++j){
      if (a[i - 1] == b[j - 1]){
        F[i][j] = F[i - 1][j - 1] + 1;
      }
      else
        F[i][j] = max(F[i - 1][j], F[i][j- 1]);
    }
  }
  return F[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<long> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
