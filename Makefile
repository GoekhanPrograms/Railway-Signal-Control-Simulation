# ——— Configuration ———
PREFIX       := /mingw64
CXX          := g++
CXXFLAGS     := -Wall -std=c++17 -Iinclude
LDFLAGS      :=

GTEST_CFLAGS  := -I$(PREFIX)/include
GTEST_LDFLAGS := -L$(PREFIX)/lib -lgtest_main -lgtest -pthread

# ——— Application sources ———
SRC          := src/main.cpp \
                src/Train.cpp \
                src/Track.cpp \
                src/RailWaySystem.cpp \
                src/SignalController.cpp \
                src/Junction.cpp
OBJ          := $(SRC:.cpp=.o)
TARGET       := railway

# ——— Test sources ———
TEST_SRC     := tests/RailWaySystemTest.cpp \
                tests/SignalControllerTest.cpp \
                tests/JunctionTest.cpp
TEST_OBJ     := $(TEST_SRC:.cpp=.o)
TEST_TARGET  := run_tests.exe
APP_OBJS_NO_MAIN := $(filter-out src/main.o,$(OBJ))

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

# ——— Build & link tests ———
.PHONY: test
test: CXXFLAGS += $(GTEST_CFLAGS)
test: LDFLAGS  += $(GTEST_LDFLAGS)
test: $(APP_OBJS_NO_MAIN) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $(APP_OBJS_NO_MAIN) $(TEST_OBJ) -o $(TEST_TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ——— Clean up build artifacts ———
.PHONY: clean
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(TARGET) $(TEST_TARGET)
