#include "division.h"

int divide(const int dividend, const int divisor) {
    if (dividend < 0) {
        return (-1)*divide(-dividend, divisor);
    }
    if (divisor < 0) {
        return (-1)*divide(dividend, -divisor);
    }
    if (divisor == 0) {
        // std::cout<<"You can't divide by zero\n";
        // 0 for simplicity
        return 0;
    }
    if (dividend == divisor) {
        return 1;
    }
    if (divisor == 1) {
        return dividend;
    }
    if (dividend < divisor) {
        return 0;
    } else {
        return make_division(dividend, divisor);
    }
}

int make_division(int dividend, int divisor) {
    int remainder = 0, quotient = 0;
    int old_dividend = 0;

    int num_bits = 32;
    //finding first remainder for division
    while (remainder < divisor) {
        int left_bit = (dividend & 0x80000000) >> 31;
        remainder = (remainder << 1) | left_bit;
        old_dividend = dividend;
        dividend = dividend << 1;
        num_bits--;
    }

    dividend = old_dividend;
    remainder = remainder >> 1;
    num_bits++;

    for (int i = 0; i < num_bits; i++) {
        int left_bit = (dividend & 0x80000000) >> 31;
        remainder = (remainder << 1) | left_bit;
        int tmp_q = remainder - divisor;
        int tmp_q_reversed_sign = !((tmp_q & 0x80000000) >> 31);
        dividend = dividend << 1;
        quotient = (quotient << 1) | tmp_q_reversed_sign;
        if (tmp_q_reversed_sign) {
            remainder = tmp_q;
        }
    }

  return quotient;
}