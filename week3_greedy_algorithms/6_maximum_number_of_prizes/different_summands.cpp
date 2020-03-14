#include <iostream>
#include <vector>
#include <math.h>
using std::vector;

vector<int> optimal_summands(long n) {
  vector<int> summands;
  //write your code here
  long m = sqrt(2*n);
  int res;
  for (int i = 0; i <= m + 1; ++i){
    if (i*(i + 1) > 2*n){
      res = i;
      break;
    }
  }
  int s = 0;
  for (int i = 1; i < res - 1; ++i){
    s += i;
    summands.push_back(i);
  }
  summands.push_back(n - s);
  return summands;
}

int main() {
  long n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
