#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

// std::vector< int > stones( int n, int a, int b ) {
//  std::vector< int > resVec;
//  int res = a * ( n - 1 );
//  resVec.push_back( res );
//  for ( int i = 0; i < n - 1; ++i ) {
//    res = res + ( b - a );
//    resVec.push_back( res );
//  }
//  return resVec;
//}

/*
1368 1413 1458 1503 1548 1593 1638 1683 1728 1773 1818 1863 1908 1953 1998 2043 2088 2133 2178 2223 2268 2313 2358 2403 2448 2493 2538 2583
2628 2673 2718 2763 2808 2853 2898 2943 2988 3033 3078 3123 3168 3213 3258 3303 3348 3393 3438 3483 3528 3573 3618 3663 3708 3753 3798 3843
3888 3933
********************************************************************************************************************************************
6642 6647 6652 6657 6662 6667 6672 6677 6682 6687 6692 6697 6702 6707 6712 6717 6722 6727 6732 6737 6742 6747 6752 6757 6762 6767 6772 6777
6782 6787 6792 6797 6802 6807 6812 6817 6822 6827 6832 6837 6842 6847 6852 6857 6862 6867 6872 6877 6882 6887 6892 6897 6902 6907 6912 6917
6922 6927 6932 6937 6942 6947 6952 6957 6962 6967 6972 6977 6982 6987 6992 6997 7002 7007 7012 7017 7022 7027 7032 7037 7042 7047 7052
*******************************************
1800
********************************************
803 812 821 830 839 848 857 866 875 884 893 902
********************************************
12 32 52 72 92
*/

std::vector< int > stones( int n, int a, int b ) {
  std::vector< int > resVec( 1, a * ( n - 1 ) );
  while ( --n ) resVec.push_back( resVec.back( ) + ( b - a ) );
  std::sort( resVec.begin( ), resVec.end( ) );
  resVec.erase( std::unique( resVec.begin( ), resVec.end( ) ), resVec.end( ) );
  return resVec;
}

int main( ) {
  //  auto res = stones( 3, 1, 2 );
  //  // auto res = stones( 4, 10, 100 );
  //  for ( auto el : res ) std::cout << el << " ";

  std::ifstream ifile( "E:/Project_CPP_QT/HACKER_RANK/HackerRank/HACKER_RANK/EASY/ManasaAndStones/inpt.txt" );

  int T = 0;
  ifile >> T;
  while ( T-- ) {
    int n = 0;
    int a = 0;
    int b = 0;
    ifile >> std::skipws >> n >> a >> b;
    // std::cout << n << " " << a << " " << b << " " << std::endl;

    auto res1 = stones( n, a, b );
    for ( auto el : res1 ) std::cout << el << " ";
    std::cout << "\n\n\n";
  }
}
