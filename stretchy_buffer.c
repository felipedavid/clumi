#include "stretchy_buffer.h"

void *buf__grow(void *prev, size_t wanted_cap, size_t prev_cap, size_t elem_size) {
    size_t new_cap = MAX(wanted_cap, (prev_cap * 2 + 1));
    size_t new_size = offsetof(Buf_Hdr, buf) + (new_cap * elem_size);

    Buf_Hdr *ptr;
    if (prev) {
        ptr = (Buf_Hdr *) realloc(buf__hdr(prev), new_size);
    } else {
        ptr = (Buf_Hdr *) malloc(new_size);
        ptr->len = 0;
    }
    ptr->cap = new_cap;

    return &(ptr->buf);
}

void buf_test() {
    int *ptr = 0;
    assert(buf_len(ptr) == 0);
    assert(buf_cap(ptr) == 0);

    for (int i = 0; i < 1024; i++) {
        buf_push(ptr, i);
    }
    assert(buf_len(ptr) == 1024);

    for (int i = 0; i < 1024; i++) {
        assert(ptr[i] == i);
    }

    buf_free(ptr);
    assert(buf_len(ptr) == 0);
    assert(buf_cap(ptr) == 0);
}
