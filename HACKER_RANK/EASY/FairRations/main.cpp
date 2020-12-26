#include <fstream>
#include <iostream>
#include <vector>

int fairRations( std::vector< int > B ) {
  int n = B.size( );
  int count = 0;
  int i = n - 2;
  for ( ; i > 0; --i ) {
    if ( B[ i + 1 ] % 2 ) {
      ++B[ i + 1 ];
      ++B[ i ];
      count += 2;
    }
  }
  //крайние случаи проблемы была!!!
  if ( ( !( B[ i ] % 2 ) && ( B[ i + 1 ] % 2 ) ) || ( ( B[ i ] % 2 ) && !( B[ i + 1 ] % 2 ) ) ) {
    count = -1;
  } else if ( ( B[ i ] % 2 ) && ( B[ i + 1 ] % 2 ) ) {
    count += 2;
  }
  return count;
}

/*
    int result = fairRations(B);
    if(result == -1) fout << "NO" << "\n";
    else
    fout << result << "\n";
*/

int main( ) {
  //  std::cout << fairRations( { 2, 3, 4, 5, 6 } ) << std::endl;
  std::cout << fairRations( { 1, 2 } ) << std::endl;

  //  std::ifstream ifile( "E:/Project_CPP_QT/HACKER_RANK/HackerRank/HACKER_RANK/EASY/FairRations/inpt1.txt" );
  //  std::vector< int > inpt;
  //  int T = 0;
  //  ifile >> T;
  //  while ( T-- ) {
  //    int x = 0;
  //    ifile >> std::skipws >> x;
  //    inpt.push_back( x );
  //  }

  //  std::cout << fairRations( inpt );  // 1042

  // for ( auto &el : inpt ) std::cout << el << " ";
}
