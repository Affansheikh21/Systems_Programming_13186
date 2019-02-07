#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main()
{

/*Read integer values from one file and apply arithmetic operations on them and write solution to another file
*/
// write means display or store in file
// read means take values from input or read from file
int f1 = open("/home/affan/Documents/source",  O_RDWR);
int f2 = open("/home/affan/Documents/destination", O_RDWR | O_CREAT,0777);
    if (f1 == -1) {
    write(STDOUT_FILENO,errno,sizeof(errno));
    perror("Error: ");
    }

// writing integers to file
// If you want to store all inputs in single line, use \n when taking inputs
//int x = write(STDOUT_FILENO,"Enter Numbers here:\n",sizeof("Enter Numbers here:\n"));
char * buff[20];
int readinput = read(f1,buff,20);
int a = write(f2,buff,readinput);
while(readinput >0){
        readinput = read(f1,buff,20);
        write(f2,buff,readinput);
}
close(f1);
close(f2);

}
