#include <iostream>

int findDigits( int n );

int main( ) { std::cout << findDigits( 1012 ); }

int findDigits( int n ) {
  int m = n;
  int count = 0;
  while ( m ) {
    int x = m % 10;
    if ( x && !( n % x ) ) ++count;
    m /= 10;
  }
  return count;
}
