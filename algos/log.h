#ifndef BASIC_ALGOS_ALGOS_LOG_H_
#define BASIC_ALGOS_ALGOS_LOG_H_


#include <iostream>
#include <utility>
#include <cctype>

#include "algos/util.h"

using namespace std;

namespace algo {

namespace log {

enum class LogSeverity {
  INFO,
  WARN,
  DEBUG,
  ERROR,
  FATAL,
};

inline std::string SeverityToString(const LogSeverity &severity) {
  switch (severity) {
    case LogSeverity::INFO:return "INFO";
    case LogSeverity::WARN:return "WARN";
    case LogSeverity::DEBUG:return "DEBUG";
    case LogSeverity::ERROR:return "ERROR";
    case LogSeverity::FATAL:return "FATAL";
    default:return "INFO";
  }
}

inline LogSeverity StringToSeverity(const std::string &severity) {
  switch (std::toupper(severity[0])) {
    case 'I':return LogSeverity::INFO;
    case 'W':return LogSeverity::WARN;
    case 'D':return LogSeverity::DEBUG;
    case 'E':return LogSeverity::ERROR;
    case 'F':return LogSeverity::FATAL;
    default:return LogSeverity::INFO;
  }
}

std::string now();

struct Record final {
 public:

  Record(const LogSeverity &severity, std::string file_name, const size_t line_number)
      : logSeverity_(severity),
        file_name_(std::move(file_name)),
        line_number_(line_number) {

  }

  std::string file_name() const {
    return file_name_;
  }

  size_t line_number() const {
    return line_number_;
  }

  // TODO(xusworld)
  std::string String() {
    return file_name() + " ";
  }

 public:
  const LogSeverity logSeverity_;
  const std::string file_name_;
  const size_t line_number_;
};

class Logger {
 public:
  DELETE_COPY_AND_MOVE_CTOR(Logger);

  static Logger *getInstance();

  ~Logger() {
    std::cout << std::endl;
  }

  // TODO(xusworld) combine LogSeverity to Record
  Logger &&write(const LogSeverity &severity, const Record &record);

 private:
  Logger() = default;

  static Logger *instance_;

  LogSeverity log_severity_;

  const std::string blank_ = " ";
  const std::string lflag_ = "[";
  const std::string rflag_ = "]";
};


} // namespace log


template<typename T>
log::Logger &&operator<<(log::Logger &&logger, T &&msg) {
  std::cout << std::forward<T>(msg);
  return std::move(logger);
}

#define LOG_IMPL(severity) \
  log::Logger::getInstance()->write(severity, log::Record(severity, __FILE__, __LINE__))

#define LOG(severity) LOG_IMPL(severity)

#define LOG_INFO LOG(log::LogSeverity::INFO)
#define LOG_WARN LOG(log::LogSeverity::WARN)
#define LOG_DEBUG LOG(log::LogSeverity::DEBUG)
#define LOG_ERROR LOG(log::LogSeverity::ERROR)
#define LOG_FATAL LOG(log::LogSeverity::FATAL)

#define LOGI LOG_INFO
#define LOGW LOG_WARN
#define LOGD LOG_DEBUG
#define LOGE LOG_ERROR
#define LOGF LOG_FATAL



} // namespace algo


#endif //BASIC_ALGOS_ALGOS_LOG_H_
