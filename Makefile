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
	$(VAL) ./pa6

clean:
	rm -f *.o *.txt *.b valgrind.log pa6
	clear