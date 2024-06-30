#include<stdio.h>
void
hello();
int
main(int argc, char **argv) {
	int nums[4] = {7,3,9,1};
	printf("nums[0+1]: %d", nums[0+1]);
	printf("nums + 1: %d\n", nums+1);
	printf("*(nums + 1): %d\n", *(nums+1));
	printf("&nums+1: %d\n", &nums+1);
	printf("*(nums[0] + 1): %d\n", *(nums[0] + 1));
	printf("nums[0]+1: %d\n", nums[0]+1);
	printf("*&nums[0] + 1): %d\n", *(&nums[0]+1));
}

