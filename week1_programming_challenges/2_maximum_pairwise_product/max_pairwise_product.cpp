#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cin;
using std::cout;
using namespace std;
long long MaxPairwiseProduct(vector<long long>& numbers) {
    long long max_product = 0;
    long long n = numbers.size();
    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}
long long MaxPairwiseProduct_fast(std::vector<long long>& numbers){
    long long max_element = 0;
    //cout << *numbers.begin() << endl;
    sort(numbers.begin(), numbers.end());
    long long n = numbers.size();
    return (numbers[n - 1] * numbers[n - 2]);
}

int main() {
    //stress test
    int counter = 0;
    while (counter < 10){
        counter++;
        long n = rand() % 10 + 2;
        cout << n << endl;
        vector<long long> a;
        for (int i = 0; i < n; ++i){
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i){
            cout << a[i] << ' ';
        }
        cout << endl;
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProduct_fast(a);
        if (res1 != res2){
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else{
            cout << "OK\n";
        }
    }

    // vector<int> a;
    // vector<long long> numbers(n);
    // cin >> n;
    // for (int i = 0; i < n; ++i) {
    //     std::cin >> numbers[i];
    // }
    //sort(numbers.begin(), numbers.end());
    //cout << MaxPairwiseProduct_fast(numbers) << "\n";
    return 0;
}
