#include <algorithm>
#include <iostream>
#include <vector>

std::vector< std::string > bigSorting( std::vector< std::string > unsorted ) {
  std::sort( unsorted.begin( ), unsorted.end( ), []( const std::string &a, const std::string &b ) {
    if ( a.size( ) == b.size( ) ) return a < b;
    return a.size( ) < b.size( );
  } );
  return unsorted;
}

int main()
{
  auto res = bigSorting( { "6", "31415926535897932384626433832795", "1", "3", "10", "3", "5" } );
  for ( std::string &el : res ) {
    std::cout << el << std::endl;
  }
}
