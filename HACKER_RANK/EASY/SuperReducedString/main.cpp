#include <iostream>
#include <string>

std::string superReducedString( std::string s ) {
  if ( s.size( ) == 1 ) return s;
  std::string start = s;
  std::string::size_type e = 0;
  std::string::size_type b = 1;
  std::string res;
  bool d = false;
  do {
    d = false;
    for ( ; b < start.size( ); ++b, ++e ) {
      if ( start[ e ] == start[ b ] ) {
	d = true;
	++b;
	++e;
      } else {
	res.push_back( start[ e ] );
      }
      if ( b == start.size( ) - 1 ) res.push_back( start[ b ] );
    }
    start = res;
    res.clear( );
    e = 0;
    b = 1;
  } while ( ( start.size( ) > 1 ) && d );
  if ( start.size( ) ) return start;
  return "Empty String";
}

int main( ) {
  // std::cout << superReducedString( "a" ) << std::endl;
  // std::cout << superReducedString( "aaabccddd" ) << std::endl;
  // std::cout << superReducedString( "aa" ) << std::endl;
  std::cout << superReducedString( "baab" ) << std::endl;
}
