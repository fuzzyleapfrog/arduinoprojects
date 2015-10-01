# RainbowDash

This project uses an RGB LED to slowly fade through the colours of the
rainbow.

Since analogWrite() takes values between 0 and 255, the colours are
defined by distributing a sum of 255 between two of the three basic
colours red, green and blue –
from red via yellow to green, from green via cyan to blue and finally from
blue via magenta to red.
