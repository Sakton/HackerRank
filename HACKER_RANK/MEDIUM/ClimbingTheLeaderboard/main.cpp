#include <iostream>
#include <iterator>
#include <set>
#include <vector>

std::vector< int > climbingLeaderboard( std::vector< int > ranked, std::vector< int > player );

int main( ) {
  std::vector< int > r = climbingLeaderboard(
      {
          100,
          100,
          50,
          40,
          40,
          20,
          10,
      },
      { 5, 25, 50, 120 } );
  // for ( auto el : r ) std::cout << el << " ";
}

std::vector< int > climbingLeaderboard( std::vector< int > ranked, std::vector< int > player ) {
  // 1. intervals
  std::vector< int >::size_type i = 0, j = 1;
  while ( j < ranked.size( ) ) {
    while ( ( j < ranked.size( ) ) && ( ranked[ i ] == ranked[ j ] ) ) {
      ++j;
    }
    // *** print
    std::vector< int >::size_type k = i;
    while ( k < j && k < ranked.size( ) ) {
      std::cout << ranked[ k ] << " ";
      ++k;
    }
    std::cout << std::endl;
    // ***
    i = j;
  }
  return { };
}

// Time limit exceeded
// std::vector< int > climbingLeaderboard( std::vector< int > ranked, std::vector< int > player ) {
//  std::set< int, std::greater< int > > set( ranked.cbegin( ), ranked.cend( ) );
//  std::vector< int > res;
//  for ( auto el : player ) {
//    auto it = set.insert( el );
//    res.push_back( std::distance( set.begin( ), it.first ) + 1 );
//    set.erase( it.second );
//  }
//  return res;
//}
