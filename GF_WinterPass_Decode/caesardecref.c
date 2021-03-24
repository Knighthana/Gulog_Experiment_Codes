#define STATUS int

#define MACROENDCHAR 36

/* 
 MACRO unuseful between "
*/

#include <stdio.h>
#include <stdlib.h>

STATUS caesarshift(char* , int);

int main(int argc, char* argv[])
{
	int i;
	char *input;
	input = malloc(128*sizeof(char));
	if(input == NULL) fprintf(stderr, "Not allocated.\n");
	scanf("%[^$]%*c", input);
	printf("\e[34m%s\e[0m\n",input);
	for(i=0; i<25; i++){
		caesarshift(input, 1);
		printf("\e[32m-----\e[0m\n");
		printf("%s\n", input);
	}
	free(input);
	return 0;
}

STATUS caesarshift(char* str, int shift)
{
	int i;
	for(i=0; str[i]!=MACROENDCHAR && i<129; i++){
		if(str[i]>='a' && str[i]<='z'){
			str[i]+=shift;
			if(str[i] > 'z'){
				str[i] -= 26;
			}
		}
		if(str[i]>='A' && str[i]<='Z'){
			str[i]+=shift;
			if(str[i] > 'Z'){
				str[i] -= 26;
			}
		}
	}
	/* fprintf(stderr, "\e[33m%dfi\n\e[0m", shift); */
	return 0;
}
