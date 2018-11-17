//
// Created by grzegorz on 17.11.18.
//

#include "Log.h"

namespace GL{

    std::shared_ptr<spdlog::logger> Log::_coreLogger;
    std::shared_ptr<spdlog::logger> Log::_userLogger;

    void Log::Init() {
        _coreLogger = spdlog::stdout_color_mt("myEngine");
        _userLogger = spdlog::stdout_color_mt("myApp");
        spdlog::set_pattern("%^[%T] %n: %v%$");
    }


}
