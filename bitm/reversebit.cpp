#include <iostream>
#include <stdlib.h>
unsigned int reverseBits(unsigned int num){
	int i=0;
	int num_bits = sizeof(num) * 8;
	int reversed = 0;
	for(i=0; i<num_bits; ++i){
		if(num & (1<<i))
			reversed |= 1<<(num_bits-1-i);
	}
	return reversed;
}
int main(){
	unsigned int input = 121;
	int reversed=0;
	reversed = reverseBits(input);
	std::cout<<"input:"<<input;
	std::cout<<"reverse:"<<reversed;
}
