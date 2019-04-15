/**
 * @file HX711.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class HX711 provides the functionality to obtain the weight on the load cell.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef HX711_h
#define HX711_h

#include <stdint.h>

class HX711
{
private:
	int PD_SCK;	///< Power Down and Serial Clock Input Pin
	int DOUT;		///< Serial Data Output Pin
	int GAIN;		///< amplification factor
	long OFFSET; ///< used for tare weight
	float SCALE;	///< used to return weight in grams, kg, ounces, whatever

public:
	// define clock and data pin, channel, and gain factor
	// channel selection is made by passing the appropriate gain: 128 or 64 for channel A, 32 for channel B
	// gain: 128 or 64 for channel A; channel B works with 32 gain factor only
	
    /**
     * @brief Initialises the weight sensor
     *
     * @param dout The serial data out pin
     * @param pd_sck Power Down and Serial Clock Input Pin
     * @param gain The gain
     */
  void setup(int dout, int pd_sck, int gain = 128);

	virtual ~HX711();

	/** check if HX711 is ready
	* from the datasheet: When output data is not ready for retrieval, digital output pin DOUT is high. Serial clock
	* input PD_SCK should be low. When DOUT goes to low, it indicates data is ready for retrieval.
  */
	bool is_ready();

	/** set the gain factor; takes effect only after a call to read()
	* channel A can be set for a 128 or 64 gain; channel B has a fixed 32 gain
	* depending on the parameter, the channel is also set to either A or B
  * @param gain The gain of the sensor
	*/
  void set_gain(int gain = 128);
  /** Gets the gain that has been set
  */
	int get_gain();

	/** waits for the chip to be ready and returns a reading 
  */
	long read();

	/** @return an average reading
  * @param times The number of readings taken before the average value is caluclated.
  */
	long read_average(int times = 10);

	/** @return (read_average() - OFFSET), that is the current value without the tare weight
	* @param times = how many readings to do
  */
  double get_value(int times = 1);

	/** @return get_value() divided by SCALE, that is the raw value divided by a value obtained via calibration
	 @param times = how many readings to do
  */
	float get_units(int times = 1);

	/** Set the OFFSET value for tare weight
  * @param times How many times to read the tare value
	*/
  void tare(int times = 10);

	/** set the SCALE value; this value is used to convert the raw data to "human readable" data (measure units)
  */
  void set_scale(float scale = 1.f);

	/** set OFFSET, the value that's subtracted from the actual reading (tare weight)
	*/
  void set_offset(long offset = 0);

	/** puts the chip into power down mode
  */
	void power_down();

	/** wakes up the chip after power down mode
  */
	void power_up();
};

#endif /* HX711_h */
