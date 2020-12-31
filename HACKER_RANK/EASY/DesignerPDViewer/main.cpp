#include <iostream>
#include <string>
#include <vector>

int designerPdfViewer( std::vector< int > h, const std::string &word );

int main( ) { std::cout << designerPdfViewer( { 1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7 }, "zaba" ); }

int designerPdfViewer( std::vector< int > h, const std::string &word ) {
  int max = 0;
  for ( auto el : word ) max = std::max( max, h[ el - 'a' ] );
  return max * word.size( );
}
