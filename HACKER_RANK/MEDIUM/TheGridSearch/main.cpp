#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string gridSearch( std::vector< std::string > G, std::vector< std::string > P ) {
  using posType = std::vector< std::string >::size_type;
  for ( posType i = 0; i < G.size( ); ++i ) {
    posType countStr = 0;
    posType pos = G[ i ].find( P[ 0 ] );
    while ( pos != std::string::npos ) {
      countStr = 1;
      posType lines = i + 1;
      for ( posType j = 1; j < P.size( ); ++j ) {
        if ( lines < G.size( ) ) {
          std::string sub = G[ lines ].substr( pos, P[ 0 ].size( ) );
          if ( sub == P[ j ] )
            ++countStr;
          else {
            break;
          }
        }
        ++lines;
      }  // while
      if ( countStr == P.size( ) )
        return "YES";
      else
        pos = G[ i ].find( P[ 0 ], ++pos );
    }
  }
  return "NO";
}

int main( ) {
  //  std::cout << gridSearch( { "7283455864", "6731158619", "8988242643", "3830589324", "2229505813", "5633845374", "6473530293",
  //  "7053106601",
  //                             "0834282956", "4607924137" },
  //                           { "9505", "3845", "3530" } );
  //  std::cout << gridSearch( { "400453592126560", "114213133098692", "474386082879648", "522356951189169", "887109450487496",
  //                             "252802633388782", "502771484966748", "075975207693780", "511799789562806", "404007454272504",
  //                             "549043809916080", "962410809534811", "445893523733475", "768705303214174", "650629270887160" },
  //                           { "99", "99" } );
  // std::cout << gridSearch( { "123412", "561212", "123634", "781288" }, { "12", "34" } );
  std::cout << gridSearch( { "999999", "121211" }, { "99", "11" } );

  //  std::ifstream ifile( "E:/Project_CPP_QT/HACKER_RANK/HackerRank/HACKER_RANK/MEDIUM/TheGridSearch/tests.txt" );
  //  int T = 0;
  //  ifile >> T;
  //  //  T = 1;
  //  while ( T-- ) {
  //    int N = 0;
  //    int G = 0;
  //    ifile >> G >> N;
  //    //    std::cout << G << " " << N << std::endl;
  //    std::vector< std::string > grid;
  //    while ( G-- ) {
  //      std::string ts;
  //      ifile >> ts;
  //      grid.push_back( ts );
  //    }
  //    //    for ( auto &el : grid ) std::cout << el << std::endl;
  //    int n = 0;
  //    int c = 0;
  //    ifile >> n >> c;
  //    //    std::cout << n << " " << c << std::endl;
  //    std::vector< std::string > pattern;
  //    while ( n-- ) {
  //      std::string ts;
  //      ifile >> ts;
  //      pattern.push_back( ts );
  //    }

  //    std::cout << gridSearch( grid, pattern ) << std::endl << std::endl;

  //    //    for ( auto &el : pattern ) std::cout << el << std::endl;
  //    //    std::cout << std::endl;

  //    //    if ( T == 1 ) {
  //    //      int x = 0;
  //    //      std::cout << "Start test " << T << " Enter symb" << std::endl;
  //    //      std::cin >> x;
  //    //      std::cout << gridSearch( grid, pattern ) << std::endl << std::endl;
  //    //    }
  //  }
}
