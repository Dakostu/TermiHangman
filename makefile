# compiler
CC = g++

TARGET = termihangman
DIR = source

default: $(TARGET)

$(TARGET): $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o
	$(CC) -o $(TARGET) $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o $(DIR)/main.cpp  
	
	
hangmanchar.o: $(DIR)/hangmanchar.cpp $(DIR)/hangmanchar.h
	$(CC) -c $(DIR)/hangmanchar.cpp
	
hangmanvector.o: $(DIR)/hangmanvector.cpp $(DIR)/hangmanvector.h
	$(CC) -c $(DIR)/hangmanvector.cpp
	
settostring.o: $(DIR)/settostring.cpp $(DIR)/settostring.h
	$(CC) -c $(DIR)/settostring.cpp
	
clean:
	$(RM) $(TARGET) $(DIR)/hangmanchar.o $(DIR)/hangmanvector.o $(DIR)/settostring.o

