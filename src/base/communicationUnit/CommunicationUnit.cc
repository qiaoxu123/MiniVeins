/**
 * @file CommunicationUnit.cc
 * @author xu qiao (george.x.qiao@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "CommunicationUnit.h"

using namespace test;

void CommunicationUnit::initialzie(int stage)
{
    ChannelAccess::initialize(stage);

    if (stage == 0) {
        // if using sendDirect, make sure that messages arrive without delay
#if OMNETPP_BUILDNUM < 1506
        gate("radioIn")->setDeliverOnReceptionStart(true);
#else
        gate("radioIn")->setDeliverImmediately(true);
#endif

        upperLayerIn = findGate("upperLayerIn");
        upperLayerOut = findGate("upperLayerOut");
        upperControlOut = findGate("upperControlOut");
        upperControlIn = findGate("upperControlIn");

        if (par("useNoiseFloor").boolValue()) {
            noiseFloorValue = FWMath::dBm2mW(par("noiseFloor").doubleValue());
        }
        else {
            noiseFloorValue = 0;
        }
        minPowerLevel = par("minPowerLevel").doubleValue();
        minPowerLevel = FWMath::dBm2mW(minPowerLevel);

        recordStats = par("recordStats").boolValue();

        radio = initializeRadio();

        world = FindModule<BaseWorldUtility*>::findGlobalModule();
        if (world == nullptr) {
            throw cRuntimeError("Could not find BaseWorldUtility module");
        }

        if (cc->hasPar("sat") && (minPowerLevel - FWMath::dBm2mW(cc->par("sat").doubleValue())) < -0.000001) {
            throw cRuntimeError("minPowerLevel can't be smaller than the signal attenuation threshold (sat) in ConnectionManager. Please adjust your omnetpp.ini file accordingly.");
        }

        initializeAnalogueModels(par("analogueModels").xmlValue());
        initializeDecider(par("decider").xmlValue());
        initializeAntenna(par("antenna").xmlValue());

        radioSwitchingOverTimer = new cMessage("radio switching over", RADIO_SWITCHING_OVER);
        txOverTimer = new cMessage("transmission over", TX_OVER);
    }
}

// --Message handling--------------------------------------

void CommunicationUnit(cMessage* msg)
{
    // self messages
    if (msg->isSelfMessage()) {
        handleSelfMessage(msg);

        // MacPkts <- MacToPhyControlInfo
    }
    else if (msg->getKind() == AIR_FRAME) {
        handleAirFrame(static_cast<AirFrame*>(msg));
        // unknown message
    }
    else {
        EV << "Unknown message received." << endl;
        delete msg;
    }
}
