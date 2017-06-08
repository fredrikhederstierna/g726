
# normal gcc

CC	:= gcc

CFLAGS := -O2 -W -Wall -Wextra -Isrc
LDFLAGS := -lm

SRC    := src/g711.c src/g726_16.c src/g726_24.c src/g726_32.c src/g726_40.c src/g726.c src/g72x.c src/test_g726.c

all:
	$(CC) -o g726 $(CFLAGS) $(SRC) $(LDFLAGS)

clean:
	rm *.o
	rm g726
