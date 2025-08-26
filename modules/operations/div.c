whole_number_calc_result_t div_operation(uint64_t* values, int count) {

    // safety check to make sure we have enough values in the array 
    int MIN_VALUES = 2;
    check_array_length(MIN_VALUES, count);

    whole_number_calc_result_t result;

    result.unsigned_val = 0;
    result.is_negative = false;

    // hex representation is limited to ONLY representing ints, 
    // as such, in order to do division we MUST end up with ints
    // by the end.
    //
    // to do so, we'll do all our math with double longs 
    // this gives us high-precision, and then at the end we can
    // convert it back for rounding

    long double precise_result = (long double)values[0];

    for ( int i = 1; i < count; i++ ) {
        if (values[i] == 0) {
            error_fail("Division-by-zero attempted");
        }
        precise_result /= (long double)values[i];
    }

    result.unsigned_val = (uint64_t)precise_result;

    printf("RESULT: %lu | 0x%lx\n", result.unsigned_val, result.unsigned_val);
    return result;

}
