#
#    ██████╗  ██████╗ ██╗  ██╗██████╗     ██╗███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗ 
#    ██╔══██╗██╔════╝ ╚██╗██╔╝██╔══██╗   ██╔╝██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
#    ██████╔╝██║  ███╗ ╚███╔╝ ██║  ██║  ██╔╝ █████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗  
#    ██╔═══╝ ██║   ██║ ██╔██╗ ██║  ██║ ██╔╝  ██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝  
#    ██║     ╚██████╔╝██╔╝ ██╗██████╔╝██╔╝   ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
#    ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═════╝ ╚═╝    ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝ Version 1.0
#
#    PGXD/Engine by PGXD/HatLink                                                                                        
#    https://github.com/Pr0G4m1ngXD/pgxdengine
#
#    turn the lights on.
#
.PHONY: default all engine runtime lvltool savetool clean

# Executable titles
RUNTIME_NAME ?= PGXDRuntime
LVLTOOL_NAME ?= PGXDEditor
SAVEDIT_NAME ?= saveEditor

# BUILD_MODE: [DEBUG | DEFAULT]
BUILD_MODE   ?= DEBUG

# Raylib Variables
RAYLIB_PATH  := C:/raylib/raylib

# Compiler
CC := gcc


# Define flags
# -std=c99					Using the language standard C from 1999 revision
# -D_DEFAULT_SOURCE 		Use with -std=c99 on Linux and PLATFORM_WEB, required for timespec
# -Wno-missing-braces		Ignore invalid warning, GCC bug 53119
# -Wall -Wextra -Werror 	Most warnings will be an error
CFLAGS += -std=gnu99 -D_DEFAULT_SOURCE -Wno-missing-braces -Wall -Wextra -Werror -DPLATFORM_DESKTOP

INCLUDE_PATHS = -I. -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external -IPGXDEngine/include
LDLIBS = -L. -LC:/raylib/raylib/src -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm

ifeq ($(BUILD_MODE),DEBUG)
    CFLAGS += -g -O0 
else
    CFLAGS += -s -O1 -Wl,--subsystem,windows
endif

# Directories
OUTPUT_DIR      ?= bin
RESOURCE_DIR    ?= resources
BUILD_DIR        = build
SRC_DIR          = src
INCL_DIR		 = include
ENGINE_DIR       = PGXDEngine
RUNTIME_DIR      = runtime
LEVEL_TOOL_DIR   = tools/lvl-editor
SAVE_TOOL_DIR    = tools/save-editor



# Source files
ENGINE_SRC       = $(wildcard $(ENGINE_DIR)/$(SRC_DIR)/*.c)
ENGINE_INCL_SRC  = $(wildcard $(ENGINE_DIR)/$(INCL_DIR)/*.c)
RUNTIME_SRC      = $(wildcard $(RUNTIME_DIR)/$(SRC_DIR)/*.c)
LEVEL_TOOL_SRC   = $(wildcard $(LEVEL_TOOL_DIR)/$(SRC_DIR)/*.c)
SAVE_TOOL_SRC    = $(wildcard $(SAVE_TOOL_DIR)/$(SRC_DIR)/*.c)

# Header files
ENGINE_SRC_H     = $(wildcard $(ENGINE_DIR)/$(SRC_DIR)/*.h)
RUNTIME_SRC_H    = $(wildcard $(RUNTIME_DIR)/$(SRC_DIR)/*.h)
LEVEL_TOOL_SRC_H = $(wildcard $(LEVEL_TOOL_DIR)/$(SRC_DIR)/*.h)
SAVE_TOOL_SRC_H  = $(wildcard $(SAVE_TOOL_DIR)/$(SRC_DIR)/*.h)

# Object files
ENGINE_OBJ       = $(patsubst $(ENGINE_DIR)/$(SRC_DIR)/%.c, $(BUILD_DIR)/$(ENGINE_DIR)/%.o, $(ENGINE_SRC))
ENGINE_INCL_OBJ  = $(patsubst $(ENGINE_DIR)/$(INCL_DIR)/%.c, $(BUILD_DIR)/$(INCL_DIR)/%.o, $(ENGINE_INCL_SRC))
RUNTIME_OBJ      = $(patsubst $(RUNTIME_DIR)/$(SRC_DIR)/%.c, $(BUILD_DIR)/$(RUNTIME_DIR)/%.o, $(RUNTIME_SRC))
LEVEL_TOOL_OBJ   = $(patsubst $(LEVEL_TOOL_DIR)/$(SRC_DIR)/%.c, $(BUILD_DIR)/$(LEVEL_TOOL_DIR)/%.o, $(LEVEL_TOOL_SRC))
SAVE_TOOL_OBJ    = $(patsubst $(SAVE_TOOL_DIR)/$(SRC_DIR)/%.c, $(BUILD_DIR)/$(SAVE_TOOL_DIR)/%.o, $(SAVE_TOOL_SRC))



default:
	@echo "No target specified.  Stop."
	@echo "make -> target: [ all | engine | runtime | lvltool | savetool ]"

engine: $(ENGINE_INCL_OBJ) $(ENGINE_OBJ) 

runtime: $(OUTPUT_DIR)/$(RUNTIME_NAME)

lvltool: $(OUTPUT_DIR)/$(LVLTOOL_NAME)

# Build engine include objects
$(BUILD_DIR)/$(INCL_DIR)/%.o: $(ENGINE_DIR)/$(INCL_DIR)/%.c | $(BUILD_DIR)/$(INCL_DIR)/ 
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< -lWs2_32

# Build engine objects
$(BUILD_DIR)/$(ENGINE_DIR)/%.o: $(ENGINE_DIR)/$(SRC_DIR)/%.c | $(BUILD_DIR)/$(ENGINE_DIR)/ 
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< -lWs2_32


# Build executable runtime
$(OUTPUT_DIR)/$(RUNTIME_NAME): $(ENGINE_INCL_OBJ) $(ENGINE_OBJ) $(RUNTIME_OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(CFLAGS) pgxd.rc.data $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -lWs2_32

# Build runtime objects
$(BUILD_DIR)/$(RUNTIME_DIR)/%.o: $(RUNTIME_DIR)/$(SRC_DIR)/%.c | $(BUILD_DIR)/$(RUNTIME_DIR)/ 
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< -lWs2_32

# Build lvltool
$(OUTPUT_DIR)/$(LVLTOOL_NAME): $(ENGINE_INCL_OBJ) $(ENGINE_OBJ) $(LEVEL_TOOL_OBJ)
	$(CC) -o $@ $^ $(CPPFLAGS) $(CFLAGS) pgxd.rc.data $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -lWs2_32

# Build lvltool objects
$(BUILD_DIR)/$(LEVEL_TOOL_DIR)/%.o: $(LEVEL_TOOL_DIR)/$(SRC_DIR)/%.c | $(BUILD_DIR)/$(LEVEL_TOOL_DIR)/ 
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDE_PATHS) $(LDFLAGS) $(LDLIBS) -c -o $@ $< -lWs2_32

# Make directories
$(BUILD_DIR)/$(ENGINE_DIR)/:
	mkdir $@ -p

$(BUILD_DIR)/$(INCL_DIR)/:
	mkdir $@ -p

$(BUILD_DIR)/$(RUNTIME_DIR)/:
	mkdir $@ -p

$(BUILD_DIR)/$(LEVEL_TOOL_DIR)/:
	mkdir $@ -p

$(BUILD_DIR)/$(SAVE_TOOL_DIR)/:
	mkdir $@

clean:
	rm -rf $(BUILD_DIR)