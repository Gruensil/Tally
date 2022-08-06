#!/usr/bin/env python3
# coding: utf-8

"""pc_tally.py - Autostart script for TL PC"""

import argparse
import PyATEMMax
import serial
import time

import serial.tools.list_ports

AtemIp = '192.168.80.9'
ArduinoSerial = 'A50285BI'
NumInputs = 3

def find_arduino(serial_number):
    for pinfo in serial.tools.list_ports.comports():
        if pinfo.serial_number == serial_number:
            return serial.Serial(pinfo.device, baudrate=4800, timeout=.1)
    raise IOError("Could not find an arduino - is it plugged in?")

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.2)
    data = arduino.readline()
    return data


print(f"[{time.ctime()}] Autostart script for tally system")


arduino = find_arduino(serial_number=ArduinoSerial)
time.sleep(1)

# Connect to the switcher
print(f"[{time.ctime()}] Connecting to switcher at {AtemIp}")
switcher = PyATEMMax.ATEMMax()
switcher.connect(AtemIp)
switcher.waitForConnection()


print(f"[{time.ctime()}] Watching for tally changes...")
while True:
    pgm = 0
    prv = 0

    for inputId in range(1, NumInputs+1):
        tally = switcher.tally.bySource.flags[inputId]
        if tally.program:
            pgm = inputId
        if tally.preview:
            prv = inputId

    transmission = pgm << 3
    transmission = transmission | prv

    result = write_read(str(transmission))
    print(result)
    time.sleep(1)

    time.sleep(0.01)     # Avoid hogging processor...

