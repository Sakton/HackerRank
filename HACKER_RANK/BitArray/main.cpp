#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

/*
test 3
100000000 923092883 976061291 1205350525
ответ
100000000 (верно)
*/

using namespace std;

int main( ) {
  int64_t n, s, p, q;
  cin >> n >> s >> p >> q;
  std::vector< int64_t > a( n );
  const uint64_t MASK = 1 << 31;
  a[ 0 ] = s % MASK;
  for ( int i = 1; i < n; ++i ) {
    a[ i ] = ( a[ i - 1 ] * p + q ) % MASK;
  }
  std::sort( a.begin( ), a.end( ) );
  a.erase( std::unique( a.begin( ), a.end( ) ), a.end( ) );
  cout << a.size( );
}

//долго!! но тест проходит ... минута
// int main( ) {
//  int64_t n, s, p, q;
//  cin >> n >> s >> p >> q;
//  std::vector< int64_t > a( n );
//  const uint64_t MASK = 1 << 31;
//  a[ 0 ] = s % MASK;
//  for ( int i = 1; i < n; ++i ) {
//    a[ i ] = ( a[ i - 1 ] * p + q ) % MASK;
//  }
//  std::sort( a.begin( ), a.end( ) );
//  a.erase( std::unique( a.begin( ), a.end( ) ), a.end( ) );
//  cout << a.size( );
//}
