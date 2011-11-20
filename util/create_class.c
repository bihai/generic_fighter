#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	FILE *f;
	char filename [10000];
	if (argc<2) {
		fprintf(stderr, "Usage: %s classname\n", argv[0]);
		return 1;
	}
	printf("Creating class named '%s'...", argv[1]);
	strcpy(filename, argv[1]);
	strcat(filename, ".h");

	f = fopen (filename, "r");
	if (f) {
		fprintf(stderr, "File '%s' alredy exists, not creating!!\n", filename);
		fclose(f);
	} else {
		f = fopen(filename, "w");
		if (!f) {
			fprintf(stderr, "Error opening file '%s'\n", filename);
			return 1;
		}
		fprintf(f, "#ifndef __%s_h__\n#define __%s_h__\n\n", argv[1], argv[1]);
		fprintf(f, "typedef struct _%s {\n\tint field1;\n} %s;\n\n", argv[1], argv[1]);
		fprintf(f, "\n\n%s *%s_new(void);\n", argv[1], argv[1]);
		fprintf(f, "void %s_init(%s *%c);\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "void %s_finish(%s *%c);\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "void %s_destroy(%s *%c);\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "\n\n#endif //__%s_h__\n", argv[1]);
		fclose(f);
	}
	
	strcpy(filename, argv[1]);
	strcat(filename, ".c");

	f = fopen (filename, "r");
	if (f) {
		fprintf(stderr, "File '%s' alredy exists, not creating!!\n", filename);
		fclose(f);
	} else {
		f = fopen(filename, "w");
		if (!f) {
			fprintf(stderr, "Error opening file '%s'\n", filename);
			return 1;
		}
		fprintf(f, "#include \"%s.h\"\n#include <stdlib.h>\n", argv[1]);
		fprintf(f, "\n\n%s *%s_new(void) { \n", argv[1], argv[1]);
		fprintf(f, "\treturn (%s *) malloc(sizeof(%s));\n}\n\n", argv[1], argv[1]);
		fprintf(f, "void %s_init(%s *%c) {\n\n}\n\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "void %s_finish(%s *%c){\n\n}\n\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "void %s_destroy(%s *%c){\n", argv[1], argv[1], argv[1][0]);
		fprintf(f, "\tfree(%c); \n%c=NULL;\n}\n\n", argv[1][0], argv[1][0]);
		fclose(f);
	}
	printf(" Created!\n");
	return 0;
}
