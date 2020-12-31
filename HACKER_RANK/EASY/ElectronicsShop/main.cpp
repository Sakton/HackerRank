#include <iostream>
#include <vector>

int getMoneySpent( std::vector< int > keyboards, std::vector< int > drives, int b ) {
  std::vector< std::vector< int > > res( keyboards.size( ) + 1, std::vector< int >( drives.size( ) + 1, 0 ) );
  for ( std::vector< int >::size_type i = 0; i < keyboards.size( ) + 1; ++i ) res[ i ][ 0 ] = -1;
  for ( std::vector< int >::size_type i = 0; i < drives.size( ) + 1; ++i ) res[ 0 ][ i ] = -1;

  for ( std::vector< int >::size_type i = 1; i < keyboards.size( ) + 1; ++i ) {
    for ( std::vector< int >::size_type j = 1; j < drives.size( ) + 1; ++j ) {
      int sm = keyboards[ i - 1 ] + drives[ j - 1 ];
      if ( sm > b ) sm = -1;
      res[ i ][ j ] = std::max( std::max( sm, res[ i - 1 ][ j - 1 ] ), std::max( res[ i ][ j - 1 ], res[ i - 1 ][ j ] ) );
    }
  }
  return res[ keyboards.size( ) ][ drives.size( ) ];
}

int main( ) {
  std::vector< int > keyb { 40, 50, 60 };
  std::vector< int > driv { 5, 8, 12 };

  std::cout << getMoneySpent( keyb, driv, 70 );
}
