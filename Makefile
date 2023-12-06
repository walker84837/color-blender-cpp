# Compiler and flags
CXX = g++
CXXFLAGS = -std=gnu++17 -Ofast -march=x86-64 -mtune=native -Wall -Wextra -pedantic

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin
BIN_FILE = color-blender-cpp

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
EXECUTABLE = $(BIN_DIR)/$(BIN_FILE)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) $(BIN_FILE)

.PHONY: all clean