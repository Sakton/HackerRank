#include <iostream>
#include <vector>

std::vector< int > quickSort( std::vector< int > arr ) {
  int pivot = arr[ 0 ];
  int l = 1;
  int r = arr.size( ) - 1;

  while ( l < r ) {
    while ( arr[ l ] < pivot ) ++l;
    while ( pivot < arr[ r ] ) --r;
    if ( l < r ) std::swap( arr[ l ], arr[ r ] );
  }
  std::swap( arr[ 0 ], arr[ l - 1 ] );
  return arr;
}

int main( ) {
  // auto vec = quickSort( { 4, 5, 3, 7, 2 } );
  auto vec = quickSort( { 45, 25, 46, 48, 28, 6, 13, 5, 36, 44, 7, 4, 11, 30, 24, 34, 15, 31, 38, 49 } );
  // auto vec = quickSort( { 2, 10, 3, 7, 9, 4, 6, 12, 8 } );
  for ( auto el : vec ) {
    std::cout << el << " ";
  }
}
