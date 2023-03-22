#include <stdio.h>
#include <assert.h>
#include "elephant.h"
#include "check-elephant.h"
#include <stdlib.h>
#include <string.h>

int main(void) {
  Elephant *elephant= new_elephant("Elvira", AFRICAN, 28673, 7821, 9.3f);

  assert(strcmp(elephant->name, "Elvira") == 0);

  printf("All assertions passed!\n");
  return 0;
}