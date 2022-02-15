#define MINIMUM_TEMPERATURE    0.0
#define MAXIMUM_TEMPERATURE    45.0
#define MINIMUM_SOC    20.0
#define MAXIMUM_SOC    80.0
#define MINIMUM_CHARGERATE    0
#define MAXIMUM_CHARGERATE    0.8


#define Discharge_Approach_limit MINIMUM_SOC + ( 0.05* MINIMUM_SOC)
#define Charge_Peak_limit MAXIMUM_SOC - ( 0.05* MAXIMUM_SOC)
