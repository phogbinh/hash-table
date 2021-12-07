#include "../inc/LinkedList.h"
#include "../inc/HashTable.h"

#define MODULO (unsigned int)(1E9 + 7)

HashTable::~HashTable() {
  for (int i = 0; i < HASH_ARRAY_LENGTH; ++i) deleteRecursively(_rootParentNodes[i]);
}

void HashTable::deleteRecursively(LinkedList* p) {
  if (p == nullptr) return;
  deleteRecursively(p->getNextPtr());
  delete p;
}

HashTable::HashTable() {
  for (int i = 0; i < HASH_ARRAY_LENGTH; ++i) _rootParentNodes[i] = new LinkedList(nullptr);
}

void HashTable::observe(const std::string& key) {
  LinkedList* parentNodePtr = getParentNodePtr(key);
  if (parentNodePtr->getNextPtr() == nullptr) parentNodePtr->setNextPtr(new LinkedList({key, 1}, nullptr));
  else parentNodePtr->getNextPtr()->incrementCount();
}

unsigned int HashTable::getCount(const std::string& key) {
  LinkedList* parentNodePtr = getParentNodePtr(key);
  if (parentNodePtr->getNextPtr() == nullptr) return 0;
  else return parentNodePtr->getNextPtr()->getCount();
}

LinkedList* HashTable::getParentNodePtr(const std::string& key) {
  unsigned int hashCode = getHashCode(key);
  size_t hashArrayIndex = hashCode % HASH_ARRAY_LENGTH;
  LinkedList* parentNodePtr = _rootParentNodes[hashArrayIndex];
  while (1) {
    if (parentNodePtr->getNextPtr() == nullptr || parentNodePtr->getNextPtr()->is(key)) break;
    parentNodePtr = parentNodePtr->getNextPtr();
  }
  return parentNodePtr;
}

unsigned int HashTable::getHashCode(const std::string& key) const {
  unsigned int hashCode = 0;
  for (char c : key) hashCode = (hashCode + (unsigned int)c) % MODULO;
  return hashCode;
}