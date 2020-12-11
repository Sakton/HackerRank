#include <iostream>
#include <vector>

std::vector< int > circularArrayRotation( std::vector< int > a, int k, std::vector< int > queries );

int main( ) {
  std::vector< int > t = circularArrayRotation( { 1, 2, 3 }, 2, { 0, 1, 2 } );
  for ( auto el : t ) std::cout << el << " ";
}

std::vector< int > circularArrayRotation( std::vector< int > a, int k, std::vector< int > queries ) {
  std::vector< int > res( queries.size( ) );
  k %= a.size( );
  for ( int index : queries ) res[ index ] = a[ ( index + a.size( ) - k ) % a.size( ) ];
  return res;
}

//влево
// std::vector< int > circularArrayRotation( std::vector< int > a, int k, std::vector< int > queries ) {
//  std::vector< int > res( queries.size( ) );
//  for ( int index : queries ) res[ index ] = a[ ( index - ( k - a.size( ) ) ) % a.size( ) ];
//  return res;
//}
