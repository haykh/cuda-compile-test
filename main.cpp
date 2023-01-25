#include <Kokkos_Core.hpp>
#include <Kokkos_Macros.hpp>

#include <iostream>
#include <sstream>

auto main(int argc, char *argv[]) -> int {
  Kokkos::initialize(argc, argv);
  {
    std::ostringstream msg;
    msg << "{" << std::endl;
    if (Kokkos::hwloc::available()) {
      msg << "hwloc( NUMA[" << Kokkos::hwloc::get_available_numa_count()
          << "] x CORE[" << Kokkos::hwloc::get_available_cores_per_numa()
          << "] x HT[" << Kokkos::hwloc::get_available_threads_per_core()
          << "] )" << std::endl;
    }
    Kokkos::print_configuration(msg);
    msg << "}" << std::endl;
    std::cout << msg.str();
  }
  Kokkos::finalize();

  return 0;
}
