#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Spell {
 private:
  string scrollName;

 public:
  Spell( ) : scrollName( "" ) {}
  Spell( string name ) : scrollName( name ) {}
  virtual ~Spell( ) {}
  string revealScrollName( ) { return scrollName; }
};

class Fireball : public Spell {
 private:
  int power;

 public:
  Fireball( int power ) : power( power ) {}
  void revealFirepower( ) { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
 private:
  int power;

 public:
  Frostbite( int power ) : power( power ) {}
  void revealFrostpower( ) { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
 private:
  int power;

 public:
  Thunderstorm( int power ) : power( power ) {}
  void revealThunderpower( ) { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
 private:
  int power;

 public:
  Waterbolt( int power ) : power( power ) {}
  void revealWaterpower( ) { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
 public:
  static string journal;
  static string read( ) { return journal; }
};

string SpellJournal::journal = "";

class Wizard {
 public:
  Spell *cast( ) {
    Spell *spell;
    string s;
    cin >> s;
    int power;
    cin >> power;
    if ( s == "fire" ) {
      spell = new Fireball( power );
    } else if ( s == "frost" ) {
      spell = new Frostbite( power );
    } else if ( s == "water" ) {
      spell = new Waterbolt( power );
    } else if ( s == "thunder" ) {
      spell = new Thunderstorm( power );
    } else {
      spell = new Spell( s );
      cin >> SpellJournal::journal;
    }
    return spell;
  }
};

void counterspell( Spell *spell ) {
  if ( Fireball *t = dynamic_cast< Fireball * >( spell ) ) {
    t->revealFirepower( );
  } else if ( Frostbite *t = dynamic_cast< Frostbite * >( spell ) ) {
    t->revealFrostpower( );
  } else if ( Waterbolt *t = dynamic_cast< Waterbolt * >( spell ) ) {
    t->revealWaterpower( );
  } else if ( Thunderstorm *t = dynamic_cast< Thunderstorm * >( spell ) ) {
    t->revealThunderpower( );
  } else {
    std::string a( spell->revealScrollName( ) );
    std::string b( SpellJournal::read( ) );
    //Нахождение наибольшей общей подпоследовательности
    std::vector< std::vector< int > > l( a.size( ) + 1, std::vector< int >( b.size( ) + 1 ) );
    for ( std::string::size_type i = 0; i < a.size( ); ++i ) l[ i ][ 0 ] = 0;
    for ( std::string::size_type j = 0; j < b.size( ); ++j ) l[ 0 ][ j ] = 0;
    for ( std::string::size_type i = 1; i <= a.size( ); ++i ) {
      for ( std::string::size_type j = 1; j <= b.size( ); ++j ) {
        if ( a[ i - 1 ] == b[ j - 1 ] )
          l[ i ][ j ] = l[ i - 1 ][ j - 1 ] + 1;
        else
          l[ i ][ j ] = std::max( l[ i - 1 ][ j ], l[ i ][ j - 1 ] );
      }
    }
    cout << l[ a.size( ) ][ b.size( ) ] << '\n';
  }
}

int main( ) {
  fstream fin( "../../MagicSpells/test1" );
  if ( !fin.is_open( ) ) cerr << "ERROR FILE" << std::endl;
  cin.rdbuf( fin.rdbuf( ) );
  //  std::cout << std::cin.rdbuf( );
  int T;
  cin >> T;
  Wizard Arawn;
  while ( T-- ) {
    Spell *spell = Arawn.cast( );
    counterspell( spell );
  }
  return 0;
}
