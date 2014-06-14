CC= g++
CFLAGS=-c -Wall -std=c++11 -O3
INCLUDE= \
	-Iinclude \
	-I/usr/include/GL \
	-I/usr/include/SDL2 \
	-I/usr/include/freetype2 \
	-I/usr/include/libpng16

LDFLAGS= 
LIBS= \
	-lSDL2 \
	-lfreetype \
	-lSDL_ttf \
	-lpng \
	-lGL

SOURCES= \
	src/SDL_ttf_lite.cpp \
	src/status_effect.cpp \
	src/enemy_inst.cpp \
	src/font.cpp \
	src/sprite_instance.cpp \
	src/damage.cpp \
	src/instance.cpp \
	src/renderer.cpp \
	src/enemy_type.cpp \
	src/debris_inst.cpp \
	src/powerup_inst.cpp \
	src/shader.cpp \
	src/spriteset.cpp \
	src/player_inst.cpp \
	src/glx.cpp \
	src/cam.cpp \
	src/player_type.cpp \
	src/world.cpp \
	src/wall.cpp \
	src/debris_type.cpp \
	src/bad_bullet_inst.cpp \
	src/bullet_type.cpp \
	src/shaderprogram.cpp \
	src/bullet_inst.cpp \
	src/oslayer.cpp \
	src/bad_bullet_type.cpp \
	src/powerup_type.cpp \
	src/ttf.cpp \
	src/input.cpp \
	src/vbo.cpp \
	src/physical.cpp \
	src/png.cpp \
	main.cpp

OBJECTS= $(SOURCES:.cpp=.o)

all: sscroll

sscroll: $(OBJECTS)
	$(CC) $(LDFLAGS) $(LIBS) $(OBJECTS) -o sscroll

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	rm $(OBJECTS) sscroll
