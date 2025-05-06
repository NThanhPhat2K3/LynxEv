# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lpthread -lrt
BUILD_DIR = build

# Output file
TARGET = main

# Source files (chỉ *.cpp, KHÔNG gồm *.h)
SRCS = main.cpp					\
       lynx_ev_message.cpp		\
       lynx_ev_task.cpp			\
       lynx_ev_task_list.cpp	\
       lynx_ev_timer.cpp		\
	   lynx_ev_task_sample.cpp	\
       system_debug.cpp

# Object files (tạo trong build/)
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Default rule
all: $(BUILD_DIR) $(TARGET)

# Create build directory if not exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compilation rule
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run rule
run:
	./$(TARGET)

# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
