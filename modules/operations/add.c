whole_number_calc_result_t add_operation(uint64_t* values, int count) {

    // safety check to make sure we have enough values in the array 
    int MIN_VALUES = 2;
    check_array_length(MIN_VALUES, count);

    whole_number_calc_result_t result;

    result.unsigned_val = 0;
    result.is_negative = false;

    uint64_t total = values[0];
    uint64_t total_to_add = 0;

    for (int i = 1; i < count; i++) {
        if ( total_to_add > UINT64_MAX - values[i]) {
            // defense against overflow
            error_fail("Addition overflow detected");
        } else {
            total_to_add += values[i];
        }
    }

    if ( total > UINT64_MAX - total_to_add ) {
        // more defense against overflow
        error_fail("Addition overflow detected");
    } else {
        result.unsigned_val = total_to_add + total;
    }

    printf("RESULT: %lu | 0x%lx\n", result.unsigned_val, result.unsigned_val);
    return result;

}
