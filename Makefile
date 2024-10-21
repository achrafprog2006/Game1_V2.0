# Compiler and Flags
CXX = g++
WIN_CXX = x86_64-w64-mingw32-g++
CXXFLAGS = -std=c++11 -Wall -g -I./include 
WIN_CXXFLAGS = -std=c++11 -Wall -g -I./abcd -I./include

# Libraries
LIBS = -lglfw -lGLEW -lGL -lm
WIN_LIBS = ./GLFWwindows/libglfw3.a -lopengl32 -lgdi32 -luser32 -lwinmm

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
OBJS_LINUX = $(patsubst src/%.cpp, $(OBJDIR)/linux/%.o, $(SRCS))
OBJS_WINDOWS = $(patsubst src/%.cpp, $(OBJDIR)/windows/%.o, $(SRCS))
OBJS_LINUX += $(OBJDIR)/linux/glad.o  # Add glad.o to OBJS for Linux
OBJS_WINDOWS += $(OBJDIR)/windows/glad.o  # Add glad.o to OBJS for Windows

# Output executables
LINUX_TARGET = build/Game1
WIN_TARGET = build/Game1.exe

# Default target
all: $(LINUX_TARGET) $(WIN_TARGET)

# Link the object files to create the Linux executable
$(LINUX_TARGET): $(OBJS_LINUX)
	$(CXX) $(OBJS_LINUX) -o $(LINUX_TARGET) $(LIBS)

# Link the object files to create the Windows executable
$(WIN_TARGET): $(OBJS_WINDOWS)
	$(WIN_CXX) $(OBJS_WINDOWS) -o $(WIN_TARGET) $(WIN_LIBS)

# Compile each .cpp file into a .o file in the bin/linux/ directory, maintaining subdirectories for Linux
$(OBJDIR)/linux/%.o: src/%.cpp
	@mkdir -p $(dir $@)  # Create subdirectories in bin/ if they don't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile each .cpp file into a .o file in the bin/windows/ directory, maintaining subdirectories for Windows
$(OBJDIR)/windows/%.o: src/%.cpp
	@mkdir -p $(dir $@)  # Create subdirectories in bin/ if they don't exist
	$(WIN_CXX) $(WIN_CXXFLAGS) -c $< -o $@

# Compile glad.c into an object file for Linux
$(OBJDIR)/linux/glad.o: src/glad.c
	@mkdir -p $(OBJDIR)/linux  # Ensure the bin/linux directory exists
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile glad.c into an object file for Windows
$(OBJDIR)/windows/glad.o: src/glad.c
	@mkdir -p $(OBJDIR)/windows  # Ensure the bin/windows directory exists
	$(WIN_CXX) $(WIN_CXXFLAGS) -c $< -o $@
	
# Clean up build files
.PHONY: clean
clean:
	rm -rf $(OBJDIR)/*.o $(LINUX_TARGET) $(WIN_TARGET)
