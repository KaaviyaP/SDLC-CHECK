
PROJ_NAME = virtual_cricket
TEST_PROJ_NAME = Test_$(PROJ_NAME)



# All source code files
SRC = src/Feature1.c \
src/Feature2.c \
src/Feature3.c \
src/Feature4.c \
src/Feature5.c


# All test source files
TEST_SRC = test/test_cricket.c\
unity/unity.c


COV_SRC = test_cricket.c

INC_H = inc
INC_T = unity

ifdef OS
   RM = del 
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Document files
DOCUMENTATION_OUTPUT = documentation/html

.PHONY: run clean test doc all

all:
	gcc -I $(INC_H) $(SRC) main.c -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm
	
run:
	$(call FixPath,$(PROJ_NAME).$(EXEC))


# Document the code using Doxygen
doc:
	make -C ./documentation

test:
	gcc -I $(INC_H) -I $(INC_T) $(TEST_SRC) $(SRC) -o $(call FixPath,$(TEST_PROJ_NAME).$(EXEC)) -lm
	./$(call FixPath,$(TEST_PROJ_NAME).$(EXEC))

coverage:
	cp test/test_cricket.c .
	gcc -fprofile-arcs -ftest-coverage -I $(INC_H) -I $(INC_T) unity/unity.c test_cricket.c $(SRC) -o $(call FixPath, $(TEST_PROJ_NAME).$(EXEC)) -lm
	$(call FixPath, ./$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(COV_SRC)
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) *.DAT
	$(RM) test_cricket.c

cppcheck:
	cppcheck --enable=all $(SRC) main.c
debug:
	gcc -I $(INC_H) $(SRC) main.c -g -o $(PROJ_NAME).$(EXEC) -lm
	gdb $(PROJ_NAME).$(EXEC)

valgrind:
	valgrind ./$(TEST_PROJ_NAME).$(EXEC)


clean:
	$(RM) *.DAT
	$(RM) *.$(EXEC)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.c.gcov
	$(RM) .*$(DOCUMENTATION_OUTPUT) 