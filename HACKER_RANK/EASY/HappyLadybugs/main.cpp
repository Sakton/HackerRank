#include <fstream>
#include <iostream>
#include <map>
#include <string>

// std::string happyLadybugs( std::string b ) {
//  using sizeType = std::string::size_type;
//  for ( sizeType i = 0; i < b.size( ) - 1; ++i ) {
//    if ( b[ i ] == '_' ) {
//      sizeType j = i + 1;
//      while ( j < ( b.size( ) - 1 ) && b[ j ] == '_' ) ++j;
//      std::swap( b[ i ], b[ j ] );
//    }
//    if ( b[ i ] != b[ i + 1 ] ) {
//      sizeType pos = 0;
//      if ( b[ i + 1 ] == '_' ) {
//        pos = b.find( b[ i ], i + 1 );
//        if ( pos != std::string::npos ) std::swap( b[ i + 1 ], b[ pos ] );
//      } else {
//        pos = b.find( '_', i + 1 );
//        if ( pos != std::string::npos ) {
//          std::swap( b[ i + 1 ], b[ pos ] );
//          pos = b.find( b[ i ], i + 1 );
//          if ( pos != std::string::npos ) {
//            std::swap( b[ i + 1 ], b[ pos ] );
//            ++i;
//          }
//        }
//      }
//    } else {
//      ++i;
//    }
//  }
//  return b;
//}

std::string happyLadybugs( std::string b ) {
  if ( b.size( ) == 1 && b[ 0 ] != '_' ) return "NO";
  std::map< char, int > slow;
  for ( auto el : b ) ++slow[ el ];
  if ( slow.find( '_' ) == slow.end( ) ) {
    using sizeType = std::string::size_type;
    sizeType ps = 1;
    sizeType pe = 0;
    while ( ps < b.size( ) ) {
      auto symbol = b[ ps ];
      int count = 0;
      while ( ps << b.size( ) && b[ ps ] == b[ pe ] ) {
        ++count;
        ++ps;
      }
      if ( count < 1 ) return "NO";
      pe = ps;
      if ( pe == b.size( ) - 1 ) return "NO";
    }
    return "YES";
  }
  for ( auto el : slow ) {
    if ( el.first != '_' && el.second == 1 ) return "NO";
  }
  return "YES";
}

int main( ) {
  //  std::cout << happyLadybugs( "RBY_YBR" ) << std::endl;
  //  std::cout << happyLadybugs( "X_Y__X" ) << std::endl;
  //  std::cout << happyLadybugs( "__" ) << std::endl;
  //  std::cout << happyLadybugs( "B_RRBR" ) << std::endl;

  //  std::cout << std::endl;
  //  std::cout << happyLadybugs( "AABBC" ) << std::endl;
  //  std::cout << happyLadybugs( "AABBC_C" ) << std::endl;
  std::cout << happyLadybugs( "_" ) << std::endl;
  //  std::cout << happyLadybugs( "DD__FQ_QQF" ) << std::endl;
  //  std::cout << happyLadybugs( "AABCBC" ) << std::endl;

  // std::cout << happyLadybugs( "IIIAA" ) << std::endl;
  // std::cout << happyLadybugs( "_GR_" ) << std::endl;
  // std::cout << happyLadybugs( "RRGGBBXX" ) << std::endl;

  // NO YES YES NO YES YES YES NO NO NO NO NO YES NO NO NO NO NO NO NO NO NO NO NO NO NO NO NO YES NO NO NO NO YES YES NO YES YES
  //  std::ifstream ifile( "E:/Project_CPP_QT/HACKER_RANK/HackerRank/HACKER_RANK/EASY/HappyLadybugs/test1" );
  //  std::ifstream ifileA( "E:/Project_CPP_QT/HACKER_RANK/HackerRank/HACKER_RANK/EASY/HappyLadybugs/aswer2" );
  //  int T = 0;
  //  ifile >> T;
  //  while ( T-- ) {
  //    int N = 0;
  //    ifile >> N;
  //    std::string ts;
  //    ifile >> ts;
  //    std::string ans;
  //    ifileA >> ans;
  //    auto t = happyLadybugs( ts );
  //    int x = 0;
  //    //    if ( t != ans ) {
  //    //      std::cin >> x;
  //    //    }
  //    std::cout << ts << "   " << happyLadybugs( ts ) << " --> " << ans << std::endl;
  //  }
}
