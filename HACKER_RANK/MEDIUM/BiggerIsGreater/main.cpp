#include <algorithm>
#include <iostream>
#include <string>

std::string biggerIsGreater( std::string w ) {
  if ( std::next_permutation( w.begin( ), w.end( ) ) ) {
    return w;
  }
  return "no answer";
}

int main( ) {
  std::cout << biggerIsGreater( "ab" ) << std::endl;
  std::cout << biggerIsGreater( "bb" ) << std::endl;
  std::cout << biggerIsGreater( "hefg" ) << std::endl;
  std::cout << biggerIsGreater( "dhck" ) << std::endl;
  std::cout << biggerIsGreater( "dkhc" ) << std::endl;
}
