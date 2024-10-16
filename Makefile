CC = gcc
CFLAGS = -Wall -g -Og

OBJS_STACK = stack/stack.o stack/stack_char.o stack/stack_string.o stack/stack_int.o 

TARGET = test_stack

test: $(TARGET)
	./$<

test_stack: test/test_stack.o $(OBJS_STACK)
	@$(CC) $(CFLAGS) -o $@ $^

test_stack_char: test/test_stack_char.o stack/stack_char.o 
	@$(CC) $(CFLAGS) -o $@ $^

test_stack_string: test/test_stack_string.o stack/stack_string.o 
	@$(CC) $(CFLAGS) -o $@ $^

test_stack_int: test/test_stack_int.o stack/stack_int.o 
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) -c -o $@ $<

clean:
	@echo "clean project"
	find . -name "*.o" -type f -delete
	find . -type f -executable -not -name "*.*" -delete
# del /S *.o  
# del /S *.exe