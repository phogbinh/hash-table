#include <string>

class LinkedList {
public:
  LinkedList(LinkedList* const nextPtr);
  LinkedList(const std::pair<std::string, unsigned int>& value, LinkedList* const nextPtr);
  void setNextPtr(LinkedList* const nextPtr);
  void incrementCount();
  bool is(const std::string& key) const;
  unsigned int getCount() const;
  LinkedList* getNextPtr() const;
private:
  std::pair<std::string, unsigned int> _value;
  LinkedList* _nextPtr = nullptr;
};