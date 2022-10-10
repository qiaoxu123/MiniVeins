//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2015 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//
import src.nodes.Cloud;
import src.nodes.RSU;
import src.nodes.Car;
import src.nodes.ConnectionManager;
import src.base.modules.BaseWorldUtility;
import src.modules.mobility.traci.TraCIScenarioManager*;
import src.visualizer.roads.RoadsCanvasVisualizer;

network Scenario
{
    parameters:
        int numOfRSUs @prompt("Number of RSUs:") = default(3);
        int numOfCars @prompt("Number of Cars:") = default(3);
        double playgroundSizeX @unit(m); // x size of the area the nodes are in (in meters)
        double playgroundSizeY @unit(m); // y size of the area the nodes are in (in meters)
        double playgroundSizeZ @unit(m); // z size of the area the nodes are in (in meters)

        @display("bgb=636,453");
        @display("bgb=526,324");
    types:
        channel Channel extends ned.DelayChannel
        {
            delay = 100ms;
        }
    submodules:
        world: BaseWorldUtility {
            parameters:
                playgroundSizeX = veins_eval_by_version(veins_omnetpp_buildnum(), "playgroundSizeX", 1525, "parent.playgroundSizeX");
                playgroundSizeY = veins_eval_by_version(veins_omnetpp_buildnum(), "playgroundSizeY", 1525, "parent.playgroundSizeY");
                playgroundSizeZ = veins_eval_by_version(veins_omnetpp_buildnum(), "playgroundSizeZ", 1525, "parent.playgroundSizeZ");
                @display("p=35,38;i=misc/globe");
        }
        manager: TraCIScenarioManagerLaunchd {
            parameters:
                @display("p=271,38");
        }
        roadsCanvasVisualizer: RoadsCanvasVisualizer {
            @display("p=145,38");
        }
        rsu: RSU {
            @display("p=369,37;i=sign/yellowdiamond");
        }
        node[0]: Car {
            @display("p=115,295;i=node/car");
        }
    connections:
}


