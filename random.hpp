#ifndef O_RAND_H
#define O_RAND_H
#include <cstdint>
namespace O_RAND{
	static unsigned long int next = 1;    // 种子

	int32_t rand(void);                        // 生成伪随机数
	int64_t rand64(void);
	void srand(unsigned int seed);
}
#endif
