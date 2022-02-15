#include <stdio.h>
#include <assert.h>
#include "Parameters.h"


void display(char *stringsToBeDisplayed) {
    if(stringsToBeDisplayed != NULL)
        printf("%s \n", stringsToBeDisplayed);
}
int Is_Temperature_safe(float temperature) {
	
  if(temperature < MINIMUM_TEMPERATURE || temperature > MAXIMUM_TEMPERATURE    ) 
  { 
   Check_low_or_high_temperature_breach(temperature);
   return 0;   
  } 
  else
  {	  
  check_warning_tolerance_approching_low_temp(temperature);
  check_warning_tolerance_approching_high_temp(temperature);
  return 1;  
  }
}
void check_warning_tolerance_approching_low_temp(float temperature)
{
	
   if(temperature>= MINIMUM_TEMPERATURE || temperature <=Temperature_approaching_low_limit )
  {
    display("LOW_temperature_WARNING\n");
  }
  
}
void check_warning_tolerance_approching_high_temp(float temperature)
{
	
   if(temperature >= Temperature_approaching_high_limit   || temperature <= MAXIMUM_TEMPERATURE    )
  {
    display("HIGH_temperature_WARNING\n");
  }
  
}
void Check_low_or_high_temperature_breach(float temperature)
{
	 if(temperature < MINIMUM_TEMPERATURE)
    {
	  display("LOW_temperature_BREACH!\n");
    }
    else
    {
	   display("HIGH_temperature_BREACH!\n"); 
    }
}
int Is_state_of_charge_not_safe(float soc) {
	
  if(soc < MINIMUM_SOC || soc > MAXIMUM_SOC    ) 
  { 
   Check_low_or_high_soc_breach(soc);
   return 0;   
  } 
  else
  {	  
  check_warning_tolerance_approching_discharge(soc);
  check_warning_tolerance_approching_charge_Peak_(soc);
  return 1;  
  }
}
void check_warning_tolerance_approching_discharge(float soc)
{
	
   if(soc>= MINIMUM_SOC || soc <=Charge_Discharge_Approach_limit)
  {
    display("LOW_SOC_WARNING\n");
  }
  
}
void check_warning_tolerance_approching_charge_Peak_(float soc)
{
	
   if(soc >= Charge_Peak_limit   || soc <= MAXIMUM_SOC    )
  {
    display("HIGH_SOC_WARNING\n");
  }
  
}
void Check_low_or_high_soc_breach(float soc)
{
	 if(soc < MINIMUM_SOC)
    {
	  display("LOW_SOC_BREACH!\n");
    }
    else
    {
	   display("HIGH_SOC_BREACH!\n"); 
    }
}


int Is_chargerate_out_of_range(float chargeRate) {
	
  if(chargeRate < MINIMUM_CHARGERATE || chargeRate > MAXIMUM_CHARGERATE    ) 
  { 
   Check_low_or_high_chargeRate_breach(chargeRate);
   return 0;   
  } 
  else
  {	  
  check_warning_tolerance_approching_low_charge_rate(chargeRate);
  check_warning_tolerance_approching_high_charge_rate(chargeRate);
  return 1;  
  }
}
void check_warning_tolerance_approching_low_charge_rate(float chargeRate)
{
	
   if(chargeRate>= MINIMUM_CHARGERATE || chargeRate <= ChargeRate_approaching_low_limit )
  {
    display("LOW_chargeRate_WARNING\n");
  }
  
}
void check_warning_tolerance_approching_high_charge_rate(float chargeRate)
{
	
   if(chargeRate >= ChargeRate_approaching_high_limit   || chargeRate <= MAXIMUM_CHARGERATE    )
  {
    display("HIGH_chargeRate_WARNING\n");
  }
  
}
void Check_low_or_high_chargeRate_breach(float chargeRate)
{
	 if(chargeRate < MINIMUM_CHARGERATE)
    {
	  display("LOW_chargeRate_BREACH!\n");
    }
    else
    {
	   display("HIGH_chargeRate_BREACH!\n"); 
    }
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
  
  return ( (Is_Temperature_safe(temperature))&&(Is_state_of_charge_not_safe( soc))&&(Is_chargerate_out_of_range( chargeRate)));
}

int main() {
	
   
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(45, 80, 0.8));
  assert(!batteryIsOk(45, 80, 0.9));
  assert(!batteryIsOk(60, 90, 0.9));
	
}
