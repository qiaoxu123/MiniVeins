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

network Scenario
{
    parameters:
        int numOfRSUs @prompt("Number of RSUs:") = default(3);
        int numOfCars @prompt("Number of Cars:") = default(3);
        @display("bgb=526,324");
    types:
        channel Channel extends ned.DelayChannel {
            delay = 100ms;
        }
    submodules:
        cloud: Cloud {
            parameters:
                @display("p=287,51");
            gates:
                lower[parent.numOfRSUs];
        }
        rsu[numOfRSUs]: RSU {
            parameters:
                @display("p=287,146");
        }
        car: Car {
            parameters:
                @display("p=287,247");
            gates:
                upper[parent.numOfRSUs];
        }
    connections:
        cloud.lower[i] <--> Channel <--> rsu[i].upper for i=0..numOfRSUs-1;
        rsu[i].lower <--> Channel <--> car.upper[i] for i=0..numOfRSUs-1;
}


