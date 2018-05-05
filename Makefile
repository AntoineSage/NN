CC = clang++
CFLAGS = -Wall -std=gnu++11 
EXEC_FLAG = -lmingw32 -lSDL2main -lSDL2 
EXEC_NAME = NN_test.exe
OBJ_FILES = NN_test.o NN.o Matrix.o

all : $(EXEC_NAME)

debug : CFLAGS += -g
debug : EXEC_FLAG += -g
debug : all

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(EXEC_FLAG)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)
