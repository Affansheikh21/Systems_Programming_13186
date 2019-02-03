#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
int fd = open("/home/affan/Documents/file", O_CREAT | O_RDONLY);

if  (fd == -1 ) {
    printf("%d",errno);
    perror("Error: ");
}

else {
char * arr[100];
int x = write(STDOUT_FILENO, "Enter String: ", sizeof("Enter String: "));
 printf("%d",errno);
int r = read(STDIN_FILENO,arr,x);
 printf("%d",errno);

int wof= write(fd,arr,r); // EBADF WILL OCCUR HERE 
 printf("%d",errno);  
 /* This will give you errno 9, which is EBADF because:
- the file was already created, and was on READONLY mode, so O_CREAT didnt work 
- if READONLY file is accessed and Write is applied, it gives you EBADF
*/






}



}
