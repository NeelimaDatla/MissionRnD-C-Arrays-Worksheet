/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (len < 0)
		return NULL;
	if (Arr == NULL)
		return NULL;
	int first = 0;
	int last = len - 1;
	int mid;
	int val;
	while (first <= last){
		mid = (first + last) / 2;
		if (num > Arr[mid])
			first = mid + 1;
		else if (num < Arr[mid])
			last = mid - 1;
		else if (Arr[mid] == num)
			val = last;
	}
	val = last;
	for (int j = len; j > val; j--){
		Arr[j] = Arr[j - 1];
	}
	Arr[val + 1] = num;
	return Arr;
}