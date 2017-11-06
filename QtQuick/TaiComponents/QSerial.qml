import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQml 2.2
import QtQuick 2.0

import QChannelSerial 1.0

ApplicationWindow
{
    id: app
    visible: true
    QChannelSerial {
        id: serial
    }

    Component.onCompleted: {
         console.log(serial.channels().length);



        // if successfull, configure port

//        if(serial.isOpen())
//        {
//            serial.paramSet('baud', '9600');
//            serial.paramSet('bits', '8');
//            serial.paramSet('parity', 'even');
//            serial.param('stop', '0');
//            serial.paramSet('dtr', '0');
//            serial.paramSet('rts', '1');

//            serial.writeBytes([1,2,3,4,5]);
//            serial.writeString('12345');
//            var data = serial.readBytes();
//            console.log(data);
//        }

    }

}
