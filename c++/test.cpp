#include <iostream>

using namespace std;


constexpr void fib(int array[],int num){
	array[0] = 1;
	array[1] = 1;
	for(int i = 2; i < num; i++){
		array[i] = array[i-1] + array[i-2];
	}
}


int main(){
	constexpr int num = 50;
	constexpr int array[num] = {0};
	fib(array, num);
	return 0;
}