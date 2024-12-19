#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 


int main(void){
    printf("C File I/O. System Calls. Binary Functions.\n");
   // int open(const char  *pathname, int flags);
    const char *pathname = "data.bin";
    int flags = O_RDWR;
    int  fd = open(pathname, flags);
    if (-1 == fd){perror("open failed"); return 1;}
    printf("Input File Contents: \n");
    char  buf[100];
    int num_read = read(fd, buf, sizeof(buf));
    for (int i = 0; i < num_read; i++){
        printf("buf[%d]: 0x%02x, %d (%c)\n", i, buf[i], buf[i], buf[i]);
    }
    close(fd);
    int  fd = open(pathname, flags);
    char bin_data[] = { 0x01, 0x02, 0x03};
    int numwritten = write(fd, bin_data, sizeof(bin_data);
    if (-1 == numwritten){perror("write"); return 2;}
    printf("numwritten: %d", numwritten);
    close(fd);
    return 0;
}





/*#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(void){
    printf("C File I/O. System Calls\n");
    const char *pathname = "hello.txt";
    int flags = O_RDONLY;
    int fd = open(pathname, flags);
    printf("fd: %d\n", fd);
    if (-1 == fd){
        perror("open");
       return 1;
    }
    int result = 1;
    while(result != 0){
        char buf[100];
        result = read(fd, buf, sizeof(buf));
        printf("result: %d\n", result);
        for (int i = 0; i < result; i++){
        printf("bug[%d]: %d, c: 0x%02x %c", i, buf[i], buf[i]);
    }
    }
    
    
    close(fd);
    return(0);
}*///part 2
/*#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
    printf("C File I/O\n");
    char *mesg = "hello";
    ssize_t length = write(1, mesg, strlen(mesg));
    write(1,"\n", 1);
    printf("length: %lu\n", length);
    
    mesg = "stderr";
    length = write(2, mesg, strlen(mesg));
    write(1,"\n", 1);
    printf("length: %lu\n", length);
    
    mesg = "stdout again\n";
   fwrite(mesg, 1, strlen(mesg), stdout);
   
     mesg = "stderr again\n";
   fwrite(mesg, 1, strlen(mesg), stderr);
    return(0);
}*///part1