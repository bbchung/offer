#include <stdio.h>

int swap_odd_even_bits(int i)
{
    int odd_mask = 0x55555555; 
    int even_mask = 0xAAAAAAAA;

    int odd_result = (i & odd_mask) << 1;
    printf("%x\n", odd_result);
    int even_result = (unsigned int)(i&even_mask) >> 1;
    printf("%x\n", even_result);

    return odd_result | even_result;
}

int main()
{
    int a = swap_odd_even_bits(0x40000000);
    printf("%x\n", a);
}
