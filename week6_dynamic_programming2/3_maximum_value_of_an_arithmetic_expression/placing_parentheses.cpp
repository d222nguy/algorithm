#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;
long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  const long long MAX_LONG = 9.223372e+18;
  const long long MIN_LONG = -9.223372e+18;
  //write your code here
  vector<int> nums;
  vector<char> op;
  long long m[20][20];
  long long M[20][20];
  //cout << exp << endl;
  int N = (exp.length() + 1)/2;
  for (int i = 0; i < exp.length(); ++i){
    if (i % 2 == 0){
      nums.push_back((exp[i] - '0'));
    }
    else{
      op.push_back(exp[i]);
    }
  }
  
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      m[i][j] = MAX_LONG;
      M[i][j] = -MAX_LONG;
    }
  }
  for (int i = 0; i < N; i++){
    m[i][i] = nums[i];
    M[i][i] = nums[i];
  }
  for (int i = 1; i < N; i++){ //gap
    for (int j = 0; j < N - i; j++){
      for (int k = j; k < j + i; k++){
        long long a = eval(m[j][k], m[k + 1][j + i], op[k]);
        long long b = eval(m[j][k], M[k + 1][j + i], op[k]);
        long long c = eval(M[j][k], m[k + 1][j + i], op[k]);
        long long d = eval(M[j][k], M[k + 1][j + i], op[k]);
        m[j][j + i] = min(m[j][j + i], min(min(a, b), min(c, d)));
        M[j][j + i] = max(M[j][j + i], max(max(a, b), max(c, d)));
      }
    }
  }
  //cout<<M[0][1]<<endl;
  return M[0][N - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
