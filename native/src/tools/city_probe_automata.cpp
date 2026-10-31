// city_probe_automata - (Open City Builder's Linux probe) the aircraft manager a city file names by class id that the
// GZCOM table lacks: the game creates it through cSC4AutomataCOMDirector, which registers no maker for it here.
#include <cstdint>

#include "sc4/AircraftManager.h"
#include "tools/city_probe_plain.h"

cIGZSerializable* CreateCityProbeWatercraft(std::uint32_t classId);   // city_probe_automata2.cpp
// the repository's further probe creators (city_probe_creators2..7.cpp), which its city_probe.cpp does not call yet
cIGZSerializable* CreateCityProbeSerializable2(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable3(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable4(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable5(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable6(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable7(std::uint32_t classId);
cIGZSerializable* CreateCityProbeSerializable8(std::uint32_t classId);

cIGZSerializable* CreateCityProbeAutomata(std::uint32_t classId) {
    typedef cIGZSerializable* (*Creator)(std::uint32_t);
    static const Creator more[] = {CreateCityProbeSerializable2, CreateCityProbeSerializable3, CreateCityProbeSerializable4,
                                   CreateCityProbeSerializable5, CreateCityProbeSerializable6, CreateCityProbeSerializable7,
                                   CreateCityProbeSerializable8};
    for (Creator c : more)
        if (cIGZSerializable* s = c(classId)) return s;
    if (classId != 0xc98f9d4a) return CreateCityProbeWatercraft(classId);
    auto* m = new sc4::cSC4AircraftManager();
    m->AddRef();
    cIGZSerializable* s = nullptr;
    if (!m->QueryInterface(sc4::kGZIID_cIGZSerializable, reinterpret_cast<void**>(&s))) s = nullptr;
    m->Release();
    return s;
}
