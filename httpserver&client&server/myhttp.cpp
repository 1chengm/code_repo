#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#define PATH "/home/stu/myhttp"
int socket_init();
void recv_data(int c);

int main(){
	int sockfd = socket_init();
	if(-1==sockfd){
		exit(1);
	}
	while(1){
		struct sockaddr_in caddr;//ip,port
		int len = sizeof(caddr);
		int c= accept(sockfd,(struct sockaddr*)&caddr,&len);
		if(c<0){
			continue;
		}
		printf("accept=:%d\n",c);
		
		recv_data(c);
		close(c);
	}
}
char*get_filename(char buff[]){
	char*s = strtok(buff," ");
	if(NULL== s){
		return NULL;
	}

		printf("请求方法:%s\n",s);
		s = strtok(NULL," ");
		return s;
	}


void recv_data(int c){
	char buff[1024]={0};
	int n=recv(c,buff,1023,0);
	printf("recv:\n%s\n",buff);
	char*filename = get_filename(buff);
	if(NULL==filename){
		send(c,"err",3,0);
		return;
	}
	printf("filename=:%s\n",filename);
	char path[4096] = {PATH};
	if(strcmp(filename,"/")==0){
		strcat(path,"/index.html");
	}
	else {
		strcat(path,filename);
	}
	printf("path=:%s\n",path);

	int fd = open(path,O_RDONLY);
	if(-1==fd){
		send(c,"open err",8,0);
		return;
	}
	int filesize = lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	char head_buff[256]={"HTTP/1.1 200 ok\r\n"};
	strcat(head_buff,"Server: myhttp\r\n");
	sprintf(head_buff+strlen(head_buff),"Content-Length:%d\r\n",filesize);
	strcat(head_buff,"\r\n");//feng ge hang;
	send(c,head_buff,strlen(head_buff),0);//send http content;
	char data[4096];
	int num=0;
	while((num =read(fd,data,4096))>0){
		send(c,data,num,0);
	}
	close(fd);
	}

int socket_init(){
	int sockfd = socket(AF_INET,SOCK_STREAM,0);//ipv4,tcp
	if(sockfd==-1){
		return -1;
	}
	struct sockaddr_in saddr;
	memset(&saddr,0,sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(80);//http xieyi;
	saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	int res = bind(sockfd,(struct sockaddr*)&saddr,sizeof(saddr));
	if(-1 == res){
		printf("bind err\n");

	}
	if(listen(sockfd,5)==-1){
		return -1;
	}
	return sockfd;
}

