#include <iostream>

int chocolateFeast( int n, int c, int m ) {
  int res = 0;
  if ( n < c )
    res = 0;
  else {
    int fan = n / c;
    res += fan;
    while ( fan >= m ) {
      int conf = fan / m;
      res += conf;
      fan = fan % m;
      fan += conf;
    }
  }
  return res;
}

int main( ) {
  // std::cout << chocolateFeast( 10, 2, 5 ) << std::endl;
  // std::cout << chocolateFeast( 12, 4, 4 ) << std::endl;
  std::cout << chocolateFeast( 6, 2, 2 ) << std::endl;
}
