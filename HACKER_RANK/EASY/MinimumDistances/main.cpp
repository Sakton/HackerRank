#include <algorithm>
#include <iostream>
#include <vector>

int minimumDistances( std::vector< int > a ) {
  int minDist = std::numeric_limits< int >::max( );
  auto it = a.begin( );
  while ( it != a.end( ) && it + 1 != a.end( ) ) {
    auto firstNum = *it;
    auto it_secondNum = std::find( it + 1, a.end( ), firstNum );
    if ( it_secondNum != a.end( ) ) {
      if ( minDist > std::distance( it, it_secondNum ) ) {
        minDist = std::distance( it, it_secondNum );
      }
    }
    ++it;
  }
  return ( minDist == std::numeric_limits< int >::max( ) ) ? -1 : minDist;
}

int main( ) {
  // std::cout << minimumDistances( { 7, 1, 3, 4, 1, 7 } ) << std::endl;
  std::cout << minimumDistances( { 1, 2, 3, 4, 5, 6 } ) << std::endl;
}
