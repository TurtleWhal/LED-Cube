static int c;

for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      disps[0]->drawPixel(j, 7 - i, HSL(((i + j + c) * (360 / (7 + 7))) % 360, 1, 0.5)); // rgb
      disps[1]->drawPixel(7 - j, 7 - i, HSL(((i + j + c) * (360 / (7 + 7))) % 360, 1, 0.5)); // rgb
      disps[2]->drawPixel(j, 7 - i, HSL(((i + j + ((c + 135) % 360)) * (360 / (7 + 7))) % 360, 1, 0.5)); // rgb
      disps[3]->drawPixel(j, i, HSL(((i + j + c) * (360 / (7 + 7))) % 360, 1, 0.5)); // rgb
    }
  }

  disps[0]->show();
  disps[1]->show();
  disps[2]->show();
  disps[3]->show();
  delay(50);

  c = c - 1 % 360;
  if (c < 0)
    c = 360;