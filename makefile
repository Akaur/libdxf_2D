# Makefile for libdxf_2D.so

# dirs
OBJ_DIR  := obj/
LIB_DIR  := lib/
TEST_DIR := test/
SRC_DIR  := src/

# compiler
CXX = g++

# compiler flags
CXXFLAGS = -c -Wall -Werror -fpic

# shared library flags
SHLIB = -shared -o

# dynamic linking flags
DYN_LINKFLAGS = -L./$(LIB_DIR) -Wall

# library dxf_2D.so
LIB      = $(LIB_DIR)libdxf_2D.so
LIB_NAME = libdxf_2D.so

# library at linking time
LINKLIB = -ldxf_2D 

# library source cpp files
SRC_BASE   := $(SRC_DIR)dxf_base.cpp
SRC_CIRCLE := $(SRC_DIR)dxf_circle.cpp
SRC_DXF    := $(SRC_DIR)dxf_dxf.cpp
SRC_LINE   := $(SRC_DIR)dxf_line.cpp
SRC_POINT  := $(SRC_DIR)dxf_point.cpp
SRC_RECT   := $(SRC_DIR)dxf_rect.cpp
		
# object files
OBJ_BASE   := $(OBJ_DIR)dxf_base.o
OBJ_CIRCLE := $(OBJ_DIR)dxf_circle.o
OBJ_DXF    := $(OBJ_DIR)dxf_dxf.o
OBJ_LINE   := $(OBJ_DIR)dxf_line.o
OBJ_POINT  := $(OBJ_DIR)dxf_point.o
OBJ_RECT   := $(OBJ_DIR)dxf_rect.o

# library object files
LIB_OBJS := $(OBJ_DIR)dxf_circle.o \
            $(OBJ_DIR)dxf_base.o   \
            $(OBJ_DIR)dxf_dxf.o    \
            $(OBJ_DIR)dxf_line.o   \
            $(OBJ_DIR)dxf_point.o  \
            $(OBJ_DIR)dxf_rect.o

LIB_OBJ := ../$(OBJ_DIR)dxf_circle.o \
           ../$(OBJ_DIR)dxf_base.o   \
           ../$(OBJ_DIR)dxf_dxf.o    \
           ../$(OBJ_DIR)dxf_line.o   \
           ../$(OBJ_DIR)dxf_point.o  \
           ../$(OBJ_DIR)dxf_rect.o


# main output program
MAIN = prog

# main cpp file
MAIN_CPP := test/example.cpp

# main object file
MAIN_OBJ := test/example.o

# remove

RM = rm -f

# coding

all: run

run: $(MAIN)
	export LD_LIBRARY_PATH=$(LIB_DIR):$ LD_LIBRARY_PATH && ./$(MAIN)

$(MAIN): $(MAIN_OBJ) $(LIB)
	$(CXX) $(DYN_LINKFLAGS) -o $(MAIN) $(MAIN_OBJ) $(LINKLIB)

$(MAIN_OBJ): $(MAIN_CPP)
	cd $(TEST_DIR) && $(CXX) -c ../$(MAIN_CPP) && cd ..

$(LIB): $(LIB_OBJS)
	cd $(LIB_DIR) && $(CXX) $(SHLIB) $(LIB_NAME) $(LIB_OBJ) && cd ..

$(OBJ_BASE): $(SRC_BASE)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_BASE) && cd ..

$(OBJ_CIRCLE): $(SRC_CIRCLE)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_CIRCLE) && cd ..

$(OBJ_DXF): $(SRC_DXF)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_DXF) && cd ..

$(OBJ_LINE): $(SRC_LINE)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_LINE) && cd ..

$(OBJ_POINT): $(SRC_POINT)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_POINT) && cd ..

$(OBJ_RECT): $(SRC_RECT)
	cd $(OBJ_DIR) && $(CXX) $(CXXFLAGS) ../$(SRC_RECT) && cd ..

clean:
	$(RM) obj/*.o test/*.o

