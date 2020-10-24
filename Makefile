CXX       := g++
CXX_FLAGS := -Werror -Wall -Wextra -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := 
LIBSTD  := stdc++
LIBEXT  := gmp
LIBRARIES   := 
EXECUTABLE  := huge


all:    $(BIN)/$(EXECUTABLE)

run:    clean all
	@echo "Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@echo "Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -l$(LIBSTD)  $^ -o $@ $(LIBRARIES)
	@echo
	@find ./bin/ -type f | xargs ls -lrt

clean:
	@echo "Clearing..."
	@-rm $(BIN)/$(EXECUTABLE)

