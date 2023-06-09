import QtQuick 2.15
import QtLocation 5.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.3

Rectangle{
    id:topBar
    width: 480
    height: 40
    color:"#1d2232"
    radius: 0
    border.color: "#4ba2ff"
    border.width: 2
/*
    property color bgcolor :"#5A6263"
    property color buttoncolor :"#5A6263"
    property color hovercolor :"#5A6263"
    property color clickcolor :"#5A6263"
    property color backgroundkcolor :"#5A6263"
*/
    Row{

        id: row_id
        x: 0
        y: 0
        width: 640
        height: 40
        focus: true
        antialiasing: true


        //Zoom_in
        Button{
            id:zoomIn
            width: 25
            height: 25
            property string property0: "This is a string"
            baselineOffset: 4
            antialiasing: true
            icon.width: 25
            display: AbstractButton.IconOnly

            transformOrigin: Item.Center
            //text: "Pin"
            icon.height: 25
            anchors{
                left: parent.left
                top:parent.top
                margins:10
            }
            icon.source: "qrc:/ui/assets/zoom_in.png"
            highlighted: true


            MouseArea{
                id:zoomInmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }

        //Zoom_out
        Button{
            id:zoomOut
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: zoomIn.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source: "qrc:/ui/assets/zoom_out.png"
            highlighted: true


            MouseArea{
                id:zoomOutmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }

        //Expand
        Button{
            id:expand
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: zoomOut.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/full_size.png"
            highlighted: true


            MouseArea{
                id:expandmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }

        //Select
        Button{

            id:select
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: expand.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/select.png"
            highlighted: true


            MouseArea{
                id:selectmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }


        //Cursor
        Button{

            id:cursor
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: select.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/cursor.png"
            highlighted: true


            MouseArea{
                id:cursormouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }


        //Takeoff
       Button{

            id:takeoff
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: cursor.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/takeoff.png"
            highlighted: true


            MouseArea{
                id:takeoffmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }


       //Addpoint
        Button{

            id:addpoint
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: takeoff.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/add_location.png"
            highlighted: true


            MouseArea{
                id:addpointmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }


        //Tracking
        Button{

            id:tracking
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: addpoint.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/tracking.png"
            highlighted: true


            MouseArea{
                id:trackingmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }


         //Pin
        Button{

            id:pin
            width: 25
            height: 25
            //text: "Pin"
            icon.height: 38
            anchors{
                left: tracking.right
                leftMargin: 10
                top:parent.top
                margins:10
            }
            icon.source:"qrc:/ui/assets/pin.png"
            highlighted: true


            MouseArea{
                id:pinmouse
                hoverEnabled: true
                anchors.fill:parent
                onEntered: {


                }
                onExited: {


                }

                onPressed: {


                }


            }

        }











    }



}
