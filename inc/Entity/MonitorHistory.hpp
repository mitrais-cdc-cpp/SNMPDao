#ifndef NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_
#define NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_

#include <memory>
#include <string>
// ODB dependencies
#include <odb/core.hxx>

#pragma db object pointer(std::shared_ptr) session
class MonitorHistory {
 public:
  MonitorHistory(const unsigned long long lastUpdate, const std::string note)
      : lastUpdate_(lastUpdate), note_(note) {}

  /// Getter for latest update
  const unsigned long long& LastUdpate_() const { return lastUpdate_; }
  /// Getter for note
  const std::string& Note() const { return note_; }

 private:
  friend class odb::access;
  MonitorHistory() {}
/// TODO: doc
#pragma db id auto
  unsigned long monitorHistoryId_;
/// TODO: doc
#pragma db type("BIGINT")  // Microsecond precision.
  unsigned long long lastUpdate_;
/// TODO: doc
#pragma db type("VARCHAR(45)")
  std::string note_;
};

#endif /* NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_ */
