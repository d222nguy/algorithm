#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
vector<long> optimal_sequence_fast(long n){
  const long MAXN = 1000000;
  vector<long> sequence;
  vector<long> F(n+ 1);
  F[1] = 0;
  for (long i = 2; i <= n; i++){
    F[i] = F[i - 1] + 1;
    if (i % 2 == 0)
      F[i] = min(F[i], F[i/2] + 1);
    if (i % 3 == 0)
      F[i] = min(F[i], F[i/3] + 1);
  }
  // for (int i = 1; i <= n; ++i){
  //   cout << F[i] << " ";
  // }
  // cout << endl;
  long d = n;
  sequence.push_back(d);
  while (d > 1){
    if (F[d] == F[d - 1] + 1){
      sequence.push_back(d - 1);
      d -= 1;
    }
    else if (d % 2 == 0 && F[d] == F[d/2] + 1){
      sequence.push_back(d/2);
      d /= 2;
    }
    else if (d % 3 == 0 && F[d] == F[d/3] + 1){
      sequence.push_back(d/3);
      d /= 3;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}
int main() {
  int n;
  std::cin >> n;
  vector<long> sequence = optimal_sequence_fast(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
