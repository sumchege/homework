import serial.tools.list_ports as available_ports
import serial
import struct, time, thread


packet = struct.pack('<c3Hf', 'S',0, 1, 2, 48.7)
global rx_count
global tx_count


def tx_func(thread_name, dev, dt):
    # Counter
    global tx_count
    tx_count = 0

    while True:

        dev.write(packet)
        tx_count = tx_count + 1

        # Sleep in s
        time.sleep(dt)


def rx_func(thread_name, dev, dt, f):
    # Counter
    global rx_count
    rx_count = 0;

    while True:
        start_byte = dev.read(1)

        if start_byte == 'S':
            data = dev.read(10)
            data = struct.unpack('<3Hf', data)
            rx_count = rx_count + 1


            # Do things, print data, log time (ms)
            data = data + (time.time()*1000, )
            data = thread_name + str(rx_count)+ str(data[0]) + ', ' + str(data[1]) + ', '+ str(data[2]) + ', '+ str(data[3]) + ', '+ str(data[4])

            f.write(data)

        # Sleep in s
        time.sleep(dt)


def main():
    # Find serial ports and start transactions
    port = available_ports.comports()[0];

    # Logging file
    f = open('data.csv', 'a')

    # Config port
    dev = serial.Serial(port.device, baudrate=115200)

    try:
        thread.start_new_thread(tx_func, 'A', dev, 0)
        thread.start_new_thread(rx_func, 'A', dev, 0)
    except:
        print 'Failed to create threeads'

    def closeIO():
        f.write('Final Count Rx: ' + str(rx_count) + 'Tx: ' + str(rx_count))
        dev.close()
        f.close()

    import atexit
    atexit.register(closeIO)


    while True:
        pass


if __name__ == '__main__':
    main()
