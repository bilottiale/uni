//Also, but only for C++
//#pragma once

#ifndef __STAMPA_H__
#define __STAMPA_H__

// C-compliant (if included in a C file, generates c-compliant linking into the "main" object file)
// void stampa(int);

// This is C++ code, because the "namespace" keyword does not exist in C
namespace paolo { namespace v1{
void stampa(int);
}}

namespace paolo{ namespace v2{
    void stampa(int);
}}

#endif