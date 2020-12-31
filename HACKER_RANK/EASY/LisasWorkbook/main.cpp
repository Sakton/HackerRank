#include <iostream>
#include <vector>

int workbook( int n, int k, std::vector< int > arr ) {
  int count = 0;
  int pages = 0;
  for ( std::vector< int >::size_type i = 0; i < arr.size( ); ++i ) {
    int pageInGlava = arr[ i ] / k;
    if ( arr[ i ] % k ) ++pageInGlava;
    int l = 1;
    int r = ( arr[ i ] < k ) ? arr[ i ] : k;
    while ( pageInGlava-- ) {
      ++pages;
      if ( l <= pages && pages <= r ) ++count;
      l += k;
      r = ( arr[ i ] < r + k && arr[ i ] >= l ) ? arr[ i ] : r + k;
    }
  }
  return count;
}

int main( ) { std::cout << workbook( 5, 3, { 4, 2, 6, 1, 10 } ) << std::endl; }
