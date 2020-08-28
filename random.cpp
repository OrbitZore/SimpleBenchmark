#include "random.hpp"
#include <cstdint>

int32_t O_RAND::rand(void){                        // 生成伪随机数
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

int64_t O_RAND::rand64(void){
	return rand()*rand();
}

void O_RAND::srand(unsigned int seed){         // 修改种
    next = seed;
}
