#include "modules/types.c"
#include "modules/get_args.c"
#include "modules/operations/sub.c"

int main(int argc, char *argv[]) {

    parsed_args_t parsed_args = parse_args(argc, argv);

    
    // For debugging, remove later 
    for (int i = 0; i < parsed_args.count; i++) {
        printf("Value: %d: 0x%lx\n", i, parsed_args.values[i]);
    }

    printf("Operation: %s\n", operation_names[parsed_args.op]);

    // Run operations 
    
    switch(parsed_args.op) { 
        case OP_SUB: 
            sub_operation(parsed_args.values, parsed_args.count);
            break;
    }



}
