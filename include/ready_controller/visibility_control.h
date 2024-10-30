#ifndef READY_CONTROLLER__VISIBILITY_CONTROL_H_
#define READY_CONTROLLER__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define READY_CONTROLLER_EXPORT __attribute__ ((dllexport))
    #define READY_CONTROLLER_IMPORT __attribute__ ((dllimport))
  #else
    #define READY_CONTROLLER_EXPORT __declspec(dllexport)
    #define READY_CONTROLLER_IMPORT __declspec(dllimport)
  #endif
  #ifdef READY_CONTROLLER_BUILDING_LIBRARY
    #define READY_CONTROLLER_PUBLIC READY_CONTROLLER_EXPORT
  #else
    #define READY_CONTROLLER_PUBLIC READY_CONTROLLER_IMPORT
  #endif
  #define READY_CONTROLLER_PUBLIC_TYPE READY_CONTROLLER_PUBLIC
  #define READY_CONTROLLER_LOCAL
#else
  #define READY_CONTROLLER_EXPORT __attribute__ ((visibility("default")))
  #define READY_CONTROLLER_IMPORT
  #if __GNUC__ >= 4
    #define READY_CONTROLLER_PUBLIC __attribute__ ((visibility("default")))
    #define READY_CONTROLLER_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define READY_CONTROLLER_PUBLIC
    #define READY_CONTROLLER_LOCAL
  #endif
  #define READY_CONTROLLER_PUBLIC_TYPE
#endif
#endif  // READY_CONTROLLER__VISIBILITY_CONTROL_H_
// Generated 30-Oct-2024 08:46:41
// Copyright 2019-2020 The MathWorks, Inc.
