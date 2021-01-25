#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector< std::string > weightedUniformStrings( std::string s, std::vector< int > queries ) {
  std::set< int > weight;
  char prev = 0;
  char cur = s[ 0 ];
  int summ = s[ 0 ] - 'a' + 1;
  for ( std::string::size_type i = 1; i < s.size( ); ++i ) {
    prev = cur;
    cur = s[ i ];
    weight.insert( summ );
    if ( cur == prev ) {
      summ += cur - 'a' + 1;
    } else {
      summ = cur - 'a' + 1;
    }
  }
  if ( summ ) weight.insert( summ );
  std::vector< std::string > answer;
  for ( auto quer : queries ) {
    auto it = weight.find( quer );
    if ( it != weight.end( ) )
      answer.push_back( "Yes" );
    else
      answer.push_back( "No" );
  }
  return answer;
}

int main( ) {
  // auto x = weightedUniformStrings( "abccddde", { 1, 3, 12, 5, 9, 10 } );
  auto x = weightedUniformStrings( "aaabbbbcccddd", { 9, 7, 8, 12, 5 } );
  for ( auto &s : x ) std::cout << s << " ";
}
