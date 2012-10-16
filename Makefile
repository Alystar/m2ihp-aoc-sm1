CC=gcc
FC=gfortran

CFLAGS=-Wall -O2
CFLAGS_KERNEL=-g -Wall -O2
FFLAGS_KERNEL=-g -Wall -O2

LDFLAGS=

OBJS=driver.o rdtsc.o kernel_c.o kernel_f.o

all: sgemm

sgemm: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

rdtsc.o: rdtsc.c
	gcc -c rdtsc.c

kernel_c.o: kernel_c.c
	$(CC) $(CFLAGS) -c -o $@ $<

kernel_f.o: kernel_f.f90
	$(FC) $(FFLAGS) -c -o $@ $<