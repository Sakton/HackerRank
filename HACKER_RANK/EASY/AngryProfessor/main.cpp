#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string angryProfessor( int k, std::vector< int > a );

int main( ) {
  // std::cout << angryProfessor( 3, { -1, -3, 4, 2 } );
  std::cout << angryProfessor( 2, { 0 - 1, 2, 1 } );
}

std::string angryProfessor( int k, std::vector< int > a ) {
  int x = std::count_if( a.begin( ), a.end( ), []( int el ) { return el <= 0; } );
  return ( x < k ) ? "YES" : "NO";
}
