char* USAGE_ERROR=
"Usage: hcal <operation> []<values>\n"
"\n"
"Operations: \n"
"    add     -   add two or more hex values together \n"
"    sub     -   subtract one or more hex values from each other \n"
"    div     -   divide one or more hex values by one another \n"
"    mul     -   multiply two or more hex values together \n"
"    ascii   -   ascii representation of given hex(s)s\n";


// print usage error and fail
int error_fail(char* error_message) {
    printf("ERROR - %s\n", error_message);
    printf("%s", USAGE_ERROR);
    exit(1);
}

// check if a given value array is long enough
bool check_array_length(int min_values, int count) {

    char message[64];

    if ( count < min_values ) { 
            snprintf(message, sizeof(message), "This operation requires at least %d values.", min_values);
            error_fail(message);
    }
}


