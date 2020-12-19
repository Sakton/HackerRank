#include <iostream>
#include <vector>

// int64_t maxFactor( int64_t N ) {
//  while ( !( N % 2 ) ) N /= 2;
//  int64_t max = 2;
//  int64_t d = 3;
//  while ( N > 1 ) {
//    max = d;
//    while ( N > 1 && !( N % d ) ) N /= d;
//    d += 2;
//  }
//  return max;
//}

int64_t maxFactor( int64_t N ) {
  while ( !( N % 2 ) ) N /= 2;
  int64_t max = 1;
  int64_t d = 3;
  int64_t maxF = static_cast< int64_t >( std::sqrt( N ) );
  while ( N > 1 && d <= maxF ) {
    if ( !( N % d ) ) {
      N /= d;
      max = d;
      while ( N > 1 && !( N % d ) ) N /= d;
      maxF = static_cast< int64_t >( std::sqrt( N ) );
    }
    d += 2;
  }
  if ( N == 1 ) return max;
  return N;
}

int main( ) { std::cout << maxFactor( 1001 ) << std::endl; }
