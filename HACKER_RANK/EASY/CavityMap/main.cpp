#include <iostream>
#include <string>
#include <vector>

std::vector< std::string > cavityMap( std::vector< std::string > grid ) {
  int rowCount = grid.size( );
  int colCount = grid[ 0 ].size( );
  std::vector< std::pair< int, int > > indexesCavity;
  for ( int i = 1; i < rowCount - 1; ++i ) {
    for ( int j = 1; j < colCount - 1; ++j ) {
      int current = grid[ i ][ j ];
      int top = grid[ i - 1 ][ j ];
      int bot = grid[ i + 1 ][ j ];
      int lef = grid[ i ][ j - 1 ];
      int rig = grid[ i ][ j + 1 ];
      if ( ( current > top ) && ( current > bot ) && ( current > lef ) && ( current > rig ) ) {
        indexesCavity.push_back( std::make_pair( i, j ) );
      }
    }
  }
  for ( auto &el : indexesCavity ) grid[ el.first ][ el.second ] = 'X';
  return grid;
}

int main( ) {
  auto res = cavityMap( { "1112", "1912", "1892", "1234" } );
  for ( auto &el : res ) std::cout << el << std::endl;
}
