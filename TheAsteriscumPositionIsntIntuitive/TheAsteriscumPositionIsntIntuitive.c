/*
    Date: 2023/07/31
    Auth: Knighthana
    The Asteriscum symbol(*)'s position does not means like it looks like
    the symbol is only related to the variable, not the typename
*/

/*
    different machines has different requirement for the type within 'printf'
    it might be %lu, or %llu
    depending on machine
*/

#include <stdio.h>

#define Struct_d char*

typedef char* Struct_t;

int main(int argc, char* argv[])
{
    Struct_t a, b;
    Struct_d c, d;
    char* e, f;
    printf("the sizeof a is %lu, the sizeof b is %lu\n", sizeof(a), sizeof(b));
    printf("the sizeof c is %lu, the sizeof d is %lu\n", sizeof(c), sizeof(d));
    printf("the sizeof e is %lu, the sizeof f is %lu\n", sizeof(e), sizeof(f));
    return 0;
}
