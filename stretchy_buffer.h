#pragma once
#include <assert.h>
#include <stddef.h>
#include "common.h"

typedef struct {
    size_t len;
    size_t cap;
    char a[0];
} Buf_Hdr;

#define buf__hdr(b) ((b) ? (Buf_Hdr *)((u8 *)(b) - offsetof(Buf_Hdr, a)) : NULL)
#define buf_fits(b, n) (((buf_len(b)+n) < buf_cap(b)))
#define buf__fit(b, n) (buf_fits((b), n) ? 0 : ((b) = buf__grow((b), (buf_len(b)+(n)), buf_cap(b), sizeof(*(b)))))

#define buf_len(b) ((b) ? buf__hdr(b)->len : 0)
#define buf_cap(b) ((b) ? buf__hdr(b)->cap : 0)

#define buf_push(b, x) (buf__fit((b), 1), (b)[buf__hdr(b)->len++] = (x))
#define buf_free(b) ((b) ? free(buf__hdr(b)), (b) = NULL : 0)

void *buf__grow(void *prev, size_t wanted_cap, size_t prev_cap, size_t elem_size);
void buf_test();
