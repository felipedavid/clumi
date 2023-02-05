#include "common.h"
#include "stretchy_buffer.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, char** argv) {
    buf_test();

    Chunk chunk = {0};
    int constant = add_const(chunk.data, 234.5);
    buf_push(chunk.code, OP_CONSTANT);
    buf_push(chunk.code, constant);
}
