#include "stdio.h"
#include "HashMap.h"

int main()
{
  HashMap hashMap;
  hashMap.observe("Vagina");
  hashMap.observe("Potato");
  hashMap.observe("Vagina");
  printf("%d", hashMap.getCount("Vagina")); // 2
  printf("%d", hashMap.getCount("Potato")); // 1
  printf("%d", hashMap.getCount("Hello")); // 0
  return 0;
}
