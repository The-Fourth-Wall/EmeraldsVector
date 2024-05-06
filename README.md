# EmeraldsVector

A dynamic list using fast memory management (golden ratio increase)

# Installation

- Install the library

`em list`
`em install`
`em build lib`

## Usage

- Include in a file

```c
#include "EmeraldsVector.h"

int main(void) {
  /* Create a new vector object */
  EmeraldsVector *v = vector_new();

  /* Add a void* value into the vector */
  vector_add(v, (void*)1);
  vector_add(v, (void*)"value"); /* Can hold heterogenous data */

  printf("%s\n", (char*)vector_get(v, 1));
  printf("%d\n", (long)vector_get(v, 0));
}
```

## Development

- Provide a custom free function pointer for specific deallocations
  (also to set a framework for an efficient garbage collector)
- Figure out word size of machine for correct conversions

## Contributing

1. Fork it (<https://github.com/Oblivious-Oblivious/EmeraldsVector/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
