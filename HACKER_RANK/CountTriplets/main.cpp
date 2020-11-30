#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <tuple>
#include <vector>

/*
test1 = 166661666700000
test4 = 0
test5 = 2325652489
*/

// Complete the countTriplets function below.
long long countTriplets( std::vector< long long > arr, long r );
const std::string PATH_TEST1 = "../../HACKER_RANK/CountTriplets/Files/inpt1.txt";
const std::string PATH_TEST4 = "../../HACKER_RANK/CountTriplets/Files/inpt4.txt";
const std::string PATH_TEST3 = "../../HACKER_RANK/CountTriplets/Files/input5.txt";
const int DELITEL = 1;

int main( ) {
  //  std::vector< long long > inputData { 1, 2, 2, 4 };
  //  std::cout << countTriplets( inputData, 2 );
  //  std::vector< long long > inputData { 1, 3, 9, 9, 27, 81 };
  //  std::cout << countTriplets( inputData, 3 );
  //  std::vector< long long > inputData { 1, 5, 5, 25, 125 };
  //  std::cout << countTriplets( inputData, 5 );
  //  std::vector< long long > inputData { 1, 2, 1, 2, 4, 1, 2, 1, 2, 4 };
  //  std::cout << countTriplets( inputData, 2 );

  //***

  std::fstream fin( PATH_TEST4 );
  if ( !fin.is_open( ) ) std::cout << "ERROR" << std::endl;
  long countElements = 0;
  long k = 0;
  fin >> countElements >> k;
  // std::cout << countElements << " " << k << std::endl;
  std::vector< long long > inputData( countElements / DELITEL );
  for ( int i = 0; i < countElements / DELITEL; ++i ) {
    fin >> std::skipws >> inputData[ i ];
  }
  //  std::cout << inputData.size( );
  std::cout << countTriplets( inputData, k );
}

long long countTriplets( std::vector< long long > arr, long r ) {
  // FIXME нет крайних случаев
  using value_type = long long;
  using tpl = std::tuple< value_type, value_type, value_type >;
  std::map< value_type, value_type > elements;
  std::map< tpl, value_type > triads;
  for ( auto it = arr.crbegin( ); it != arr.crend( ); ++it ) {
    //если считать его первым в тройке
    value_type el1 = *it;
    value_type el2 = el1 * r;
    value_type el3 = el2 * r;
    if ( elements.find( el2 ) != elements.cend( ) && elements.find( el3 ) != elements.cend( ) ) {  //если оба элемента уже были
      //то можно составить тройку
      tpl triad( el1, el2, el3 );
      triads[ triad ] += elements[ el2 ] * elements[ el3 ];
    }
    //после того как посчитали по конкретному первому элементу
    //можно внести текущий в карту, тем самым разрешить его использование в расчете троек
    elements[ el1 ]++;
  }
  //когда все прошли считаем

  value_type res =
      std::accumulate( triads.cbegin( ), triads.cend( ), 0,
                       [ & ]( value_type var, const std::map< tpl, value_type >::value_type& pair ) { return var + pair.second; } );
  value_type xxx = 0;
  for ( auto el : triads ) xxx += el.second;
  std::cout << "xxx = " << xxx << std::endl;
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
