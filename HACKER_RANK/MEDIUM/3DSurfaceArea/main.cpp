#include <iostream>
#include <vector>

int surfaceArea( std::vector< std::vector< int > > A ) {
  int row = A.size( );
  int col = A[ 0 ].size( );
  int summ = 0;
  for ( int i = 0; i < row; ++i ) {
    for ( int j = 0; j < col; ++j ) {
      if ( A[ i ][ j ] != 0 ) {
        summ += 2;
        if ( i == 0 ) {
          summ += A[ i ][ j ];
        }
        if ( i == row - 1 ) {
          summ += A[ i ][ j ];
        }
        if ( j == 0 ) {
          summ += A[ i ][ j ];
        }
        if ( j == col - 1 ) {
          summ += A[ i ][ j ];
        }
        if ( ( i - 1 ) >= 0 ) {
          summ += std::abs( A[ i ][ j ] - A[ i - 1 ][ j ] );
        }
        if ( ( j - 1 ) >= 0 ) {
          summ += std::abs( A[ i ][ j ] - A[ i ][ j - 1 ] );
        }
      }
    }
  }
  return summ;
}

int main( ) {
  std::cout << "summ = " << surfaceArea( { { 1 } } ) << std::endl;
  // std::cout << "summ = " << surfaceArea( { { 1, 3, 4 }, { 2, 2, 3 }, { 1, 2, 4 } } ) << std::endl;
  // std::cout /*<< "summ = " */ << surfaceArea({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}) << std::endl;
}
