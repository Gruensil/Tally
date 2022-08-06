import serial
import time

# arduino = serial.Serial(port='/dev/ttyUSB0', baudrate=4800, timeout=.1)
# time.sleep(1)

import serial.tools.list_ports

def find_arduino(serial_number):
    for pinfo in serial.tools.list_ports.comports():
        if pinfo.serial_number == serial_number:
            return serial.Serial(pinfo.device, baudrate=4800, timeout=.1)
    raise IOError("Could not find an arduino - is it plugged in?")

arduino = find_arduino(serial_number='A50285BI')
time.sleep(1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.2)
    data = arduino.readline()
    return data


while True:
    num = input("Enter a number: ")
    value = write_read(num)
    print(value)
