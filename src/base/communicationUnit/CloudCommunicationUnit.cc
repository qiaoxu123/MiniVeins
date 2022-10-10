/**
 * @brief
 *
 */

#include "CloudCommunicationUnit.h"

using namespace test;

void CloudCommunicationUnit::initialize()
{
    queuesStatus.resize(par("numOfRSUs"));
    EV << "Test" << endl;
}

void CloudCommunicationUnit::handleMessage(cMessage* frame)
{
    if (dynamic_cast<QueueStatusFrame*>(frame)) {
        EV << "Have received the QueueStatusFrame" << endl;
    }
    else if (dynamic_cast<RSUTaskSignalFrame*>(frame)) {
        EV << "Have received the RSUTaskSignalFrame" << endl;
    }
    else {
        EV << "Have received the cMessage" << endl;
    }
}

void CloudCommunicationUnit::handleSelfMessage(cMessage* frame)
{

}
