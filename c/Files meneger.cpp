#include <stdio.h>
#include <stdlib.h>

int Readfile(char name[]) {
	FILE* file;
	int code = fopen_s(&file, name, "r");
	if (file == NULL) {
		return printf("\n The file was not found.\n");
	}

	int c;
	c = fgetc(file);
	while (c != EOF) {
		putc(c, stdout);
		c = getc(file);
	}

	fclose(file);
	printf("\n File prochitan.\n");
	return 0;
}

int Createfile(char name[]) {
	FILE* file;
	fopen_s(&file, name, "w");

	fclose(file);
	printf("\n File sozdan.\n");
	return 0;
}

int Writefile(char name[]) {
	FILE* file;
	fopen_s(&file, name, "a");
	char messege[256];
	printf("\n Vvedite stroky dlya zapisi v file.\n");
	fgets(messege, 256, stdin);

	fputs(messege, file);

	fclose(file);
	printf("\n Soobshenie zapisano.\n");
	return 0;
}

int main() {
	char wish = 'y';

	do {
		printf("\n__________________________________________");
		printf("\n Hochesh` prodoljit`? (vvedi y - esli da).\n");
		scanf_s(" %c", &wish);

		if (wish != 'y') {
			printf("\n Good luck!");
			break;
		}

		printf(" Viberi chto-to.\n");
		printf(" 1. Read file. \n 2. Create file. \n 3. Write to file.\n");
		int a;
		scanf_s("%d", &a);

		char pyt[128] = "\n";
		switch (a) {
		case 1:
			printf("\n Vvedite pyt` k file.\n");
			while (pyt[0] == '\n') {
				fgets(pyt, 128, stdin);
			}
			printf("\n");
			for (int i = 0; i < 128; i++) {
				if (pyt[i] == '\n') {
					pyt[i] = '\0';
				}
			}

			Readfile(pyt);
			break;
		case 2:
			printf("Vvedite file's name.\n");
			while (pyt[0] == '\n') {
				fgets(pyt, 128, stdin);
			}
			printf("\n");
			for (int i = 0; i < 128; i++) {
				if (pyt[i] == '\n') {
					pyt[i] = '\0';
				}
			}

			Createfile(pyt);
			break;
		case 3:
			printf("Vvedite file's name.\n");
			while (pyt[0] == '\n') {
				fgets(pyt, 128, stdin);
			}
			printf("\n");
			for (int i = 0; i < 128; i++) {
				if (pyt[i] == '\n') {
					pyt[i] = '\0';
				}
			}

			Writefile(pyt);
			break;
		default:
			printf("\n Vvedite normal'noe znachenie.\n");
		}

	} while (wish == 'y');


	return 0;
}