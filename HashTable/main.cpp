#include "stdio.h"
#include "HashMap.h"

int main()
{
  HashMap hashMap;
  hashMap.observe("Vagina");
  hashMap.observe("Potato");
  hashMap.observe("Vagina");
  hashMap.observe("anigaV");
  printf("%d\n", hashMap.getCount("Vagina")); // 2
  printf("%d\n", hashMap.getCount("Potato")); // 1
  printf("%d\n", hashMap.getCount("Hello")); // 0
  printf("%d\n", hashMap.getCount("anigaV")); // 1
  return 0;
}
