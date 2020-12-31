#include <iostream>

int utopianTree( int n );

int main( ) { std::cout << utopianTree( 5 ); }

int utopianTree( int n ) {
  int res = 1;
  for ( int i = 0; i <= n; ++i ) {
    if ( i == 0 )
      res = 1;
    else if ( i == 1 )
      res = 2;
    else {
      if ( i % 2 )
        res *= 2;
      else
        res += 1;
    }
  }
  return res;
}
