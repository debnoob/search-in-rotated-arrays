#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(const vector<int>& r, int from, int to, int x) {
  int p1 = from;
  int p2 = to;
  while (p1 < p2 - 1) {
    int mid = (p1 + p2 ) / 2;
    if (x < r[mid])
      p2 = mid;
    else
      p1 = mid;
  }
  if (r[p1] == x) return p1;
  if (r[p2] == x) return p2;
  return -1;
}

int BinarySearchRotatedSortedArray(const vector<int>& r, int x) {
  int p1 = 0;
  int p2 = r.size() - 1;
  while (p1 < p2 - 1) {
    int mid = (p1 + p2) / 2;
    if (r[mid] >= r[p1])
      p1 = mid;
    else
      p2 = mid;
  }
  if (r[p1] < r[p2]) p1++;
  if (x >= r[0])
    return BinarySearch(r, 0, p1, x);
  else
    return BinarySearch(r, p1 + 1, r.size() - 1, x);
}


int main() {
  std::vector<int> x(10);
  int cur_value = 0;
  int cur_place = 5;
  for (int i = 0 ; i < 10; i++) {
    x[cur_place] = cur_value;
    cur_value++;
    cur_place++;
    cur_place %= 10;
  }
  for (int i = 0; i < 10; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 11; i++) {
    cout << i << " is at place " << BinarySearchRotatedSortedArray(x, i) << endl;
  }
  cout << endl;
  return 0;
}

