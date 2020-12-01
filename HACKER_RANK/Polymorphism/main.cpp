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
  LRUCache( long c ) {
    cp = c;
    tail = head = nullptr;
  };

  // Cache interface
 public:
  void set( int k, int v ) override {
    if ( head == nullptr && tail == head ) {
      mp[ k ] = new Node( k, v );
      head = tail = mp[ k ];
      return;
    }
    auto it = mp.find( k );
    if ( it != mp.end( ) ) {  //есть элемент в КЭШЕ
      Node* A = it->second;
      A->value = v;
      if ( A == head ) return;  //если голова
      A->prev->next = A->next;  //общая для всех
      if ( A == tail ) {        //если хвост
        tail = A->prev;
      } else {
        A->next->prev = A->prev;
      }
      //вставка в голову любого
      A->next = head;
      A->prev = head->prev;
      head->prev = A;
      head = A;
    } else {
      //нет такого, то вставляем его в голову
      Node* B = new Node( head->prev, head, k, v );
      mp[ k ] = B;
      head->prev = B;
      head = B;

      if ( mp.size( ) > static_cast< map< int, Node* >::size_type >( cp ) )  //если уже много, то уберу последний
      {
        Node* D = tail;
        tail = D->prev;
        tail->next = D->next;
        mp.erase( D->key );
        delete D;
      }
    }
  }

  int get( int k ) override {
    //только чтение, ничего не менять тут, все изменения в set
    auto it = mp.find( k );
    if ( it != mp.end( ) ) return it->second->value;
    return -1;
  }
};

/*

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
    if ( !cp ) {
      mp.erase( tail->key );
      Node* del = tail;
      tail = tail->prev;
      tail->next = nullptr;
      delete del;
      ++cp;
    } else {
      if ( head == nullptr && tail == nullptr ) {
        head = tail = tmp;
      } else {
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
      }
      mp.insert( std::make_pair( k, tmp ) );
      --cp;
    }
  }

  int get( int key ) override {
    int res = -1;
    if ( mp.find( key ) != mp.end( ) ) {
      res = mp.find( key )->second->value;
      Node* t1 = head;
      while ( t1 != nullptr && t1->key != key ) {
        t1 = t1->next;
      }
      if ( t1 != nullptr && t1 != head ) {
        t1->prev->next = t1->next;
        if ( t1->next != nullptr ) {
          t1->next->prev = t1->prev;
        }
        t1->next = head;
        t1->prev = head->prev;
        head->prev = t1;
        head = t1;
      }
    }
    return res;
  };
};

*/

/*
    Node* t1 = head;
    while ( t1 ) {
      std::cout << "key = " << t1->key << " value = " << t1->value << std::endl;
      t1 = t1->next;
    }
 * */

int main( ) {
  std::ifstream fin( "../../Polymorphism/test5" );
  if ( !fin ) std::cout << "ERROR FILE";

  std::ifstream fin2( "../../Polymorphism/answer5" );

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
      //*****

      //*****
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
