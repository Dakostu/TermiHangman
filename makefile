# compiler
CC = g++

TARGET = termihangman
DIR = source
FLAGS = -std=c++17

default: $(TARGET)

$(TARGET): $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o
	$(CC) -o $(TARGET) $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o $(DIR)/main.cpp $(FLAGS)
	
	
hangmanchar.o: $(DIR)/hangmanchar.cpp $(DIR)/hangmanchar.h
	$(CC) -c $(DIR)/hangmanchar.cpp $(FLAGS)
	
hangmanvector.o: $(DIR)/hangmanvector.cpp $(DIR)/hangmanvector.h
	$(CC) -c $(DIR)/hangmanvector.cpp $(FLAGS)
	
settostring.o: $(DIR)/settostring.cpp $(DIR)/settostring.h
	$(CC) -c $(DIR)/settostring.cpp $(FLAGS)
	
clean:
	$(RM) $(TARGET) $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o

