#include <iostream>
using namespace std;

// https://habr.com/ru/post/101430/

// template < int n, bool... digits >
// auto reversed_binary_value( int n, bool digits ) {}

template < bool... digits >
void reversed_binary_value( ) {
  if ( sizeof...( digits ) == 0 ) std::cout << '0' << ' ';
  // std::cout << return sizeof...( digits );
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
  reversed_binary_value< 0, 0, 1 >( );
  // std::cout << reversed_binary_value< 0, 0, 1 >( );

  //  int t;
  //  std::cin >> t;

  //  for ( int i = 0; i != t; ++i ) {
  //    int x, y;
  //    cin >> x >> y;
  //    CheckValues< 6 >::check( x, y );
  //    cout << "\n";
  //  }
}
