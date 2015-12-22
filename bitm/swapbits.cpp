#include <stdio.h>
#include <stdlib.h>

unsigned int swapBits(unsigned int input, unsigned int n, unsigned int m, unsigned int k){
	unsigned int mask;
	unsigned int xor_num ;
	unsigned int xor_mask ;
	mask = (1<<k)-1;
	xor_num = (input>>n)&mask ^ (input>>m)&mask;
	xor_mask = xor_num<<n | xor_num<<m;
	return input^xor_mask;
}
int main(){
	unsigned int input = 7;
	unsigned int output = swapBits(input, 0, 6, 3);
	printf("input: %x output: %x", input, output);
}
