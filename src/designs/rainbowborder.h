static int c;

for (int i = 0; i < 8; i++)
    disps[3].drawPixel(0, i, HSL(c + (i * 8), 1, 0.5));

for (int i = 1; i < 8; i++)
    disps[3].drawPixel(8 - i, 0, HSL(c + ((i - 8) * 8), 1, 0.5));

for (int i = 0; i < 8; i++)
    disps[1].drawPixel(7, 7 - i, HSL(c + ((i - 15) * 8), 1, 0.5));

for (int i = 0; i < 7; i++)
    disps[1].drawPixel(i, 7, HSL(c + ((i - 22) * 8), 1, 0.5));

for (int i = 0; i < 8; i++)
    disps[0].drawPixel(i, 7, HSL(c + ((i - 29) * 8), 1, 0.5));

for (int i = 0; i < 7; i++)
    disps[0].drawPixel(0, i, HSL(c + ((i - 37) * 8), 1, 0.5));

disps[3].show();
disps[1].show();
disps[0].show();

c = c + 1 % 360;

delay(10);