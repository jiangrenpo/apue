#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define BUFFSIZE 4069

void err_quit(char *msg);

int main(void)
{
	int n;
	char buf[BUFFSIZE];
	while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if(write(STDOUT_FILENO, buf, n) != n)
			err_quit("write file error!\n");
	if(n < 0)
		err_quit("read file error!\n");
	return 0;
}

void err_quit(char *msg)
{
	printf(msg,NULL);
	exit(120);
}
