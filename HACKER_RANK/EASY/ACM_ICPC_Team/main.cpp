#include <bitset>
#include <iostream>
#include <string>
#include <vector>

std::vector< int > acmTeam( std::vector< std::string > topic ) {
  using bitType = std::bitset< 500 >;
  std::vector< bitType > vbs( topic.size( ) );
  int k = 0;
  for ( auto &el : topic ) {
    vbs[ k++ ] = bitType( el );
  }
  // for ( auto &el : vbs ) std::cout << "count = " << el.count( ) << "    " << el << std::endl;

  std::size_t max = 0;
  std::size_t count = 0;

  for ( std::vector< bitType >::size_type i = 0; i < vbs.size( ) - 1; ++i ) {
    for ( std::vector< bitType >::size_type j = i + 1; j < vbs.size( ); ++j ) {
      bitType t = vbs[ i ] | vbs[ j ];
      if ( t.count( ) == max ) {
        ++count;
      } else if ( t.count( ) > max ) {
        max = t.count( );
        count = 1;
      }
    }
  }
  return { static_cast< int >( max ), static_cast< int >( count ) };
}

int main( ) {
  // auto v = acmTeam( { { "10101" }, { "11110" }, { "00010" } } );
  auto v = acmTeam( { { "10101" }, { "11100" }, { "11010" }, { "00101" } } );
  std::cout << v[ 0 ] << "   " << v[ 1 ] << std::endl;
}
