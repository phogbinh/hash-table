#include "stdio.h"
#include "HashMap.h"

int main()
{
  HashMap hashMap;
  hashMap.observe("Vagina");
  hashMap.observe("Potato");
  hashMap.observe("Vagina");
  printf("%d\n", hashMap.getCount("Vagina")); // 2
  printf("%d\n", hashMap.getCount("Potato")); // 1
  printf("%d\n", hashMap.getCount("Hello")); // 0
  return 0;
}
