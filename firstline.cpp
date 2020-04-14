
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

#define BUFFSIZE 1

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "incorrect usage, expected: " << argv[0] << " filename" << endl;
        return 1;
    }

    int n;
    char buf[BUFFSIZE];
    int fd = open(argv[1], O_RDONLY);
    int count=0;



    if (fd == -1) {  //checks to see if file can be opened
        perror("error opening");
        return 2;
    }


    while ((n = read(fd, buf, BUFFSIZE)) > 0 && count>=0) {

        if(buf[0]=='\n'){ //if new line character is found count is set to negative 1 so file is not read anymore
            count=-1;
        }else{
            count++;
            if ((write(STDOUT_FILENO, buf, n) != n)) {
                cout << "error writing" << endl;
            }
        }


    }
    cout<<endl;
}