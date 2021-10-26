#include <string>

using namespace std;

class LinkedList
{
public:
  LinkedList(const string& key, unsigned int value, LinkedList* nextPtr);
  const string& key();
  const unsigned int& value();
  LinkedList* const next();
  void setValue(unsigned int value);
private:
  string _key;
  unsigned int _value = 0;
  LinkedList* _nextPtr = nullptr;
};
