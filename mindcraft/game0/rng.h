#ifndef _RNG_H_
#define _RNG_H_

static __attribute__((always_inline))
int32_t rng(int32_t *random)
{
	*random = ((*random * 1103515245U) + 12345U) & 0x7fffffff;
	return *random;
}

#endif
