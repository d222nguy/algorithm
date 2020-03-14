#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
struct index_pair{
  int first;
  int second;
};
int partition2(vector<long> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
index_pair partition3(vector<long> &a, int l, int r){
  //l -> j: < pivot
  //j + 1 -> k: = pivot
  //k + 1 -> i: > pivot
  //if we encounter an element that is less than pivot, shift j and k, swap a[i] and a[k] then a[k] to a[j]
  int x = a[l];
  int j = l - 1;
  int k = l;
  for (int i = l + 1; i <= r; ++i){
    if (a[i] < x){
      j++;
      k++;
      swap(a[i], a[k]);
      swap(a[k], a[j]);
    }
    else if (a[i] == x){
      k++;
      swap(a[i], a[k]);
    }
  }
  index_pair res;
  res.first = j;
  res.second = k;
  return res;
}
void randomized_quick_sort(vector<long> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  index_pair ip = partition3(a, l, r);
  randomized_quick_sort(a, l, ip.first);
  randomized_quick_sort(a, ip.second + 1, r);
}
int main() {
  int n;
  std::cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
