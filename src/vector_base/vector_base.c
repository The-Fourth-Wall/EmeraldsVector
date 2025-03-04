#include "../EmeraldsVector.h"

void *
_vector_growf(void *self, size_t elemsize, size_t addlen, size_t min_cap) {
  void *b;
  size_t min_len = vector_size(self) + addlen;

  if(min_len > min_cap) {
    min_cap = min_len;
  }

  if(min_cap <= vector_capacity(self)) {
    return self;
  }

  if(min_cap < 2 * vector_capacity(self)) {
    min_cap = 2 * vector_capacity(self);
  } else if(min_cap < 4) {
    min_cap = 4;
  }

  b = vector_allocator(
    (self) ? _vector_get_header(self) : 0,
    elemsize * min_cap + sizeof(_vector_header)
  );
  b = (char *)b + sizeof(_vector_header);

  if(self == NULL) {
    _vector_get_header(b)->size = 0;
  }

  _vector_get_header(b)->capacity = min_cap;

  return b;
}
