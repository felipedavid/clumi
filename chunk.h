#pragma once
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} Opcode;

typedef struct {
    u8 *code;
    Value *data;
} Chunk;
