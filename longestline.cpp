#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "vector"

using namespace std;

#define BUFFSIZE 1 //reads one character at a time from the from the file

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "incorrect usage, expected: " << argv[0] << " filename" << endl;
        return 1;
    }


    char buf[BUFFSIZE];
    int fd;
    int count=0;
    std::vector<int> array;  //int vector will store the number of characters per line in file


    fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        perror("error opening");
        return 2;
    }

    while(read(fd, buf, BUFFSIZE) > 0) {
        count++;

        if(buf[0]=='\n'){
            count=count-1;
           array.push_back(count);
            count = 0;
        }


    }
    array.push_back(count);

    int result=0;
    for(int i=0; i < array.size(); i++){
        if(array.at(i)>result){
            result=array.at(i);  //makes result the largest number of characters for a line in the file
        }
    }
       cout<<result<<endl;


}




