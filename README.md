# EmeraldsVector

A fast single file dynamic list with optional generics

# Installation

- Install the library

`em list`
`em install`
`em build lib release`

## Usage

- Include in a file

```c
#include "EmeraldsVector.h"

int main(void) {
  /* Create a new vector object */
  int **v = vector_new(1);

  vector_add(v, 2);
  vector_add(v, 3);

  printf("%d\n", v[1]);
  printf("%d\n", v[0]);
}
```

## Contributing

1. Fork it (<https://github.com/The-Fourth-Wall/EmeraldsVector/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
