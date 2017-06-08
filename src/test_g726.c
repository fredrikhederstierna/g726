#include <stdio.h>
#include <stdint.h>

#include <g726.h>

#define ABS(a) (((a)<0)?-(a):a)

// reduce size from 480 16bit PCM (960 bytes) to 120 bytes (ratio 1:8)
// running 8kHz makes ---> 16 frames with 480 samples = 16*480=8000,
// 16 frames encoded to 120*16=1920 bytes/sec
static int16_t pcm_in[480];
static int16_t pcm_out[480];
static int8_t bitstream[120];

int main(void)
{
  int i;
  
  printf("Test G726\n");

  for (i = 0; i < 480; i++) {
    pcm_in[i]  = -0x7800;
    pcm_out[i] = 0;
  }
  
  printf("Encode...\n");
  g726_encode(pcm_in,
              bitstream);

  printf("Decode...\n");
  g726_decode(bitstream,
              pcm_out);

  for (i = 0; i < 480; i++) {
    int16_t cin  = pcm_in[i];
    int16_t cout = pcm_out[i];
    int16_t diff = ABS(cin - cout);
    printf("%04x: [%04x - %04x: %d]\n", i, cin & 0xFFFF, cout & 0xFFFF, diff & 0xFFFF); 
  }

  printf("Done.\n");
  return 0;
}
