#include <iostream>
#include <vector>

int migratoryBirds( std::vector< int > arr ) {
  std::vector< int > t( 6, 0 );
  for ( auto &el : arr ) t[ el ]++;
  int index = 0;
  int max = t[ 0 ];
  for ( std::vector< int >::size_type i = 1; i < t.size( ); ++i ) {
    if ( max < t[ i ] ) {
      index = i;
      max = t[ i ];
    }
  }
  return index;
}

int main( ) {
  // std::vector< int > inpt { 1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4 };
  std::vector< int > inpt { 1, 4, 4, 4, 5, 3 };
  std::cout << migratoryBirds( inpt );
}
