#include "LinkedList.h"

LinkedList::LinkedList(const string& key, unsigned int value, LinkedList* nextPtr)
{
  _key = key;
  _value = value;
  _nextPtr = nextPtr;
}

const string& LinkedList::key()
{
  return _key;
}

const unsigned int& LinkedList::value()
{
  return _value;
}

LinkedList* const LinkedList::next()
{
  return _nextPtr;
}

void LinkedList::setValue(unsigned int value)
{
  _value = value;
}