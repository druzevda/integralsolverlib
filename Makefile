FILENAME =main.cpp
SRC      =./$(FILENAME)
EXE      =exefile.exe
MARCH    =x86-64
MTUNE    =intel

CC=      g++
INCLUDE= -I./include -I/usr/local/include
STD=     c++17
LIBS=    -lm

FLAGS= -march=$(MARCH) -mtune=$(MTUNE) -std=$(STD) -fomit-frame-pointer -fexpensive-optimizations -O3 -Wnon-virtual-dtor -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wzero-as-null-pointer-constant -Wmain -pedantic-errors -pedantic -Wextra -Wall -Werror=vla -fdiagnostics-show-option -Wno-div-by-zero -Wuninitialized -Werror=vla -fdiagnostics-show-option -Wno-div-by-zero -Wuninitialized -Wstack-protector -Wtype-limits -Wimplicit-fallthrough -Wmisleading-indentation -Wswitch -Wswitch-bool -Wswitch-unreachable -Wint-in-bool-context -Wunused-parameter -Wunused-variable -Wunused-value -Wunused -Wpointer-arith -Wcast-qual -Wmissing-field-initializers -Wmissing-noreturn -Wlong-long -Wdisabled-optimization -Wchar-subscripts -Wcomment -Wformat -Wformat-overflow -Wformat-security -Wformat-signedness -Wmissing-braces -Wsequence-point -Wwrite-strings -Wmissing-format-attribute -Wnormalized=nfkc -Wpacked -Winvalid-pch -Wvariadic-macros -Wunsafe-loop-optimizations -Wduplicated-branches -Wduplicated-cond -Wtrampolines -Wlogical-op -Wlogical-not-parentheses -Wno-aggressive-loop-optimizations -Wvector-operation-performance -funroll-loops -fvariable-expansion-in-unroller -fprefetch-loop-arrays -freorder-blocks-and-partition -fno-cprop-registers -funswitch-loops -funsafe-loop-optimizations

all:debug

debug: clean
	$(CC) $(INCLUDE) $(LIBS) $(FLAGS) $(SRC) -o $(EXE)
	./$(EXE)
	rm -rf ./$(EXE)

release: clean
	(CC) $(INCLUDE) $(LIBS)  $(FLAGS) $(SRC) -DNDEBUG -o $(EXE)
	./$(EXE)
	rm -rf ./$(EXE)

clean:
	rm -rf ./$(EXE)
