#include <stdio.h>      //printf
#include <stdlib.h>     //exit
#include <unistd.h>     //read, write, close
#include <sys/types.h>  //socket, bind, listen, accept
#include <sys/socket.h> //socket, bind, listen, accept
#include <string.h>     //strerror
#include <ctype.h>      //inet_ntop
#include <arpa/inet.h>  //inet_ntop
#include <errno.h>      //strerror

#define SERVER_PORT 666

//出错处理
void perror_exit(const char* des) {
    fprintf(stderr, "%s error, reason: %s\n", des, strerror(errno));
    exit(1);
}

int main(void){

    int sock;//代表信箱
    int ret;//作为bind和listen的返回值，用于处理出错信息
    struct sockaddr_in server_addr;


    //1.创建套嵌字（信箱）。成功：返回socket的文件描述符，失败：返回-1，设置errno
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror_exit("create socket");
    }

    //2.清空服务器地址空间（标签），写上地址和端口号
    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;//选择协议族IPV4
    //inet_pton(AF_INET, "1.1.1.1", &server_addr.sin_addr.s_addr);//测试出错处理函数perror_exit
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//监听本地所有IP地址
    server_addr.sin_port = htons(SERVER_PORT);//绑定端口号

    //3. 实现标签贴到收信得信箱上
    ret = bind(sock, (struct sockaddr *)&server_addr,  sizeof(server_addr));
    if(ret == -1) {
        perror_exit("bind");
    }

    //4. 把信箱挂置到传达室，这样，就可以接收信件了（监听客户端）
    ret = listen(sock, 128);
    if(ret == -1) {
        perror_exit("listen");
    }

    //万事俱备，只等来信
    printf("等待客户端的连接\n");

    //5. 处理客户端请求
    int done =1;
    while(done){
        struct sockaddr_in client;
        int client_sock, len, i;
        char client_ip[64];
        char buf[256];

        socklen_t  client_addr_len;
        client_addr_len = sizeof(client);
        client_sock = accept(sock, (struct sockaddr *)&client, &client_addr_len);

        //打印客服端IP地址和端口号
        printf("client ip: %s\t port : %d\n",
                 inet_ntop(AF_INET, &client.sin_addr.s_addr,client_ip,sizeof(client_ip)),
                 ntohs(client.sin_port));
        /*读取客户端发送的数据*/
        len = read(client_sock, buf, sizeof(buf)-1);
        buf[len] = '\0';
        printf("receive[%d]: %s\n", len, buf);

        //转换成大写
        for(i=0; i<len; i++){
            buf[i] = toupper(buf[i]);
        }


        len = write(client_sock, buf, len);

        printf("finished. len: %d\n", len);
        close(client_sock);

    }
    
    //6. 关闭连接
    close(sock);
    return 0;
}
