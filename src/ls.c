
/* this is my source code for ls command with l option "ls -l"
you give the file or folder as argument
it's easy to modify for the whole directory
I made the option l to show the functions in c language that return the statistics of a file and not just ls simple which only displays*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<pwd.h>
#include<time.h>
#include<string.h>


int main(int argc, char *argv[]){
	struct stat StatusBuffer;
	

	/*stat returns the attributes of a file*/

	if (stat(argv[1],&StatusBuffer) == -1)
	{
		perror(argv[1]);
		exit(1);
	}

	if (S_ISREG(StatusBuffer.st_mode))
	{
		printf("-");

	} else if(S_ISDIR(StatusBuffer.st_mode)) {
		printf("d");
	}

	printf("%c", StatusBuffer.st_mode & S_IRUSR ? 'r':'-');
	printf("%c", StatusBuffer.st_mode & S_IWUSR ? 'w':'-');
	printf("%c", StatusBuffer.st_mode & S_IXUSR ? 'x':'-');


	printf("%c", StatusBuffer.st_mode & S_IRGRP ? 'r':'-');
	printf("%c", StatusBuffer.st_mode & S_IWGRP ? 'w':'-');
	printf("%c", StatusBuffer.st_mode & S_IXGRP ? 'x':'-');

	printf("%c", StatusBuffer.st_mode & S_IROTH ? 'r':'-');
	printf("%c", StatusBuffer.st_mode & S_IWOTH ? 'w':'-');
	printf("%c", StatusBuffer.st_mode & S_IXOTH ? 'x':'-');

	printf("  %ld",StatusBuffer.st_nlink);

	printf("	%s ",getpwuid(StatusBuffer.st_uid)->pw_name);
	printf("	%s ",getpwuid(StatusBuffer.st_gid)->pw_name);
	printf(" %ld	",StatusBuffer.st_size);
	
	char* ss;
	ss=ctime(&StatusBuffer.st_mtime);
	/*for display reasons
	  so as not to have a line break*/
        ss[strlen(ss)-1]=0;
	printf(" %s", ss); 
	printf(" %s\n",argv[1]);
	
	
	
	

 return EXIT_SUCCESS;
}
