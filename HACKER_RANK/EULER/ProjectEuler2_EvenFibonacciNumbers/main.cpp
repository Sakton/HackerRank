#include <iostream>

int64_t summF( int64_t n ) {
  int64_t a = 1;
  int64_t b = 1;
  int64_t c = a + b;
  int64_t summ = 0;
  while ( c < n ) {
    summ += c;
    a = c + b;
    b = a + c;
    c = a + b;
  }
  return summ;
}

int main( ) { std::cout << summF( 100 ); }
