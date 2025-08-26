#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM_OPERATIONS (sizeof(operations)) / (sizeof(operations[0]))

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
