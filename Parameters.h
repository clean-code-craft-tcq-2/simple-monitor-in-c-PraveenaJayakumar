#define MINIMUM_TEMPERATURE    0.0
#define MAXIMUM_TEMPERATURE    45.0
#define MINIMUM_SOC    20.0
#define MAXIMUM_SOC    80.0
#define MINIMUM_CHARGERATE    0
#define MAXIMUM_CHARGERATE    0.8

#define English 1
#define German 2
#define Language English



#define Charge_Discharge_Approach_limit (MINIMUM_SOC + ( 0.05* MINIMUM_SOC))
#define Charge_Peak_limit (MAXIMUM_SOC - ( 0.05* MAXIMUM_SOC))

#define Temperature_approaching_low_limit (MINIMUM_TEMPERATURE + ( 0.05* MINIMUM_TEMPERATURE))
#define Temperature_approaching_high_limit (MAXIMUM_TEMPERATURE - ( 0.05* MAXIMUM_TEMPERATURE))

#define ChargeRate_approaching_low_limit (MINIMUM_CHARGERATE + ( 0.05* MINIMUM_CHARGERATE))
#define ChargeRate_approaching_high_limit (MAXIMUM_CHARGERATE - ( 0.05* MAXIMUM_CHARGERATE))
