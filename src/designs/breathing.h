static int color = 100;
static float j;

float brightness = -2 * (j - 0.5) * (j - 0.5) + 0.5;

for (int i = 0; i < 4; i++)
{
    disps[i].clear();
    // disps[i].fillRect(0, 0, 8, 8, HSL(color, 1, brightness));

    // disps[i].fillCircle(4, 4, 5, HSL(color, 1, constrain(brightness - 0.4, 0, 0.5)));
    // disps[i].fillCircle(4, 4, 4, HSL(color, 1, constrain(brightness - 0.3, 0, 0.5)));
    // disps[i].fillCircle(4, 4, 3, HSL(color, 1, constrain(brightness - 0.2, 0, 0.5)));
    // disps[i].fillCircle(4, 4, 2, HSL(color, 1, constrain(brightness - 0.1, 0, 0.5)));
    // disps[i].fillCircle(4, 4, 1, HSL(color, 1, constrain(brightness - 0.0, 0, 0.5)));

    disps[i].fillRoundRect(0, 0, 8, 8, 1, HSL(color, 1, constrain(brightness - 0.4, 0, 0.5)));
    disps[i].fillRoundRect(0, 0, 8, 8, 3, HSL(color, 1, constrain(brightness - 0.3, 0, 0.5)));
    disps[i].fillRoundRect(1, 1, 6, 6, 2, HSL(color, 1, constrain(brightness - 0.2, 0, 0.5)));
    disps[i].fillRoundRect(2, 2, 4, 4, 2, HSL(color, 1, constrain(brightness - 0.1, 0, 0.5)));
    disps[i].fillRoundRect(3, 3, 2, 2, 1, HSL(color, 1, constrain(brightness - 0.0, 0, 0.5)));
    disps[i].show();
}

j = j + 0.002;

if (j > 1)
{
    j = 0;
    color = random(0, 360);
    delay(1200);
}

// delay(10);