#include <stdio.h>      //printf
#include <stdlib.h>     //exit
#include <string.h>     //memset, strlen
#include <unistd.h>     //read, write, close
#include <sys/socket.h> //socket, connect
#include <arpa/inet.h>  //inet_pton

#define SERVER_PORT 666
#define SERVER_IP  "127.0.0.1"
int main(int argc, char *argv[]){//argc表示传入命令的个数，argv表示传入的具体信息

    int sockfd;
    char *message;
    struct sockaddr_in servaddr;
    int n;
    char buf[64];

    //异常处理
    if(argc != 2){
        fputs("Usage: ./echo_client message \n", stderr);
        exit(1);
    }

    message = argv[1];//传入的信息
    printf("message: %s\n", message);

    //1. 创建套嵌字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&servaddr, '\0', sizeof(struct sockaddr_in));//分配空间

    //定义地址IP和端口
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERVER_PORT);

    //2. 连接服务器
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    //3. 读写和服务器的交互信息
    write(sockfd, message, strlen(message));

    n = read(sockfd, buf, sizeof(buf)-1);

    if(n>0){
        buf[n]='\0';
        printf("receive: %s\n", buf);
    }else {
        perror("error!!!");
    }

    printf("finished.\n");

    //4. 关闭连接
    close(sockfd);

    return 0;
}
