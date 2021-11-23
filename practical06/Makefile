CC = gcc
CCFLAGS = -O3
LDFLAGS = -lm
CPROGS = $(shell ls *.c)
OBJ = $(CPROGS:.c=.o)

all: mm

mm: $(OBJ)
	$(CC) -o $@ $^ ${LDFLAGS}

$(OBJ):
	$(CC) -c ${CCFLAGS} $(@:.o=.c)

clean:
	rm -f *.o
	rm mm
