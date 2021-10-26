#include <string>

using namespace std;

#define HASH_ARRAY_LENGTH 100

class LinkedList;
class HashMap
{
public:
  HashMap();
  void observe(string key);
  unsigned int getCount(string key);
private:
  LinkedList*& getLinkedList(string key);
  size_t getHashArrayIndex(string key);
  unsigned int getHashCode(string key);
  void addNode(LinkedList*& pairsPtr, string key);
private:
  LinkedList* _hashArray[HASH_ARRAY_LENGTH];
};
