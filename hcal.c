// Include stdlib
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Include modules
#include "modules/utils.c"
#include "modules/types.c"
#include "modules/get_args.c"
#include "modules/operations/sub.c"
#include "modules/operations/add.c"
#include "modules/operations/xor.c"
#include "modules/operations/mult.c"
#include "modules/operations/div.c"



int main(int argc, char *argv[]) {

    parsed_args_t parsed_args = parse_args(argc, argv);

    // Run operations

    switch(parsed_args.op) {
        case OP_SUB:
            sub_operation(parsed_args.values, parsed_args.count);
            break;
        case OP_ADD:
            add_operation(parsed_args.values, parsed_args.count);
            break;
        case OP_XOR:
            xor_operation(parsed_args.values, parsed_args.count);
            break;
        case OP_MULT:
            mult_operation(parsed_args.values, parsed_args.count);
            break;
        case OP_DIV: 
            div_operation(parsed_args.values, parsed_args.count);
            break;
    }

}
