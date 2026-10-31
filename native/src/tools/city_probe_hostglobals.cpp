// city_probe_hostglobals - (Open City Builder's Linux probe) the two load-time hosts city_probe_creators8.cpp reads; null
// makes it fall back to the stub hosts (the native app's NativeTrafficHosts.cpp sets real ones).
#include "sc4/TrafficAutomaton.h"
#include "sc4/Vehicle.h"

namespace sc4 {
ITrafficAutomatonHost* g_loadTrafficHost = nullptr;
IVehicleHost* g_loadVehicleHost = nullptr;
}  // namespace sc4
