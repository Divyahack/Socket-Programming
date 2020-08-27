# Socket-Programming
Client -Server Application in which two endpoints named client and Server established 
 Here are two Application of such setup:
  
  1) Chat Application : clients sends a request to server via msg and server replies back to client . Its a chat based appliaction among two end points.
  
  2) TCP Calculator: server helps clients to solve basic mathematical operations requested by  client.

  Language Used : C
  Terminal Used : Ubuntu

  To Compile and  run server.c 
       gcc -o server server.c
       ./server #port_num

 To compile and run client.c
     gcc -o client client.c
     ./client  #host_name  #port_num