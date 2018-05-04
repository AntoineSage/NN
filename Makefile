CC = clang++
CFLAGS = -Wall
EXEC_NAME = NN_test.exe
OBJ_FILES = NN_test.o

all : $(EXEC_NAME)

debug : CFLAGS += -g
debug : all

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)
