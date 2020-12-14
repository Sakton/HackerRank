#include <cmath>
#include <iostream>
#include <string>

std::string appendAndDelete( std::string s, std::string t, int k );

int main( ) {
  // std::cout << appendAndDelete( "hackerhappy", "hackerrank", 9 );
  // std::cout << appendAndDelete( "aba", "aba", 7 );  // Yes
  // std::cout << appendAndDelete( "ashley", "ash", 2 );  // No
  std::cout << appendAndDelete( "y", "yu", 2 );  // No
  // std::cout << appendAndDelete( "zzzzz", "zzzzzzz", 4 );  // Yes
}

std::string appendAndDelete( std::string s, std::string t, int k ) {
  std::string::size_type i = 0;
  while ( i < ( std::min( s.size( ), t.size( ) ) ) && s[ i ] == t[ i ] ) ++i;
  int x = s.size( ) + t.size( ) - 2 * i;
  if ( k < x )
    return "No";
  else if ( x % 2 == k % 2 )
    return "Yes";
  else if ( static_cast< int >( s.size( ) + t.size( ) ) < k )
    return "Yes";
  else
    return "No";
}

// std::string appendAndDelete( std::string s, std::string t, int k ) {
//  if ( s == t && k == 0 ) return "Yes";
//  if ( s == t && ( k > static_cast< int >( s.size( ) ) ) ) return "Yes";
//  std::string::size_type i = 0;
//  while ( i < ( std::min( s.size( ), t.size( ) ) ) && s[ i ] == t[ i ] ) ++i;
//  int x = s.size( ) + t.size( ) - 2 * i;
//  if ( k < x ) return "No";
//  if ( ( x % 2 == 0 && k % 2 == 0 ) || ( x % 2 != 0 && k % 2 != 0 ) ) return "Yes";
//  return "No";
//}
