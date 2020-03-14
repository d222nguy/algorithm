#include <iostream>
typedef long long ll;
using namespace std;
struct mat{
    ll a;
    ll b;
    ll c;
    ll d;
};
mat fibmat, idmat;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}
mat matmul(mat x, mat y, ll m){
    mat res;
    res.a = ((x.a * y.a) % m + (x.b * y.c) %m) %m;
    res.b = ((x.a * y.b) % m + (x.b * y.d) %m) %m;
    res.c = ((x.c * y.a) % m + (x.d * y.c) %m) %m;
    res.d = ((x.c * y.b) % m + (x.d * y.d) %m) %m;
    return res;
}
mat fib_mat_pow(ll n, ll m){
    if (n == 0)
        return idmat;
    if (n == 1)
        return fibmat;
    if (n % 2 == 0){
        mat r = fib_mat_pow(n/2, m);
        return matmul(r, r, m);
    }
    else{
        mat r = fib_mat_pow(n/2, m);
        return matmul(matmul(r, r, m), fibmat, m);
    }
}
ll get_fibonacci_huge_fast(ll n, ll m){
    if (n <= 1){
        return n;
    }
    mat resmat;
    resmat = fib_mat_pow(n - 1, m);
    return (resmat.a);
}



int main() {
    fibmat.a = 1; fibmat.b = 1; fibmat.c = 1; fibmat.d = 0;
    idmat.a = 1; idmat.b = 0; idmat.c = 0; idmat.d = 1;
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
