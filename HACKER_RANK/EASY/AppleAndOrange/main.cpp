#include <iostream>
#include <vector>

void countApplesAndOranges( int s, int t, int a, int b, std::vector< int > apples, std::vector< int > oranges ) {
  int x = 0;
  for ( auto &el : apples )
    if ( s <= ( a + el ) && ( a + el ) <= t ) ++x;
  std::cout << x << std::endl;
  x = 0;
  for ( auto &el : oranges )
    if ( s <= ( b + el ) && ( b + el ) <= t ) ++x;
  std::cout << x << std::endl;
}

int main( ) { countApplesAndOranges( 7, 11, 5, 15, { -2, 2, 1 }, { 5, -6 } ); }
