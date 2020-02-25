#include "trout.h"
#include "util.h"

extern int max_ttl;
extern int nprobes;

/* other global variables */

extern int seq;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];
extern Rec *rec;

int sendfd, recvfd;
int pipefd[2];              /* the pipe for the alarm handler */

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

socklen_t salen;                    /* length of a socket address */
extern int datalen;         /* length of the data in a datagram */

u_short sport;                      /* source UDP port # */
extern u_short dport;       /* destination port -- hopefully unused */
                                    /* 668 = the neighbor of the beast */
Timeval sendtv[1];
Timeval recvtv[1];
Timeval difftv[1];


// extern max_ttl = 30;
// nprobes = 2;

// /* other global variables */

// seq = 0;


// rec = (Rec *) sendbuf;
//            /* the pipe for the alarm handler */


//                   /* length of a socket address */
// datalen = sizeof (Rec);         /* length of the data in a datagram */
//               /* source UDP port # */
// dport = 32768 + 668;        /* destination port -- hopefully unused */
//                                     /* 668 = the neighbor of the beast */




int main (int argc, char **argv)
{
  int c;
  struct addrinfo *ai;
  char *host;

  opterr = 0;
  while ( (c = getopt (argc, argv, "m:")) != -1) {
    switch (c) {
    case 'm':
      if ( (max_ttl = atoi(optarg)) <= 1) {
	err_quit ("invalid -m value");
      }
      break;
    default:
      err_quit ("unrecognizd option: %c", c);
    }
  }

  if (optind != argc - 1) {
    err_quit ("usage: trout [ -m <maxttl>] <hostname>");
  }
  host = argv[optind];
  ai = Host_serv (host, NULL, 0, 0);

  printf ("trout to %s (%s): %d hops max, %d data bytes\n",
	  ai->ai_canonname,
	  Sock_ntop_host (ai->ai_addr, ai->ai_addrlen),
	  max_ttl, datalen);

  if (ai->ai_family != AF_INET) {
    err_quit ("unknown address family %d", ai->ai_family);
  }

  sasend = ai->ai_addr;
  salen = ai->ai_addrlen;
  sarecv = Calloc (1, salen);
  salast = Calloc (1, salen);
  sabind = Calloc (1, salen);

  loop_ttl ();
  exit (0);
}

