#include <iostream>
#include <vector>
using std::vector;
typedef long long ll;
using namespace std;
struct mat{
    ll a;
    ll b;
    ll c;
    ll d;
};
mat fibmat, idmat;
const int MOD = 10;
long long get_fibonacci_huge_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % MOD;
}
mat matmul(mat x, mat y){
    mat res;
    res.a = ((x.a * y.a) % MOD + (x.b * y.c) %MOD) %MOD;
    res.b = ((x.a * y.b) % MOD + (x.b * y.d) %MOD) %MOD;
    res.c = ((x.c * y.a) % MOD + (x.d * y.c) %MOD) %MOD;
    res.d = ((x.c * y.b) % MOD + (x.d * y.d) %MOD) %MOD;
    return res;
}
mat fib_mat_pow(ll n){
    if (n == 0)
        return idmat;
    if (n == 1)
        return fibmat;
    if (n % 2 == 0){
        mat r = fib_mat_pow(n/2);
        return matmul(r, r);
    }
    else{
        mat r = fib_mat_pow(n/2);
        return matmul(matmul(r, r), fibmat);
    }
}
ll get_fibonacci_fast(ll n){
    if (n <= 1){
        return n;
    }
    mat resmat;
    resmat = fib_mat_pow(n - 1);
    return (resmat.a);
}
long get_last_digit_fast(ll n){
    mat A = fib_mat_pow(n);
    //cout << A.a << endl;
    A.a -= 1;
    A.d -= 1;
    mat B;
    B.a = 1; B.b = 1; B.c = 1; B.d = 0;
    mat r = matmul(B, A);
    return r.a;
}
long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}
ll get_fibonacci_partial_sum_fast(ll from, ll to){
    long a, b;
    if (from < 1)
        a = 0;
    else
        a = get_last_digit_fast(from - 1);
    if (to < 0)
        b = 0;
    else
        b = get_last_digit_fast(to);
    //cout << a << endl << b << endl;
    return (b - a + 10)%MOD;
}
int main() {
    long long from, to;
    fibmat.a = 1; fibmat.b = 1; fibmat.c = 1; fibmat.d = 0;
    idmat.a = 1; idmat.b = 0; idmat.c = 0; idmat.d = 1;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
