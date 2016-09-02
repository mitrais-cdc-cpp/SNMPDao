#ifndef NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_
#define NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_

#include <cstddef>
#include <string>

#include <boost/date_time/posix_time/ptime.hpp>
#include <odb/core.hxx>

#pragma db object

namespace Mitrais {
namespace SNMPDao {
namespace Entity {
class MonitorHistory {
 public:
  MonitorHistory(const boost::posix_time::ptime& lastUpdate,
                 const std::string note)
      : lastUpdate_(lastUpdate), note_(note) {}

  const boost::posix_time::ptime& LastUdpate_() const { return lastUpdate_; }

  const std::string& Note() const { return note_; }

 private:
  friend class odb::access;
  MonitorHistory() {}
#pragma db id auto
  unsigned long monitorHistoryId_;

#pragma db type("TIMESTAMP")  // Microsecond precision.
  boost::posix_time::ptime lastUpdate_;

#pragma db type("VARCHAR(45)")
  std::string note_;
};

#pragma db view object(MonitorHistory)
struct MonitorHistory_stat {
#pragma db column("count(" + MonitorHistory::monitorHistoryId_ + ")")
  std::size_t count;
};
}
}
}

#endif /* NEMSTA_INC_ENTITY_MONITORHISTORY_HPP_ */
