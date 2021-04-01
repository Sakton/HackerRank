#include <iostream>
#include <map>
#include <vector>

using namespace std;

// TODO оптимизировать надо

vector< int > freqQuery( vector< vector< int > > queries ) {
  vector< int > res;
  map< int, int > tmp;
  for ( const auto& el : queries ) {
    int query = el[ 0 ];
    int param = el[ 1 ];
    switch ( query ) {
      case 1:
        tmp[ param ]++;
        break;
      case 2: {
        auto tt = tmp.find( param );
        if ( tt != tmp.end( ) ) tmp[ param ]--;
        if ( tmp[ param ] <= 0 ) tmp.erase( param );
      } break;
      case 3: {
        auto t = std::find_if( tmp.cbegin( ), tmp.cend( ),
                               [ &param ]( std::pair< int, int >& pr ) {
                                 return param == pr.second;
                               } );
        if ( t != tmp.end( ) )
          res.push_back( 1 );
        else
          res.push_back( 0 );
      } break;
    }
  }
  return res;
}

int main( ) {
  vector< vector< int > > v { { 1, 5 },  { 1, 6 }, { 3, 2 }, { 1, 10 },
                              { 1, 10 }, { 1, 6 }, { 2, 5 }, { 3, 2 } };
  auto r = freqQuery( v );
  for ( int e : r ) std::cout << e << " ";
}
