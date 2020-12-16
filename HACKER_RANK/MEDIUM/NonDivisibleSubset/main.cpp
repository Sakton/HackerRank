#include <iostream>
#include <vector>

int nonDivisibleSubset( int k, std::vector< int > &&s );

int main( ) {
  std::vector< int > ttt { 1, 7, 2, 4 };
  std::cout << "res = " << nonDivisibleSubset( 3, { 1, 7, 2, 4 } );
}

// YESSSSSSSSSSSSS!!!!!!!!!!!
int nonDivisibleSubset( int k, std::vector< int > &&s ) {
  std::vector< int > modules( k, 0 );
  for ( auto el : s ) modules[ el % k ]++;
  int count = modules[ 0 ] ? 1 : 0;
  for ( int i = 1, j = modules.size( ) - 1; i < j; ++i, --j ) {
    count += std::max( modules[ i ], modules[ j ] );
  }
  if ( k % 2 == 0 && modules[ k / 2 ] ) ++count;
  return count;
}

// int nonDivisibleSubset( int k, std::vector< int > &&s ) {
//  std::vector< int > modules( k, 0 );
//  for ( auto el : s ) modules[ el % k ]++;

//  //**
//  for ( std::vector< int >::size_type i = 0; i < modules.size( ); ++i ) {
//    std::cout << i << " --> " << modules[ i ] << std::endl;
//  }  //**

//  int count = modules[ 0 ] ? 1 : 0;
//  for ( int i = 1, j = modules.size( ) - 1; i < j; ++i, --j ) {
//    count += std::max( modules[ i ], modules[ j ] );
//  }
//  if ( k % 2 == 0 && modules[ k / 2 ] ) ++count;
//  return count;
//}
