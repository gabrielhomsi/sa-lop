#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "Singleton.h"

#include <boost/program_options.hpp>
#include <string>

namespace po = boost::program_options;

class Parameters : public Singleton<Parameters>
{
public:
    bool silent;

    po::variables_map vm;

    void load(int argc, char** argv);
private:
    friend class Singleton<Parameters>;
};

#endif
