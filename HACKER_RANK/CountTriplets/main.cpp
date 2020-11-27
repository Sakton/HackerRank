#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

/*
test1 = 166661666700000
test4 = 0
test5 = 2325652489
*/

// Complete the countTriplets function below.
long countTriplets( std::vector< long > arr, long r );
const std::string PATH_TEST1 = "../../HACKER_RANK/CountTriplets/Files/inpt1.txt";
const std::string PATH_TEST3 = "../../HACKER_RANK/CountTriplets/Files/input5.txt";
const int DELITEL = 1;

int main( ) {
  std::vector< long > inputData { 1, 2, 2, 4 };
  std::cout << countTriplets( inputData, 2 );
  //  std::vector< long > inputData { 1, 3, 9, 9, 27, 81 };
  //  std::cout << countTriplets( inputData, 3 );
  //  std::vector< long > inputData { 1, 5, 5, 25, 125 };
  //  std::cout << countTriplets( inputData, 5 );

  //***

  //  std::fstream fin( PATH_TEST3 );
  //  if ( !fin.is_open( ) ) std::cout << "ERROR" << std::endl;
  //  long countElements = 0;
  //  long k = 0;
  //  fin >> countElements >> k;
  //  // std::cout << countElements << " " << k << std::endl;
  //  std::vector< long > inputData( countElements / DELITEL );
  //  for ( int i = 0; i < countElements / DELITEL; ++i ) {
  //    fin >> std::skipws >> inputData[ i ];
  //  }
  //  // std::cout << inputData.size( );
  //  std::cout << countTriplets( inputData, k );
}

long countTriplets( std::vector< long > arr, long r ) {
  //  std::sort( arr.begin( ), arr.end( ) );
  //  for ( auto &el : arr ) {
  //    std::cout << el << " ";
  //  }
  //  return 0;
  //  std::map< long, long > counts;
  //  for ( auto const &el : arr ) counts[ el ]++;
  //  for ( auto const &el : counts ) std::cout << el.first << " --- " << el.second << std::endl;
  std::map< long, long > elemCount;
  int res = 0;
  for ( size_t i = 0; i < arr.size( ); ++i ) {
    elemCount[ arr[ i ] ]++;
    if ( elemCount.find( ( arr[ i ] / r ) ) != elemCount.end( ) ) {
      if ( elemCount.find( ( arr[ i ] / ( r * r ) ) ) != elemCount.end( ) ) {
        res += elemCount[ arr[ i ] / r ] + elemCount[ arr[ i ] / ( r * r ) ];
      }
    }
  }
  // lalala
  return res;
}

//медленно
// long countTriplets( std::vector< long > arr, long r ) {
//  std::map< std::vector< long >, long > mapTriplets;
//  std::vector< long > tmp;
//  for ( size_t i = 0; i < arr.size( ) - 2; ++i ) {
//    tmp.push_back( arr[ i ] );
//    for ( size_t j = i + 1; ( j < arr.size( ) - 1 ); ++j ) {
//      if ( ( arr[ j ] / tmp.back( ) ) == r ) {
//        tmp.push_back( arr[ j ] );
//        for ( size_t n = j + 1; n < arr.size( ); ++n ) {
//          if ( ( arr[ n ] / tmp.back( ) ) == r ) {
//            tmp.push_back( arr[ n ] );
//            if ( mapTriplets.find( tmp ) == mapTriplets.end( ) )
//              mapTriplets.insert( std::make_pair( tmp, 1 ) );
//            else
//              mapTriplets[ tmp ]++;
//            tmp.pop_back( );
//          }
//        }
//        tmp.pop_back( );
//      }
//    }
//    tmp.pop_back( );
//  }
//  long res = 0;
//  if ( !mapTriplets.empty( ) ) {
//    for ( const auto &el : mapTriplets ) {
//      res += el.second;
//    }
//  }
//  return res;
//}

//это не запускать!!!!
// long countTriplets( std::vector< long > arr, long r ) {
//  std::multimap< long, std::vector< long > > mapTriplets;
//  std::sort( arr.begin( ), arr.end( ) );
//  std::vector< long > tmp;
//  for ( size_t i = 0; i < arr.size( ) - 2; ++i ) {
//    tmp.push_back( arr[ i ] );
//    for ( size_t j = i + 1; ( j < arr.size( ) - 1 ); ++j ) {
//      if ( ( arr[ j ] / tmp.back( ) ) == r ) {
//        tmp.push_back( arr[ j ] );
//        for ( size_t n = j + 1; n < arr.size( ); ++n ) {
//          if ( ( arr[ n ] / tmp.back( ) ) == r ) {
//            tmp.push_back( arr[ n ] );
//            mapTriplets.insert( std::make_pair( arr[ i ], tmp ) );
//            tmp.pop_back( );
//          }
//        }
//        tmp.pop_back( );
//      }
//    }
//    tmp.pop_back( );
//  }
//  return mapTriplets.size( );
//}

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
