#include <stdio.h>

int main(int argc, char* argv[])
{
	char helloworld[7];
	char happyworld[7];
	helloworld[0] = 'e';
	helloworld[1] = 'c';
	helloworld[2] = 's';
	helloworld[3] = 't';
	helloworld[4] = 'r';
	helloworld[5] = 'e';
	int num = 0;
	int i, j, k, l, m, n;
	for(i=0; i<6; i++){
		for(j=0; j<6; j++){
			if(j==i) continue;
			else{
				for(k=0; k<6; k++){
					if(k==j||k==i) continue;
					else{
						for(l=0; l<6; l++){
							if(l==k||l==j||l==i) continue;
							else{
								for(m=0; m<6; m++){
									if(m==l||m==k||m==j||m==i) continue;
									else{
										for(n=0; n<6; n++){
											if(n==m||n==l||n==k||n==j||n==i) continue;
											happyworld[0] = helloworld[i];
											happyworld[1] = helloworld[j];
											happyworld[2] = helloworld[k];
											happyworld[3] = helloworld[l];
											happyworld[4] = helloworld[m];
											happyworld[5] = helloworld[n];
											num++;
											printf("%4d %s\n", num, happyworld);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
