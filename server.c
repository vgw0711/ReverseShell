// Author: Engin Kirda
// Function: Code that has a vulnerability
// Authenticate using your Husky ID!

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFERSIZE 1024

int sockd=-1;

void cleanup() {
   close(sockd);
}

void handle_signal_cld(int signal) {
   wait3(NULL, WNOHANG, NULL); 
}

void handle_signal_intterm(int signal) {
   cleanup();
   exit(0);
}

void error(char * msg) {	
   cleanup();
   fprintf(stderr,"%s",msg);
   exit(1);
}

void process(char *echo, int socket) {
   char buffer[512];
   strcpy(buffer,echo);
   write(socket,buffer,strlen(buffer));
}

int main(int argc, char ** argv) {
   struct sockaddr_in addr;
   uid_t tuid;
   int port = 0;
   int length, husky_id;
   char * buffer;
   char husky_id_string[3];

   int r;
   int new_socket=0;

   if (argc!=2) {
      fprintf(stderr,"Synopsis:\n%s <port>\n", argv[0]);
      exit(1);
   }

   signal(SIGCHLD,handle_signal_cld);
   signal(SIGINT,handle_signal_intterm);
   signal(SIGTERM,handle_signal_intterm);

   port = atoi(argv[1]);

   if ((sockd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
      error("Could not open TCP socket");

   int on = 1;
   if (setsockopt(sockd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
      error("error: set socket option");

   addr.sin_family = AF_INET;
   addr.sin_port = htons(port);
   addr.sin_addr.s_addr = INADDR_ANY;

   if (bind (sockd, (struct sockaddr *) &addr, sizeof(addr)) !=0)
      error("Could not bind TCP socket to address");

   if (listen(sockd, 5)==-1) {
      error("Could not listen");
   }

   length = sizeof(addr);

   if ((buffer = (char *) malloc(BUFFERSIZE*sizeof(char)))==NULL) {
      error("malloc");
   } 

   for(;;) {

      if ((new_socket=accept(sockd, (struct sockaddr *) &addr, (socklen_t *) &length)) ==-1) {
         error("Could not accept connection");
      }	

      if (fork()==0) { 

         close(sockd);

         r=read(new_socket,buffer,BUFFERSIZE)>0;

         strncpy(husky_id_string,buffer,3);

         husky_id_string[3]='\0';

         husky_id=atoi(husky_id_string);

         if (husky_id<=0) error("error: error in Husky ID");

         tuid = 6000 + husky_id; 
         if (setreuid(tuid, tuid) < 0)
            error("error: setting permissions");
         else {
            printf("Worked... EUID is %d EGID is %d\n\n",geteuid(),getegid());
         }

         if (r==-1) {
            error("error:connection error!");
            exit(1);
         }

         process(buffer,new_socket);

         close(new_socket);
         exit(0);
      } else close(new_socket);
   }
   return 0;
}
