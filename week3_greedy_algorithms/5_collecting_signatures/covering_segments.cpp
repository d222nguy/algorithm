#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //algorithm: greedy
  //sort all segments by starting points
  //if the last point is still on this segment, continue
  //if need to add a point, new point = end point of this segment
  //write your code here
  std::sort(segments.begin(), segments.end(), [](const auto& i, const auto& j){return i.end < j.end;});
  points.push_back(segments[0].end);
  for (int i = 0; i < segments.size(); ++i){
    if (segments[i].start <= points.back()){
      continue;
    }
    else{
      points.push_back(segments[i].end);
    }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
