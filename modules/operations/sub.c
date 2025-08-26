whole_number_calc_result_t sub_operation(uint64_t* values, int count) {
    
    // Debug statement 
    printf("Subtraction underway");
    
    uint64_t total_to_sub = 0;

    for (int i = 1; i < count; i++) { 
        total_to_sub += values[i];
    }

    // safety check to make sure we won't underflow the buffer

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
    }

    printf("RESULT HEX: %ld\n", result);
    printf("RESULT DEC: %d\n", result);
    

}
