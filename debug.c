#include "debug.h"

void disassemble(u8 *code, const char *name) {
    printf("== %s ==\n", name);
    for (int offset = 0; offset < buf_len(code);) {
        offset = disassemble_instr(code, offset);
    }
}

int disassemble_instr(u8 *code, int offset) {
    printf("%04d ", offset);

    u8 instr = code[offset];
    switch (instr) {
    case OP_CONSTANT:
    case OP_RETURN:
        printf("OP_RETURN\n");
        return offset+1;
    default:
        printf("Unknown opcode %d\n", instr);
        return offset+1;
    }
}
