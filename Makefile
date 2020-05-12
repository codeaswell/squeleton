build:
	gcc -w -std=c99 -Wfatal-errors \
	./src/*.c \
	-o game \
	-lSDL2 \
	-lSDL2_image \
	-lSDL2_ttf \
	-lSDL2_mixer;

clean:
	rm ./game;

run:
	./game;
