#include <iostream>

int howManyGames( int p, int d, int m, int s ) {
  if ( s < p ) return 0;
  int count = 0;
  while ( s >= p ) {
    s -= p;
    p = ( ( p - d ) > m ) ? p - d : m;
    ++count;
  }
  return count;
}

int main( ) {
  // std::cout << howManyGames( 20, 3, 6, 80 ) << std::endl;
  std::cout << howManyGames( 20, 3, 6, 85 ) << std::endl;
}
