#ifndef __EMERALDS_VECTOR_BASE_H_
#define __EMERALDS_VECTOR_BASE_H_

#include <stdarg.h> /* va_list, va_arg, va_start, va_end */
#include <stddef.h> /* ptrdiff_t */
#include <stdlib.h> /* NULL, realloc */
#include <string.h> /* memmove */

#define VECTOR_PP_256TH_ARG( \
  _1,                        \
  _2,                        \
  _3,                        \
  _4,                        \
  _5,                        \
  _6,                        \
  _7,                        \
  _8,                        \
  _9,                        \
  _10,                       \
  _11,                       \
  _12,                       \
  _13,                       \
  _14,                       \
  _15,                       \
  _16,                       \
  _17,                       \
  _18,                       \
  _19,                       \
  _20,                       \
  _21,                       \
  _22,                       \
  _23,                       \
  _24,                       \
  _25,                       \
  _26,                       \
  _27,                       \
  _28,                       \
  _29,                       \
  _30,                       \
  _31,                       \
  _32,                       \
  _33,                       \
  _34,                       \
  _35,                       \
  _36,                       \
  _37,                       \
  _38,                       \
  _39,                       \
  _40,                       \
  _41,                       \
  _42,                       \
  _43,                       \
  _44,                       \
  _45,                       \
  _46,                       \
  _47,                       \
  _48,                       \
  _49,                       \
  _50,                       \
  _51,                       \
  _52,                       \
  _53,                       \
  _54,                       \
  _55,                       \
  _56,                       \
  _57,                       \
  _58,                       \
  _59,                       \
  _60,                       \
  _61,                       \
  _62,                       \
  _63,                       \
  _64,                       \
  _65,                       \
  _66,                       \
  _67,                       \
  _68,                       \
  _69,                       \
  _70,                       \
  _71,                       \
  _72,                       \
  _73,                       \
  _74,                       \
  _75,                       \
  _76,                       \
  _77,                       \
  _78,                       \
  _79,                       \
  _80,                       \
  _81,                       \
  _82,                       \
  _83,                       \
  _84,                       \
  _85,                       \
  _86,                       \
  _87,                       \
  _88,                       \
  _89,                       \
  _90,                       \
  _91,                       \
  _92,                       \
  _93,                       \
  _94,                       \
  _95,                       \
  _96,                       \
  _97,                       \
  _98,                       \
  _99,                       \
  _100,                      \
  _101,                      \
  _102,                      \
  _103,                      \
  _104,                      \
  _105,                      \
  _106,                      \
  _107,                      \
  _108,                      \
  _109,                      \
  _110,                      \
  _111,                      \
  _112,                      \
  _113,                      \
  _114,                      \
  _115,                      \
  _116,                      \
  _117,                      \
  _118,                      \
  _119,                      \
  _120,                      \
  _121,                      \
  _122,                      \
  _123,                      \
  _124,                      \
  _125,                      \
  _126,                      \
  _127,                      \
  _128,                      \
  _129,                      \
  _130,                      \
  _131,                      \
  _132,                      \
  _133,                      \
  _134,                      \
  _135,                      \
  _136,                      \
  _137,                      \
  _138,                      \
  _139,                      \
  _140,                      \
  _141,                      \
  _142,                      \
  _143,                      \
  _144,                      \
  _145,                      \
  _146,                      \
  _147,                      \
  _148,                      \
  _149,                      \
  _150,                      \
  _151,                      \
  _152,                      \
  _153,                      \
  _154,                      \
  _155,                      \
  _156,                      \
  _157,                      \
  _158,                      \
  _159,                      \
  _160,                      \
  _161,                      \
  _162,                      \
  _163,                      \
  _164,                      \
  _165,                      \
  _166,                      \
  _167,                      \
  _168,                      \
  _169,                      \
  _170,                      \
  _171,                      \
  _172,                      \
  _173,                      \
  _174,                      \
  _175,                      \
  _176,                      \
  _177,                      \
  _178,                      \
  _179,                      \
  _180,                      \
  _181,                      \
  _182,                      \
  _183,                      \
  _184,                      \
  _185,                      \
  _186,                      \
  _187,                      \
  _188,                      \
  _189,                      \
  _190,                      \
  _191,                      \
  _192,                      \
  _193,                      \
  _194,                      \
  _195,                      \
  _196,                      \
  _197,                      \
  _198,                      \
  _199,                      \
  _200,                      \
  _201,                      \
  _202,                      \
  _203,                      \
  _204,                      \
  _205,                      \
  _206,                      \
  _207,                      \
  _208,                      \
  _209,                      \
  _210,                      \
  _211,                      \
  _212,                      \
  _213,                      \
  _214,                      \
  _215,                      \
  _216,                      \
  _217,                      \
  _218,                      \
  _219,                      \
  _220,                      \
  _221,                      \
  _222,                      \
  _223,                      \
  _224,                      \
  _225,                      \
  _226,                      \
  _227,                      \
  _228,                      \
  _229,                      \
  _230,                      \
  _231,                      \
  _232,                      \
  _233,                      \
  _234,                      \
  _235,                      \
  _236,                      \
  _237,                      \
  _238,                      \
  _239,                      \
  _240,                      \
  _241,                      \
  _242,                      \
  _243,                      \
  _244,                      \
  _245,                      \
  _246,                      \
  _247,                      \
  _248,                      \
  _249,                      \
  _250,                      \
  _251,                      \
  _252,                      \
  _253,                      \
  _254,                      \
  _255,                      \
  _256,                      \
  _257,                      \
  _258,                      \
  _259,                      \
  _260,                      \
  _261,                      \
  _262,                      \
  _263,                      \
  _264,                      \
  _265,                      \
  _266,                      \
  _267,                      \
  _268,                      \
  _269,                      \
  _270,                      \
  _271,                      \
  _272,                      \
  _273,                      \
  _274,                      \
  _275,                      \
  _276,                      \
  _277,                      \
  _278,                      \
  _279,                      \
  _280,                      \
  _281,                      \
  _282,                      \
  _283,                      \
  _284,                      \
  _285,                      \
  _286,                      \
  _287,                      \
  _288,                      \
  _289,                      \
  _290,                      \
  _291,                      \
  _292,                      \
  _293,                      \
  _294,                      \
  _295,                      \
  _296,                      \
  _297,                      \
  _298,                      \
  _299,                      \
  _300,                      \
  _301,                      \
  _302,                      \
  _303,                      \
  _304,                      \
  _305,                      \
  _306,                      \
  _307,                      \
  _308,                      \
  _309,                      \
  _310,                      \
  _311,                      \
  _312,                      \
  _313,                      \
  _314,                      \
  _315,                      \
  _316,                      \
  _317,                      \
  _318,                      \
  _319,                      \
  _320,                      \
  _321,                      \
  _322,                      \
  _323,                      \
  _324,                      \
  _325,                      \
  _326,                      \
  _327,                      \
  _328,                      \
  _329,                      \
  _330,                      \
  _331,                      \
  _332,                      \
  _333,                      \
  _334,                      \
  _335,                      \
  _336,                      \
  _337,                      \
  _338,                      \
  _339,                      \
  _340,                      \
  _341,                      \
  _342,                      \
  _343,                      \
  _344,                      \
  _345,                      \
  _346,                      \
  _347,                      \
  _348,                      \
  _349,                      \
  _350,                      \
  _351,                      \
  _352,                      \
  _353,                      \
  _354,                      \
  _355,                      \
  _356,                      \
  _357,                      \
  _358,                      \
  _359,                      \
  _360,                      \
  _361,                      \
  _362,                      \
  _363,                      \
  _364,                      \
  _365,                      \
  _366,                      \
  _367,                      \
  _368,                      \
  _369,                      \
  _370,                      \
  _371,                      \
  _372,                      \
  _373,                      \
  _374,                      \
  _375,                      \
  _376,                      \
  _377,                      \
  _378,                      \
  _379,                      \
  _380,                      \
  _381,                      \
  _382,                      \
  _383,                      \
  _384,                      \
  _385,                      \
  _386,                      \
  _387,                      \
  _388,                      \
  _389,                      \
  _390,                      \
  _391,                      \
  _392,                      \
  _393,                      \
  _394,                      \
  _395,                      \
  _396,                      \
  _397,                      \
  _398,                      \
  _399,                      \
  _400,                      \
  _401,                      \
  _402,                      \
  _403,                      \
  _404,                      \
  _405,                      \
  _406,                      \
  _407,                      \
  _408,                      \
  _409,                      \
  _410,                      \
  _411,                      \
  _412,                      \
  _413,                      \
  _414,                      \
  _415,                      \
  _416,                      \
  _417,                      \
  _418,                      \
  _419,                      \
  _420,                      \
  _421,                      \
  _422,                      \
  _423,                      \
  _424,                      \
  _425,                      \
  _426,                      \
  _427,                      \
  _428,                      \
  _429,                      \
  _430,                      \
  _431,                      \
  _432,                      \
  _433,                      \
  _434,                      \
  _435,                      \
  _436,                      \
  _437,                      \
  _438,                      \
  _439,                      \
  _440,                      \
  _441,                      \
  _442,                      \
  _443,                      \
  _444,                      \
  _445,                      \
  _446,                      \
  _447,                      \
  _448,                      \
  _449,                      \
  _450,                      \
  _451,                      \
  _452,                      \
  _453,                      \
  _454,                      \
  _455,                      \
  _456,                      \
  _457,                      \
  _458,                      \
  _459,                      \
  _460,                      \
  _461,                      \
  _462,                      \
  _463,                      \
  _464,                      \
  _465,                      \
  _466,                      \
  _467,                      \
  _468,                      \
  _469,                      \
  _470,                      \
  _471,                      \
  _472,                      \
  _473,                      \
  _474,                      \
  _475,                      \
  _476,                      \
  _477,                      \
  _478,                      \
  _479,                      \
  _480,                      \
  _481,                      \
  _482,                      \
  _483,                      \
  _484,                      \
  _485,                      \
  _486,                      \
  _487,                      \
  _488,                      \
  _489,                      \
  _490,                      \
  _491,                      \
  _492,                      \
  _493,                      \
  _494,                      \
  _495,                      \
  _496,                      \
  _497,                      \
  _498,                      \
  _499,                      \
  _500,                      \
  _501,                      \
  _502,                      \
  _503,                      \
  _504,                      \
  _505,                      \
  _506,                      \
  _507,                      \
  _508,                      \
  _509,                      \
  _510,                      \
  _511,                      \
  _512,                      \
  N,                         \
  ...                        \
)                            \
  N
#define VECTOR_PP_RSEQ_N()                                                     \
  512, 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498,   \
    497, 496, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, \
    482, 481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, \
    467, 466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, \
    452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, \
    437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423, \
    422, 421, 420, 419, 418, 417, 416, 415, 414, 413, 412, 411, 410, 409, 408, \
    407, 406, 405, 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, \
    392, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, \
    377, 376, 375, 374, 373, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, \
    362, 361, 360, 359, 358, 357, 356, 355, 354, 353, 352, 351, 350, 349, 348, \
    347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, \
    332, 331, 330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, \
    317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, \
    302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, \
    287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, \
    272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, \
    257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, \
    242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, \
    227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, \
    212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, \
    197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, \
    182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, \
    167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, \
    152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, \
    137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, \
    122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, \
    107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92,    \
    91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74,    \
    73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56,    \
    55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38,    \
    37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20,    \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
#define VECTOR_PP_NARG_(...) VECTOR_PP_256TH_ARG(__VA_ARGS__)
#define VECTOR_PP_NARG(...)  VECTOR_PP_NARG_(__VA_ARGS__, VECTOR_PP_RSEQ_N())

typedef struct {
  size_t size;
  size_t capacity;
} _vector_header;

#define _vector_get_header(type) ((_vector_header *)(type) - 1)
#define _vector_getcapacity(self) \
  ((self) ? _vector_get_header(self)->capacity : 0)
#define _vector_selfptr_size(self) sizeof(*(self)) // NOLINT
#define _vector_grow(self, n) \
  (*(void **)&(self) =        \
     _vector_growf((self), _vector_selfptr_size(self), (n), 0))
#define _vector_maybegrow(self, n)                                             \
  ((!(self) ||                                                                 \
    _vector_get_header(self)->size + (n) > _vector_get_header(self)->capacity) \
     ? (_vector_grow(self, n), 0)                                              \
     : 0)

#ifndef vector_allocator
  #define vector_allocator realloc
#endif

/**
 * @brief Macro helper for variadic arguments
 */
#define _vector_internal_get_first_arg(first, ...) first
#define vector_new(...)                                                                                                                                                                                                                                                                 \
  _Generic(_vector_internal_get_first_arg(__VA_ARGS__), void *: _vector_internal_voidptr_new, char *: _vector_internal_charptr_new, const char *: _vector_internal_charptr_new, int: _vector_internal_int_new, long: _vector_internal_long_new, default: _vector_internal_voidptr_new)( \
    VECTOR_PP_NARG(__VA_ARGS__), __VA_ARGS__                                                                                                                                                                                                                                            \
  )

/**
 * @brief Initializes an empty vector without adding an element
 * @param self -> The vector to use
 */
#define vector_initialize(self) _vector_maybegrow(self, 1)

/**
 * @brief Adds a new element in the vector
 * @param self -> The vector to use
 * @param item -> The item to add
 **/
#define vector_add(self, item) \
  (_vector_maybegrow(self, 1), \
   (self)[_vector_get_header(self)->size++] = (item))

/**
 * @brief Adds a larger element in the vector
 * @param self -> The vector to use
 * @param item -> The item to add (usually byte sized like char*)
 * @param n -> The number with which to extend size
 */
#define vector_add_n(self, item, n)           \
  _vector_maybegrow(self, n);                 \
  memmove(self + string_size(self), item, n); \
  _vector_get_header(self)->size += n;

/** Helpers for stacks */
#define vector_push vector_add
#define vector_pop(self) \
  (_vector_get_header(self)->size--, (self)[_vector_get_header(self)->size])
#define vector_peek(self) (self)[_vector_get_header(self)->size - 1]

/**
 * @brief Set the value of a specific vector index to a new one
 * @param self -> The vector
 * @param index -> The index to set the value of
 * @param item -> The item to set the value as
 **/
#define vector_set(self, index, item) \
  (index < vector_size(self) ? (self)[index] = (item) : 0)

/**
 * @brief Get the value of a specific vector index
 * @param self -> The vector to use
 * @param index -> The index to get the value of
 * @return The value
 **/
#define vector_get(self, index) (self == NULL ? 0 : (self)[index])

/**
 * @brief Delete a multiple values from the vector
 * @param self -> The vector to use
 * @param index -> The index to start
 * @param n -> The number of elements to delete
 **/
#define vector_remove_n(self, index, number_of_elements)                 \
  (memmove(                                                              \
     &(self)[index],                                                     \
     &(self)[(index) + (number_of_elements)],                            \
     sizeof *(self) *                                                    \
       (_vector_get_header(self)->size - (number_of_elements) - (index)) \
   ),                                                                    \
   _vector_get_header(self)->size -= (number_of_elements))

/**
 * @brief Delete a specific vector value by index
 * @param self -> The vector to use
 * @param index -> The index to delete
 **/
#define vector_remove(self, index) vector_remove_n(self, index, 1)

/**
 * @brief Deletes the last element of the vector
 * @param self -> The vector to use
 **/
#define vector_remove_last(self) vector_remove((self), vector_size(self) - 1)

/**
 * @brief Finds the last element of the vector
 * @param self -> The vector to use
 */
#define vector_last(self) ((self)[_vector_get_header(self)->size - 1])

/**
 * @brief Get the total number of values inserted in the vector
 * @param self -> The vector to use
 * @return: The number of items in the vector
 **/
#define vector_size(self) ((self) ? (size_t)_vector_get_header(self)->size : 0)

/**
 * @brief Same as vector_size but returns a signed value
 * @param self -> The vector to use
 * @return: The number of items in the vector
 */
#define vector_size_signed(self) \
  ((self) ? (ptrdiff_t)_vector_get_header(self)->size : 0)

/**
 * @brief Frees the memory of the vector
 * @param self -> The vector to free
 */
#define vector_free(self)                                              \
  ((void)((self) ? vector_allocator(_vector_get_header(self), 0) : 0), \
   (self) = NULL)

/**
 * @brief Get a memory duplicate of the passed vector
 * @param self -> The vector to use
 * @param dup -> The vector to duplicate to
 **/
#define vector_dup(self, dup)                 \
  do {                                        \
    size_t vlen = vector_size(self);          \
    for(size_t i = 0; i < vlen; i++) {        \
      vector_add((dup), vector_get(self, i)); \
    }                                         \
  } while(0)

/**
 * @brief Maps all vector elements in iteration using a modifier function
 *pointer
 * @param self -> The vector to map
 * @param dup -> The new vector to map to
 * @param modifier -> The modifier function
 **/
#define vector_map(self, dup, modifier)                      \
  do {                                                       \
    size_t vlen = vector_size(self);                         \
    if((void *)(self) == (void *)(dup)) {                    \
      for(size_t i = 0; i < vlen; i++) {                     \
        vector_set((dup), i, modifier(vector_get(self, i))); \
      }                                                      \
    } else {                                                 \
      for(size_t i = 0; i < vlen; i++) {                     \
        vector_add((dup), modifier(vector_get(self, i)));    \
      }                                                      \
    }                                                        \
  } while(0)

/**
 * @brief Filters all vector elements in iteration using a filter function
 * @param self -> The vector to filter
 * @param dup -> The new vector to store results
 * @param filter -> The filter function
 **/
#define vector_filter(self, dup, filter)              \
  do {                                                \
    size_t vlen = vector_size(self);                  \
    if((void *)(self) == (void *)(dup)) {             \
      for(size_t i = 0; i < vector_size(self); i++) { \
        if(filter(vector_get(self, i))) {             \
          vector_remove((dup), i);                    \
          i--;                                        \
        }                                             \
      }                                               \
    } else {                                          \
      for(size_t i = 0; i < vlen; i++) {              \
        if(!filter(vector_get(self, i))) {            \
          vector_add((dup), vector_get(self, i));     \
        }                                             \
      }                                               \
    }                                                 \
  } while(0)

/**
 * @brief Selects vector elements according to a selector lambda
 * @param self -> The vector to select from
 * @param dup -> The new vector to store results
 * @param selector -> The selector function
 */
#define vector_select(self, dup, selector) vector_filter(self, dup, !selector)

/**
 * @brief Recudes all vector elements into a void* result using a foldl function
 * @param self -> The vector to reduce
 * @param fold -> The folding function to use
 * @param res -> The result pointer
 **/
#define vector_reduce(self, fold, res)        \
  do {                                        \
    *res        = vector_get(self, 0);        \
    size_t vlen = vector_size(self);          \
    for(size_t i = 1; i < vlen; i++) {        \
      *res = fold(*res, vector_get(self, i)); \
    }                                         \
  } while(0)

static void *
_vector_growf(void *self, size_t elemsize, size_t addlen, size_t min_cap) {
  void *b;
  size_t min_len = vector_size_signed(self) + addlen;

  if(min_len > min_cap) {
    min_cap = min_len;
  }

  if(min_cap <= _vector_getcapacity(self)) {
    return self;
  }

  if(min_cap < 2 * _vector_getcapacity(self)) {
    min_cap = 2 * _vector_getcapacity(self);
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

/**
 * @brief: Initializes a vector data structure
 * @param argc -> The number of arguments provided by the automation macro
 * @param ... -> Initialization arguments
 * @return: The newly created vector
 */
#define _vector_internal_new(type, name)                         \
  static type *_vector_internal_##name##_new(size_t argc, ...) { \
    type *self = NULL;                                           \
                                                                 \
    va_list vars;                                                \
    va_start(vars, argc)                                         \
      ;                                                          \
      for(size_t i = 0; i < argc; i++) {                         \
        vector_add(self, va_arg(vars, type));                    \
      }                                                          \
    va_end(vars);                                                \
                                                                 \
    return self;                                                 \
  }
_vector_internal_new(void *, voidptr);
_vector_internal_new(char *, charptr);
_vector_internal_new(int, int);
_vector_internal_new(long, long);

#endif
