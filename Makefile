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

CLIENT_MAIN := $(SRC)/client.cpp
SERVER_MAIN := $(SRC)/server.cpp

COMMON_SOURCES := $(filter-out $(CLIENT_MAIN) $(SERVER_MAIN),$(CXX_SOURCES))

COMMON_OBJECTS := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(COMMON_SOURCES))
CLIENT_OBJECT  := $(OBJ)/client.o
SERVER_OBJECT  := $(OBJ)/server.o

# outputs
EXEC_CLIENT := $(OUT)/exec/$(NAME)-$(VERSION)-client
EXEC_SERVER := $(OUT)/exec/$(NAME)-$(VERSION)-server
STATIC_LIB  := $(OUT)/lib/lib$(NAME)-$(VERSION).a

all: build

build: $(EXEC_CLIENT) $(EXEC_SERVER)

$(EXEC_CLIENT): $(COMMON_OBJECTS) $(CLIENT_OBJECT)
	@mkdir -p $(dir $@)
	$(COMPILER) $^ $(CXX_ARCHIVES) -o $@ $(LDFLAGS) $(FLAGS)

$(EXEC_SERVER): $(COMMON_OBJECTS) $(SERVER_OBJECT)
	@mkdir -p $(dir $@)
	$(COMPILER) $^ $(CXX_ARCHIVES) -o $@ $(LDFLAGS) $(FLAGS)

lib: $(STATIC_LIB)

$(STATIC_LIB): $(COMMON_OBJECTS)
	@mkdir -p $(dir $@)
	ar rvs $@ $(COMMON_OBJECTS)

$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(dir $@)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@ $(FLAGS)

run-client: $(EXEC_CLIENT)
	chmod +x $(EXEC_CLIENT)
	$(EXEC_CLIENT)

run-server: $(EXEC_SERVER)
	chmod +x $(EXEC_SERVER)
	$(EXEC_SERVER)

clean:
	rm -rf $(OUT)/lib/
	rm -rf $(OUT)/exec/
	rm -rf $(OUT)/obj/
