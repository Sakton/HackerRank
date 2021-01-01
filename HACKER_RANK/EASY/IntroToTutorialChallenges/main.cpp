#include <iostream>
#include <vector>

int introTutorial(int V, std::vector<int> arr) {
  int r = arr.size() - 1;
  int l = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == V) {
      return mid;
    }
    if (arr[mid] < V)
      l = mid + 1;
    if (arr[mid] > V)
      r = mid - 1;
  }
  return -1;
}

int main() {
  std::cout << introTutorial(2, {1, 4, 5, 7, 9, 12}) << std::endl;
}
