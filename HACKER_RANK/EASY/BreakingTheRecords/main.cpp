#include <iostream>
#include <vector>
std::vector< int > breakingRecords( std::vector< int > scores ) {
  int countMax = 0;
  int countMin = 0;
  int max = scores[ 0 ];
  int min = scores[ 0 ];
  for ( auto &el : scores ) {
    if ( el > max ) {
      max = el;
      ++countMax;
    }
    if ( el < min ) {
      min = el;
      ++countMin;
    }
  }
  return { countMax, countMin };
}

int main()
{
  // std::vector< int > inpt { 3, 4, 21, 36, 10, 28, 35, 5, 24, 42 };
  std::vector< int > inpt { 10, 5, 20, 20, 4, 5, 2, 25, 1 };
  std::vector< int > t = breakingRecords( inpt );
  for ( auto el : t ) {
    std::cout << el << " ";
  }
  return 0;
}
