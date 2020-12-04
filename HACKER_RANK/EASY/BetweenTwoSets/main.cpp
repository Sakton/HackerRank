#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//  { 3, 9, 6 }, { 36, 72 } - ответ 2

int getTotalX( vector< int > a, vector< int > b ) {
  vector< int > c;
  for ( auto el_b : b ) {
    c.push_back( el_b );
    for ( auto el_a : a ) {
      c.push_back( el_a );
      if ( !( el_b % el_a ) ) {
        c.push_back( el_b / el_a );
      }
    }
  }
  std::sort( c.begin( ), c.end( ) );
  c.erase( std::unique( c.begin( ), c.end( ) ), c.end( ) );

  for ( auto el : c ) cout << el << ' ';
  cout << endl;

  vector< int > d;
  for ( auto el_c : c ) {
    bool f1 = std::none_of( a.cbegin( ), a.cend( ), [ = ]( int x ) { return ( el_c % x ); } );
    bool f2 = std::none_of( b.cbegin( ), b.cend( ), [ = ]( int x ) { return ( x % el_c ); } );
    if ( f1 && f2 ) d.push_back( el_c );
  }
  for ( auto el_d : d ) cout << el_d << ' ';
  cout << endl;
  return d.size( );
}

int main( ) { /*std::cout << */
  // getTotalX( { 2, 4 }, { 16, 32, 96 } );
  // getTotalX( { 2, 6 }, { 24, 36 } );
  // getTotalX( { 3, 4 }, { 24, 48 } );
  getTotalX( { 3, 9, 6 }, { 36, 72 } );
}
