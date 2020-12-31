#include <iostream>

int pageCount( int n, int p ) {
  n = ( n / 2 ) * 2;
  p = ( p / 2 ) * 2;
  return std::min( p / 2, ( n - p ) / 2 );
}

int main( ) {
  // std::cout << pageCount( 6, 5 );
  // std::cout << pageCount( 6, 2 );
  std::cout << pageCount( 5, 4 );
}
