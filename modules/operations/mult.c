whole_number_calc_result_t mult_operation(uint64_t* values, int count) {

    // safety check to make sure we have enough values in the array 
    int MIN_VALUES = 2;
    check_array_length(MIN_VALUES, count);

    whole_number_calc_result_t result;

    result.unsigned_val = values[0];
    result.is_negative = false;

    for ( int i = 1; i < count; i++ ) {
        if ( values[i] != 0 && result.unsigned_val > UINT64_MAX / values[i]) {
            // defense against overflow, but we also need to defend against 
            // division-by-zero issues
            error_fail("Multiplication overflow detected");
        } else  {
            // if values[i] = 0 we'll silently zero the entire operation, 
            // which is fine as it's mathematically accurate
            result.unsigned_val *= values[i];
        }
    }

    printf("RESULT: %lu | 0x%lx\n", result.unsigned_val, result.unsigned_val);
    return result;

}
