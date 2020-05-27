# remark region
#
#
#

CC = gcc

RMRF = rm -rf

TAR = h4

OBJ = struct.o main.o

$(TAR) : $(OBJ)
	$(CC) -Wall -g -o $(TAR) $(OBJ)

*.o : *.c
	$(CC) *.c -o *.o


.PHONY:
clean:
	$(RMRF) $(OBJ)

cleanall:
	$(RMRF) $(OBJ) $(TAR)
