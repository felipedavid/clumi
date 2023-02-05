#include "instr.h"

inline int add_const(Chunk *chunk, Value value) {
    buf_push(chunk.data, value);
    return buf_len(chunk.data) - 1;
}
