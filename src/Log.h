//
// Created by grzegorz on 17.11.18.
//
#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GL {

    /**
     * @class Log
     * @brief implementation of logging system
     */

    class Log {
    public:

        /**
         * @fn Init
         * @brief Initialize Core Logger and User Logger
         */

        static void Init();

        /**
         * @fn GetCoreLogger
         * @brief use to get access to Core Logger
         * @return reference to Core Logger
         */

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _coreLogger; }

        /**
         * @fn GetUserLogger
         * @brief use to get access to User Logger
         * @return reference to User Logger
         */

        inline static std::shared_ptr<spdlog::logger>& GetUserLogger() { return _userLogger; }

    private:
        static std::shared_ptr<spdlog::logger> _coreLogger; /**< pointer to core logger */
        static std::shared_ptr<spdlog::logger> _userLogger; /**< pointer to user logger */
    };

}

#define CORE_LOG_INFO(...) ::GL::Log::GetCoreLogger()->info(__VA_ARGS__) /**< print info in Core Logger */
#define CORE_LOG_WARN(...) ::GL::Log::GetCoreLogger()->warn(__VA_ARGS__) /**< print warning in Core Logger */
#define CORE_LOG_ERROR(...) ::GL::Log::GetCoreLogger()->error(__VA_ARGS__) /**< print error in Core Logger */
#define CORE_LOG_DEBUG(...) ::GL::Log::GetCoreLogger()->debugz(__VA_ARGS__) /**< print only in Debug mode */
#define CORE_LOG_TRACE(...) ::GL::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define USER_LOG_INFO(...) ::GL::Log::GetUserLogger()->info(__VA_ARGS__) /**< print info in User Logger */
#define USER_LOG_WARN(...) ::GL::Log::GetUserLogger()->warn(__VA_ARGS__)   /**< print warning in User Logger */
#define USER_LOG_ERROR(...) ::GL::Log::GetUserLogger()->error(__VA_ARGS__) /**< print error in User Logger */
#define USER_LOG_TRACE(...) ::GL::Log::GetUserLogger()->trace(__VA_ARGS__)


