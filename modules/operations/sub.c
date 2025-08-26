whole_number_calc_result_t sub_operation(uint64_t* values, int count) {
 
    // basic safety check to prevent running the op if there aren't enough
    // items in the values array 
    int MIN_VALUES = 2;

    check_array_length(MIN_VALUES, count);

    whole_number_calc_result_t result;

    result.is_negative = false;

    uint64_t total_to_sub = 0;

    for (int i = 1; i < count; i++) {
        // underflow defense 
        if ( total_to_sub > UINT64_MAX - values[i] ) {
            error_fail("Subtraction underflow");
        } else {
            total_to_sub += values[i];
        }
    }

    // safety check to make sure we won't overflow the integer
    //  (since we're working with possibly-negative values)

    if (values[0] < total_to_sub) {

        printf("WARNING: The total value subtracted is lesser"
                " than the initial value so the result is coming"
                " out negative - this shouldn't typically be"
                " possible in most places where you'd do hex math,"
                " are you sure you got this right?\n");

        result.signed_val = (int64_t)values[0] - (int64_t)total_to_sub;
        result.is_negative = true;

    } else {
        result.unsigned_val = values[0] - total_to_sub;
        result.is_negative = false;
    }

    if (result.is_negative) {
        printf("RESULT: %ld | 0x%lx\n", result.signed_val, (uint64_t)result.signed_val);
    } else {
        printf("RESULT: %lu | 0x%lx\n", result.unsigned_val, result.unsigned_val);
    }

    return result;

}
