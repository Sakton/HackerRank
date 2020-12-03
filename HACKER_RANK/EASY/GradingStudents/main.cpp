#include <algorithm>
#include <iostream>
#include <vector>

std::vector< int > gradingStudents( std::vector< int > grades ) {
  for ( auto &el : grades ) {
    if ( el >= 38 ) {
      if ( !( ( el + 1 ) % 5 ) ) el += 1;
      if ( !( ( el + 2 ) % 5 ) ) el += 2;
    }
  }
  return grades;
}

int main( ) {
  std::vector< int > input { 73, 67, 38, 33 };
  std::vector< int > res = gradingStudents( input );
  for ( auto &el : res ) {
    std::cout << el << ' ';
  }
}
