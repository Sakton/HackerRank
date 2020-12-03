#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

/*
test 3
100000000 923092883 976061291 1205350525
ответ
100000000


test  100000000 1 3 1
ответ
100000000

100000000 1232077670 126810854 1536183938
ответ 26


100000000 569099406 1607140150 823906344
ответ 31
*/

using namespace std;

// ВОТ!!!
int main( ) {
  int64_t n, s, p, q;
  cin >> n >> s >> p >> q;
  uint64_t MASK = 2147483648;
  int64_t m = s % MASK;
  std::cout << "m = " << m << std::endl;
  int64_t x = m;
  int64_t i = 1;
  for ( ; i < n; ++i ) {
    int64_t t = x;
    x = ( x * p + q ) % MASK;
    if ( x == m || t == x ) break;
  }
  cout << i;
}
