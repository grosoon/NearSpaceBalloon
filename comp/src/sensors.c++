/*
 * NEAR SPACE BALLOON PROJECT
 * FLIGHT COMPUTER CODE
 *
 * GRINNELL SPACE EXPLORATION AGENCY
 *
 * (c) 2015.  All Rights Reserved.
 */

 #include "sensors.h"

/*
 * Return current probe latitude, in degrees above the equator.
 */
double getLatitude() {
	return 0.0; // TODO Implement
}

/*
 * Return current probe longitude, in degrees east of Greenwich.
 */
double getLongitude() {
	return 0.0; // TODO Implement
}

/*
 * Return current probe altitude, in feet above sea level.
 */
double getAltitude() {
	return 0.0; // TODO Implement
}

/*
 * Return current air temperature, in Kelvin
 */
double getTemperature() {
  Wire.requestFrom(tmp102Address,2); 

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it's a 12bit int, using two's compliment for negative
  int temperatureSum = ((MSB << 8) | LSB) >> 4; 

  double celsius = temperatureSum*0.0625;
  return celsius;
}

/* 
 * Return current air pressure, in bars
 */
double getPressure() {
	return 0.0; // TODO Implement
}
