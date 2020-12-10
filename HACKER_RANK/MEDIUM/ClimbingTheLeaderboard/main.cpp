#include <algorithm>
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
  for ( auto el : r ) std::cout << el << " ";
}

std::vector< int > climbingLeaderboard( std::vector< int > ranked, std::vector< int > player ) {
  std::vector< int > results;
  int pos = 1;
  auto rit = ranked.begin( );
  for ( int pit = player.size( ) - 1; pit >= 0; pit-- ) {
    //пока есть значения и пока значение текущих баллов у игрока меньше чем в рейтиноговой таблице
    while ( rit != ranked.end( ) && player[ pit ] < *rit ) {
      // продвигаем указатель через все повторные до следуюущего повышения ранга
      rit = std::find_if_not( rit, ranked.end( ), [ rit ]( int n ) { return n == *rit; } );
      //повышаем ранг
      pos++;
    }
    //вставить в начало вектора
    results.insert( results.begin( ), pos );
  }
  return results;
}

// std::vector< int > climbingLeaderboard( std::vector< int > ranked, std::vector< int > player ) {
//  std::vector< int >::size_type i = 0, j = 1;
//  int rank = 1;
//  int n = player.size( ) - 1;
//  std::vector< int > res( player.size( ) );
//  while ( j < ranked.size( ) && n >= 0 ) {
//    while ( ( j < ranked.size( ) ) && ( ranked[ i ] == ranked[ j ] ) ) ++j;
//    if ( player[ n ] >= ranked[ i ] ) {
//      // res.push_back( rank );
//      res[ n ] = rank;
//      --n;
//    }
//    ++rank;
//    i = j;
//  }
//  if ( !n ) res[ n ] = rank;
//  return res;
//}

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
