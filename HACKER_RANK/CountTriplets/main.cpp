#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

// Complete the countTriplets function below.
long countTriplets( std::vector< long > arr, long r );

int main( ) {
  //  std::vector< long > inputData { 1, 2, 2, 4 };
  //  std::cout << countTriplets( inputData, 2 );
  //  std::vector< long > inputData { 1, 3, 9, 9, 27, 81 };
  //  std::cout << countTriplets( inputData, 3 );
  std::vector< long > inputData { 1, 5, 5, 25, 125 };
  std::cout << countTriplets( inputData, 5 );
}

long countTriplets( std::vector< long > arr, long r ) {
  std::multimap< long, std::vector< long > > mapTriplets;
  std::sort( arr.begin( ), arr.end( ) );
  std::vector< long > tmp;
  for ( size_t i = 0; i < arr.size( ) - 2; ++i ) {
    tmp.push_back( arr[ i ] );
    for ( size_t j = i + 1; ( j < arr.size( ) - 1 ); ++j ) {
      if ( ( arr[ j ] / tmp.back( ) ) == r ) {
        tmp.push_back( arr[ j ] );
        for ( size_t n = j + 1; n < arr.size( ); ++n ) {
          if ( ( arr[ n ] / tmp.back( ) ) == r ) {
            tmp.push_back( arr[ n ] );
            mapTriplets.insert( std::make_pair( arr[ i ], tmp ) );
            tmp.pop_back( );
          }
        }
        tmp.pop_back( );
      }
    }
    tmp.pop_back( );
  }
  return mapTriplets.size( );
}

// long countTriplets( std::vector< long > arr, long r ) {
//  std::multimap< long, std::vector< long > > mapTriplets;
//  for ( size_t i = 0; i < arr.size( ) - 2; ++i ) {
//    long key = arr[ i ];
//    std::vector< long > tmp( 3 );
//    int k = 0;
//    tmp[ k++ ] = key;
//    for ( size_t j = i + 1; ( j < arr.size( ) ) && ( k < 3 ); ++j ) {
//      if ( k < 3 && ( ( arr[ j ] / tmp[ k - 1 ] ) == r ) ) {
//        tmp[ k++ ] = arr[ j ];
//      }
//    }
//    mapTriplets.insert( std::make_pair( key, tmp ) );
//  }
//  return mapTriplets.size( );
//}
