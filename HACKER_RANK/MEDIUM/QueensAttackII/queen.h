#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include <vector>

class Queen {
 public:
  struct Ogran {
    int l;
    int r;
    int t;
    int d;

    friend std::ostream& operator<<( std::ostream& o, const Ogran& gr ) {
      std::cout << "leftOgr  = " << gr.l << "\n"
                << "rightOgr = " << gr.r << "\n"
                << "topOgr   = " << gr.t << "\n"
                << "downPred = " << gr.d << "\n";
      return o;
    }
  };

  Queen( int n, int r, int c ) : countNboard { n }, rowQ { r }, colQ { c }, answerCount { 0 }, grani { 0, 0, 0, 0 } { grantsy( ); }

  int queensAttack( ) {
    std::cout << grani;
    return answerCount;
  }

 private:
  int nRow( int r ) { return countNboard - r; }

  void grantsy( ) {
    grani.l = -( colQ );
    grani.r = ( countNboard - colQ ) + 1;
    grani.t = -( rowQ );
    grani.d = ( countNboard - rowQ ) + 1;
  }

 private:
  //
  std::vector< int > actualNapravl;
  int countNboard;
  int rowQ;
  int colQ;
  int answerCount;
  Ogran grani;
  // int k { 0 };
};

#endif // QUEEN_H
