#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define WORD_MAX 1024

int Take(char* ori[],char* inp);

int Take(char* ori[], char* inp) {
	int i = 0;
	char* ptr = strtok(inp, ";");

	while (ptr != NULL) {
		ori[i] = ptr;
		ptr = strtok(NULL, ";");
		i++;
	}
	return i;
}

void main() {
	FILE *of = fopen("test.txt", "r");
	
	int file, data;
	char* inp, ptr, ori[WORD_MAX];
	int Buffer_size = WORD_MAX * WORD_MAX;

	inp = malloc(sizeof(Buffer_size));

	while (fgets(inp, Buffer_size, of))
		file = Take(ori, inp);
	for (data = 0; data < file; data++)
		printf("%d\n", ori[data]);

	fclose(of);
}
