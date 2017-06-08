#include <stdint.h>

void g726_encode(int16_t *pcm,
                 int8_t *bitstream);

void g726_decode(int8_t *bitstream,
                 int16_t *pcm);
