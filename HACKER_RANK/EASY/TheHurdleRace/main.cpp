#include <algorithm>
#include <iostream>
#include <vector>

int hurdleRace( int k, std::vector< int > height );

int main( ) {
  //  std::vector< int > inpt { 1, 6, 3, 5, 2 };
  //  std::cout << hurdleRace( 4, inpt );
  //  std::vector< int > inpt { 2, 5, 4, 5, 2 };
  //  std::cout << hurdleRace( 5, inpt );
  std::vector< int > inpt { 2, 5, 4, 5, 2 };
  std::cout << hurdleRace( 7, inpt );
}

int hurdleRace( int k, std::vector< int > height ) { return std::max( 0, *std::max_element( height.begin( ), height.end( ) ) - k ); }
