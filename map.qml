
//Moduller
import QtQuick 2.0
import QtQuick.Window 2.14
import QtLocation 5.6
import QtPositioning 5.6
import QtQuick.Controls 2.5

import "ui/TopBar"
import "ui/RightBar"
import "ui/BottomBar"


/*
-Bu örnekte, temel bileşenleri (Rectangle, Image ve Metin) sağlayacak ortak modül olan QtQuick'i ve
ana uygulama penceresini (Pencere) sağlayacak olan Qt Quick.Window modülünü de içe aktarıyoruz

*/
Rectangle {
    id: rectangle
    width: 480

    height: 560
    visible: true
    color: "#1d2232"

    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
        // specify plugin parameters if necessary
        // PluginParameter {
        //     name:
        //     value:
        // }
    }

    RouteQuery {
        id: routeQuery
    }

    RouteModel {
        id: routeModel
        plugin: mapPlugin
        query: routeQuery
        autoUpdate: false
    }

    Map {
        id: map
        width: 480
        visible: true
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.topMargin: 40
        anchors.bottomMargin: 40
        gesture.enabled: true
        gesture.acceptedGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture

        plugin: mapPlugin
        center: QtPositioning.coordinate(59.91, 10.75) // Oslo
        zoomLevel: 14



        MouseArea{
            id:mousearea
            anchors.fill:parent
            acceptedButtons: Qt.LeftArrow | Qt.RightButton
            hoverEnabled: true
//                onPositionChanged:{


//                   console.log("Position x " + mouseX  + "Position y" + mouseY)

//               }
            onClicked:{
               console.log("Mouse pressed for mappolyline")
                routeQuery.addWaypoint(map.toCoordinate(Qt.point(mouseX,mouseY)))
                routeModel.update()


            }
        }


        MapItemView {
            model: routeQuery.waypoints
            delegate: MapQuickItem {
                anchorPoint.x: waypointMarker.width / 2
                anchorPoint.y: waypointMarker.height / 2
                coordinate: modelData

                sourceItem: Rectangle {
                    id: waypointMarker
                    width: 10
                    height: 10
                    radius: 10
                    border.width: 1
                    border.color: "black"
                    color: "red"
                }
            }
        }








    /*
    Shortcut {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    */
//    function addMarker(latitude,longitude){

//        var Component = Qt.createComponent("qrc:///views/marker.qml")
//        var item = Component.createObject(window, { coordinate: QtPositioning.coordinate(latitude, longitude)})
//        map.addMapItem(item)


//    }




    }

    TopBar{
        id:topBar
        anchors.top: parent.top
        anchors.topMargin: 0

    }
    BottomBar{
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

    }



    RightBar{
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.rightMargin: -40

    }

    MiniMap{



    }



}
