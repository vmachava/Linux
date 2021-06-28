#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int p[2];
	int ret_val,pid;
	char data[40]="hello buddy...";

	ret_val = pipe(p);
	if(ret_val == -1)
	{
		perror("pipe fail");
		return 1;
	}
	else
	{
		pid = fork();
		if(pid == 0)
		{//child
		
			char data1[40];
			printf("this is child process\n");
			read(p[0],data1,sizeof(data1));
			printf("read: %s\n",data1);
			//exit(1);
		}
		else
		{//parent
		
			printf("this is my parent\n");
			write(p[1],data,sizeof(data));
			//wait(&ret_val);
			printf("this is write: %s",data);
		}
	}

	return 0;
}
