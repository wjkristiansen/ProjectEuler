#include <iostream>
#include <memory>
#include <InCommand.h>

#include "Problems.h"

void main(int argc, const char *argv[])
{
    InCommand::CCommandReader CommandReader("pe", "Project Euler Solutions", argc, argv);
    InCommand::InCommandInt ProblemNumber(-1);
    InCommand::InCommandBool ShowHelp;
    CommandReader.DefaultCommand()->DeclareVariableOption(ProblemNumber, "problem", "Project Euler Problem Number", 'p');
    CommandReader.DefaultCommand()->DeclareSwitchOption(ShowHelp, "help", "Get help", 'h');
    CommandReader.ReadOptions();

    if(ShowHelp)
    {
        std::cout << std::endl;
        std::cout << CommandReader.DefaultCommand()->UsageString() << std::endl;
        std::cout << std::endl;
        return;
    }

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
        CProblem<12>::Execute();
        break;
    case 13:
        CProblem<13>::Execute();
        break;
    case 14:
        CProblem<14>::Execute();
        break;
    case 15:
        CProblem<15>::Execute();
        break;
    case 16:
        CProblem<16>::Execute();
        break;
    case 17:
        CProblem<17>::Execute();
        break;
    case 18:
        CProblem<18>::Execute();
        break;
    case 19:
        CProblem<19>::Execute();
        break;
    case 20:
        CProblem<20>::Execute();
        break;
    case 21:
    default:
        CProblem<21>::Execute();
        break;
    }
}