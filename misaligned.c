#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors =  sizeof(minorColor) / sizeof(minorColor[0]);

int printColorMap() {
    
    int majorColorCount = 0,minorColorCount = 0;
    ColorPair colorPairReference;
    printf("\n Color Coding Reference Manual\n");
    printf("Major Color | \t Minor Color | \t Pair Number \n");
    for(majorColorCount=0;majorColorCount<numberOfMajorColors;majorColorCount++)
    {
        for(minorColorCount=0;minorColorCount<numberOfMinorColors;minorColorCount++)
        {
            colorPairReference.majorColor = (MajorColor)majorColorCount;
            colorPairReference.minorColor = (MinorColor)minorColorCount;
            int pairNumberReference = GetPairNumberFromColor(&colorPairReference);
            printf("%d | %s | %s\n", pairNumberReference, majorColor[majorColorCount], minorColor[minorColorCount]);

        }
    }
    return majorColorCount * minorColorCount;
}

int GetPairNumberFromColor(const ColorPair* colorPair) {
    return colorPair->majorColor * numberOfMinorColors +
            colorPair->minorColor + 1;
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

int main() {
    int result = printColorMap();
    assert(result == 25);
    testPairToNumber(BLACK, ORANGE, 12);
    testPairToNumber(VIOLET, SLATE, 25);
    printf("All is well (maybe!)\n");
    return 0;
}
