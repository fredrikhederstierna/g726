#!/bin/bash

# -ar Rate (8k = 8kHz sample rate)
# -ac Channels (1 = one channel mono)
# -ab Bitrate output (16k = 16kbit/s)
# assume 16bit PCM indata, default endian

#ffmpeg -i a2002011001-e02-8kHz.wav -acodec g726 -ar 8k -ac 1 -ab 16k g726.wav
#ffmpeg -i man2_orig.wav -acodec g726 -ar 8k -ac 1 -ab 16k man.wav
ffmpeg -i woman2_orig.wav -acodec g726 -ar 8k -ac 1 -ab 16k woman.wav
