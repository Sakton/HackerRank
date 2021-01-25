#include <iostream>
#include <string>

std::string hackerrankInString( std::string s ) {
  std::string pattern = "hackerrank";
  std::string res;
  std::string::size_type i = 0;
  std::string::size_type pos = 0;
  while ( i < pattern.size( ) && pos != std::string::npos ) {
    char ch = pattern[ i ];
    pos = s.find( ch, pos );
    if ( pos != std::string::npos ) {
      res.push_back( s[ pos ] );
      pos = pos + 1;
    }
    ++i;
  }
  return ( pattern == res ) ? "YES" : "NO";
}

int main( ) {
  // std::cout << hackerrankInString( "hereiamstackerrank" );
  // std::cout << hackerrankInString( "hackerworld" );
  // std::cout << hackerrankInString( "hhaacckkekraraannk" );
  std::cout << hackerrankInString( "rhbaasdndfsdskgbfefdbrsdfhuyatrjtcrtyytktjjt" );
}
