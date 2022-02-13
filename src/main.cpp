#include <memory>
#include <InCommand.h>

#include "Problems.h"

void main(int argc, const char *argv[])
{
    InCommand::CCommandReader CommandReader("pe", "Project Euler Solutions", argc, argv);
    InCommand::InCommandInt ProblemNumber;
    CommandReader.DefaultCommand()->DeclareVariableOption(ProblemNumber, "problem", "Project Euler Problem Number", 'p');
    CommandReader.ReadOptions();

    switch (ProblemNumber.Value())
    {
    case 1:
        CProblem<1>::Execute();
        break;
    case 2:
        CProblem<2>::Execute();
        break;
    case 3:
        CProblem<3>::Execute();
        break;
    case 4:
        CProblem<4>::Execute();
        break;
    case 5:
        CProblem<5>::Execute();
        break;
    case 6:
        CProblem<6>::Execute();
        break;
    case 7:
        CProblem<7>::Execute();
        break;
    case 8:
        CProblem<8>::Execute();
        break;
    case 9:
        CProblem<9>::Execute();
        break;
    case 10:
        CProblem<10>::Execute();
        break;
    case 11:
        CProblem<11>::Execute();
        break;
    case 12:
    default:
        CProblem<12>::Execute();
        break;
    }
}