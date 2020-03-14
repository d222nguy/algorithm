#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
struct object{
  long weights;
  long values;
  double key; // values/weights
};
double get_optimal_value(long capacity, vector<long> weights, vector<long> values) {
  double value = 0.0;
  //greedy:
  //sort objects by their values/weights, then pick each object until we cannot
  // write your code here
  long N = values.size();
  vector<object> obj(N);
  for (long i = 0; i < N; i++){
    obj[i].weights = weights[i];
    obj[i].values = values[i];
    obj[i].key = values[i]*1.0/weights[i];
  }
  std::sort(obj.begin(), obj.end(), [](const auto& i, const auto& j){ return i.key > j.key;});
  long iter = 0;
  while (iter < N && capacity > 0){
    if (capacity >= obj[iter].weights){
      capacity -= obj[iter].weights;
      value += obj[iter].values;
    }
    else{
      value += obj[iter].values * capacity*1.0/obj[iter].weights;
      capacity = 0;
      //std::cout<<"Hella no! " << obj[iter].va;
    }
    iter += 1;
  }
  return value;
}

int main() {
  long n;
  long capacity;
  std::cin >> n >> capacity;
  vector<long> values(n);
  vector<long> weights(n);
  for (long i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
