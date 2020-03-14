#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long get_majority_element(vector<long> &a, int left, int right) {
  if (left > right) return -1;
  if (left == right)
    return a[left];
  //write your code here
  int mid = (left + right) / 2;
  long x = get_majority_element(a, left, mid);
  long y = get_majority_element(a, mid + 1, right);
  int i = 0, count_x = 0, count_y = 0;
  if (x == y)
    return x;
  for (i = left; i <= right; ++i){
    if (a[i] == x){
      count_x++;
    }
    else if (a[i] == y){
      count_y++;
    }
  }
  if (count_x > (right - left + 1)/2)
    return x;
  if (count_y > (right - left + 1)/2)
    return y;
  return -1;
}
long get_majority_element_fast(vector<long>& a){
  int N = a.size();
  //need: major_ind (keep tracks of an index whose values = majority value)
  //and major_value
  //and: count
  int count = 0, major_ind = -1, major_value = -1;
  for (int i = 0; i < N; i++){
    if (count > 0){
      if (a[i] == major_value){
        count++;
      }
      else{
        count--;
      }
    }
    if (count == 0){
      major_value = a[i];
      count++;
    }
  }
  count = 0;
  for (int i = 0; i < N; i++){
    if (a[i] == major_value){
      count++;
    }
  }
  return (count > N/2);
}
int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  //std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
  std::cout << (get_majority_element_fast(a)) << '\n';
}
