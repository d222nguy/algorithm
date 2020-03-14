#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int partition3(vector<int> &A) {
  //write your code here
  bool F[21][6001];
  for (int i = 0; i <= A.size(); ++i){
    F[0][i] = false;
  }
  F[0][0] = true;
  for (int i = 1; i <= A.size(); ++i){
    for (int j = 0; j < 6001; ++j){
      if (j >= A[i - 1])
        F[i][j] = max(F[i - 1][j], F[i - 1][j - A[i - 1]]);
      else
        F[i][j] = F[i - 1][j];
    }
  }
  long s = 0;
  for (int i = 0; i < A.size(); ++i)
    s += A[i];
  //cout << F[A.size()][4] << endl;
  //cout << F[0][5] << endl;
  //cout << s % 3 << endl;
  //cout << F[A.size()][118] << endl;
  if (s % 3 == 0 && F[A.size()][s/3] > 0 && F[A.size()][2*s/3] > 0)
    return 1;
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
