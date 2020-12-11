#include <iostream>

int beautifulDays( int i, int j, int k );

int main( ) { std::cout << beautifulDays( 20, 23, 6 ); }

int beautifulDays( int i, int j, int k ) {
  int count = 0;
  for ( int n = i; n <= j; ++n ) {
    int x = n;
    int y = 0;
    while ( x ) {
      y = y * 10 + x % 10;
      x /= 10;
    }
    if ( !( std::abs( n - y ) % k ) ) ++count;
  }
  return count;
}
