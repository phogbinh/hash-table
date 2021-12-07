#include <string>

#define HASH_ARRAY_LENGTH 100

class LinkedList;
class HashTable {
public:
  ~HashTable();
  HashTable();
  void observe(const std::string& key);
  unsigned int getCount(const std::string& key);
private:
  void deleteRecursively(LinkedList* p);
  LinkedList* getParentNodePtr(const std::string& key);
  unsigned int getHashCode(const std::string& key) const;
private:
  LinkedList* _rootParentNodes[HASH_ARRAY_LENGTH];
};