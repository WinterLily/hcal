#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_OPERATIONS (sizeof(operations)) / (sizeof(operations[0]))

char* USAGE_ERROR=
"Usage: hcal <operation> []<values>\n"
"\n"
"Operations: \n"
"    add     -   add two or more hex values together \n"
"    sub     -   subtract one or more hex values from each other \n"
"    div     -   divide one or more hex values by one another \n"
"    mul     -   multiply two or more hex values together \n"
"    ascii   -   ascii representation of given hex(s)s\n";

// enum for viable operation args s
typedef enum {
    OP_ADD,
    OP_SUB,
    OP_DIV,
    OP_MULT,
    OP_XOR,
    OP_ASCII
} operation_t;

// struct for parsed args
typedef struct {
    operation_t op;
    uint64_t *values; // number of input hex values
    int count;        // number of values
} parsed_args_t;

// operation to input mapping
struct op_mapping {
    char* name;
    operation_t op;
} operations[] = {
    {"add",     OP_ADD},
    {"sub",     OP_SUB},
    {"div",     OP_DIV},
    {"mult",    OP_MULT},
    {"xor",     OP_XOR},
    {"ascii",   OP_ASCII}
};

// map of operation enums to strings for easier reverse lookups
char* operation_names[] = {
    [OP_ADD] = "add",
    [OP_SUB] = "sub",
    [OP_DIV] = "div",
    [OP_MULT] = "mult",
    [OP_XOR] = "xor",
    [OP_ASCII] = "ascii"
};

// print usage error and fail
int error_fail(char* error_message) {
    printf("ERROR - %s\n", error_message);
    printf("%s", USAGE_ERROR);
    exit(1);
}

// main arg parser
parsed_args_t parse_args(int argc, char *argv[]) {

    parsed_args_t result;

    // check if we have enough args
    if ( argc < 2 ) {
        error_fail("Must have at least 2 arguments (operation + value) to run, most operations need 3");
    }

    bool found_operation = false;

    // parse operation argument
    for (int i = 0; i < NUM_OPERATIONS; i++) {
        if (strcmp(argv[1], operations[i].name) ==0) {
            result.op = operations[i].op;
            found_operation = true;
            break;
        }
    }

    // check if operation was valid
    if ( found_operation == false ) {
        error_fail("Invalid operation");
    }

    // get the rest of the args and allocate buffer
    int num_values = argc - 2;
    result.values = malloc(num_values * sizeof(uint64_t));
    result.count = num_values;

    for (int i = 2 ; i < argc ; i++) {
        uint64_t value = strtoull(argv[i], NULL, 16);
        result.values[i-2] = value;
    }

    return result;

}
