CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

SRC = src/main.cpp src/Train.cpp src/Track.cpp src/RailWaySystem.cpp src/SignalController.cpp src/Junction.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = railway

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
