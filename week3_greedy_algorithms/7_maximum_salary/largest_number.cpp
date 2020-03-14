#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here
  //sort a from largest to smallest, then concat a0 >a1 > ... > a(n-1)
  std::sort(a.begin(), a.end(), [](const string& i, const string& j){
    string a = i + j;
    string b = j + i;
    return a > b;
    // int iter = 0;
    // int m = i.length();
    // int n = j.length();
    // while (iter < std::min(m, n) && i[iter] == j[iter])
    //   iter++;
    // if (iter < std::min(m, n)){
    //   return i[iter] > j[iter];
    // }
    // else{
    //   if (iter < m){ //mean i is longer
    //     string tmp = j;
        
    //   }
    //   else{
    //     string tmp = i;
    //     while (tmp.length() < j.length())
    //       tmp = tmp + i[iter - 1];
    //     return tmp > j;
    //   }
    // }
  });

  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
