import QtQuick 2.0
import QtQuick.Window 2.0
Window{
    visible: true
    width: 400
    height: 400


Canvas{
    width: 400
    height: 400
    anchors.fill: parent

    function rnd(a, b){
        return a + (b-a)*Math.random()
    }

    onPaint:
    {
        var ctx = getContext("2d")
        ctx.fillStyle  = 'rgb(.1, .1, .1)'
        ctx.fillRect(0, 0, width, height)

        for(var i=0; i<100; i++)
        {
            var x=rnd(0, width)
            var y=rnd(0, height)
            var d = rnd(1, 5)
            var r = rnd(.5, 1)
            var g = rnd(.5, 1)
            var b = rnd(.5, 1)
            var c = Qt.rgba(r, g, b, 1.)
            ctx.fillStyle = c
            ctx.beginPath()
            ctx.ellipse(x, y, d, d)
            ctx.fill()
        }
    }

}
}
