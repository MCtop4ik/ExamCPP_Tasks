#include <iostream>
#include <assert.h>

int main() {

  History h;

  h = h + 10;
  h = h + 20;
  h = h + 30;
  
  assert(h.current() == 30);
  assert(h.steps() == 3);

  h = h.undo();

  assert(h.current() == 20);
  assert(h.steps() == 2);

  h = h.undo();

  assert(h.current() == 10);

  h = h.redo();

  assert(h.current() == 20);

  h = h + 40;

  assert(h.current() == 40);
  assert(h.steps() == 3);
}