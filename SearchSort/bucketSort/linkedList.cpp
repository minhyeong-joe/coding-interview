/**
Simple linked list implemented specifically for bucket sort
*/

#include <string>
#include <exception>
using namespace std;

struct EmptyListException: public exception {
  const char* what() const throw() {
    return "list is empty";
  }
};

template <class T>
struct Node {
  T value;
  Node<T>* next;
};

template <class T>
class LinkedList {

private:
  Node<T>* head;

public:

  LinkedList() {
    head = nullptr;
  }

  LinkedList(T val) {
    head = new Node<T>();
    head->value = val;
    head->next = nullptr;
  }

  // insert to the given position.
  // if pos not provided, insert to the beginning of list
  void insert(T val, int pos = 0) {
    Node<T>* newNode = new Node<T>;
    newNode->value = val;
    newNode->next = nullptr;
    // if list is empty
    if (size() == 0) {
      head = newNode;
    }
    // if list has head only
    else if (size() == 1) {
      if (pos == 0) {
        Node<T>* oldHead = head;
        head = newNode;
        head->next = oldHead;
      } else {
        head->next = newNode;
      }
    }
    else {
      if (pos == 0) {
        Node<T>* oldHead = head;
        head = newNode;
        newNode->next = oldHead;
      } else {
        Node<T>* curPtr = head->next;
        Node<T>* prevPtr = head;
        int i = 1;
        while (curPtr != nullptr) {
          if (i == pos) {
            break;
          }
          curPtr = curPtr->next;
          prevPtr = prevPtr->next;
          i++;
        }
        prevPtr->next = newNode;
        newNode->next = curPtr;
      }
    }
  }

  // returns the position of the first larger element
  int firstLarger(T target) {
    Node<T>* curPtr = head;
    int pos = 0;
    while (curPtr != nullptr) {
      if (curPtr->value >= target) {
        return pos;
      }
      curPtr = curPtr->next;
      pos++;
    }
    return pos;
  }

  // pop out the list element from the beginning
  T pop() {
    Node<T>* temp = head;
    if (temp != nullptr) {
      head = head->next;
      T val = temp->value;
      delete temp;
      temp = NULL;
      return val;
    }
    throw new EmptyListException;
  }

  int size() {
    int size = 0;
    Node<T>* counter = head;
    while (counter != nullptr) {
      size++;
      counter = counter->next;
    }
    return size;
  }

  string toString() {
    string output = "";
    Node<T>* curPtr = head;
    while (curPtr != nullptr) {
      output.append(to_string(curPtr->value));
      output.append(" ");
      curPtr = curPtr->next;
    }
    return output;
  }
};
