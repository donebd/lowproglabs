.PHONY: all clean

OBJS= tests.o

FLAGS= -std=c11 -pedantic -Wall -Wextra -O1 -I ../mylib/include

all: tests


clean:
	$(R) $(OBJS)
	$(R) $(OBJS:.o=.d)
	$(R) tests tests.exe

vpath %.c  \
    src/
vpath %.a  \
    ../mylib

# Не забудем зависимость от библиотеки!
# И компилятору, и make передается только название библиотеки, из него формируется имя файла библиотеки
tests: $(OBJS) -lmylib
	$(CC) -o $@  $^

%.o: %.c
	$(CC) -MD $(FLAGS) -c -o $@ $<

-include $(OBJS:.o=.d)