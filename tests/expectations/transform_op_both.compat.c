#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct StylePoint_i32 {
  int32_t x;
  int32_t y;
} StylePoint_i32;

typedef struct StylePoint_f32 {
  float x;
  float y;
} StylePoint_f32;

enum StyleFoo_i32_Tag
#ifdef __cplusplus
  : uint8_t
#endif // __cplusplus
 {
  Foo_i32,
  Bar_i32,
  Baz_i32,
  Bazz_i32,
};
#ifndef __cplusplus
typedef uint8_t StyleFoo_i32_Tag;
#endif // __cplusplus

typedef struct StyleFoo_Body_i32 {
  StyleFoo_i32_Tag tag;
  int32_t x;
  struct StylePoint_i32 y;
  struct StylePoint_f32 z;
} StyleFoo_Body_i32;

typedef union StyleFoo_i32 {
  StyleFoo_i32_Tag tag;
  StyleFoo_Body_i32 foo;
  struct {
    StyleFoo_i32_Tag bar_tag;
    int32_t bar;
  };
  struct {
    StyleFoo_i32_Tag baz_tag;
    struct StylePoint_i32 baz;
  };
} StyleFoo_i32;

typedef enum StyleBar_i32_Tag {
  Bar1_i32,
  Bar2_i32,
  Bar3_i32,
  Bar4_i32,
} StyleBar_i32_Tag;

typedef struct StyleBar1_Body_i32 {
  int32_t x;
  struct StylePoint_i32 y;
  struct StylePoint_f32 z;
  int32_t (*u)(int32_t);
} StyleBar1_Body_i32;

typedef struct StyleBar_i32 {
  StyleBar_i32_Tag tag;
  union {
    StyleBar1_Body_i32 bar1;
    struct {
      int32_t bar2;
    };
    struct {
      struct StylePoint_i32 bar3;
    };
  };
} StyleBar_i32;

typedef struct StylePoint_u32 {
  uint32_t x;
  uint32_t y;
} StylePoint_u32;

typedef enum StyleBar_u32_Tag {
  Bar1_u32,
  Bar2_u32,
  Bar3_u32,
  Bar4_u32,
} StyleBar_u32_Tag;

typedef struct StyleBar1_Body_u32 {
  int32_t x;
  struct StylePoint_u32 y;
  struct StylePoint_f32 z;
  int32_t (*u)(int32_t);
} StyleBar1_Body_u32;

typedef struct StyleBar_u32 {
  StyleBar_u32_Tag tag;
  union {
    StyleBar1_Body_u32 bar1;
    struct {
      uint32_t bar2;
    };
    struct {
      struct StylePoint_u32 bar3;
    };
  };
} StyleBar_u32;

enum StyleBaz_Tag
#ifdef __cplusplus
  : uint8_t
#endif // __cplusplus
 {
  Baz1,
  Baz2,
  Baz3,
};
#ifndef __cplusplus
typedef uint8_t StyleBaz_Tag;
#endif // __cplusplus

typedef union StyleBaz {
  StyleBaz_Tag tag;
  struct {
    StyleBaz_Tag baz1_tag;
    struct StyleBar_u32 baz1;
  };
  struct {
    StyleBaz_Tag baz2_tag;
    struct StylePoint_i32 baz2;
  };
} StyleBaz;

enum StyleTaz_Tag
#ifdef __cplusplus
  : uint8_t
#endif // __cplusplus
 {
  Taz1,
  Taz2,
  Taz3,
};
#ifndef __cplusplus
typedef uint8_t StyleTaz_Tag;
#endif // __cplusplus

typedef struct StyleTaz {
  StyleTaz_Tag tag;
  union {
    struct {
      struct StyleBar_u32 taz1;
    };
    struct {
      union StyleBaz taz2;
    };
  };
} StyleTaz;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void foo(const union StyleFoo_i32 *foo,
         const struct StyleBar_i32 *bar,
         const union StyleBaz *baz,
         const struct StyleTaz *taz);

#ifdef __cplusplus
}  // extern "C"
#endif  // __cplusplus
