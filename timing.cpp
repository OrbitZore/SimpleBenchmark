#include "timing.hpp"

timing::timing(){
	this->begin = clock();
}

clock_t timing::stop(){
	clock_t end=clock();
	clock_t continued=end-begin;
	begin=end;
	return continued;
}


