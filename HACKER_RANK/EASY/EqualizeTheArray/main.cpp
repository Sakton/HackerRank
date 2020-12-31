#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int equalizeArray( std::vector< int > &&arr );

int main( ) {
  // std::cout << equalizeArray( { 3, 3, 2, 1, 3 } );
  std::cout << equalizeArray(
      { 10, 27, 9, 10, 100, 38, 30, 32, 45, 29, 27, 29, 32, 38, 32, 38, 14, 38, 29, 30, 63, 29, 63, 91, 54, 10, 63 } );
}

int equalizeArray( std::vector< int > &&arr ) {
  std::vector< int > t( 101, 0 );
  for ( auto el : arr ) t[ el ]++;
  int maxCount = 0;
  int count = 0;
  for ( auto el : t ) {
    if ( maxCount < el ) maxCount = el;
    count += el;
  }
  return count - maxCount;
}
