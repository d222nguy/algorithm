#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
void swap(long& a, long& b){
  long tmp = a;
  a = b;
  b = tmp;
}
long gcd_fast(long a, long b){
    if (a < b)
      swap(a, b);
    if (b == 0)
      return 1;
    while (b != 0){
      a = a % b;
      swap(a, b);
    }
    return a;
}
int main() {
  long a, b;
  int counter = 0;
  // while (counter < 10){
  //   counter++;
  //   long a = rand() % 1000;
  //   long b = rand() % 1000;
  //   long res1 = gcd_naive(a, b);
  //   long res2 = gcd_fast(a, b);
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
  std::cout << gcd_fast(a, b);
  return 0;
}
