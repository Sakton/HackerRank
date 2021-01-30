#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int gemstones( std::vector< std::string > arr ) {
  for ( auto &s : arr ) {
    std::sort( s.begin( ), s.end( ) );
  }
  for ( auto &s : arr ) {
    s.erase( std::unique( s.begin( ), s.end( ) ), s.end( ) );
  }
  std::map< char, int > mp;
  for ( auto &s : arr ) {
    for ( char ch : s ) {
      mp[ ch ]++;
    }
  }
  int count = 0;
  for ( auto el : mp ) {
    if ( el.second == arr.size( ) ) ++count;
  }
  return count;
}

int main( ) { std::cout << gemstones( { { "abcdde" }, { "baccd" }, { "eeabg" } } ); }
