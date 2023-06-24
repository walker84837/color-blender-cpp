CXX = g++
CXXFLAGS = -O3 -std=c++20

SRCS = main.cpp header.hpp
TARGET = color-blender

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

clean:
	rm -f $(TARGET)
