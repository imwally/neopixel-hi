#include <Adafruit_NeoPixel.h>
#include <gol.h>

#define PIXELS 32
#define PIN 6
#define MAX_BRIGHTNESS 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELS, PIN, NEO_GRB + NEO_KHZ800);


int grid[HEIGHT][WIDTH] = {
        {1,0,1,0,1,0,0,0},
        {1,0,1,0,0,0,0,0},
        {1,1,1,0,1,0,0,0},
        {1,0,1,0,1,0,0,0},
};


void setup() {
        strip.begin();
        strip.show();
        strip.setBrightness(MAX_BRIGHTNESS);
}


void loop() {
        printGrid(grid);
        shiftGrid(grid);
        delay(500);
}


void printGrid(int grid[HEIGHT][WIDTH]) {
        int cell = 0;
        for (int i = 0; i < HEIGHT; i++) {
                for (int j = 0; j < WIDTH; j++) {
                        if (grid[i][j] == 1) {
                                strip.setPixelColor(cell, strip.Color(255,0,0));
                        } else {
                                strip.setPixelColor(cell, strip.Color(0,0,0));
                        }
                        cell++;
                }
        }

        strip.show();
}


void shiftGrid(int grid[HEIGHT][WIDTH]) {
        for (int i = 0; i < HEIGHT; i++) {
                // Remember first element for when the index reaches the end
                // because by then the first element would have been shifted
                // over and would no longer exist.
                int first = grid[i][0];
                for (int j = 0; j < WIDTH; j++) {
                        if (j == WIDTH-1) {
                                grid[i][j] = first;
                        } else {
                                grid[i][j] = grid[i][j+1];
                        }
                }
        }
}
