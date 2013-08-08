/*
  AddressableLEDStrip.h - A simple library for interacting with the
  FLB-W5050RGB-16-5-N14 addressable RGB LED strip sold by SparkFun
  (https://www.sparkfun.com/products/11272)
*/

#ifndef AddressableLEDStrip_h
#define AddressableLEDStrip_h


#include "Arduino.h"

class AddressableLEDStrip
{
  public:
    // Create the LED strip object with the clock pin, serial data pin and the number of LEDs in the strip.
    AddressableLEDStrip(uint8_t clk_pin, uint8_t spi_pin, uint16_t num_leds);

    // By default all color values will enforced to be between 0 - 255.
    // Set this to true if you want to preserve the set value, even though the LED will only get 0 - 255
    bool allow_out_of_bounds;

    // Sets all the LEDs to OFF
    // This does not write them to the strip.
    void clear_leds();

    // Set the RGB value on a single LED
    // This does not write anything to the strip.
    void set_led(uint16_t index, int8_t red, int8_t green, int8_t blue);

    // Set all the LEDs to the same RGB value.
    // This does not write them to the strip.
    void set_all_leds(int8_t red, int8_t green, int8_t blue);

    // Update the LED strip with all the LED values.
    void send();

    // Get the number of LED that are in this strip (or at least what you set the length to be).
    uint16_t length();

    // Get the red value at an LED index
    int8_t get_red(uint16_t index);

    // Get the green value at an LED index
    int8_t get_green(uint16_t index);

    // Get the blue value at an LED index
    int8_t get_blue(uint16_t index);

  private:
    int clk;
    int sdi;
    int strip_len;
    uint16_t *red_values;
    uint16_t *green_values;
    uint16_t *blue_values;

    void _send_color_bits(int8_t value);
};

#endif