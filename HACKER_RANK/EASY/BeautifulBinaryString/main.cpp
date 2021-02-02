#include <iostream>
#include <string>

int beautifulBinaryString( std::string b ) {
  int count = 0;
  for ( int i = 2; i < b.size( ); ++i ) {
    if ( b[ i - 2 ] == '0' && b[ i - 1 ] == '1' && b[ i ] == '0' ) {
      b[ i ] = '1';
      ++count;
    }
  }
  return count;
}

int main( ) {
  std::cout << beautifulBinaryString( "0101010" ) << std::endl;
  std::cout << beautifulBinaryString( "01100" ) << std::endl;
  std::cout << beautifulBinaryString( "0100101010" ) << std::endl;
}
