# EEPROM--Arduino
This applies for I2C based EEPROM from mmicrochip and TI.
This works particularly on arduino with Wire library
Accessing EEPROM for different datatype
The repository includes the programs to write and consequentially read from the bit wise accessed EEPROM for the arduino.
The file int_write.ino reads and writes integer data into the EEPROM
The file page_write.ino reads and writes pages of string imnto the EEPROM. This proagram has a special functuion of writing from the next byte of the previously stoered data.
