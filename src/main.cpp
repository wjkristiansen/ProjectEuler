#include <memory>
#include <InCommand.h>

#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"

void main(int argc, const char *argv[])
{
    InCommand::CCommandScope CommandLine("pe");
    auto &ProblemParam = CommandLine.DeclareVariableOption("problem", "0");
    CommandLine.ParseOptions(argc, argv, 1);

    int problem = std::stoi(ProblemParam.GetValueAsString());

    switch (problem)
    {
    case 1:
        CProblem1::Execute();
        break;
    case 2:
        CProblem2::Execute();
        break;
    case 3:
        CProblem3::Execute();
        break;
    case 4:
        CProblem4::Execute();
        break;
    case 5:
        CProblem5::Execute();
        break;
    case 6:
        CProblem6::Execute();
        break;
    case 7:
    default:
        CProblem7::Execute();
        break;
    }
}