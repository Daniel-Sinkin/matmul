# @GPT4

# Compiler
CC = gcc

# Compilation flags
# -Wall: Warnings
# -Wextra: Extra Warnings 
# -g: Debug Flag
# -pedantic: Enforces strict ISO C, and warns on any non-standard practices.
CFLAGS = -Wall -Wextra -g -pedantic

# The name of the final executable that will be created.
TARGET = program

# Objects
OBJS = main.o matrix.o

# The default target. Typing 'make' with no argument will make the first target found in the
# Makefile, which is the 'all' target in this case. This target depends on the $(TARGET), so
# it ensures that the main program is compiled and linked.
all: $(TARGET)

# Rule to link the program. The command below will take the object files listed in $(OBJS),
# then compile and link them to create the final executable named $(TARGET). The $(CC) variable
# is the compiler command, $(CFLAGS) are the compiler options, and $(OBJS) are the input object files.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the main.c file into main.o object file. It specifies that main.o depends on
# main.c and matrix.h. Whenever main.c or matrix.h changes, main.o will be recompiled.
# The -c flag tells the compiler to generate object code, not an executable.
main.o: main.c matrix.h
	$(CC) $(CFLAGS) -c main.c

# Rule to compile the matrix.c file into matrix.o object file. It specifies that matrix.o depends
# on matrix.c and matrix.h. This ensures that changes in either file will trigger recompilation
# of matrix.o.
matrix.o: matrix.c matrix.h
	$(CC) $(CFLAGS) -c matrix.c

# A special target to clean up the files that the make process creates.
# It removes the executable and all object files. 
clean:
	rm -f $(TARGET) $(OBJS)

# Declaring phony targets. These are targets that are not filenames. Declaring these ensures
# that make doesn't get confused by actual files named 'all' or 'clean'. It's good practice
# to declare all targets that do not produce output files as .PHONY.
.PHONY: all clean
