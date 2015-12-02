/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	if (len < 0)
		return NULL;
	if (Arr == NULL)
		return NULL;
	int i;
	int first = 0;
	int last = 0;
	int mid;
	for (i = 0; i < len;){
		int first = i + 1;
		last = len - 1;
		if (Arr[i] == 0)
			i++;
		else{
			while (first <= last){
				mid = (first + last) / 2;
				if (Arr[i] > Arr[mid])
					first = mid + 1;
				else if (Arr[i] < Arr[mid])
					last = mid - 1;
				else{
					Arr[mid] = 0;
				}
			}
			i++;
		}
	}
	int j;
	for (i = 0, j = 0; j < len;){
		if (Arr[i] != 0){
			i++;
			j = i;
		}
		else if (Arr[j] == 0)
			j++;
		else{
			Arr[i] = Arr[j];
			Arr[j] = 0;
		}
	}
	return Arr;
}