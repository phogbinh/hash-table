#include "HashMap.h"
#include "LinkedList.h"

HashMap::HashMap()
{
  for (int i = 0; i < HASH_ARRAY_LENGTH; ++i) _hashArray[i] = nullptr;
}

void HashMap::observe(string key)
{
  LinkedList*& pairsPtr = getLinkedList(key);
  while (pairsPtr != nullptr)
  {
    if (pairsPtr->key() == key)
    {
      pairsPtr->setValue(pairsPtr->value() + 1);
      return;
    }
    pairsPtr = pairsPtr->next();
  }
  // key not exist, add it!
  addNode(pairsPtr, key);
}

unsigned int HashMap::getCount(string key)
{
  LinkedList* pairsPtr =  getLinkedList(key);
  while (pairsPtr != nullptr)
  {
    if (pairsPtr->key() == key) return pairsPtr->value();
    pairsPtr = pairsPtr->next();
  }
  // key not exist, return -1
  return -1;
}

LinkedList*& HashMap::getLinkedList(string key)
{
  return _hashArray[getHashArrayIndex(key)];
}

size_t HashMap::getHashArrayIndex(string key)
{
  return getHashCode(key) % HASH_ARRAY_LENGTH;
}

unsigned int HashMap::getHashCode(string key)
{
  unsigned int result = 0;
  for (auto character : key) result += character;
  return result;
}

void HashMap::addNode(LinkedList*& pairsPtr, string key)
{
  pairsPtr = new LinkedList(key, 0, nullptr);
}
