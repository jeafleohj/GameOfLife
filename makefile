BUILD = build
TEST = test
BIN = bin
TARGET = bin/gol3d
TARGET2 = bin/gol3d_2
SRCDIR = src
SRCFILES = $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJ=$(patsubst $(SRCDIR)/%,$(BUILD)/%,$(SRCFILES:.cpp=.o))
TESTOBJ=$(patsubst $(SRCDIR)/%,$(TEST)/%,$(SRCFILES:.cpp=.o))
FLAGS = -DRULE1
FLAGS2 = -DRULE2
LIBS = -lGL -lGLU -lGLEW -lglfw 
CC = g++
INC = -I include

all: $(TARGET) $(TARGET2)

$(TARGET): $(OBJ)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET) $(LIBS) ";
	$(CC) $^ -o $(TARGET) $(LIBS) $(INC) 

$(TARGET2): $(TESTOBJ)
	@echo " Linking...";
	@echo " $(CC) $^ -o $(TARGET2) $(LIBS) ";
	$(CC) $^ -o $(TARGET2) $(LIBS) $(INC) 

$(BUILD)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILD)
	@mkdir -p $(BIN)
	$(CC)  $(LIBS) $(INC) -c $^ -o $@  $(FLAGS)

$(TEST)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(TEST)
	$(CC)  $(LIBS) $(INC) -c $^ -o $@  $(FLAGS2)

.PHONY: clean
clean:
	@echo "Cleaning..."
	@echo " $(RM)  $(BUILD) $(BIN)"
	$(RM) -r $(BUILD) $(BIN)
cleantest:
	@echo "Cleaning..."
	@echo " $(RM)  $(TEST) "
	$(RM) -r $(TEST)
