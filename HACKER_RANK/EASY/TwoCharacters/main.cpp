#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// int alternate( std::string s ) {
//  using para = std::pair< char, int >;
//  std::vector< para > frequency( 26 );

//  for ( int i = 0; i < 26; ++i ) {
//    frequency[ i ].first = i + 'a';
//  }

//  for ( auto ch : s ) {
//    frequency[ ch - 'a' ].second++;
//  }

//  std::sort( frequency.begin( ), frequency.end( ), []( para a, para b ) { return b.second < a.second; } );

//  for ( auto par : frequency ) {
//    std::cout << static_cast< int >( par.first ) << " -> " << par.first << "  cnt = " << par.second << '\n';
//  }

//  int max = 0;

//  for ( int i = 0; i < 26 - 1; ++i ) {
//    int j = i + 1;
//    auto charA = frequency[ i ].first;
//    auto charB = frequency[ j ].first;
//    auto countA = frequency[ i ].second;
//    auto countB = frequency[ j ].second;
//    auto delta = std::abs( countA - countB );

//    //***
//    while ( ( j < 26 ) && ( countA != 0 && countB != 0 ) && ( delta == 0 || delta == 1 ) ) {
//      std::string temp;
//      for ( auto ch : s ) {
//        if ( ( ch == charA ) || ( ch == charB ) ) {
//          if ( temp.empty( ) && ( delta == 1 ) && ( ch == charB ) ) break;
//          if ( !temp.empty( ) ) {
//            auto backChar = temp.back( );
//            if ( backChar == ch ) break;
//          }
//          temp.push_back( ch );
//          std::cout << temp << std::endl;
//        }
//      }
//      if ( max < static_cast< int >( temp.size( ) ) && ( ( countA + countB ) == static_cast< int >( temp.size( ) ) ) ) max = temp.size( );
//      ++j;
//      charB = frequency[ j ].first;
//      countB = frequency[ j ].second;
//      delta = std::abs( countA - countB );
//    }
//    //***
//  }

//  if ( max < 3 ) max = 0;

//  return max;
//}

int alternate( std::string s ) {
  using para = std::pair< char, int >;
  std::vector< para > frequency( 26 );

  for ( int i = 0; i < 26; ++i ) {
    frequency[ i ].first = i + 'a';
  }

  for ( auto ch : s ) {
    frequency[ ch - 'a' ].second++;
  }

  std::sort( frequency.begin( ), frequency.end( ), []( para a, para b ) { return b.second < a.second; } );

  int max = 0;

  for ( int i = 0; i < 26 - 1; ++i ) {
    int j = i + 1;
    auto charA = frequency[ i ].first;
    auto charB = frequency[ j ].first;
    auto countA = frequency[ i ].second;
    auto countB = frequency[ j ].second;
    auto delta = std::abs( countA - countB );

    //***
    while ( ( j < 26 ) && ( countA != 0 && countB != 0 ) && ( delta == 0 || delta == 1 ) ) {
      std::string temp;
      for ( auto ch : s ) {
        if ( ( ch == charA ) || ( ch == charB ) ) {
          if ( temp.empty( ) && ( delta == 1 ) && ( ch == charB ) ) break;
          if ( !temp.empty( ) ) {
            auto backChar = temp.back( );
            if ( backChar == ch ) break;
          }
          temp.push_back( ch );
        }
      }
      if ( max < static_cast< int >( temp.size( ) ) && ( ( countA + countB ) == static_cast< int >( temp.size( ) ) ) ) max = temp.size( );
      ++j;
      charB = frequency[ j ].first;
      countB = frequency[ j ].second;
      delta = std::abs( countA - countB );
    }
    //***
  }
  return max;
}

int main( ) {
  // std::cout << alternate( "beabeefeab" ) << std::endl;  // 5
  std::cout << alternate( "asvkugfiugsalddlasguifgukvsa" ) << std::endl;  // 0
  // std::cout << alternate( "asdcbsdcagfsdbgdfanfghbsfdab" ) << std::endl;  // 8
}
