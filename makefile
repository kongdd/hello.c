# -MM -MMD -MP 
CC=gcc
CFLAGS=-g -O2 -std=gnu17 -Iinclude -IC/include -Iinclude/algorithm -Wno-unused-result -MMD -MP

CPP=g++
CPPFLAGS=-g -O2 -std=c++17 -Iinclude -IC++/include -Wno-unused-result -MMD -MP

# -lcurses
# `ncurses5-config --cflags --libs`

IDIR=C++
ODIR=build

# includes = $(wildcard include/*.hpp)
# sources_cpp=main_leaf.cpp  main_leaf_v2.cpp
sources_cpp:=$(notdir $(wildcard C++/*.cpp))
SOURCES=$(patsubst %,$(IDIR)/%, $(sources_cpp))
OBJS=$(patsubst %.cpp,$(ODIR)/%.exe, $(sources_cpp))

# OBJS = $(patsubst %,$(ODIR)/%, $(_OBJS))

main: $(OBJS) makedir

# main: $(OBJS) 
# build/LAB1.exe

# 自动处理头文件的依赖关系
DEPENDS := $(patsubst %.exe, %.d, $(OBJS))
-include $(DEPENDS)
# <https://stackoverflow.com/questions/52034997/how-to-make-makefile-recompile-when-a-header-file-is-changed>

# $(OBJS): 
$(ODIR)/%.exe: $(IDIR)/%.cpp makefile
	$(CPP) $(CPPFLAGS) $< -o $@

# build/LAB1.exe: src/LAB1.c 
# 	$(CC) $(CFLAGS) $^ -o $@

# build/Queue.o
# build/Queue.o: include/algorithm/Queue.c 
# 	$(CC) $(CFLAGS) -c $< -o $@

# %.o: %.cpp Makefile
# 	$(CXX) $(WARNING) $(CXXFLAGS) -MMD -MP -c $< -o $@

makedir:
	@mkdir -p $(ODIR)

echo:
	@echo SOURCES
	@echo $(OBJS)
# 
# $(ODIR)/%: $(IDIR)/%.c
# 	$(CC) $(CFLAGS) $< -o $@ 

# $(OBJS): $(SOURCES)
# 	$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm *.exe build/*.exe build/*.d src/*.exe $(OBJS) -f
