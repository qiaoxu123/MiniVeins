/**
 * @file CarCommunicationUnit.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CarCommunicationUnit.h"

using namespace test;

void CarCommunicationUnit::initialize(int stage)
{
    sendMessageEvent = new cMessage("Send the message periodly");
    scheduleAt(0.5, sendMessageEvent);
}

void CarCommunicationUnit::handleMessage(cMessage* msg)
{
    ASSERT(msg == sendMessageEvent);
    uploadFrame();
    scheduleAt(simTime() + 0.5, sendMessageEvent);
}

void CarCommunicationUnit::uploadFrame()
{
    // Produce source and destination addresses.
    //    int carID = getIndex(); // our module index
    const int carID = intuniform(0, 10);
    const int n = gateSize("upper"); // module vector size
    const int rsuID = intuniform(0, n - 1);

    char framename[20];
    sprintf(framename, "Car%d-to-RSU%d", carID, rsuID);

    // Create message object and set source and destination field.
    TaskFrame* frame = new TaskFrame(framename);
    frame->setCarID(carID);
    frame->setRsuID(rsuID);
    frame->setTaskSize(100);

    EV << "Upload task to RSU" << endl;
    send(frame, "upper$o", rsuID);
}

void CarCommunicationUnit::handleSelfMessage(cMessage* frame)
{

}
