#include <iostream>
#include <vector>

int64_t maxFactor( int64_t N ) {
  while ( !( N % 2 ) ) N /= 2;
  int64_t max = 2;
  int64_t d = 3;
  while ( N > 1 ) {
    max = d;
    while ( N > 1 && !( N % d ) ) N /= d;
    d += 2;
  }
  return max;
}

int main( ) { std::cout << maxFactor( 13195 ) << std::endl; }
