whole_number_calc_result_t xor_operation(uint64_t* values, int count) {

    // sanity check for number of values 
    int MIN_VALUES = 2;
    check_array_length(MIN_VALUES, count);

    whole_number_calc_result_t result;

    result.unsigned_val = values[0];
    result.is_negative = false;

    for (int i = 1; i < count; i++) {
        result.unsigned_val ^= values[i];
    }

    printf("RESULT: %lu | 0x%lx\n", result.unsigned_val, result.unsigned_val);
    return result;

}
