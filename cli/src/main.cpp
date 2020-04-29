#include <iostream>

#include "spdlog/spdlog.h"
#include "cxxopts.hpp"
#include "utils.hpp"

#include "iris_compare_cli.hpp"

int main(int argc, char** argv)
{
    cxxopts::Options options(argv[0], "- Iris recognition CLI.");

    options.add_options()
        ("b,baseiris", "Base iris image path", cxxopts::value<std::string>())
        ("t,targetiris", "Target iris image path", cxxopts::value<std::string>())
        ("d,debug", "Enable debugging",
          cxxopts::value<bool>()->default_value("false"))
        // ("f,foo", "Param foo",
        //   cxxopts::value<int>()->default_value("10"))
        ("h,help", "Print usage");

    auto args = options.parse(argc, argv);

    if (args.count("help"))
    {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    bool debug = args["debug"].as<bool>();
    if (debug) {
      spdlog::info("Debug option is on.");
    }

    std::string baseImagePath, targetImagePath;
    if (args.count("baseiris")){
      baseImagePath = args["baseiris"].as<std::string>();
      if (!Utils::fileExist(baseImagePath)) {
        spdlog::error("The base image does not exist {}", baseImagePath);
        exit(0);
      } else {
        spdlog::info("Base iris file exist: {}", baseImagePath);
      }
    }

    spdlog::info("base iris {}", baseImagePath);
    if (args.count("targetiris")) {
      targetImagePath = args["targetiris"].as<std::string>();
      if (!Utils::fileExist(targetImagePath)) {
        spdlog::error("The target image does not exist.");
        exit(0);
      } else {
        spdlog::info("Target iris file exist: {}", targetImagePath);
      }
    }

    bool result;
    IrisCompareCli irisCompareCli = IrisCompareCli(baseImagePath, targetImagePath);
    result = irisCompareCli.compare();
    std::cout << "Iris compare result: " << result << std::endl;

    return 0;
}
