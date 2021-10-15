#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNUSED __attribute__((unused))
#define NLINES 10

int main(UNUSED int argc, UNUSED char *argv[]){
	char *lines[NLINES];  // array of char *
	char buf[BUFSIZ];
	char *p;
	int i = 0;

	/*
	 * First, lets read the first 10 lines from stdin and store them dynamically
	 * in memory
	 *
	 */

	while (i < NLINES && fgets(buf, BUFSIZ, stdin) != NULL){  // read from stdin
		p = strdup(buf);  // return char * to duplicate on heap 
		lines[i] = p;  // element i in lines array is address of duplicate
		i++;  // increment i
	}
	int k = i-1;
	int j = 0;
	
	printf("================\n"); // just helpful visually

	/*
	 * Next, lets reverse our array
	 */

	while (j < k) {
		char *temp = lines[j]; // make a temporary char * to hold arr[j]
		lines[j] = lines[k];  // swap elements
		lines[k] = temp;
		j++;  // increment
		k--;
	}

	/*
	 * Next, lets print our reversed array
	 */

	for (j=0; j<i; j++){ 
		printf("%s", lines[j]);
	}
	
	/*
	 * since we used heap memory, we must free it
	 */
	
	for (j = 0; j < i; j++)
		free((void *)lines[j]);

	return EXIT_SUCCESS;
}
