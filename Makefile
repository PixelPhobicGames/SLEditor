
    UOS=$(shell uname)
    
    ifeq ($(OS),Windows_NT)
        PLATFORM = windows
    else
		ifeq ($(UOS),Linux)
			PLATFORM = linux
		endif
	endif
  ifeq ($(PLATFORM),windows)
    CC = C:\raylib\mingw\bin\g++.exe
    exename ?= SLEditor.exe
    CFLAGS  = -static -Os -Wall -Iexternal -DPLATFORM_DESKTOP -lopengl32 -lraylib -lgdi32 -lwinmm 
  endif
  ifeq ($(PLATFORM),linux)
    CC = g++
    exename ?= SLEditor
    CFLAGS  =  -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
  endif

  all: $(TARGET)
	  $(CC) SLEditor.cpp -o $(exename) $(CFLAGS)
