#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long lcm_fast(long a, long b){
  if (a < b)
    std::swap(a, b);
  long long res;
  for (long i = 1; i <= b; i++){
    res = a * i;
    if (res % b == 0)
      return res;
  }
  return -1;
}
void swap(long& a, long& b){
  long tmp = a;
  a = tmp;
  tmp = b;
}
int main() {
  int a, b;
  // int counter = 0;
  // while (counter < 100){
  //   counter++;
  //   long a = rand() % 1000;
  //   long b = rand() % 1000;
  //   long res1 = lcm_naive(a, b);
  //   long res2 = lcm_fast(a, b);
  //   std::cout <<"a = " << a << ", b = "<< b << std::endl;
  //   if (res1 == res2){
  //     std::cout<<"OK!"<<std::endl;
  //   } 
  //   else{
  //     std::cout<<"Wrong answer! "<< res1 << " " << res2 << std::endl;
  //     break;
  //   }
  // }
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
