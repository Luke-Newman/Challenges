#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int run(vector<int>& A, vector<int>& B, int M, int X, int Y) {
  /* 0 - M floors, people cap = X, weight limit = Y  */
  int stops = 0;
  int tmp_weight = 0;
  int tmp_people = 0;
  set<int> lift;
  /* Lift gets loaded up */
  for (int i = 0; i < A.size(); i++) {
    if (tmp_weight + A[i] > Y || tmp_people > X) {
      cout << "capacity: " << tmp_weight << endl;
      cout << "num people in lift: " << tmp_people << endl;
      stops += lift.size() + 1;
      lift.clear();
      tmp_weight = 0;
      tmp_people = 0;
    }
    lift.insert(B[i]);
    tmp_weight += A[i];
    tmp_people++;
  }
  /* last load of people (if load did not exceed weight limit or capacity) */
  if (!lift.empty()) {
    cout << "capacity: " << tmp_weight << endl;
    cout << "num people in lift: " << tmp_people << endl;
    stops += lift.size() + 1;
  }
  return stops;
}

int main() {
  /* A = vec of each person's weight, B = vec of each person's target floor */
  vector<int> A = {40, 40, 100, 80, 20, 20, 200, 20};
  vector<int> B = {3, 1, 2, 2, 3, 4, 1, 1}; /* 4 + 4 + 2 + 2 = 12 stops */
  /* 0 - M floors, people cap = X, weight limit = Y  */
  int M = 3, X = 5, Y = 200;
  int ans = run(A, B, M, X, Y);
  cout << "num stops: " << ans << endl;

  return 0;
}
