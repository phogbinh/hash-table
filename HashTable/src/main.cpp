#include "../inc/HashTable.h"

int main() {
  HashTable hashTable;
  hashTable.observe("Potato");
  hashTable.observe("Vagina");
  hashTable.observe("Vagina");
  hashTable.observe("anigaV");
  printf("%d\n", hashTable.getCount("Potato")); // 1
  printf("%d\n", hashTable.getCount("otatoP")); // 0
  printf("%d\n", hashTable.getCount("Vagina")); // 2
  printf("%d\n", hashTable.getCount("anigaV")); // 1
  return 0;
}