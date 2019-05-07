/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "complex.h"

void
arith_prog_1(char *host,int first_real,int first_imag,int second_real,int second_imag,int option)
{
	CLIENT *clnt;
	int  *result_1;
	complex  arith_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, ARITH_PROG, ARITH_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	arith_1_arg.first_real = first_real;
	arith_1_arg.first_imag = first_imag;
	arith_1_arg.second_real = second_real;
	arith_1_arg.second_imag = second_imag;
	arith_1_arg.option = option;

	result_1 = arith_1(&arith_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else {
		printf("The real part is : %d\n",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 7) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	arith_prog_1 (host,atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]));
exit (0);
}