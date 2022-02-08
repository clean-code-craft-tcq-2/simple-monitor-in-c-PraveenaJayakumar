#include <stdio.h>
#include <assert.h>

#define MINIMUM_TEMPERATURE    0.0
#define MAXIMUM_TEMPERATURE    45.0
#define MINIMUM_SOC    20.0
#define MAXIMUM_SOC    80.0
#define MINIMUM_CHARGERATE    0
#define MAXIMUM_CHARGERATE    0.8

void display(char *stringsToBeDisplayed) {
    if(stringsToBeDisplayed != NULL)
        printf("%s \n", stringsToBeDisplayed);
}
int Is_Temperature_safe(float temperature) {
	
  if(temperature < MINIMUM_TEMPERATURE || temperature > MAXIMUM_TEMPERATURE) {
    display("Temperature out of range!\n");
    return 0;
  } 
  return 1;
}

int Is_state_of_charge_not_safe(float soc) {
	
  if(soc < MINIMUM_SOC || soc > MAXIMUM_SOC) {
    display("State of Charge out of range!\n");
    return 0;
  }
  return 1;
}

int Is_state_of_charge_not_safe(float chargeRate) {
	
  if(chargeRate > MAXIMUM_CHARGERATE) {
    display("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  return ( (Is_Temperature_safe(temperature))(Is_state_of_charge_not_safe( soc))(Is_state_of_charge_not_safe( chargeRate)))
}

int main() {
	
  int temp_test_state , soc_test_state , chargeRate_test_state ;   
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
