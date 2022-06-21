typedef enum { WHITE,	RED, BLACK,	YELLOW,	VIOLET } MajorColor;

typedef enum { BLUE, ORANGE, GREEN,	BROWN, SLATE } MinorColor;

typedef struct {
    MajorColor majorColor;
    MinorColor minorColor;
}ColorPair;

#define MAX_COLORPAIR 16


int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

int 	printColorMap			(void);
int 	GetPairNumberFromColor	(const ColorPair* colorPair);
void 	testPairToNumber		(MajorColor major, MinorColor minor, int expectedPairNumber);
