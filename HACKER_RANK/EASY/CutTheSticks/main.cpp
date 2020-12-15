#include <iostream>
#include <map>
#include <numeric>
#include <vector>

std::vector< int > cutTheSticks( std::vector< int > &&arr );

int main( ) {
  auto r = cutTheSticks( { 1, 2, 3, 4, 3, 3, 2, 1 } );
  for ( auto el : r ) std::cout << el << " ";
}

std::vector< int > cutTheSticks( std::vector< int > &&arr ) {
  std::map< int, int > mp;
  for ( auto el : arr ) mp[ el ]++;
  std::vector< int > res;
  while ( !mp.empty( ) ) {
    auto summ = std::accumulate( std::begin( mp ), std::end( mp ), 0,
                                 []( int sum, const std::map< int, int >::value_type &p ) { return ( sum + p.second ); } );
    mp.erase( mp.begin( ) );
    res.push_back( summ );
  }
  return res;
}
