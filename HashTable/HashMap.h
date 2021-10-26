#include <string>

using namespace std;

#define HASH_ARRAY_LENGTH 100

class LinkedList;
class HashMap
{
public:
  HashMap();
  void observe(const string& key);
  unsigned int getCount(const string& key);
private:
  LinkedList*& getLinkedList(const string& key);
  size_t getHashArrayIndex(const string& key);
  unsigned int getHashCode(const string& key);
  void addNode(LinkedList*& pairsPtr, const string& key);
private:
  LinkedList* _hashArray[HASH_ARRAY_LENGTH];
};
