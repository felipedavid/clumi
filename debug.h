#pragma once
#include "common.h"
#include "stretchy_buffer.h"
#include "instr.h"

void disassemble(u8 *code, const char *name);
int disassemble_instr(u8 *code, int offset);
