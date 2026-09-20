CC = gcc

CFLAGS = -Wall -Wextra -IC:/raylib/raylib/src

LIBS = -LC:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm

TARGET = quick-sort-visualizer.exe
SOURCE = main.c visualizer.c quick-sort.c

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	del $(TARGET)
