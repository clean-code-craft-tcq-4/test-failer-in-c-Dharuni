#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);

void ColorPairToString(const ColorPair* colorPair, char* buffer) {
    sprintf(buffer, "%s %s",
        majorColor[colorPair->majorColor],
        minorColor[colorPair->minorColor]);
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    ColorPair colorPair;
    int zeroBasedPairNumber = pairNumber - 1;
    colorPair.majorColor = 
        (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    colorPair.minorColor =
        (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
    return colorPair;
}

void testPairToNumber(
    MajorColor major,
    MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetPairNumberFromColor(&colorPair);
    assert(pairNumber == expectedPairNumber);
}

int printColorMap() {

//     int i = 0, j = 0;
//     for(i = 0; i < 5; i++) {
//         for(j = 0; j < 5; j++) {
//             printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
//         }
//     }
//     return i * j;
    int majorColorCount,minorColorCount;
    ColorPair colorPairReference;
    char colorPairManual[MAX_COLORPAIR];
    printf("\n Color Coding Reference Manual\n");
    printf("Major Color | \t Minor Color | \t Pair Number \n");
    for(majorColorCount=0;majorColorCount<numberOfMajorColors;majorColorCount++)
    {
        for(minorColorCount=0;minorColorCount<numberOfMinorColors;minorColorCount++)
        {
            colorPairReference.majorColor = (MajorColor)majorColorCount;
            colorPairReference.minorColor = (MinorColor)minorColorCount;
            int pairNumberReference = GetPairNumberFromColor(&colorPairReference);
            ColorPairToString(&colorPairReference, colorPairManual);
            printf(" %s\t%d\n", colorPairManual,pairNumberReference );

        }
    }
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
