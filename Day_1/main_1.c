        #include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd>

int main() 
	{
	int fd[2];
	int pid;
	printf("Parent : ", getpid());
	pid = fork();
	printf("Child : ", getpid());
	char str[100]; 
	
	printf("Enter the string : ");
	scanf("%s", &str);

	if (pipe(fd) < 0)
	{	
		printf("Cant create pipe\n");
		exit(-1);
	}
			
	size = write(fd[1], string, 100);
	if (size != 100)
	{
		printf("Cant write all string\n");
		exit(-1)
	}	

	printf("%s \n", str);
	
	}
