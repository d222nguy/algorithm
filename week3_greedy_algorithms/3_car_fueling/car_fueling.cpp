#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

long compute_min_refills(long dist, long tank, vector<long> & stops) {
    // write your code here
    //Greedy algorithms: go to the farthest stops[i] that we can!
    //iterate through all stops:
    //if stops[i] - stop > dist, then update: next_stop = stops[i - 1]
    //else increase i
    long stop = 0;
    long res = 0;
    long iter = 0;
    long N = stops.size();
    while (iter < N && stops[iter] <= dist){
        if (stops[iter] - stop <= tank){
            iter++;
        }
        else{
            if (stops[iter - 1] - stop <= tank){
                stop = stops[iter - 1];
                res++;
                iter++;
            }
            else
                return -1;
        }
    }
    //std::cout << stop << std::endl;
    if (dist - stop > tank)
    {
        stop = stops[N - 1];
        //std::cout << "stops[n]: " <<stops[N - 1] << std::endl;
        if (dist - stop > tank)
            return -1;
        else
            return res + 1;
    }
    return res;
}


int main() {
    long d = 0;
    cin >> d;
    long m = 0;
    cin >> m;
    long n = 0;
    cin >> n;

    vector<long> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
