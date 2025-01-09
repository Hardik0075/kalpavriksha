#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int length(char array[]) {
	int count=0;
	while(array[count]!='\0') {
		count++;
	}
	return count;
}
int main()
{
	int inputs;
	scanf("%d",&inputs);
	printf("Enter String: \n");
	char *array[inputs];
	for(int i=0; i<inputs; i++) {
		array[i]=(char *)malloc(sizeof(char)*50);
	}
	for(int i=0; i<inputs; i++) {
		scanf("%s",*(array+i));
	}
	char substring[50];
	printf("Enter Sunbstring : \n");
	scanf("%s",substring);
	int result_count=0;
	printf("result : \n");
	for(int outer_loop=0; outer_loop<inputs; outer_loop++) {
		for(int inner_loop=0; inner_loop<length(array[outer_loop]); inner_loop++) {
			if(array[outer_loop][inner_loop]==substring[0]) {
				int substring_incrementor=0,main_string_incrementor=0;
				int match_count=0;
				while(substring_incrementor<length(substring) && inner_loop<length(array[outer_loop]) && match_count<=length(substring)) {
					if(substring[substring_incrementor]==array[outer_loop][inner_loop+main_string_incrementor]) {
						match_count++;
					}
					substring_incrementor++;
					main_string_incrementor++;
				}
				if(match_count==length(substring)) {
					result_count++;
					printf("%s\n",*(array+outer_loop));
					break;
				}
			}
		}
	}
	printf("%d",result_count);
	return 0;
}
