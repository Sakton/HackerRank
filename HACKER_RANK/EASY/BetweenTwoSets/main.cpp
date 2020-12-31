#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

//  { 3, 9, 6 }, { 36, 72 } - ответ 2

int getTotalX( vector< int > a, vector< int > b ) {
  auto start = *std::max_element( a.cbegin( ), a.cend( ) );
  auto end = *std::min_element( b.cbegin( ), b.cend( ) );
  int res = 0;
  for ( auto i = start; i <= end; ++i ) {
    bool f1 = std::none_of( a.cbegin( ), a.cend( ), [ & ]( int el ) { return ( i % el ); } );
    bool f2 = std::none_of( b.cbegin( ), b.cend( ), [ & ]( int el ) { return ( el % i ); } );
    if ( f1 && f2 ) ++res;
  }
  return res;
}

void osnovnayaTeoremaArifmetici( int n ) {
  std::vector< int > res;
  std::map< int, int > mapres;
  int d = 2;
  while ( n > 1 ) {
    while ( n % d == 0 ) {
      n /= d;
      res.push_back( d );
      mapres[ d ]++;
    }
    ++d;
  }
  for ( auto el : res ) std::cout << el << " ";
  std::cout << std::endl;
  for ( auto x : mapres ) std::cout << x.first << " : " << x.second << std::endl;
}

int main( ) { /*std::cout << */

  // osnovnayaTeoremaArifmetici( 1164 );

  // std::cout << getTotalX( { 2, 4 }, { 16, 32, 96 } );
  // getTotalX( { 2, 6 }, { 24, 36 } );
  std::cout << getTotalX( { 3, 4 }, { 24, 48 } );
  // std::cout << getTotalX( { 3, 9, 6 }, { 36, 72 } );
}
