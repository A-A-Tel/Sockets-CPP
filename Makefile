NAME := sockets
VERSION := 1.0
COMPILER := g++
STD := c++20
FLAGS := -std=$(STD) -Iinclude/ -Wall -Wextra
LDFLAGS := -ldate-tz

SRC := src
OUT := out
LIB := lib/
OBJ := $(OUT)/obj

CXX_SOURCES := $(shell find $(SRC) -type f -name "*.cpp")
CXX_HEADERS := $(shell find include/$(NAME)/ -type f -name "*.hpp")
CXX_ARCHIVES := $(shell find $(LIB) -type f -name "*.a")
CXX_OBJECTS := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(CXX_SOURCES))

FILE_NAME := $(NAME)-$(VERSION)
EXEC := $(OUT)/exec/$(FILE_NAME)
STATIC_LIB := $(OUT)/lib/lib$(FILE_NAME).a

all: build

# Build executable
build: $(EXEC)

$(EXEC): $(CXX_OBJECTS)
	@mkdir -p $(dir $@)
	$(COMPILER) $(CXX_OBJECTS) $(CXX_ARCHIVES) -o $@ $(LDFLAGS) $(FLAGS)

# Build static library
lib: $(STATIC_LIB)

$(STATIC_LIB): $(CXX_OBJECTS)
	@mkdir -p $(dir $@)
	ar rvs $@ $(CXX_OBJECTS)

# Object file compilation
$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@ $(FLAGS)

run: $(EXEC)
	chmod +x $(EXEC)
	$(EXEC)

clean:
	rm -rf $(OUT)/lib/
	rm -rf $(OUT)/exec/

# !!! fix format
#format:
#	clang-format -style='{BasedOnStyle: GNU, PointerAlignment: Left}' -i $(CXX_SOURCES) $(CXX_HEADERS)