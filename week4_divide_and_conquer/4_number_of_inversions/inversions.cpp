#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  //std::cout << "ave = " << ave << "\n";
  size_t i = left;
  size_t j = ave;
  size_t k = left;
  while (i < ave && j < right){
    if (a[i] > a[j]){
      b[k] = a[j];
      j++;
    }
    else{
      b[k] = a[i];
      i++;
      number_of_inversions += (j - ave);
    }
    k++;
  }
  while (i < ave){
    b[k] = a[i];
    number_of_inversions += (right - ave);
    i++;
    k++;
  }
  while (j < right){
    b[k] = a[j];
    j++;
    k++;
  }
  for (int i = left; i < right; i++){
    a[i] = b[i];
  }
  // if (left == 0 && right ==a.size()){
  //   for (int i = 0; i < b.size(); i++){
  //     std::cout<<b[i] << ", ";
  //   }
  //   std::cout<<"\n";
  // }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
