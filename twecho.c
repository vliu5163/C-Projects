#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char** duplicateArgs(int argc, char** argv)
{
	char **copy = (char**) malloc((argc + 1) * sizeof(char*));
	if (copy == NULL)
	{
		perror("malloc returned NULL");
		exit(1);
	}
	for (int i = 0; i < argc; i++)
	{
		copy[i] = (char*) malloc((strlen(argv[i]) + 1) * sizeof(char));
		if (copy[i] == NULL)
		{
			perror("malloc returned NULL");
			exit(1);
		}
		for (int letter = 0; letter < strlen(argv[i]); letter++)
		{
			copy[i][letter] = toupper(argv[i][letter]);
		}
	}
	copy[argc] = NULL;
	return copy;
}

void freeDuplicatedArgs(char** copy)
{
	int i = 0;
	while (copy[i] != NULL)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		return 1;
	}
	char **copy = duplicateArgs(argc, argv);
	char **p = copy;
	argv++;
	p++;
	while (*argv)
	{
		printf("%s %s\n", *argv++, *p++);
	}
	freeDuplicatedArgs(copy);
	return 0;
}
