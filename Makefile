# Compiler
CC = gcc

# Compilation flags
# -Wall: Enables all compiler's warning messages
# -Wextra: Enables extra warning messages
# -g: Generates debug information to be used by GDB debugger
# -pedantic: Ensures strict ISO compliance, warns on non-standard practices
CFLAGS = -Wall -Wextra -g -pedantic -Iinclude

# The name of the final executable that will be created
TARGET = build/program

# Source and Object Directories
SRC_DIR = src
OBJ_DIR = build
INC_DIR = include

# Objects
# Specifies the object files that the program depends on. 
# Now includes the path from the build directory
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/matrix.o

# The default target. Typing 'make' with no argument will make the first target found in the
# Makefile, which is the 'all' target in this case. This target depends on the $(TARGET), so
# it ensures that the main program is compiled and linked.
all: $(TARGET)

# Rule to link the program. The command below will take the object files listed in $(OBJS),
# then compile and link them to create the final executable named $(TARGET). The $(CC) variable
# is the compiler command, $(CFLAGS) are the compiler options, and $(OBJS) are the input object files.
$(TARGET): $(OBJS)
        $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile the .c files into .o object files. Specifies that each .o file depends on its
# corresponding .c file and on matrix.h. Whenever a .c file or matrix.h changes, the corresponding .o
# file will be recompiled. The -c flag tells the compiler to generate object code, not an executable.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(OBJ_DIR)/*

# Declaring phony targets. These are targets that are not filenames. Declaring these ensures
# that make doesn't get confused by actual files named 'all' or 'clean'. It's good practice
# to declare all targets that do not produce output files as .PHONY.
.PHONY: all clean
