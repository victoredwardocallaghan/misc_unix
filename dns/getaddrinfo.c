#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "ec.h"

int main(int argc, const char *argv[])
{
  struct addrinfo *infop = NULL, hint;

  memset(&hint, 0, sizeof(hint));
  hint.ai_family = AF_INET;
  hint.ai_socktype = SOCK_STREAM;
  ec_ai( getaddrinfo("www.yahoo.com", "80", &hint, &infop) )
  // getaddrinfo("www.yahoo.com", "80", &hint, &infop);
  for ( ; infop != NULL; infop = infop->ai_next) {
    struct sockaddr_in *sa = (struct sockaddr_in *)infop->ai_addr;

    printf("%s port: %d protocol: %d\n", inet_ntoa(sa->sin_addr),
           ntohs(sa->sin_port), infop->ai_protocol);
  }

  return 0;
}
