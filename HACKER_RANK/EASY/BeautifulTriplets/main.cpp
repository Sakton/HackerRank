#include <algorithm>
#include <iostream>
#include <vector>

int beautifulTriplets( int d, std::vector< int > arr ) {
  int count = 0;
  auto a = arr.begin( );
  while ( a != arr.end( ) ) {
    auto b = std::find( a, arr.end( ), *a + d );
    if ( b != arr.end( ) ) {
      auto c = std::find( b, arr.end( ), *b + d );
      if ( c != arr.end( ) ) ++count;
    }
    ++a;
  }
  return count;
}

int main( ) {
  std::cout << beautifulTriplets( 3, { 1, 2, 4, 5, 7, 8, 10 } ) << std::endl;
  std::cout << beautifulTriplets( 1, { 2, 2, 3, 4, 5 } ) << std::endl;
}
