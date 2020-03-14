#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
struct segment{
  long start;
  long end;
};
struct points_keep_idx{
  long value;
  long idx;
};
vector<long> fast_count_segments(vector<long> starts, vector<long> ends, vector<long> points) {
  vector<segment> segments(starts.size());
  vector<points_keep_idx> points_ki(points.size());
  for (int i = 0; i < segments.size(); i++){
    segments[i].start = starts[i];
    segments[i].end = ends[i];
  }
  for (int i = 0; i < points.size(); i++){
    points_ki[i].value = points[i];
    points_ki[i].idx = i;
  }
  std::sort(segments.begin(), segments.end(), [](const auto& i, const auto& j){return i.start < j.start;});
  std::sort(points_ki.begin(), points_ki.end(), [](const auto& i, const auto& j){return i.value < j.value;});
  vector<long> cnt(points.size());
  vector<long> start_after(points.size());
  vector<long> end_before(points.size());
  //two pointers: i on segments, j on points
  int i, j;
  i = 0;
  j = 0;
  while (i < segments.size() && j < points.size()){
    if (segments[i].start > points_ki[j].value){
      start_after[j] = (segments.size() - i);
      j++;
    }
    else{
      i++;
    }
  }
  while (j < points.size()){
    start_after[j] = 0;
    j++;
  }
  std::sort(segments.begin(), segments.end(), [](const auto& i, const auto& j){return i.end < j.end;});
  i = 0;
  j = 0;
  while (i < segments.size() && j < points.size()){
    if (segments[i].end >= points_ki[j].value){
      end_before[j] = i;
      j++;
    }
    else{
      i++;
    }
  }
  while (j < points.size()){
    end_before[j] = segments.size();
    j++;
  }
  // for (i = 0; i < points_ki.size(); i++){
  //   std::cout<< points_ki[i].value << " " << points_ki[i].idx << "\n";
  // }
  // std::cout<<"============================"<<"\n";
  for (i = 0; i < cnt.size(); ++i){
    //std::cout<< start_after[i] << " " << end_before[i] << "\n";
    cnt[points_ki[i].idx] = segments.size() - end_before[i] - start_after[i];
  }
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<long> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<long> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<long> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
