#ifndef H_COMMON_H
#define H_COMMON_H

// Standard headers

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


// Library headers

#include <SDL.h>


// Application information

#define APP_NAME "C2C"

#define APP_VERSION_MAJOR 0
#define APP_VERSION_MINOR 0
#define APP_VERSION_EXTRA 1

#define APP_VERSION_RELEASE_CANDIDATE 0


// Macros

#define STRINGIFY(x) STRINGIFY_2(x)
#define STRINGIFY_2(x) #x

#define APP_VERSION_STRING_BASIC STRINGIFY(APP_VERSION_MAJOR) "." STRINGIFY(APP_VERSION_MINOR) "." STRINGIFY(APP_VERSION_EXTRA)

#if APP_VERSION_EXTRA % 2 == 1
#define APP_VERSION_STRING APP_VERSION_STRING_BASIC " DEVELOPMENT VERSION"
#elif APP_VERSION_RELEASE_CANDIDATE != -1
#define NDEBUG
#define APP_VERSION_STRING APP_VERSION_STRING_BASIC " RELEASE CANDIDATE " STRINGIFY(APP_VERSION_RELEASE_CANDIDATE)
#else
#define NDEBUG
#define APP_VERSION_STRING APP_VERSION_STRING_BASIC
#endif

#define APP_TITLE APP_NAME " " APP_VERSION_STRING

#endif
