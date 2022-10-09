/**
 * @file CommunicationUnit.h
 * @author xu qiao (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include "src/base/connectionManager/ChannelAccess.h"
#include "src/test.h"

namespace test {

class ChannelAccess;

/**
 * @brief Inner module in Cars and RSUs, provide the function of communicating
 *
 */
class CommunicationUnit : public ChannelAccess {
private:
protected:
    /**
     * Initialize members and associated objects according to parameterization.
     */
    void initialize(int stage) override;

    /**
     * Process received messages and pass to specific handlers.
     *
     * @see handleSelfMessage
     */
    void handleMessage(cMessage* msg) override;
};
} // namespace Test
