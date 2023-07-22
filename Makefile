CXX = g++
CXXFLAGS = -O3 -std=c++17

SRCS = main.cpp header.hpp
TARGET = color-blender

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)
