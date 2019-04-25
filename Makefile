GCC = gcc -std=c99 -g $(WARNING) $(ERROR)
WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
VAL = valgrind --tool=memcheck --log-file=valgrind.log --leak-check=full --show-reachable=yes --verbose  --track-origins=yes
TESTFLAGS = -DTEST_MAIN
SRCS = pa6.c seqpair.c #UPDATE WITH MORE FILES
OBJS = $(SRCS:%.c=%.o)

PA6: $(OBJS)
	$(GCC) $(TESTFLAGS) $(OBJS) -o pa6

.c.o:
	$(GCC) $(TESTFLAGS) -c $*.c

VAL: pa6
	$(VAL) ./pa6 examples/r8.sp r8.pck

test1: pa6
	./pa6 examples/r8.sp r8.pck
	diff r8.pck examples/r8.pck

test2: pa6
	./pa6 examples/r100.sp r100.pck
	diff r100.pck examples/r100.pck

test3: pa6
	./pa6 examples/r100h.sp r100h.pck
	diff r100h.pck examples/r100h.pck

test4: pa6
	./pa6 examples/r100v.sp r100v.pck
	diff r100v.pck examples/r100v.pck

test5: pa6
	./pa6 examples/r1K.sp r1K.pck

test6: pa6
	./pa6 examples/r2K.sp r2K.pck

clean:
	rm -f *.o *.txt *.b valgrind.log pa6
	clear