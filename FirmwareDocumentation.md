#Documentation of Firmware

# Introduction #

This page has all current documentaion of the OpenEVSE Firmware and its modules

# Classes #

## CLI Class ##
### Members ###
### Public Methods ###

## OnboardDisplay Class ##
### Members ###
### Public Methods ###

## Gfi Class ##
### Members ###
### Public Methods ###

## J1772Pilot Class ##
### Members ###
### Public Methods ###

## J1772EVSEController Class ##
### Members ###
  * [J1772Pilot](FirmwareDocumentation#J1772Pilot_Class.md) m\_Pilot
  * Gfi m\_Gfi;
  * unsigned long m\_GfiTimeout;
  * unsigned long m\_GfiRetryCnt;
  * uint8\_t m\_GfiTripCnt;
  * uint8\_t m\_bFlags; // ECF\_xxx
  * THRESH\_DATA m\_ThreshData;
  * uint8\_t m\_EvseState;
  * uint8\_t m\_PrevEvseState;
  * uint8\_t m\_TmpEvseState;
  * unsigned long m\_TmpEvseStateStart;
  * uint8\_t m\_CurrentCapacity; // max amps we can output
  * time\_t m\_ChargeStartTime;
  * time\_t m\_ElapsedChargeTime;
  * time\_t m\_ElapsedChargeTimePrev;
### Public Methods ###