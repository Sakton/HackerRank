#include <fstream>
#include <iostream>

int64_t taumBday( int64_t b, int64_t w, int64_t bc, int64_t wc, int64_t z ) {
  int64_t res = 0;
  if ( bc > wc + z ) {
    res = w * wc + b * ( wc + z );
  } else if ( wc > bc + z ) {
    res = b * bc + w * ( bc + z );
  } else {
    res = b * bc + w * wc;
  }
  return res;
}

int main( ) {
  // std::cout << taumBday( 10, 10, 1, 1, 1 );
  // std::cout << taumBday( 10, 10, 5, 3, 1 );

  std::fstream inpt( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/EASY/TaumAndBday/inpt.txt" );
  std::fstream ans( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/EASY/TaumAndBday/outp.txt" );
  int T = 0;
  inpt >> T;
  long b, w, bc, wc, z;
  int64_t answer;
  while ( T-- ) {
    inpt >> std::skipws >> b >> w >> bc >> wc >> z;
    // std::cout << b << ",," << w << ",," << bc << ",," << wc << ",," << z << "\n";
    ans >> answer;
    int64_t x = taumBday( b, w, bc, wc, z );
    if ( answer != x ) std::cout << answer << "  != >> " << x << std::endl;
  }
}
