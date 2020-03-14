#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  long F[101][101][101];
  for (int i = 0; i <= a.size(); ++i)
    for (int j = 0; j <= b.size(); ++j)
      for (int k = 0; k <= c.size(); ++k)
        F[i][j][k] = 0;
  for (int i = 1; i <= a.size(); ++i){
    for (int j = 1; j <= b.size(); ++j){
      for (int k = 1; k <= c.size(); ++k){
        if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]){
          //cout << i << " " << j << " " << k << endl;
          F[i][j][k] = F[i - 1][j - 1][k - 1] + 1; 
        }
        else{
          F[i][j][k] = max(max(F[i - 1][j][k], F[i][j - 1][k]), F[i][j][k - 1]);
        }
      }
    }
  }
  return F[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
