#include "algos/log.h"

namespace algo {

namespace log {

Logger *Logger::getInstance() {
  if (instance_ == nullptr) {
    instance_ = new Logger();
  }
  return instance_;
}

// TODO(xusworld) combine LogSeverity to Record
Logger &&Logger::write(const LogSeverity &severity, const Record &record) {
  log_severity_ = severity;
  std::cout << lflag_ << SeverityToString(log_severity_) << rflag_ << now() << blank_
            << record.file_name() << blank_ << record.line_number() << blank_;
  return std::move(*instance_);
}

std::string now() {
  // std::time_point
  auto tp = std::chrono::system_clock::now();
  // std::time_point to std::time_t
  std::time_t now = std::chrono::system_clock::to_time_t(tp);
  char buffer[56];
  std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

  return std::string(buffer);
}


Logger *Logger::instance_ = nullptr;

} // namespace log

} // namespace algo