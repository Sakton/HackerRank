#include <algorithm>
#include <iostream>
#include <vector>

int flatlandSpaceStations( int n, std::vector< int > c ) {
  std::sort( c.begin( ), c.end( ) );
  int beg = 0;
  int end = 0;
  int max = 0;
  max = ( max < ( c[ 0 ] - 0 ) ) ? ( c[ 0 ] - 0 ) : max;
  for ( std::vector< int >::size_type i = 0; i < c.size( ) - 1; ++i ) {
    beg = c[ i ];
    end = c[ i + 1 ];
    max = ( max < ( end - beg ) / 2 ) ? ( end - beg ) / 2 : max;
  }
  max = ( max < ( n - 1 - end ) ) ? ( n - 1 - end ) : max;
  return max;
}

int main( ) {
  // std::cout << flatlandSpaceStations( 5, { 0, 2 } );
  // std::cout << flatlandSpaceStations( 20, { 13, 1, 11, 10, 6 } );  // 6
  std::cout << flatlandSpaceStations( 95, { 68, 81, 46, 54, 30, 11, 19, 23, 22, 12, 38, 91, 48, 75, 26, 86, 29, 83, 62 } );  // 11
}
