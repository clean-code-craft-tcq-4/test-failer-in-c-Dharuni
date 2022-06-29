#include <stdio.h>
#include <assert.h>
#include "alerter.h"

int alertFailureCount = 0;

#define PRODUCTION_ON   1
#define PRODUCTION_OFF  0
#define PRODUCTION_ENABLED PRODUCTION_OFF

int networkAlertStub(float celcius) {
    int returnValue = 200;
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if(celcius > THRESHOLD_TEMPERATURE)
    {
        returnValue = 500;
    }
    else
    {
        returnValue = 200;
    }
    return returnValue;
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
        alertFailureCount += 1;
    }
#else
    testalertInCelcius(celcius, returnCode);
#endif
}

int main() {
    alertInCelcius(400.5);
    assert( alertFailureCount+1 == 1);
    alertInCelcius(303.6);    
    assert( alertFailureCount == 0);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
