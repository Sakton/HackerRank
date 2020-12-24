#include <algorithm>
#include <iostream>
#include <vector>

std::vector< int > serviceLane( std::vector< int > width, std::vector< std::vector< int > > cases ) {
  std::vector< int > result;
  for ( auto &interval : cases ) {
    result.push_back( *std::min_element( width.begin( ) + interval[ 0 ], width.begin( ) + interval[ 1 ] + 1 ) );
  }
  return result;
}

int main()
{
  int n = 8;
  std::vector< int > width( n );
  auto res = serviceLane( { 2, 3, 1, 2, 3, 2, 3, 3 }, { { 0, 3 }, { 4, 6 }, { 6, 7 }, { 3, 5 }, { 0, 7 } } );
  for ( auto x : res ) std::cout << x << " ";
}
