#define variables for later use in function
CC=g++
CXXFLAGS=-Wall -g -std=c++11
LFLAGS=-lm
TARGET=todoTest

#define source files for use in compiling
C_SRCS := \
	$(wildcard *.cpp) \
	$(wildcard src/*.cpp) \
	$(wildcard src/**/*.cpp) 

#define header files for use in compiling
HDRS := \
	$(wildcard *.h) \
	$(wildcard src/*.h) \
	$(wildcard src/**/*.h)

#define object files for use in compiling
OBJS := $(patsubst %.cpp, bin/%.o, $(wildcard *.cpp))
OBJS += $(filter %.o, $(patsubst src/%.cpp, bin/%.o, $(C_SRCS)))

#default target if none other is specified
all: build
	@echo "All Done"

#target that compiles the code together
build: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

#sets the bin directory to hold needed files
bin/%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#sets the bin directory to hold needec files from the source directory
bin/%.o: src/%.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

#clean target that removes the bin directory
clean:
	rm -f $(TARGET)
	rm -rf bin

#run target that compiles and runs program
run: build
	./$(TARGET)

#which target that displays the found files
which:
	@echo "FOUND SOURCES: ${C_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"