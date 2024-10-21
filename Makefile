# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -I./include 
# Include glad directory
LIBS = -lglfw -lGLEW -lGL -lm

# ImGui directory
IMGUI_DIR = include/imgui

# Source files
SRCS = $(wildcard src/*.cpp src/game/factories/*.cpp src/game/gui/*.cpp src/game/loaders/*.cpp src/game/objects/*.cpp src/game/openGL/*.cpp src/game/render/*.cpp src/game/scenes/*.cpp src/game/shaders/*.cpp src/game/window/*.cpp src/game/objects/terrain/*.cpp)

# Add ImGui source files
SOURCES = $(IMGUI_DIR)/imgui.cpp \
          $(IMGUI_DIR)/imgui_demo.cpp \
          $(IMGUI_DIR)/imgui_draw.cpp \
          $(IMGUI_DIR)/imgui_tables.cpp \
          $(IMGUI_DIR)/imgui_widgets.cpp \
          $(IMGUI_DIR)/imgui_impl_glfw.cpp \
          $(IMGUI_DIR)/imgui_impl_opengl3.cpp

# Combine source files
SRCS += $(SOURCES)

# Object files (place .o files in bin/ with same structure as src/)
OBJDIR = bin
OBJS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SRCS))
OBJS += $(OBJDIR)/glad.o  # Add glad.o to OBJS

# Output executable name
TARGET = build/Game1

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LIBS)

# Compile each .cpp file into a .o file in the bin/ directory, maintaining subdirectories
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)  # Create subdirectories in bin/ if they don't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile glad.c into an object file
$(OBJDIR)/glad.o: src/glad.c
	@mkdir -p $(OBJDIR)  # Ensure the bin directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJS) $(TARGET)
