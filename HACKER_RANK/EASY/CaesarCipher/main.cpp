#include <iostream>
#include <string>

std::string caesarCipher( std::string s, int k ) {
  k %= 26;
  for ( auto &ch : s ) {
    if ( std::isupper( ch ) ) {
      if ( ch + k > 'Z' )
	ch = ( ( ch + k ) % 'Z' ) + ( 'A' - 1 );
      else
	ch += k;
    }
    if ( std::islower( ch ) ) {
      if ( ch + k > 'z' )
	ch = ( ( ch + k ) % 'z' ) + ( 'a' - 1 );
      else
	ch += k;
    }
  }
  return s;
}

int main( ) {
  // std::cout << caesarCipher( "middle-Outz", 2 );
  std::cout << caesarCipher( "www.abc.xy", 87 );
  // std::cout << caesarCipher( "z", 2 );
}
