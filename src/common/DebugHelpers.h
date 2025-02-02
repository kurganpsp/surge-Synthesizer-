/*
** DebugHelpers.h
**
** Contains debug APIs. Do not use them in production code.
** Pull requests with references to these functions will not be merged!
**
*/

#pragma once
#include <string>
#include <chrono>

#define _DBGCOUT std::cout << __func__ << ":" << __LINE__ << "| "
#define _D(x) " " << (#x) << "=" << x
#define _R(x, y) Surge::Debug::LifeCycleToConsole y(x);
#define _DUMPR(r)                                                                                  \
    " " << (#r) << "=(L/X=" << r.left << ",T/Y=" << r.top << ")+(W=" << r.getWidth()               \
        << ",H=" << r.getHeight() << ")+(R=" << r.right << ",B=" << r.bottom << ")"
#define _DUMPCOL(c)                                                                                \
    " " << (#c) << "r=" << (int)c.red << " g=" << (int)c.green << " b=" << (int)c.blue             \
        << " a=" << (int)c.alpha

namespace Surge
{
namespace Debug
{

bool openConsole();   // no-op on Linux and macOS; force console open on Windows
bool toggleConsole(); // no-op on Linux and macOS; shows or closes console on Windows

void stackTraceToStdout(int depth = -1); // no-op on Windows; shows stack trace on macOS and Linunx

struct LifeCycleToConsole
{ // simple class which printfs in ctor and dtor
    LifeCycleToConsole(const std::string &s);
    ~LifeCycleToConsole();
    std::string s;
};

struct TimeBlock
{
    TimeBlock(const std::string &tag);
    ~TimeBlock();
    std::string tag;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

} // namespace Debug
} // namespace Surge
