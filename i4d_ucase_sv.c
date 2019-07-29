#include "i4d_ucase.h"
int
main(int argc, char *argv[])
{
	struct sockaddr_in svaddr, claddr;
	int sfd, j;
	ssize_t numBytes;
	socklen_t len;
	char buf[BUF_SIZE];
	char claddrStr[INET_ADDRSTRLEN];
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sfd == -1)
		errExit("socket");
	memset(&svaddr, 0, sizeof(struct sockaddr_in6));
	svaddr.sin_family = AF_INET;
	 /* Wildcard address */
	svaddr.sin_port = htons(PORT_NUM);
	if (bind(sfd, (struct sockaddr *) &svaddr,
				sizeof(struct sockaddr_in)) == -1)
		errExit("bind");
	/* Receive messages, convert to uppercase, and return to client */
	for (;;) {
		len = sizeof(struct sockaddr_in);
		numBytes = recvfrom(sfd, buf, BUF_SIZE, 0,
				(struct sockaddr *) &claddr, &len);
		if (numBytes == -1)
			errExit("recvfrom");
		if (inet_ntop(AF_INET, &claddr.sin_addr, claddrStr,
					INET6_ADDRSTRLEN) == NULL)
			fprintf(stdout,"Couldn't convert client address to string\n");
		else
			fprintf(stdout,"Server received %ld bytes from (%s, %u)\n",
					(long) numBytes, claddrStr, ntohs(claddr.sin_port));
		for (j = 0; j < numBytes; j++)
			buf[j] = toupper((unsigned char) buf[j]);
		if (sendto(sfd, buf, numBytes, 0, (struct sockaddr *) &claddr, len) !=
				numBytes)
			fatal("sendto");
	}
}
