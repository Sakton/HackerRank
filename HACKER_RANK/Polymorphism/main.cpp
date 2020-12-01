#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

/*
Сообщение компилятора
Wrong Answer
Ввод (стандартный ввод)

Скачать
8 4
    set 4 2
    set 2 7
    get 2
    set 1 8
    set 5 9
    set 6 15
    get 4
    get 5

    Ваш вывод (стандартный вывод)
    7
    2
    9

    Ожидаемый результат
    7
    -1
    9
*/

struct Node {
  Node* next;
  Node* prev;
  int value;
  int key;
  Node( Node* p, Node* n, int k, int val ) : prev( p ), next( n ), key( k ), value( val ) { };
  Node( int k, int val ) : prev( NULL ), next( NULL ), key( k ), value( val ) { };
};

class Cache {
 protected:
  map< int, Node* > mp;              // map the key to the node in the linked list
  int cp;                            // capacity
  Node* tail;                        // double linked list tail pointer
  Node* head;                        // double linked list head pointer
  virtual void set( int, int ) = 0;  // set function
  virtual int get( int ) = 0;        // get function
};

class LRUCache : public Cache {
 public:
  explicit LRUCache( int cap ) {
    cp = cap;
    tail = nullptr;
    head = nullptr;
  }

 public:
  void set( int k, int v ) override {
    Node* tmp = new Node( k, v );
    if ( cp ) {
      if ( head == nullptr && tail == nullptr ) {
        head = tail = tmp;
      } else {
        //        tmp->prev = tail;
        //        tail->next = tmp;
        //        tail = tmp;
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
      }
      mp.insert( std::make_pair( k, tmp ) );
      --cp;
    } else {
      tmp->next = head;
      head->prev = tmp;
      head = tmp;

      // FIXME

      Node* del = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete del;
    }

    Node* t = head;
    while ( t ) {
      cout << "key = " << t->key << " val = " << t->value << std::endl;
      t = t->next;
    }
    std::cout << "//****//" << std::endl;
  }

  int get( int key ) override { return ( mp.find( key ) != mp.end( ) ) ? mp.find( key )->second->value : -1; };
};

int main( ) {
  std::ifstream fin( "../../Polymorphism/file" );
  if ( !fin ) std::cout << "ERROR FILE";
  //  std::cout << fin.rdbuf( ) << std::endl;
  cin.rdbuf( fin.rdbuf( ) );
  //  cout << cin.rdbuf( );
  int n, capacity, i;
  cin >> n >> capacity;
  // std::cout << n << " " << capacity;
  LRUCache l( capacity );
  for ( i = 0; i < n; i++ ) {
    string command;
    cin >> command;
    if ( command == "get" ) {
      int key;
      cin >> key;
      cout << l.get( key ) << endl;
    } else if ( command == "set" ) {
      int key, value;
      cin >> key >> value;
      l.set( key, value );
    }
  }
  return 0;
}
