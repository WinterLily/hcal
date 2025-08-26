  whole_number_calc_result_t ascii_operation(uint64_t* values, int count) {

      // basic safety check to make sure we have at least one value
      int MIN_VALUES = 1; 
      check_array_length(MIN_VALUES, count);

      whole_number_calc_result_t result;
      result.unsigned_val = 0;  
      result.is_negative = false;

      printf("RESULT: ");

      // process each 'word' by hex 
      for (int word = 0; word < count; word++) {
          uint64_t val = values[word];

          // extract bytes 
          char word_chars[8]; 
          int byte_count = 0;

          while (val > 0 && byte_count < 8) {
              word_chars[byte_count] = val & 0xFF;
              byte_count++;
              val >>= 8;  
          }

          for (int i = byte_count - 1; i >= 0; i--) {
              char c = word_chars[i];
              if (c >= 32 && c <= 126) {
                  printf("%c", c);
              } else {
                  printf("_") ;
              }
          }

          if (word < count - 1) {
              printf(" ");
          }
      }

      printf("\n");
      return result;
  }
