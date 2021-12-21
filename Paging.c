#include <stdio.h>
struct page
{
	int n;
	int p[50];
};
int frame[100] = {0};
int nof;
int no_free_frames()
{
	int i, count = 0;
	for (i = 0; i < nof; i++)
	{
		if (frame[i] == 0)
		{
			count++;
		}
	}
	return count;
}
void main()
{

	int mem_size, frame_size, nop, i, j, y, pno, z, frame1, temp, k, l;
	struct page process[50];
	printf("\nenter the main memory size in bytes:");
	scanf("%d", &mem_size);
	printf("\nenter the page size/frame size:");
	scanf("%d", &frame_size);
	nof = mem_size / frame_size;
	printf("%d frames are present in main memory and let them be numbered from 0 to %d", nof, nof - 1);
	printf("\nenter the number of processes:");
	scanf("%d", &nop);
	for (i = 0; i < nop; i++)
	{
		printf("\nenter the number of pages for process %d:", i);
		scanf("%d", &process[i].n);

		for (j = 0; j < process[i].n; j++)
		{
		x:
			if (process[i].n > nof)
			{
				printf("only %d frames are available !this process cannot be allocated!", nof);
				for (j = 0; j < process[i].n; j++)
				{
					process[i].p[j] = -1;
				}

				break;
			}
			printf("\npage no %d of process %d is allocated to which frame:", j, i);
			scanf("%d", &frame1);
			k = frame1;
			if (frame[k] == 0 && frame1 < nof)
			{
				frame[k] = 1;
				process[i].p[j] = frame1;
			}

			else
			{
				if (frame1 >= nof)
				{
					printf("\nframe not available");
				}
				printf("\nalready allocated frame:");
				y = no_free_frames();
				printf("\nnumber of free frames: %d", y);
				printf("\nthe free frames are:");
				int o;
				for (o = 0; o < nof; o++)
				{
					if (frame[o] == 0)
					{
						printf("\n%d ", o);
					}
				}
				if (y == 0 || y < process[i].n)
				{
					printf("\nno enough frames are free to be allocated to this process!");
					printf("\nenter the process to be terminated:");
					scanf("%d", &pno);
					for (z = 0; z < process[pno].n; z++)
					{
						temp = process[pno].p[z];
						l = temp;
						frame[l] = 0;
						process[pno].p[z] = -1;
					}
					goto x;
				}
				else
				{
					goto x;
				}
			}
		}
	}
	for (i = 0; i < nop; i++)
	{
		printf("\nAllocation for process %d\t-1 indicates no allocation!", i);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\npage no\t\tframe no");
		printf("\n----------------------");
		for (j = 0; j < process[i].n; j++)
		{
			printf("\n%d\t\t%d", j, process[i].p[j]);
		}
	}
}

/*
Output: 

	enter the main memory size in bytes:1024

	enter the page size/frame size:128
	8 frames are present in main memory and let them be numbered from 0 to 7
	enter the number of processes:3

	enter the number of pages for process 0:1

	page no 0 of process 0 is allocated to which frame:0

	enter the number of pages for process 1:4

	page no 0 of process 1 is allocated to which frame:1

	page no 1 of process 1 is allocated to which frame:2

	page no 2 of process 1 is allocated to which frame:3

	page no 3 of process 1 is allocated to which frame:4

	enter the number of pages for process 2:4

	page no 0 of process 2 is allocated to which frame:5

	page no 1 of process 2 is allocated to which frame:6

	page no 2 of process 2 is allocated to which frame:7

	page no 3 of process 2 is allocated to which frame:0

	already allocated frame:
	number of free frames: 0
	the free frames are:
	no enough frames are free to be allocated to this process!
	enter the process to be terminated:0

	page no 3 of process 2 is allocated to which frame:0

	Allocation for process 0        -1 indicates no allocation!
	~~~~~~~~~~~~~~~~~~~~~~~
	page no         frame no
	----------------------
	0               -1
	Allocation for process 1        -1 indicates no allocation!
	~~~~~~~~~~~~~~~~~~~~~~~
	page no         frame no
	----------------------
	0               1
	1               2
	2               3
	3               4
	Allocation for process 2        -1 indicates no allocation!
	~~~~~~~~~~~~~~~~~~~~~~~
	page no         frame no
	----------------------
	0               5
	1               6
	2               7
	3               0
*/
