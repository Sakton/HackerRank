#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// TODO оптимизировать надо

vector< int > freqQuery( vector< vector< int > > queries ) {
  vector< int > res;
  map< int, int > tmp;   //число - частота
  map< int, int > temp;  //частота - количество
  for ( const auto& el : queries ) {
    int query = el[ 0 ];
    int param = el[ 1 ];
    switch ( query ) {
      case 1: {
        if ( tmp[ param ] > 0 ) {
          temp[ tmp[ param ] ]--;
          tmp[ param ]++;
          temp[ tmp[ param ] ]++;
        } else {
          tmp[ param ]++;
          temp[ tmp[ param ] ]++;
        }
      } break;
      case 2: {
        if ( tmp[ param ] > 0 ) {
          temp[ tmp[ param ] ]--;
          tmp[ param ]--;
          temp[ tmp[ param ] ]++;
        }
      } break;
      case 3: {
        ( temp[ param ] > 0 ) ? res.push_back( 1 ) : res.push_back( 0 );
      } break;
    }
  }
  return res;
}

int main( ) {
  //  vector< vector< int > > v { { 1, 5 },  { 1, 6 }, { 3, 2 }, { 1, 10 },
  //                              { 1, 10 }, { 1, 6 }, { 2, 5 }, { 3, 2 } };
  vector< vector< int > > v { { 1, 5 }, { 1, 5 }, { 1, 5 }, { 2, 5 }, { 1, 4 },
                              { 1, 4 }, { 1, 4 }, { 2, 4 }, { 2, 4 } };
  auto r = freqQuery( v );
  for ( int e : r ) std::cout << e << " ";

  //  v.clear( );
  //  std::ifstream ifile(
  //      "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/MEDIUM/"
  //      "FrequencyQueries/input.txt" );
  //  int count = 0;
  //  ifile >> count;
  //  while ( count-- ) {
  //    int a, b;
  //    ifile >> a >> b;
  //    v.push_back( { a, b } );
  //  }
  //  auto r = freqQuery( v );
  //  // for ( auto el : r ) std::cout << el << " ";

  //  std::ifstream ifile2(
  //      "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/MEDIUM/"
  //      "FrequencyQueries/ans.txt",
  //      std::ifstream::binary );

  //  std::vector< int > an;
  //  std::copy( std::istream_iterator< int >( ifile2 ),
  //             std::istream_iterator< int >( ), std::back_insert_iterator( an
  //             ) );

  //  for ( int i = 0; i < an.size( ); ++i ) {
  //    if ( r[ i ] != an[ i ] ) std::cout << r[ i ] << " ";
  //  };
}
