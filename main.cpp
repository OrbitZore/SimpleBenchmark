#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <limits>
#include "timing.hpp"
#include "cmdline/cmdline.h"
#include "random.hpp"
#include <functional>
#include <unistd.h>

#define DEBUG_FUNCTION __attribute__ ((__used__))
#define DEBUG_VARIABLE __attribute__ ((__used__))

using namespace std;

int amount;

template<class T>
DEBUG_FUNCTION void NumberBenchmark(){
	function<T()> f=[]()->T{return O_RAND::rand64()%numeric_limits<T>::max();};
	DEBUG_VARIABLE T a=f(),b=f();
	
	T ans;clock_t t;
	timing empty;
	for (int i=0;i<amount;i++)a=a;
		
	t=empty.stop();
	cout << "empty:" << (double)t/CLOCKS_PER_SEC << "s" << endl;
	
	timing plus;
	for (int i=0;i<amount;i++)
		a=a+b;
	t=plus.stop();
	cout << "plus:" << (double)t/CLOCKS_PER_SEC << "s" << endl;
	
	timing minus;
	for (int i=0;i<amount;i++)
		a=a-b;
	t=minus.stop();
	cout << "minus:" << (double)t/CLOCKS_PER_SEC << "s" << endl;

	timing multi;
	for (int i=0;i<amount;i++)
		a=a*b;
	t=multi.stop();
	cout << "multiply:" << (double)t/CLOCKS_PER_SEC << "s" << endl;

	timing div;
	for (int i=0;i<amount;i++)
		a=a/b;
	t=div.stop();
	cout << "division:" << (double)t/CLOCKS_PER_SEC << "s" << endl;
}



int main(int argc,char *argv[]){
	cmdline::parser a;
	a.add<int>("seed", 's', "benchmark random seed value",false,time(NULL));
	a.add<int>("amount",'a',"batch amount",false,300000000);
	a.parse_check(argc, argv);

	O_RAND::srand(a.get<int>("seed"));
	amount=a.get<int>("amount");
	cout << "======now:" << "int8" << "======" << endl;
	NumberBenchmark<int8_t>();
	cout << "======now:" << "int16" << "======" << endl;
	NumberBenchmark<int16_t>();
	cout << "======now:" << "int32" << "======" << endl;
	NumberBenchmark<int32_t>();
	cout << "======now:" << "int64" << "======" << endl;
	NumberBenchmark<int64_t>();
}

