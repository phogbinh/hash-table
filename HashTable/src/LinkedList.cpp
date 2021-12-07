#include "../inc/LinkedList.h"

LinkedList::LinkedList(LinkedList* const nextPtr) : _nextPtr(nextPtr) {
  // body intentionally blank
}

LinkedList::LinkedList(const std::pair<std::string, unsigned int>& value, LinkedList* const nextPtr) : _value(value), _nextPtr(nextPtr) {
  // body intentionally blank
}

void LinkedList::setNextPtr(LinkedList* const nextPtr) {
  _nextPtr = nextPtr;
}

void LinkedList::incrementCount() {
  ++_value.second;
}

bool LinkedList::is(const std::string& key) const {
  return _value.first == key;
}

unsigned int LinkedList::getCount() const {
  return _value.second;
}

LinkedList* LinkedList::getNextPtr() const {
  return _nextPtr;
}