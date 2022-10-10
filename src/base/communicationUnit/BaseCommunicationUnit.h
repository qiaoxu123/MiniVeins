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

#include <map>
#include <vector>
#include <string>
#include <memory>

#include "src/base/connectionManager/ChannelAccess.h"
#include "src/test.h"

namespace test {

class ChannelAccess;
class BaseWorldUtility;

/**
 * @brief Inner module in Cars and RSUs, provide the function of communicating
 *
 */
class BaseCommunicationUnit : public ChannelAccess {
protected:
    bool recordStats; ///< Stores if tracking of statistics (esp. cOutvectors) is enabled.
    BaseWorldUtility* world = nullptr; ///< Pointer to the World Utility, to obtain some global information
protected:
    /**
     * Initialize members and associated objects according to parameterization.
     */
    void initialize(int stage) override;
};
} // namespace Test
