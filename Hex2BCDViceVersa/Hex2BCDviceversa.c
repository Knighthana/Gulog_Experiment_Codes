/* 
    Auth: Kngihthan
    Date: 2023 Jul. 28th
    Name: Hex2BCD Vice Versa
    Usage:
        Hex to 8421BCD
        und
        8421BCD to Hex
    Notice:
        all inputs and outputs are asserted as Hexadecimal
*/

#include <stdio.h>

/* 自然数的指数函数 */
unsigned int uintpow(unsigned int base, unsigned int exponent)
{
    unsigned int output = 1;
    if(base == 0){
        return 0;
    }
    if(exponent == 0){
        return 1;
    }
    for(;exponent>0; exponent--){
        output *= base;
    }
    return output;
}

unsigned int hex2bcd(unsigned int input);

unsigned int bcd2hex(unsigned int input);

int main(int argc, char* argv[])
{
    unsigned int input;
    printf("Choose 1.Hex to BCD or \n2.BCD to Hex:");
    scanf("%u", &input);
    switch(input)
    {
        case(1):
            scanf("%x", &input);
            printf("hex %#x to BCD is %#x\n", input, hex2bcd(input));
            break;
        case(2):
            scanf("%x", &input);
            printf("BCD %#x to hex is %#x\n", input, bcd2hex(input));
            break;
        default:
            break;
    }
    return 0;
}

unsigned int hex2bcd(unsigned int input)
{
    int i;
    unsigned int bit = 0, output = 0;
    for(i=0; input>0; i++){
        bit = input % 10;
        output += bit * uintpow(0x10, i);
        input /= 10;
    }
    return output;
}

unsigned int bcd2hex(unsigned int input)
{
    int i;
    unsigned int bit = 0, output = 0;
    for(i=0; input>0; i++){
        bit = input % 0x10;
        output += bit * uintpow(10, i);
        input /= 0x10;
    }
    return output;
}
