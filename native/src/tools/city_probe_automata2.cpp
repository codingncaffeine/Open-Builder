// city_probe_automata2 - (Open City Builder's Linux probe) the watercraft manager, by class id (see city_probe_automata).
#include <cstdint>

#include "sc4/WatercraftManager.h"
#include "tools/city_probe_plain.h"

cIGZSerializable* CreateCityProbeWatercraft(std::uint32_t classId) {
    return classId == 0xa98f9d28 ? sc4::WrapPlain(new sc4::cSC4WatercraftManager()) : nullptr;
}
