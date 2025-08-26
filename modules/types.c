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

// union for whole number arithmetic operations
typedef struct {
    union {
        int64_t signed_val;
        uint64_t unsigned_val;
    };
    bool is_negative;
} whole_number_calc_result_t;

