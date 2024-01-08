#include <stdio.h>
int main(void)
{
    char* string = "HELLO? this %d in static string is useless in formatted string.\n";
    printf("%s", string);
    return 0;
}
