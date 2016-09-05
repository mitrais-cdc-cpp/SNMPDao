#ifndef NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_
#define NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_

#include <boost/date_time/posix_time/ptime.hpp>
#include <cstddef>
#include <memory>
#include <odb/core.hxx>
#include <string>

#pragma db object pointer(std::shared_ptr) session
class MonitorHistory {
 public:
  MonitorHistory(const unsigned long long lastUpdate, const std::string note)
      : lastUpdate_(lastUpdate), note_(note) {}

  const unsigned long long& LastUdpate_() const { return lastUpdate_; }

  const std::string& Note() const { return note_; }

 private:
  friend class odb::access;
  MonitorHistory() {}
#pragma db id auto
  unsigned long monitorHistoryId_;

#pragma db type("BIGINT")  // Microsecond precision.
  unsigned long long lastUpdate_;

#pragma db type("VARCHAR(45)")
  std::string note_;
};

#endif /* NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_ */
