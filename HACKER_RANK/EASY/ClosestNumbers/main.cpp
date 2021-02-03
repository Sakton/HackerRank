#include <algorithm>
#include <iostream>
#include <vector>

std::vector< int64_t > closestNumbers( std::vector< int64_t > arr ) {
  int64_t min = std::numeric_limits< int64_t >::max( );
  std::vector< int64_t > res;
  std::sort( arr.begin( ), arr.end( ) );
  for ( auto i = arr.begin( ) + 1; i != arr.end( ); ++i ) {
    if ( min > ( *i - *( i - 1 ) ) ) {
      res.clear( );
      min = ( *i - *( i - 1 ) );
      res.push_back( *( i - 1 ) );
      res.push_back( *i );
    } else if ( min == ( *i - *( i - 1 ) ) ) {
      res.push_back( *( i - 1 ) );
      res.push_back( *i );
    }
  }
  return res;
}

int main()
{
  // auto res = closestNumbers( { -20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854 } );
  auto res = closestNumbers( { 5, 4, 3, 2 } );
  for ( auto el : res ) {
    std::cout << el << " ";
  }
}
