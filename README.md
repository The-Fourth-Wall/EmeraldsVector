# Vector

A dynamic list using fast memory management (golden ratio increase)

# Installation

* Install the library

`em list`
`em install`
`em build lib`

## Usage

* Include in a file

`touch test.c`
```c
#include "export/Vector.h"
int main(void) {
    /* Create a new vector object */
    vector *v = vector_new();

    /* Add a void* value into the vector */
    vector_add(v, (void*)1);
    vector_add(v, (void*)"value"); /* Can hold heterogenous data */

    printf("%s\n", (char*)vector_get(v, 1));
    printf("%d\n", (long)vector_get(v, 0));
}
```

* Compile

`clang test.c export/Vector.so`

## Development

* Figure out word size of machine for correct conversions

## Contributing

1. Fork it (<https://github.com/Oblivious-Oblivious/Vector/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Contributors

- [Oblivious](https://github.com/Oblivious-Oblivious) - creator and maintainer
