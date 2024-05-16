#include "benchmark/poseidon/poseidon_config.h"

#include <string>

#include "tachyon/base/console/iostream.h"
#include "tachyon/base/flag/flag_parser.h"

namespace tachyon {

bool PoseidonConfig::Parse(int argc, char** argv) {
  base::FlagParser parser;

  parser.AddFlag<base::Flag<size_t>>(&repeating_num_)
      .set_short_name("-n")
      .set_help("Specify the number of repetition 'n'. By default, 10.");
  parser.AddFlag<base::Flag<bool>>(&check_results_)
      .set_long_name("--check_results")
      .set_help("Whether checks results generated by each poseidon runner.");

  std::string error;
  if (!parser.Parse(argc, argv, &error)) {
    tachyon_cerr << error << std::endl;
    return false;
  }

  return true;
}

}  // namespace tachyon
