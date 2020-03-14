#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
struct point{
  double x;
  double y;
};
double dist(point a, point b){
  return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double find_minimum_inside(vector<point> &points, int l, int r){
  if (l >= r){
    return 1E8;
  }
  int mid = (l + r)/2;
  double d1 = find_minimum_inside(points, l, mid);
  double d2 = find_minimum_inside(points, mid + 1, r);
  double d = min(d1, d2);
  //std::cout<<d<<"\n";
  vector<point> shortlist;
  for (int i = l; i <= r; ++i){
    if (abs(points[i].x - points[mid].x )< d){
      point p;
      p.x = points[i].x;
      p.y = points[i].y;
      shortlist.push_back(p);
    }
  }
  sort(shortlist.begin(), shortlist.end(), [](const auto& i, const auto& j){
    return i.y < j.y;
  });
  for (int i = 0; i < shortlist.size(); i++){
    for (int j = i + 1; j < i + 8 && j <  shortlist.size(); j++){
      if (dist(shortlist[i], shortlist[j]) < d){
        d = dist(shortlist[i], shortlist[j]);
      }
    }
  }
  return d;
}
double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  vector<point> points(x.size());
  for (int i = 0; i < x.size(); ++i){
    points[i].x = x[i];
    points[i].y = y[i];
  }
  //first, sort points according to their x coordinates
  sort(points.begin(), points.end(), [](const auto& i, const auto& j){return i.x < j.x;});
  double d = find_minimum_inside(points, 0, points.size() - 1);
  return d;
}
int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
