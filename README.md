# Motorbike_Shifter_EGI
Motorbike Shifter and engaged gear indicator

This project intend to complete this tutorial http://www.jbx9.16mb.com/index.php?page=GIND and achieve motorcycle engaged gear indicator + Shift light by measuring actual engine speed and engaged gear.

RPM is aquired through the Alternator. Votlage between two phases is picked up and shaped by "RPM Signal Conditioning" stage. Then it's isolated by an optocoupler and fed into the Micro controler.

Mechanical modification on the shifter allows to short one wire to bike ground when corresponding gear is engaged. Each wire is connected to a different voltage divider "step". Result is 6 discrete voltage steps barely equally distributed between 0 and 5V. Correspondance table is given in schematic.

An ATTiny84 MCU does the signal analysis and drives 6 independant outputs which can be connected on embeded LEDs or externalized using header connector.

PCB files are available at https://circuitmaker.com/Projects/Details/Alexis-Damiens-2/Shift-light
