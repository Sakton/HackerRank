#include <iostream>
#include <string>

std::string funnyString( std::string s ) {
  using sty = std::string::size_type;
  int forward = s.front( );
  int backward = s.back( );
  for ( sty i = 1, j = s.size( ) - 2; i <= j; ++i, --j ) {
    int f = s[ i ];
    int b = s[ j ];
    if ( std::abs( forward - f ) != std::abs( backward - b ) ) return "Not Funny";
    forward = f;
    backward = b;
  }
  return "Funny";
}

int main( ) {
  //  std::cout << funnyString( "acxz" ) << std::endl;
  //  std::cout << funnyString( "bcxz" ) << std::endl;
  std::cout << funnyString( "ivvkx" ) << std::endl;
  // std::cout << funnyString( "ivvkxq" ) << std::endl;
}
