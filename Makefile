CC=gcc
FC=gfortran

CFLAGS=-Wall -O3 -Ofast
CFLAGS_KERNEL=-g -Wall -O3 -Ofast
FFLAGS_KERNEL=-g -Wall -O3

LDFLAGS=-pg

OBJS=driver.o rdtsc.o kernel_c.o kernel_f.o

.PHONY: all clean

all: sgemm

sgemm: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

rdtsc.o: rdtsc.c
	gcc -c rdtsc.c

kernel_c.o: kernel_c.c
	$(CC) $(CFLAGS_KERNEL) -c -o $@ $<

kernel_f.o: kernel_f.f90
	$(FC) $(FFLAGS_KERNEL) -c -o $@ $<

clean:
	rm -f $(OBJS) sgemm