#############################################################
# Makefile
# author       : phat.nguyen-thanh
# created Date : 2025-05-07
# description  : build system for C++ event-driven project
#############################################################

# compiler and flags
CXX = g++
CXXFLAGS = -Wall  -std=c++11 -g -O2
LDFLAGS = -lpthread -lrt

# build and target
BUILD_DIR = 04_build
TARGET = lynx_app_main

# source directories
SRC_DIRS := 00_application_software 01_event_driven_kernel 02_driver 03_others

# include paths for headers
INCLUDES := $(foreach dir,$(SRC_DIRS),-I$(dir))

# source files
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# object files (mirror folder structure)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# default rule
all: $(TARGET)

# link object files into target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

# compile .cpp to .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# run target
run: $(TARGET)
	./$(TARGET)

# clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# debug rule (rebuild with no optimization)
debug: CXXFLAGS += -O0 -DDEBUG -fsanitize=address
debug: clean all

# release rule (max optimization, no debug info)
release: CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -O3
release: clean all
