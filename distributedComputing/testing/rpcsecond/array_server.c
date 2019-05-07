/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "array.h"

int *
add_1_svc(arrays *argp, struct svc_req *rqstp)
{
	static int result;

	int first_matrix[argp->row_first][argp->col_first];
	for(int i = 0;i < argp->row_first;i++)
		for(int j = 0;j < argp->col_first;j++)
			first_matrix[i][j] = argp->first[i*argp->col_first+j];

	int second_matrix[argp->row_sec][argp->col_sec];
	for(int i = 0;i < argp->row_sec;i++)
		for(int j = 0;j < argp->col_sec;j++)
			second_matrix[i][j] = argp->second[i*argp->col_sec+j];

	int temp;
	for(int i = 0;i < argp->row_first;i++){
		for(int j = 0;j < argp->col_sec;j++){
			temp = 0;
			for(int k = 0;k < argp->col_first;k++)
				temp += argp->first[i*argp->col_first+k]*argp->second[k*argp->col_sec+j];
			printf("%d ",temp);
		}
		printf("\n");
	}

	result = 1;
	return &result;
}