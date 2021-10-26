#include "HashMap.h"
#include "LinkedList.h"

HashMap::HashMap()
{
  for (int i = 0; i < HASH_ARRAY_LENGTH; ++i) _hashArray[i] = nullptr;
}

void HashMap::observe(const string& key)
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

unsigned int HashMap::getCount(const string& key)
{
  LinkedList* pairsPtr =  getLinkedList(key);
  while (pairsPtr != nullptr)
  {
    if (pairsPtr->key() == key) return pairsPtr->value();
    pairsPtr = pairsPtr->next();
  }
  // key not exist, return 0
  return 0;
}

LinkedList*& HashMap::getLinkedList(const string& key)
{
  return _hashArray[getHashArrayIndex(key)];
}

size_t HashMap::getHashArrayIndex(const string& key)
{
  return getHashCode(key) % HASH_ARRAY_LENGTH;
}

unsigned int HashMap::getHashCode(const string& key)
{
  unsigned int result = 0;
  for (auto character : key) result += character;
  return result;
}

void HashMap::addNode(LinkedList*& pairsPtr, const string& key)
{
  pairsPtr = new LinkedList(key, 1, nullptr);
}
