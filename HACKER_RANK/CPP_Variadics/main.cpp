#include <iostream>
using namespace std;

// https://habr.com/ru/post/101430/

template < bool... digits >
uint64_t reversed_binary_value( ) {
  bool array[ sizeof...( digits ) ] { digits... };
  uint64_t res = 0;
  uint64_t k = 1;
  res = array[ 0 ];
  for ( uint64_t i = 1; i < sizeof...( digits ); ++i ) {
    k *= 2;
    res += array[ i ] * k;
  }
  return res;
}

template < int n, bool... digits >
struct CheckValues {
  static void check( int x, int y ) {
    CheckValues< n - 1, 0, digits... >::check( x, y );
    CheckValues< n - 1, 1, digits... >::check( x, y );
  }
};

template < bool... digits >
struct CheckValues< 0, digits... > {
  static void check( int x, int y ) {
    int z = reversed_binary_value< digits... >( );
    std::cout << ( z + 64 * y == x );
  }
};

int main( ) {
  // reversed_binary_value< 0, 1, 1, 0, 1 >( );
  std::cout << reversed_binary_value< 1, 1, 1, 1, 1, 1 >( );

  //  int t;
  //  std::cin >> t;

  //  for ( int i = 0; i != t; ++i ) {
  //    int x, y;
  //    cin >> x >> y;
  //    CheckValues< 6 >::check( x, y );
  //    cout << "\n";
  //  }
}
