/* ************************************************************************** */
/*         .-.                                                                */
/*   __   /   \   __                                                          */
/*  (  `'.\   /.'`  )  Logger.hpp                                             */
/*   '-._.(;;;)._.-'                                                          */
/*   .-'  ,`"`,  '-.                                                          */
/*  (__.-'/   \'-.__)  By: Rosie (https://github.com/BlankRose)               */
/*      //\   /        Last Updated: March 24, 2024 [05:51 am]                */
/*     ||  '-'                                                                */
/* ************************************************************************** */

#pragma once

#include <mutex>
#include <sstream>

namespace rose
{
    /// @brief      Tag which marks the end of a log message
    struct LoggerEnd {};

    /// @brief      Enumeration of the various levels available for the logger
    ///             ( default level being INFO for @class Logger )
    enum class LoggerLevel
    {
        DEBUG,              // Debugging messages, for developpment usually
        INFO,               // Informative messages, for history and general purpose usually
        WARNING,            // Warning messages, for warn off the team usually
        ERROR,              // Error messages, for unexpected inputs usually
        FATAL,              // Fatal messages, for emergency and critical moments usually
    };

    /// @brief      Logger class, to allow easier handling of logging anything
    ///             nicely, wether it be in a console or in a file, while
    ///             also being thread-safe
    class Logger
    {
    public:
        /// @brief          Constructs a new logger, associated to the standard output
        Logger();

        /// @brief          Constructs a new logger, associated to the given output stream
        ///
        /// @param stream   Output stream to associate the logger to
        explicit Logger(std::ostream &stream);

        /// @brief          Constructs a new logger, create and associate to a given file
        ///
        /// @param filepath Path to the file to associate the logger to
        explicit Logger(const char *filepath);

        /// @brief          Constructs a new logger, create and associate to a given file
        ///
        /// @param filepath Path to the file to associate the logger to
        explicit Logger(const std::string &filepath);

        /// @brief          Creates a copy of the provided logger (DISABLED)
        Logger(const Logger &) = delete;

        /// @brief          Creates from the ressources of the provided logger (DISABLED)
        Logger(Logger &&) noexcept;

        /// @brief          Destroys the logger
        ~Logger();

        /// @brief          Copies the given logger (DISABLED)
        Logger &operator=(const Logger &) = delete;

        /// @brief          Assign to itself the given logger's ressources (DISABLED)
        Logger &operator=(Logger &&) noexcept;

        /// @brief          Constructs the internal buffer with the given elements,
        ///                 as long as it has an overload to the operator << availale
        ///
        /// @tparam T       Type of the element
        /// @param rhs      Element to construct the buffer with
        ///
        /// @return         The logger for chaining
        template < class T >
        Logger &operator<<(const T &rhs)
        {
            this->_lock.lock();
            this->_buffer << rhs;
            this->_lock.unlock();
            return *this;
        }

        /// @brief          Marks the internal buffer as ready to send, finalise
        ///                 and finally sends over the output stream the
        ///                 constructed log message
        ///
        /// @param marker   Logger end marker
        ///
        /// @return         The logger for chaining
        Logger &operator<<(const LoggerEnd &marker);

        /// @brief          Defines the level of all the upcomming logs messages
        ///
        /// @param level    Level of the following up log messages
        ///
        /// @return         The logger for chaining
        Logger &operator<<(const LoggerLevel &level);

        /// @brief          Constructs the internal buffer with the given elements,
        ///                 as long as it has an overload to the operator << availale
        ///
        /// @tparam T       Type of the element
        /// @param obj      Element to construct the buffer with
        ///
        /// @return         The logger for chaining
        template < class T >
        Logger &append(const T &obj)
        { return *this << obj; }

        /// @brief          Marks the internal buffer as ready to send, finalise
        ///                 and finally sends over the output stream the
        ///                 constructed log message
        ///
        /// @param marker   Logger end marker
        ///
        /// @return         The logger for chaining
        Logger &append(const LoggerEnd &marker);

        /// @brief          Defines the level of all the upcomming logs messages
        ///
        /// @param level    Level of the following up log messages
        ///
        /// @return         The logger for chaining
        Logger &append(const LoggerLevel &level);

        /// @brief          Completely clears the internal buffer,
        ///                 without sending it. Useful to cancel the buffer constructions
        void clear();

        /// @brief          Finalize the constructed buffer and sends it over
        ///                 to the output stream
        void send();

        /// @brief          Define the level of all the upcomming logs messages
        ///
        /// @param level    Level of the following up log messages
        void set_level(const LoggerLevel &level);

        /// @brief          Define the minimum level for the upcomming logs message,
        ///                 preventing sending the log if the level is lower than
        ///                 the defined mimimum
        ///
        /// @param level    Minimum level requierements of the following up log messages
        void set_min_level(const LoggerLevel &level);

        /// @brief          Define the time format to use when finalizing the
        ///                 constructed buffer when about to send the log
        ///
        /// @param format   Format to use
        /// @see            https://en.cppreference.com/w/cpp/chrono/c/strftime
        void set_time_format(const std::string &format);

        /// @brief          Define the prefix to display to the log message
        ///
        /// @param prefix   Prefix message to display
        void set_prefix(const std::string &prefix);

        /// @brief          Change the current output stream to another stream
        ///
        /// @param stream   New output stream to use
        void set_stream(std::ostream &stream);

        /// @brief          Change the current output stream to another stream
        ///                 (doesn't change if opening the file fails)
        ///
        /// @param filepath Path to the file to assiociate the logger to
        ///
        /// @return         TRUE if successfully changed, otherwise FALSE
        bool set_stream(const char *filepath);

        /// @brief          Change the current output stream to another stream
        ///                 (doesn't change if opening the file fails)
        ///
        /// @param filepath Path to the file to assiociate the logger to
        ///
        /// @return         TRUE if successfully changed, otherwise FALSE
        bool set_stream(const std::string &filepath);

        /// @brief          Retrieves the logger's currently set logger level
        ///
        /// @return         Logger level to send as
        [[nodiscard]] const LoggerLevel &get_level() const;

        /// @brief          Retrieves the logger's minimum level needed to send logs
        ///
        /// @return         Minimum logger level requierement
        [[nodiscard]] const LoggerLevel &get_min_level() const;

        /// @brief          Retrieves the logger's currently using time format
        ///
        /// @return         Currently defined time format
        /// @see            https://en.cppreference.com/w/cpp/chrono/c/strftime
        [[nodiscard]] const std::string &get_time_format() const;

        /// @brief          Retrieves the logger's current prefix
        ///
        /// @return         Current prefix to display
        [[nodiscard]] const std::string &get_prefix() const;

        /// @brief          Retrieves the logger's current assigned output stream
        ///
        /// @return         Current using output stream
        [[nodiscard]] std::ostream &get_stream() const;

        /// @brief          Enables back the logger if previously disabled
        void enable();

        /// @brief          Disables completely the logger, preventing it
        ///                 to output anything
        void disable();

        /// @brief          Checks if the logger is ready for usage, or not
        ///                 ( such as: is output stream ready? )
        ///
        /// @return         TRUE if safe to use, otherwise FALSE
        bool isReady() const;

        /// @brief          Quickly sends a message, with given level through
        ///                 the logger (does not use or modify the current buffer)
        ///
        /// @param level    Level of the log
        /// @param what     What to write down on the log
        void log(const LoggerLevel &level, const std::string &what) const;

        /// @brief          Quickly sends a debug message through the logger
        ///                 (does not use or modify the current buffer)
        ///
        /// @param what     What to write down on the log
        void debug(const std::string &what) const;

        /// @brief          Quickly sends an info message through the logger
        ///                 (does not use or modify the current buffer)
        ///
        /// @param what     What to write down on the log
        void info(const std::string &what) const;

        /// @brief          Quickly sends a warning message through the logger
        ///                 (does not use or modify the current buffer)
        ///
        /// @param what     What to write down on the log
        void warn(const std::string &what) const;

        /// @brief          Quickly sends an error message through the logger
        ///                 (does not use or modify the current buffer)
        ///
        /// @param what     What to write down on the log
        void error(const std::string &what) const;

        /// @brief          Quickly sends a fatal message through the logger
        ///                 (does not use or modify the current buffer)
        ///
        /// @param what     What to write down on the log
        void fatal(const std::string &what) const;

    protected:
        /// @brief          Constructs the time string, from the defined time
        ///                 format (can be set via set_time_format member function)
        ///
        /// @return         String containing the time, ready to print
        [[nodiscard]] std::string get_time() const;

        /// @brief          Retrieves the string associated to the currently
        ///                 defined log level
        ///
        /// @return         String containing the level, ready to print
        [[nodiscard]] const char *get_level_string() const
        { return get_level_string(this->_level); }

        /// @brief          Retrieves the string associated to the
        ///                 requested log level
        ///
        /// @param level    Requested log level
        /// @return         String containing the level, ready to print
        [[nodiscard]] static const char *get_level_string(const LoggerLevel& level);

    private:
        std::mutex          _lock;
        std::ostream*       _stream;
        std::ostringstream  _buffer;
        std::string         _time_format;
        std::string         _prefix;
        LoggerLevel         _level;
        LoggerLevel         _min_level;
        bool                _constructed_stream;
        bool                _enabled;
    };

    /// @brief      Default logger, ready for a user quick usage
    extern Logger           logs;

    /// @brief      Pre-constructed log end marker, ready for usage
    extern const LoggerEnd  logs_send;

    /// @brief      Quickly setup debug logs
    Logger &logs_debug();

    /// @brief      Quickly setup info logs
    Logger &logs_info();

    /// @brief      Quickly setup warning logs
    Logger &logs_warn();

    /// @brief      Quickly setup error logs
    Logger &logs_error();

    /// @brief      Quickly setup fatal logs
    Logger &logs_fatal();
}