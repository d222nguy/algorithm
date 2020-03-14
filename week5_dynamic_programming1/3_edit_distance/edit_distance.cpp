#include <iostream>
#include <string>

using std::string;
using namespace std;
int edit_distance(const string &str1, const string &str2) {
  //write your code here
  long F[101][101];
  F[0][0] = 0;
  for (int i = 1; i <= str1.length(); i++)
    F[i][0] = i;
  for (int j = 1; j <= str2.length(); j++)
    F[0][j] = j;
  //
  for (int i = 1; i <= str1.length(); ++i){
    for (int j = 1; j <= str2.length(); ++j){
      if (str1[i - 1] == str2[j - 1]){
        F[i][j] = F[i - 1][j - 1];
      }
      else{
        F[i][j] = F[i - 1][j - 1] + 1;
        F[i][j] = min(F[i][j], F[i - 1][j] + 1);
        F[i][j] = min(F[i][j], F[i][j - 1] + 1);
      }
    }
  }  
  return F[str1.length()][str2.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
