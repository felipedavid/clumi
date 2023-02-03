#include "common.h"
#include "stretchy_buffer.h"
#include "instr.h"
#include "debug.h"

int main(int argc, char** argv) {
    buf_test();

    u8 *code = NULL;
    buf_push(code, OP_RETURN);
    disassemble(code, "test");
}
