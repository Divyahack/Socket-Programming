#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
void error(const char *msg)
{
        perror(msg);
        exit(1);
}
int main(int argc, char *argv[])
{
          int sockfd, newsockfd, portno,n;
          socklen_t clilen;
         char buffer[255];
         struct sockaddr_in serv_addr, cli_addr;
         if (argc < 2) {
                 fprintf(stderr,"ERROR, no port provided\n");
                 exit(1);


                            }


           sockfd =  socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0)
                     error("ERROR opening socket");

  bzero((char *) &serv_addr, sizeof(serv_addr));
            portno = atoi(argv[1]);
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons(portno);
            if (bind(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)                                                                                                                                                                                   error("ERROR on binding");

             listen(sockfd , 5);

             clilen = sizeof(cli_addr);


  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);


                   if (newsockfd < 0)


                           error("ERROR on accept");
       int num1 , num2 , ans , choice ;

S: n=write(newsockfd , "Enter Number 1 : ", strlen ("Enter Number 1"));
                        if(n<0)

                                error("ERROR writing to socket");
                        read (newsockfd , &num1 , sizeof(int) );
                        printf("client - Number 1 is : %d\n", num1);

                            n=write(newsockfd , "Enter Number 2 : ", strlen ("Enter Number 2"));
                                                    if(n<0)
                                                            error("ERROR writing to socket");
                                                                read (newsockfd , &num2 , sizeof(int) );
                                                                 printf("client - Number 2 is : %d\n", num2);
                                                                 n= write(newsockfd , "Enter your choice : \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n 5. Exit \n" , strlen("Enter your choice : \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division \n 5. Exit \n"));
                                                                if(n<0)
                                                                       error("ERROR writing to socket ");
                                                        read(newsockfd , &choice , sizeof(int));
                                                printf("client - choice is %d\n ", choice);
                                        switch(choice)
                                        {
                                                case 1 :
                                                        ans = num1+num2;
                                                        break;
                                                case 2 :
                                                        ans=num1-num2;
                                                        break;
                                                case 3 :
                                                        ans=num1*num2;
                                                         break;
                                                case 4:
                                                        ans=num1/num2;
                                                       break;                                                                                                                                                                                                      case 5:
                                                        goto Q;
                                                        break;

                                        }

         write(newsockfd , &ans , sizeof(int));
        if(choice !=5)
               goto S;

    Q:       close(newsockfd);


                   close(sockfd);


                   return 0;

}
