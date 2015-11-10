/*
 * NEAR SPACE BALLOON PROJECT
 * FLIGHT COMPUTER CODE
 *
 * GRINNELL SPACE EXPLORATION AGENCY
 *
 * (c) 2015.  All Rights Reserved.
 */
#include <SFE_BMP180.h>
#include <Wire.h>


double getLatitude();
double getLongitude();
double getAltitude();
double getTemperature();
double getPressure();

void sensorSetup();
