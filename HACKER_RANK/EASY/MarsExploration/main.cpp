#include <iostream>
#include <string>

int marsExploration( std::string s ) {
  int resCount = 0;
  for ( std::string::size_type i = 0; i <= s.length( ) - 3; i += 3 ) {
    if ( s[ i ] != 'S' ) ++resCount;
    if ( s[ i + 1 ] != 'O' ) ++resCount;
    if ( s[ i + 2 ] != 'S' ) ++resCount;
  }
  return resCount;
}

int main( ) {
  // std::cout << marsExploration( "SOSSPSSQSSOR" );
  // std::cout << marsExploration( "SOSSOSSOS" );
  std::cout << marsExploration( "SOSSOT" );
}
