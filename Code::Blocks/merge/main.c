
/* ************************************
 * Book		 : Intruction to Algorithms
 * Page		 : 17 and 19
 * Algorihtms: merge_sort
 * ************************************/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#define NUM		1000000	/*length of the array*/

/* do the sort */
void merge_sort(int array[],int head, int end);
void merge(int array[], int head, int middle, int end);

int main(void)
{
	int i;
	        int data;
        /* do the sort */
        if((data = open("/home/Og/Pro/CPro/Algorithms/Beauty_of_Programming/ID/result", O_RDONLY)) < 0){
            perror("open");
            exit(EXIT_FAILURE);
        }
        if(dup2(data, 0) < 0){
            perror("dup2");
            exit(EXIT_FAILURE);
        }
	int *array = malloc(sizeof(int) * NUM);
	for(i = 0; i < NUM; i++){
        scanf("%d", &array[i]);
        //printf("%d", array[i]);
	}
	merge_sort(array, 0, NUM-1);		  /* do the dort */

	for(i = 0; i < NUM; i++)	{		  /* print the right sort */
		printf("%d ",array[i]);
    }
	printf("\n");

	return 0;
}

/* *************************************************
 * merge_sort: merge the array, and sort each array
 * array[]	 : the array I want to sort
 * head		 : the first element of each small array
 * end		 : the end element of each small array
 * *************************************************/
void merge_sort(int array[], int head, int end){
	int middle;
	if(head < end){
		middle = (head + end) / 2;		 /* get the middle position */
		merge_sort(array, head, middle); /* change the first array */
		merge_sort(array, middle+1, end);/* change the second array */
		merge(array, head, middle, end); /* sort each big array */
	}
}

/* *******************************************
 *	merge  : for each small array,
 *			 get the right sort for this array
 *	array[]: the array you want to aort
 *	head   : the first position of this array
 *	middle : the middle position of this array
*/
void merge(int array[], int head, int middle, int end){

	int i,j,k;

	int length_first  = middle - head + 1;/* the whole array change two arrays, one's length is length_first */
	int length_second = end - middle;	  /* one's length is length_second */

	int *array_first ;		/* get the one samll array */
	int *array_second;		/* get the one samll array */

	array_first  = (int *)malloc(sizeof(int) * (length_first + 1)); /* get the space */
	array_second = (int *)malloc(sizeof(int) * (length_second + 1));/*  get the space */
	array_first[length_first] = 1000000;	/* put a very big number into the first array position */
	array_second[length_second] = 1000000;	/* put a very big number into the second array position */

	/* change the whole array into two small arrays */
	for(i = 0; i < length_first; i++){
		array_first[i] = array[head + i];
	}
	for(i = 0; i < length_second; i++){
		array_second[i] = array[middle + 1 + i];
	}

	i = 0;/* begin with the first array */
	j = 0;/* begin with the second array */

	/* ******************************************
	 * two small arrays do the comparing
	 * the smaller will be put into the big array
	 * ******************************************/
	for(k = head; k < (end + 1); k++){
		if(array_first[i] > array_second[j]){/* the first bigger? */
			array[k] = array_second[j];
			j = j + 1;						 /* move position */
		}else{
			array[k] = array_first[i];		 /* or the second bigger */
			i = i + 1;						 /* move position */
		}
	}
}
