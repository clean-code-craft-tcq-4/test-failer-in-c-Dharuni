#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

#define PRODUCTION_ON   1
#define PRODUCTION_OFF  0
#define PRODUCTION_ENABLED PRODUCTION_ON

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

#if(PRODUCTION_ENABLED != PRODUCTION_ON)
void testalertInCelcius(float celcius, int returnCode) {
    assert(celcius<returnCode);
}  
#endif

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
#if(PRODUCTION_ENABLED == PRODUCTION_ON)   
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
#else
    testalertInCelcius(celcius, returnCode);
#endif
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
