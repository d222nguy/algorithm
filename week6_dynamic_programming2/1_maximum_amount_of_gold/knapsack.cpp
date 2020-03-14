#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int optimal_weight(long W, const vector<int> &w) {
  //write your code here
  bool F[10001];
  bool f[10001];
  F[0] = true;
  f[0] = true;
  for (int i = 1; i <= W; ++i){
    F[i] = false;
    f[i] = false;
  }
  for (int i = 1; i <= w.size(); i++){
    for (int j = W; j >= 1; j--){
      // F[j] = f[j];
      // if (j >= w[i - 1] && f[j - w[i - 1]])
      //   F[j] = true;
      if (j >= w[i - 1] && F[j - w[i - 1]])
        F[j] = true;
    }
    for (int j = 1; j <= W; j++){
      f[j] = F[j];
    }
  }
  for (int i = W; i >= 0; i--){
    if (F[i])
      return i;
  }
  std::cout<<f[1]<<endl;
  //std::cout<<F[2][1]<<endl;
  return -1;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
