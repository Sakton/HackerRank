#include <iostream>
#include <string>

int alternatingCharacters( std::string s ) {
  int count = 0;
  for ( std::string::size_type i = 0; i < s.size( ) - 1; ++i )
    if ( s[ i ] == s[ i + 1 ] ) ++count;
  return count;
}

int main( ) {
  std::cout << alternatingCharacters( "AAAA" ) << std::endl;
  std::cout << alternatingCharacters( "BBBBB" ) << std::endl;
  std::cout << alternatingCharacters( "ABABABAB" ) << std::endl;
  std::cout << alternatingCharacters( "BABABA" ) << std::endl;
  std::cout << alternatingCharacters( "AAABBB" ) << std::endl;
}
