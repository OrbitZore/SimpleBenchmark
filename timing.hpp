#ifndef TIMING_T
#define TIMING_T

#include <ctime>
class timing{
	private:
		clock_t begin;
	public:
		timing();
		clock_t stop();
};

#endif


