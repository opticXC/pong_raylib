ifndef CONFIG
	CONFIG = DEBUG
endif

PROG = pong

SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = bin


INCLUDE := -Iinclude
LINK	:= -Llib  -lraylib  -lopengl32 -lgdi32 -lwinmm

CC_FLAGS += -D AMD64

ifeq ($(CONFIG), DEBUG)
	ifeq ($(OS), WINDOWS_NT)
		CC_FLAGS += -m64 
	else 
		ifeq ($(OS), Linux)
			CC_FLAGS += -D LINUx
		endif
	endif
endif

CC_FLAGS += 
CC = g++

SOURCES=$(wildcard $(SRC_DIR)/*.cpp)

_FILES=$(SOURCES:.cpp=.o)
OBJS=$(subst $(SRC_DIR),$(OBJ_DIR),$(_FILES))



.PHONY: all clean preprocess

all: preprocess $(OBJS)
	@ echo $(BUILD_DIR)/$(PROG);
	@ $(CC) -o $(BUILD_DIR)/$(PROG) $(OBJS) $(CC_FLAGS) $(INCLUDE) $(LINK)


preprocess:
	@if ! [ -d $(OBJ_DIR) ]; \
	then \
	mkdir $(OBJ_DIR); \
	fi;

	@if ! [ -d $(BUILD_DIR) ]; \
	then \
	mkdir  $(BUILD_DIR); \
	fi;

clean:
	@ if [ -d $(BUILD_DIR) ]; \
	then \
	rm -r $(BUILD_DIR); \
	fi;

	@ if [ -d $(OBJ_DIR) ]; \
	then \
	rm -r $(OBJ_DIR); \
	fi;


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp

	@ echo $@;
	@ $(CC) -c -o $(OBJ_DIR)/$*.o  $(SRC_DIR)/$*.cpp $(INCLUDE) $(LINK) $(CC_FLAGS)
