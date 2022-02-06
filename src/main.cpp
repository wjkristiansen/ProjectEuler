#include <memory>
#include <InCommand.h>

#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"

void main(int argc, const char *argv[])
{
    InCommand::CCommandScope CommandParser;
    auto &ProblemParam = CommandParser.DeclareVariableParameter("problem", "0");
    CommandParser.ParseParameterArguments(1, argc, argv);

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
    default:
        CProblem6::Execute();
        break;
    }
}