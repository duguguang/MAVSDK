// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see https://github.com/mavlink/MAVSDK-Proto/blob/main/protos/gripper/gripper.proto)

#pragma once

#include <array>
#include <cmath>
#include <functional>
#include <limits>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "plugin_base.h"

#include "handle.h"

namespace mavsdk {

class System;
class GripperImpl;

/**
 * @brief Allows users to send gripper actions.
 */
class Gripper : public PluginBase {
public:
    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gripper = Gripper(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gripper(System& system); // deprecated

    /**
     * @brief Constructor. Creates the plugin for a specific System.
     *
     * The plugin is typically created as shown below:
     *
     *     ```cpp
     *     auto gripper = Gripper(system);
     *     ```
     *
     * @param system The specific system associated with this plugin.
     */
    explicit Gripper(std::shared_ptr<System> system); // new

    /**
     * @brief Destructor (internal use only).
     */
    ~Gripper() override;

    /**
     * @brief Gripper Actions.
     *
     * Available gripper actions are defined in mavlink under
     * https://mavlink.io/en/messages/common.html#GRIPPER_ACTIONS
     */
    enum class GripperAction {
        Release, /**< @brief Open the gripper to release the cargo. */
        Grab, /**< @brief Close the gripper and grab onto cargo. */
    };

    /**
     * @brief Stream operator to print information about a `Gripper::GripperAction`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream&
    operator<<(std::ostream& str, Gripper::GripperAction const& gripper_action);

    /**
     * @brief Possible results returned for gripper action requests.
     */
    enum class Result {
        Unknown, /**< @brief Unknown result. */
        Success, /**< @brief Request was successful. */
        NoSystem, /**< @brief No system is connected. */
        Busy, /**< @brief Temporarily rejected. */
        Timeout, /**< @brief Request timed out. */
        Unsupported, /**< @brief Action not supported. */
        Failed, /**< @brief Action failed. */
    };

    /**
     * @brief Stream operator to print information about a `Gripper::Result`.
     *
     * @return A reference to the stream.
     */
    friend std::ostream& operator<<(std::ostream& str, Gripper::Result const& result);

    /**
     * @brief Callback type for asynchronous Gripper calls.
     */
    using ResultCallback = std::function<void(Result)>;

    /**
     * @brief Gripper grab cargo.
     *
     * This function is non-blocking. See 'grab' for the blocking counterpart.
     */
    void grab_async(uint32_t instance, const ResultCallback callback);

    /**
     * @brief Gripper grab cargo.
     *
     * This function is blocking. See 'grab_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result grab(uint32_t instance) const;

    /**
     * @brief Gripper release cargo.
     *
     * This function is non-blocking. See 'release' for the blocking counterpart.
     */
    void release_async(uint32_t instance, const ResultCallback callback);

    /**
     * @brief Gripper release cargo.
     *
     * This function is blocking. See 'release_async' for the non-blocking counterpart.
     *
     * @return Result of request.
     */
    Result release(uint32_t instance) const;

    /**
     * @brief Copy constructor.
     */
    Gripper(const Gripper& other);

    /**
     * @brief Equality operator (object is not copyable).
     */
    const Gripper& operator=(const Gripper&) = delete;

private:
    /** @private Underlying implementation, set at instantiation */
    std::unique_ptr<GripperImpl> _impl;
};

} // namespace mavsdk