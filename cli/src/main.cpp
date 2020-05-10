#include <iostream>
#include "spdlog/spdlog.h"
#include "cxxopts.hpp"
#include "iris_compare_cli.hpp"
#include "utils.hpp"

int main(int argc, char** argv) {
    cxxopts::Options options(argv[0], "- Iris recognition CLI.");
    options.add_options()
      ("b,baseiris", "Base iris image path", cxxopts::value<std::string>())
      ("t,targetiris", "Target iris image path", cxxopts::value<std::string>())
      ("d,debug", "Enable debugging", cxxopts::value<bool>()->default_value("false"))
      ("i,iris-quality", "Iris image quality threshold", cxxopts::value<float>()->default_value("0.30"))
      ("m,hamming-dist", "Hamming distance threshold for comparison", cxxopts::value<float>()->default_value("0.39"))
      ("h,help", "Print usage");

    auto args = options.parse(argc, argv);

    if (args.count("help")) {
      std::cout << options.help() << std::endl;
      exit(0);
    }

    bool debug = args["debug"].as<bool>();
    if (debug) {
      spdlog::debug("Debug option is on.");
    }

    std::string baseImagePath, targetImagePath;
    float imgQualityThreshold, hammingDistThreshold = 0.0;
    if (args.count("baseiris")){
      baseImagePath = args["baseiris"].as<std::string>();
      if (!Utils::fileExist(baseImagePath)) {
        spdlog::error("The base image does not exist {}", baseImagePath);
        exit(0);
      } else {
        spdlog::debug("Base iris file exist: {}", baseImagePath);
      }
    }

    if (args.count("targetiris")) {
      targetImagePath = args["targetiris"].as<std::string>();
      if (!Utils::fileExist(targetImagePath)) {
        spdlog::error("The target image does not exist.");
        exit(0);
      } else {
        spdlog::debug("Target iris file exist: {}", targetImagePath);
      }
    }

    if (args.count("iris-quality")) {
      imgQualityThreshold = args["iris-quality"].as<float>();
      spdlog::debug("Image quality threshold {}", imgQualityThreshold);
    }

    if (args.count("hamming-dist")) {
      hammingDistThreshold = args["hamming-dist"].as<float>();
      spdlog::debug("Hamming distance threshold {}", hammingDistThreshold);
    }

    bool result;
    IrisCompareCli irisCompareCli = IrisCompareCli(baseImagePath, targetImagePath);
    result = irisCompareCli.compare();
    std::cout << result << std::endl;

    return 0;
}
