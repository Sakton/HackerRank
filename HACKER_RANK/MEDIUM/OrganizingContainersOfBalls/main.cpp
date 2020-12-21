#include <iostream>
#include <string>
#include <vector>

// std::string organizingContainers( std::vector< std::vector< int64_t > > container ) {
//  int size = container.size( );
//  std::string answer = "Possible";
//  for ( int i = 0; i < size - 1; ++i ) {
//    //**
//    for ( int row = i + 1, col = i + 1; col < size; ++row, ++col ) {
//      if ( container[ row ][ i ] != container[ i ][ col ] ) {
//        return answer = "Impossible";
//      }
//    }
//  }
//  return answer;
//}

std::string organizingContainers( std::vector< std::vector< int64_t > > container ) {
  using sz = std::vector< int64_t >::size_type;
  sz size = container.size( );
  for ( sz curRow = 0; curRow < size - 1; ++curRow ) {
    sz interressantCol = curRow;
    sz nextRow = curRow + 1;
    for ( ; nextRow < size; ++nextRow ) {
      for ( sz nextCol = interressantCol + 1; nextCol < size && container[ nextRow ][ interressantCol ] > 0; ++nextCol ) {
        if ( container[ curRow ][ nextCol ] ) {
          int16_t delta = std::min( container[ curRow ][ nextCol ], container[ nextRow ][ interressantCol ] );
          container[ curRow ][ interressantCol ] += delta;
          container[ curRow ][ nextCol ] -= delta;
          container[ nextRow ][ nextCol ] += delta;
        } else {
          // FIXME
        }
      }
    }
  }

  for ( auto &el : container ) {
    for ( auto &line : el ) std::cout << line << " ";
    std::cout << '\n';
  }

  return { };
}

int main( ) {
  // std::cout << organizingContainers( { { 1, 1 }, { 1, 1 } } );
  // std::cout << organizingContainers( { { 1, 3, 1 }, { 2, 1, 2 }, { 3, 3, 3 } } );
  std::cout << organizingContainers( { { 0, 2, 1 }, { 1, 1, 1 }, { 2, 0, 0 } } );
}
