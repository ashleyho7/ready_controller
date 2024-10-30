/*
 * ready_controller.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "ready_controller".
 *
 * Model version              : 1.14
 * Simulink Coder version : 24.1 (R2024a) 19-Nov-2023
 * C++ source code generated on : Wed Oct 30 08:46:36 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ready_controller_h_
#define ready_controller_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "ready_controller_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
struct B_ready_controller_T {
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T Saturation;                   /* '<S6>/Saturation' */
  real_T UnitDelay;                    /* '<Root>/Unit Delay' */
  real_T ego_accel;                    /* '<Root>/accel_desired_' */
  real_T relative_vel;                 /* '<Root>/Sum2' */
  real_T time_gap;                     /* '<Root>/Divide' */
  real_T Product2;                     /* '<S8>/Product2' */
  real_T UnitDelay_m;                  /* '<S7>/Unit Delay' */
  real_T Product1;                     /* '<S7>/Product1' */
  real_T Bias1;                        /* '<S8>/Bias1' */
  real_T Sum1;                         /* '<S7>/Sum1' */
  real_T Constant5;                    /* '<Root>/Constant5' */
  real_T TransferFcn;                  /* '<S6>/Transfer Fcn' */
  SL_Bus_ready_controller_std_msgs_Float64 In1;/* '<S9>/In1' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_ready_controller_T {
  ros_slroscpp_internal_block_P_T obj; /* '<S4>/SinkBlock' */
  ros_slroscpp_internal_block_S_T obj_n;/* '<S5>/SourceBlock' */
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay_DSTATE_m;           /* '<S7>/Unit Delay' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  int_T Integrator_IWORK;              /* '<S6>/Integrator' */
  int_T Integrator1_IWORK;             /* '<S6>/Integrator1' */
  boolean_T objisempty;                /* '<S5>/SourceBlock' */
  boolean_T objisempty_k;              /* '<S4>/SinkBlock' */
};

/* Continuous states (default storage) */
struct X_ready_controller_T {
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S6>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_ready_controller_T {
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S6>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S6>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_ready_controller_T {
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S6>/Integrator1' */
  boolean_T TransferFcn_CSTATE;        /* '<S6>/Transfer Fcn' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_ready_controller_T_ {
  SL_Bus_ready_controller_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                           * Referenced by: '<S1>/Constant'
                                                           */
  SL_Bus_ready_controller_std_msgs_Float64 Out1_Y0;/* Computed Parameter: Out1_Y0
                                                    * Referenced by: '<S9>/Out1'
                                                    */
  SL_Bus_ready_controller_std_msgs_Float64 Constant_Value_e;/* Computed Parameter: Constant_Value_e
                                                             * Referenced by: '<S5>/Constant'
                                                             */
  real_T Constant4_Value;              /* Expression: 5
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 80
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T tau_Value;                    /* Expression: 3
                                        * Referenced by: '<Root>/tau'
                                        */
  real_T tau2_Value;                   /* Expression: 0.25
                                        * Referenced by: '<Root>/tau2'
                                        */
  real_T tau1_Value;                   /* Expression: 0.75
                                        * Referenced by: '<Root>/tau1'
                                        */
  real_T tau3_Value;                   /* Expression: 5
                                        * Referenced by: '<Root>/tau3'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T accel_desired_UpperSat;       /* Expression: 20
                                        * Referenced by: '<Root>/accel_desired_'
                                        */
  real_T accel_desired_LowerSat;       /* Expression: -20
                                        * Referenced by: '<Root>/accel_desired_'
                                        */
  real_T Constant6_Value;              /* Expression: 0.25
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T tau_Gain;                     /* Expression: tau
                                        * Referenced by: '<S7>/tau'
                                        */
  real_T Bias_Bias;                    /* Expression: 1
                                        * Referenced by: '<S8>/Bias'
                                        */
  real_T UnitDelay_InitialCondition_m; /* Expression: 0
                                        * Referenced by: '<S7>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -2
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Bias1_Bias;                   /* Expression: 1
                                        * Referenced by: '<S8>/Bias1'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S6>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S6>/Transfer Fcn'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ready_controller_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_ready_controller_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_ready_controller_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_ready_controller_T ready_controller_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_ready_controller_T ready_controller_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_ready_controller_T ready_controller_X;

/* Disabled states (default storage) */
extern XDis_ready_controller_T ready_controller_XDis;

/* Block states (default storage) */
extern struct DW_ready_controller_T ready_controller_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void ready_controller_initialize(void);
  extern void ready_controller_step(void);
  extern void ready_controller_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_ready_controller_T *const ready_controller_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ready_controller'
 * '<S1>'   : 'ready_controller/Blank Message'
 * '<S2>'   : 'ready_controller/Discrete Varying Lowpass'
 * '<S3>'   : 'ready_controller/MATLAB Function1'
 * '<S4>'   : 'ready_controller/Publish'
 * '<S5>'   : 'ready_controller/Subscribe'
 * '<S6>'   : 'ready_controller/ego_car'
 * '<S7>'   : 'ready_controller/Discrete Varying Lowpass/FOS'
 * '<S8>'   : 'ready_controller/Discrete Varying Lowpass/FOS/Arithmetic'
 * '<S9>'   : 'ready_controller/Subscribe/Enabled Subsystem'
 */
#endif                                 /* ready_controller_h_ */
