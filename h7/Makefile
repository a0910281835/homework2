# remark region
#
#
#


CC = gcc

RMRF = rm -rf

TAR = h7

OBJ = struct.o main.o

LEAK = valgrind

LOG = vglog
$(TAR) : $(OBJ)
	$(CC) -Wall -g -o $(TAR) $(OBJ)

*.o : *.c
	$(CC) -Wall -g -o *.o *.c


.PHONY:
clean:
	$(RMRF) $(OBJ)

cleanall:
	$(RMRF) $(OBJ) $(TAR) $(LOG)

leak:
	$(LEAK) --leak-check=full --log-file=$(LOG) ./$(TAR)
