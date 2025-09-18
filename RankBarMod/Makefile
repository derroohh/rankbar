# Compiler
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17 -Iinclude
LDFLAGS = -Llib -lScriptHookV -static-libgcc -static-libstdc++

# Project
TARGET = build/RankBar.asi
SRC = $(wildcard src/*.cpp)

# Build rule
$(TARGET): $(SRC)
	$(CXX) -shared -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	rm -f $(TARGET)
