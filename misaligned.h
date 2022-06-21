typedef enum { WHITE,	RED, BLACK,	YELLOW,	VIOLET } MajorColor;

typedef enum { BLUE, ORANGE, GREEN,	BROWN, SLATE } MinorColor;

typedef struct {
    MajorColor majorColor;
    MinorColor minorColor;
}ColorPair;

int 	printColorMap			(void);
int 	GetPairNumberFromColor	(const ColorPair* colorPair);
void 	testPairToNumber		(MajorColor major, MinorColor minor, int expectedPairNumber);
