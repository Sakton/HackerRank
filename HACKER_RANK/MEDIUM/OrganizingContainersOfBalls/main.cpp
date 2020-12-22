#include <algorithm>
#include <fstream>
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

// std::string organizingContainers( std::vector< std::vector< int64_t > > container ) {
//  using sz = std::vector< int64_t >::size_type;
//  sz size = container.size( );
//  for ( sz curRow = 0; curRow < size - 1; ++curRow ) {
//    sz interressantCol = curRow;
//    sz nextRow = curRow + 1;
//    for ( ; nextRow < size; ++nextRow ) {
//      sz nextCol = interressantCol + 1;
//      for ( ; nextCol < size && container[ nextRow ][ interressantCol ] > 0; ++nextCol ) {
//        if ( container[ nextRow ][ interressantCol ] ) {
//          if ( container[ curRow ][ nextCol ] ) {
//            int16_t delta = std::min( container[ curRow ][ nextCol ], container[ nextRow ][ interressantCol ] );
//            container[ curRow ][ interressantCol ] += delta;
//            container[ curRow ][ nextCol ] -= delta;
//            container[ nextRow ][ nextCol ] += delta;
//            container[ nextRow ][ interressantCol ] -= delta;
//          }
//        }
//      }
//    }
//  }

//  for ( auto &el : container ) {
//    for ( auto &line : el ) std::cout << line << " ";
//    std::cout << '\n';
//  }

//  for ( sz r = 0; r < size; ++r ) {
//    for ( sz c = 0; c < size; ++c ) {
//      if ( r == c && container[ r ][ c ] == 0 )
//        return "Impossible";
//      else if ( r != c && container[ r ][ c ] != 0 )
//        return "Impossible";
//    }
//  }

//  return "Possible";
//}

std::string organizingContainers( std::vector< std::vector< int64_t > > container ) {
  int size = container.size( );
  std::vector< int64_t > sumRows( size );
  for ( int col = 0; col < size; ++col ) {
    for ( int row = 0; row < size; ++row ) {
      sumRows[ col ] += container[ row ][ col ];
    }
  }
  std::vector< int64_t > summColl( size );
  for ( int row = 0; row < size; ++row ) {
    for ( int col = 0; col < size; ++col ) {
      summColl[ row ] += container[ row ][ col ];
    }
  }

  std::sort( std::begin( sumRows ), std::end( sumRows ) );
  std::sort( std::begin( summColl ), std::end( summColl ) );

  for ( int i = 0; i < size; ++i ) {
    if ( sumRows[ i ] != summColl[ i ] ) return "Impossible";
  }
  return "Possible";
}

int main( ) {
  // std::cout << organizingContainers( { { 1, 1 }, { 1, 1 } } );
  // std::cout << organizingContainers( { { 0, 2 }, { 1, 1 } } );
  // std::cout << organizingContainers( { { 1, 3, 1 }, { 2, 1, 2 }, { 3, 3, 3 } } );
  std::vector< std::vector< int64_t > > data = { { 0, 2, 1 }, { 1, 1, 1 }, { 2, 0, 0 } };
  std::cout << organizingContainers( data );

  //*****************************************************************************
  //  std::vector< std::vector< int64_t > > data = {
  //      { 850352964, 977596446, 949048147, 948864413, 583894071, 690057713, 997747480, 989967717 },
  //      { 989808562, 768213277, 465807106, 806209383, 997601076, 726063750, 886274860, 999745463 },
  //      { 999716184, 614327240, 646233100, 701848586, 996640233, 637114525, 979053522, 973751653 },
  //      { 729579413, 623758391, 789451199, 998061161, 915515002, 887943421, 667982910, 663066401 },
  //      { 625660022, 983861176, 747822232, 924237583, 765182731, 879961473, 915988053, 973592376 },
  //      { 978486425, 911982749, 995853966, 373364101, 706580937, 995621049, 869416897, 906988203 },
  //      { 996021364, 982486194, 880450667, 971761433, 779568692, 990258135, 985311146, 547004947 },
  //      { 963237644, 954080173, 997900896, 551011238, 803702301, 931274261, 685754083, 585606717 } };  // Possible
  //  std::cout << organizingContainers( data );
  //*****************************************************************************

  //  std::fstream dataFile( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/MEDIUM/OrganizingContainersOfBalls/data.txt" );
  //  std::fstream answerFile( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/MEDIUM/OrganizingContainersOfBalls/resultes.txt" );
  //  // std::cout << dataFile.rdbuf( );
  //  int T = 0;
  //  dataFile >> T;
  //  std::string answer;
  //  while ( T-- ) {
  //    int N = 0;
  //    dataFile >> N;
  //    std::vector< std::vector< int64_t > > data( N, std::vector< int64_t >( N ) );
  //    for ( int i = 0; i < N; ++i ) {
  //      for ( int j = 0; j < N; ++j ) {
  //        dataFile >> std::skipws >> data[ i ][ j ];
  //      }
  //    }
  //    if ( answer != organizingContainers( data ) ) {
  //      std::cout << "NUMBER TEST = " << T << std::endl;
  //    }
  //    for ( int i = 0; i < N; ++i ) {
  //      for ( int j = 0; j < N; ++j ) {
  //        std::cout << data[ i ][ j ] << " ";
  //      }
  //      std::cout << "\n";
  //    }
  //    std::cout << "\n\n";
  //    answerFile >> answer;
  //  }
}
