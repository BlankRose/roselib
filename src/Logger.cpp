/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  Logger.cpp                                             */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 24, 2024 [05:51 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#include "roselib/Logger.hpp"
using namespace rose;

#include <iostream>
#include <fstream>

#define DEFAULT_TIME_FORMAT "[ %d-%m-%y %I:%M:%S %p ]"

Logger              logs;
constexpr LoggerEnd logs_send;

Logger::Logger():
    _stream(&std::cout), _time_format(DEFAULT_TIME_FORMAT),
    _level(LoggerLevel::INFO), _min_level(LoggerLevel::INFO),
    _constructed_stream(false), _enabled(true)
{}

Logger::Logger(std::ostream &stream):
    _stream(&stream), _time_format(DEFAULT_TIME_FORMAT),
    _level(LoggerLevel::INFO), _min_level(LoggerLevel::INFO),
    _constructed_stream(false), _enabled(true)
{}

Logger::Logger(const char *filepath):
    _stream(nullptr), _time_format(DEFAULT_TIME_FORMAT),
    _level(LoggerLevel::INFO), _min_level(LoggerLevel::INFO),
    _constructed_stream(false), _enabled(true)
{
    set_stream(filepath);
}

Logger::Logger(const std::string &filepath):
    Logger(filepath.c_str())
{}

Logger::Logger(Logger &&other) noexcept:
    _stream(other._stream),
    _buffer(std::move(other._buffer)),
    _time_format(std::move(other._time_format)),
    _level(other._level),
    _min_level(other._min_level),
    _constructed_stream(other._constructed_stream),
    _enabled(other._enabled)
{
    other._lock.unlock();
}

Logger::~Logger()
{
    if (_stream && _constructed_stream)
    {
        auto *stream = dynamic_cast<std::ofstream *>(this->_stream);
        if (stream->is_open())
            stream->close();
        delete _stream;
    }
}

Logger& Logger::operator=(Logger &&other) noexcept
{
    other._lock.unlock();
    this->_stream = other._stream;
    this->_buffer = std::move(other._buffer);
    this->_time_format = std::move(other._time_format);
    this->_level = other._level;
    this->_min_level = other._min_level;
    this->_constructed_stream = other._constructed_stream;
    this->_enabled = other._enabled;
    return *this;
}

Logger& Logger::operator<<(const LoggerEnd&)
{
    if (this->_level >= this->_min_level && this->_enabled)
    {
        this->_lock.lock();
        std::string log =
              get_time() + " "
            + get_level_string() + " ";
        if (!this->_prefix.empty())
            log += this->_prefix + " ";
        log += this->_buffer.str();
        get_stream() << log << std::endl;
        this->_lock.unlock();
    }
    clear();
    return *this;
}

Logger& Logger::operator<<(const LoggerLevel& level)
{
    this->_level = level;
    return *this;
}

Logger &Logger::append(const LoggerEnd&)
{
    return *this;
}

Logger& Logger::append(const LoggerLevel& level)
{
    *this << static_cast<int>(level);
    return *this;
}

void Logger::clear()
{
    this->_lock.lock();
    this->_buffer.str("");
    this->_buffer.clear();
    this->_lock.unlock();
}

void Logger::send()
{
    *this << logs_send;
}

void Logger::set_level(const LoggerLevel& level)
{
    this->_level = level;
}

void Logger::set_min_level(const LoggerLevel& level)
{
    this->_min_level = level;
}

void Logger::set_time_format(const std::string& format)
{
    this->_time_format = format;
}

void Logger::set_prefix(const std::string& prefix)
{
    this->_prefix = prefix;
}

void Logger::set_stream(std::ostream& stream)
{
    this->_constructed_stream = false;
    this->_stream = &stream;
}

bool Logger::set_stream(const std::string& filepath)
{
    return set_stream(filepath.c_str());
}

bool Logger::set_stream(const char* filepath)
{
    auto* stream = new(std::nothrow) std::ofstream(filepath);
    if (!stream)
        return false;
    if (!stream->is_open())
    {
        delete stream;
        return false;
    }

    this->_constructed_stream = true;
    this->_stream = stream;
    return true;
}

const LoggerLevel& Logger::get_level() const
{
    return this->_level;
}

const LoggerLevel& Logger::get_min_level() const
{
    return this->_min_level;
}

const std::string& Logger::get_time_format() const
{
    return this->_time_format;
}

const std::string& Logger::get_prefix() const
{
    return this->_prefix;
}

std::ostream& Logger::get_stream() const
{
    if (!this->_stream)
        return std::cout;
    return *this->_stream;
}

void Logger::disable()
{
    this->_enabled = false;
}

void Logger::enable()
{
    this->_enabled = true;
}

bool Logger::isReady() const
{
    return !!_stream;
}

void Logger::log(const LoggerLevel& level, const std::string& what) const
{
    if (level >= this->_min_level && this->_enabled)
    {
        get_stream() << what << std::endl;
    }
}

inline
void Logger::debug(const std::string& what) const
{
    log(LoggerLevel::DEBUG, what);
}

inline
void Logger::info(const std::string& what) const
{
    log(LoggerLevel::INFO, what);
}

inline
void Logger::warn(const std::string& what) const
{
    log(LoggerLevel::WARNING, what);
}

inline
void Logger::error(const std::string& what) const
{
    log(LoggerLevel::ERROR, what);
}

inline
void Logger::fatal(const std::string& what) const
{
    log(LoggerLevel::FATAL, what);
}

std::string Logger::get_time() const
{
    constexpr std::size_t   BUFFER_LENGTH = 100;
    const std::time_t       time = std::time(nullptr);
    char                    time_buffer[BUFFER_LENGTH];

    std::strftime
        (time_buffer,
        BUFFER_LENGTH,
        this->_time_format.c_str(),
        std::gmtime(&time));
    return time_buffer;
}

const char* Logger::get_level_string() const
{
    switch (this->_level)
    {
    case LoggerLevel::DEBUG:
        return "[ DEBUG ]";
    case LoggerLevel::INFO:
        return "[ INFO  ]";
    case LoggerLevel::WARNING:
        return "[ WARN  ]";
    case LoggerLevel::ERROR:
        return "[ ERROR ]";
    default:
        return "[ FATAL ]";
    }
}

Logger &rose::logs_debug()
{
    return logs << LoggerLevel::DEBUG;
}

Logger &rose::logs_info()
{
    return logs << LoggerLevel::INFO;
}

Logger &rose::logs_warn()
{
    return logs << LoggerLevel::WARNING;
}

Logger &rose::logs_error()
{
    return logs << LoggerLevel::ERROR;
}

Logger &rose::logs_fatal()
{
    return logs << LoggerLevel::FATAL;
}