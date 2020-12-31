#include <iostream>

int viralAdvertising( int n );

int main( ) { std::cout << viralAdvertising( 3 ); }

int viralAdvertising( int n ) {
  const int START_PEOPLE = 5;
  int liked = START_PEOPLE / 2;
  int total = liked;
  int virus = liked * 3;
  for ( int i = 2; i <= n; ++i ) {
    liked = virus / 2;
    total += liked;
    virus = liked * 3;
  }
  return total;
}
