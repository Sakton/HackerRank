#include <algorithm>
#include <iostream>
#include <vector>

/*
10
10 0
10 1
7 0
10 9
9 0
10 3
8 2
8 0
7 0
10 1


1 2 3 4 5 6 7 8 9 10
2 1 4 3 6 5 8 7 10 9
1 2 3 4 5 6 7
-1
1 2 3 4 5 6 7 8 9
-1
3 4 1 2 7 8 5 6
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7
2 1 4 3 6 5 8 7 10 9

//    if ( temp[ i ] <= k )
//      res.push_back( std::abs( temp[ i ] + k ) );
//    else
//      res.push_back( std::abs( temp[ i ] - k ) );

*/

std::vector< int > absolutePermutation( int n, int k ) {
  std::vector< int > res;
  if ( k != 0 ) {
    if ( n % 2 == 1 ) return { -1 };
    if ( n % 2 == 0 && n % ( k * 2 ) == 0 ) {
      int j = 1;
      for ( int i = 1; i <= n; i++ ) {
        if ( j <= k ) {
          res.push_back( i + k );
        } else {
          res.push_back( i - k );
        }
        j++;
        if ( j > k * 2 ) j = 1;
      }
      return res;
    } else {
      return { -1 };
    }
  } else {
    for ( int i = 1; i <= n; i++ ) {
      res.push_back( i );
    }
    return res;
  }
}

//  std::vector< int64_t > absolutePermutation( int n, int k ) {
//    if ( ( n % 2 ) ) return { -1 };
//    std::vector< int64_t > etalon( n );
//    for ( int64_t i = 0; i < n; ++i ) etalon[ i ] = i + 1;
//    std::vector< int64_t > res;
//    for ( int i = 0; i < n; ++i ) {
//      int64_t a = etalon[ i ] - k;
//      if ( std::binary_search( res.begin( ), res.end( ), a ) ) {
//        a = etalon[ i ] + k;
//        if ( std::binary_search( res.begin( ), res.end( ), a ) ) {
//          return { -1 };
//        } else {
//          res.push_back( a );
//        }
//      } else {
//        if ( a > 0 ) res.push_back( a );
//      }
//    }
//    return res;
//  }

int main( ) {
  // auto vec = absolutePermutation( 4, 2 );
  // auto vec = absolutePermutation( 2, 1 );
  // auto vec = absolutePermutation( 3, 2 );
  auto vec = absolutePermutation( 10, 1 );
  // auto vec = absolutePermutation( 10, 9 );
  // auto vec = absolutePermutation( 10, 3 );

  for ( auto el : vec ) {
    std::cout << el << " ";
  }
}
