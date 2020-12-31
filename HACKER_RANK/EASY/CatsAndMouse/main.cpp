#include <iostream>
#include <string>

std::string catAndMouse( int x, int y, int z ) {
  return ( std::abs( z - x ) == std::abs( z - y ) ) ? "Mouse C" : ( std::abs( z - x ) < std::abs( z - y ) ) ? "Cat A" : "Cat B";
}

int main( ) { std::cout << catAndMouse( 1, 2, 3 ); }
