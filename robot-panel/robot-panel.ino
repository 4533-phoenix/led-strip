#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(42, 7, 7,
                            NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
                            NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
                            NEO_GRB);

void setup() {
  matrix.begin();
  matrix.setBrightness(8);
  matrix.setTextColor(matrix.Color(255,0,0));
  matrix.setTextWrap(false);
}

void scrollText(String text) {
  int x = matrix.width();
  int pixelsInText = text.length() * 6;

  while (x > 0 - pixelsInText) {
    matrix.fillScreen(matrix.Color(0, 0, 0));
    matrix.setCursor(--x, 0);
    matrix.print(text);
    matrix.show();
    delay(100);
  }
}

void loop() {
  scrollText("Team 4533");
  scrollText("Vicki");
}
