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
test5 = 2325652489 //что выходит -> 4605887179
test6 = 1339347780085 //что выходит -> 2680744002957
test7 = 1667018988625 //что выходит -> 166661666700000
*/

// Complete the countTriplets function below.
long long countTriplets( std::vector< long long > arr, long r );
const std::string PATH_TEST1 = "../../HACKER_RANK/CountTriplets/Files/inpt1.txt";
const std::string PATH_TEST4 = "../../HACKER_RANK/CountTriplets/Files/inpt4.txt";
const std::string PATH_TEST5 = "../../HACKER_RANK/CountTriplets/Files/input5.txt";
const std::string PATH_TEST6 = "../../HACKER_RANK/CountTriplets/Files/input6.txt";
const std::string PATH_TEST7 = "../../HACKER_RANK/CountTriplets/Files/input7.txt";

const int DELITEL = 1;

// FIXME, ни одно из решений тест не прошло....

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

  std::fstream fin( PATH_TEST1 );
  if ( !fin.is_open( ) ) std::cout << "ERROR" << std::endl;
  long countElements = 0;
  long long k = 0;
  fin >> countElements >> k;
  // std::cout << countElements << " " << k << std::endl;
  std::vector< long long > inputData( countElements / DELITEL );
  for ( int i = 0; i < countElements / DELITEL; ++i ) {
    long long x = 0;
    fin >> std::skipws >> x;
    if ( fin.good( ) ) {
      inputData[ i ] = x;
    }
  }
  fin.close( );
  //  std::cout << inputData.size( );
  std::cout << countTriplets( inputData, k );
}

// bool findes( const std::map< long long, long long >& map, long long el ) { return map.find( el ) != map.end( ); }

// long long countTriplets( std::vector< long long > arr, long r ) {
//  //если r = 1, то ответ дать сразу
//  long long count = 0;
//  //  if ( r == 1 )
//  //    count = ( arr.size( ) * ( arr.size( ) - 1 ) * ( arr.size( ) - 2 ) ) / 6;
//  //  else {
//  // 2 карты:
//  // №1 будет отслеживать номера - key = само число, value = его количество
//  // №2 будет отслеживать ситуацию когда есть парный к текущему
//  std::map< long long, long long > elem;
//  std::map< long long, long long > pairs;
//  for ( auto it = arr.crbegin( ); it != arr.crend( ); ++it ) {
//    //если есть
//    if ( findes( pairs, *it * r ) ) {
//      count += pairs[ *it * r ];
//    }
//    if ( findes( elem, *it * r ) ) {
//      if ( findes( pairs, *it ) ) {
//        pairs[ *it ] += elem[ *it * r ];
//      } else {
//        pairs[ *it ] = elem[ *it * r ];
//      }
//    }
//    if ( findes( elem, *it ) ) {
//      elem[ *it ]++;
//    } else {
//      elem[ *it ] = 1;
//    }
//  }
//  //}
//  return count;
//}

// long long countTriplets( std::vector< long long > arr, long r ) {
//  std::map< long long, long long > nums;
//  std::map< long long, long long > tuples;
//  long long count = 0;
//  for ( auto it = arr.crbegin( ); it != arr.crend( ); ++it ) {
//    if ( findes( tuples, *it * r ) ) {
//      count += tuples[ *it * r ];
//    }
//    if ( findes( nums, *it * r ) ) {
//      if ( findes( tuples, *it ) ) {
//        tuples[ *it ] += nums[ *it * r ];
//      } else {
//        tuples[ *it ] = nums[ *it * r ];
//      }
//    }
//    if ( findes( nums, *it ) ) {
//      nums[ *it ]++;
//    } else {
//      nums[ *it ] = 1;
//    }
//  }
//  return count;
//}

// long long countTriplets( std::vector< long long > arr, long r ) {
//  //еще искать подход...
//  if ( r == 1 ) return ( arr.size( ) * ( arr.size( ) - 1 ) * ( arr.size( ) - 2 ) ) / 6;
//  using value_type = int64_t;
//  using tpl = std::tuple< value_type, value_type, value_type >;
//  std::map< value_type, value_type > elements;
//  std::map< tpl, value_type > triads;
//  for ( auto it = arr.crbegin( ); it != arr.crend( ); ++it ) {
//    //если считать его первым в тройке
//    if ( !*it ) continue;
//    value_type el1 = *it;
//    value_type el2 = el1 * r;
//    value_type el3 = el1 * r * r;
//    if ( elements.find( el2 ) != elements.cend( ) && elements.find( el3 ) != elements.cend( ) ) {  //если оба элемента уже были
//      //то можно составить тройку
//      tpl triad( el1, el2, el3 );
//      // value_type v = triads[ triad ];
//      triads[ triad ] += 0;  //???????  //считает больше чем надо //что то тут
//    }
//    //после того как посчитали по конкретному первому элементу
//    //можно внести текущий в карту, тем самым разрешить его использование в расчете троек
//    ++elements[ el1 ];
//  }
//  //когда все прошли считаем
//  value_type res = 0;
//  if ( !triads.empty( ) ) {
//    res =
//        std::accumulate( triads.cbegin( ), triads.cend( ), static_cast< value_type >( 0 ),
//                         [ & ]( value_type& var, const std::map< tpl, value_type >::value_type& pair ) { return ( var + pair.second );
//                         }
//                         );
//  }
//  return res;
//}

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
