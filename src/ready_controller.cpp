/*
 * ready_controller.cpp
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

#include "ready_controller.h"
#include "rtwtypes.h"
#include "ready_controller_types.h"
#include "ready_controller_private.h"
#include <string.h>

extern "C"
{

#include "rt_nonfinite.h"

}

/* Block signals (default storage) */
B_ready_controller_T ready_controller_B;

/* Continuous states */
X_ready_controller_T ready_controller_X;

/* Disabled State Vector */
XDis_ready_controller_T ready_controller_XDis;

/* Block states (default storage) */
DW_ready_controller_T ready_controller_DW;

/* Real-time model */
RT_MODEL_ready_controller_T ready_controller_M_ = RT_MODEL_ready_controller_T();
RT_MODEL_ready_controller_T *const ready_controller_M = &ready_controller_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ready_controller_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ready_controller_step();
  ready_controller_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ready_controller_step();
  ready_controller_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void ready_controller_step(void)
{
  if (rtmIsMajorTimeStep(ready_controller_M)) {
    /* set solver stop time */
    if (!(ready_controller_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ready_controller_M->solverInfo,
                            ((ready_controller_M->Timing.clockTickH0 + 1) *
        ready_controller_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ready_controller_M->solverInfo,
                            ((ready_controller_M->Timing.clockTick0 + 1) *
        ready_controller_M->Timing.stepSize0 +
        ready_controller_M->Timing.clockTickH0 *
        ready_controller_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ready_controller_M)) {
    ready_controller_M->Timing.t[0] = rtsiGetT(&ready_controller_M->solverInfo);
  }

  {
    SL_Bus_ready_controller_std_msgs_Float64 rtb_BusAssignment;
    real_T rtb_Sum;
    real_T rtb_tau;
    real_T *lastU;
    boolean_T b_varargout_1;
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Constant: '<Root>/Constant4' */
      ready_controller_B.Constant4 = ready_controller_P.Constant4_Value;
    }

    /* Integrator: '<S6>/Integrator' */
    if (ready_controller_DW.Integrator_IWORK != 0) {
      ready_controller_X.Integrator_CSTATE = ready_controller_B.Constant4;
    }

    /* Saturate: '<S6>/Saturation' incorporates:
     *  Integrator: '<S6>/Integrator'
     */
    if (ready_controller_X.Integrator_CSTATE >
        ready_controller_P.Saturation_UpperSat) {
      /* Saturate: '<S6>/Saturation' */
      ready_controller_B.Saturation = ready_controller_P.Saturation_UpperSat;
    } else if (ready_controller_X.Integrator_CSTATE <
               ready_controller_P.Saturation_LowerSat) {
      /* Saturate: '<S6>/Saturation' */
      ready_controller_B.Saturation = ready_controller_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S6>/Saturation' */
      ready_controller_B.Saturation = ready_controller_X.Integrator_CSTATE;
    }

    /* End of Saturate: '<S6>/Saturation' */

    /* BusAssignment: '<Root>/Bus Assignment' */
    rtb_BusAssignment.Data = ready_controller_B.Saturation;

    /* Outputs for Atomic SubSystem: '<Root>/Publish' */
    /* MATLABSystem: '<S4>/SinkBlock' */
    Pub_ready_controller_235.publish(&rtb_BusAssignment);

    /* End of Outputs for SubSystem: '<Root>/Publish' */
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Outputs for Atomic SubSystem: '<Root>/Subscribe' */
      /* MATLABSystem: '<S5>/SourceBlock' */
      b_varargout_1 = Sub_ready_controller_234.getLatestMessage
        (&rtb_BusAssignment);

      /* Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
       *  EnablePort: '<S9>/Enable'
       */
      /* Start for MATLABSystem: '<S5>/SourceBlock' */
      if (b_varargout_1) {
        /* SignalConversion generated from: '<S9>/In1' */
        ready_controller_B.In1 = rtb_BusAssignment;
      }

      /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
      /* End of Outputs for SubSystem: '<S5>/Enabled Subsystem' */
      /* End of Outputs for SubSystem: '<Root>/Subscribe' */

      /* UnitDelay: '<Root>/Unit Delay' */
      ready_controller_B.UnitDelay = ready_controller_DW.UnitDelay_DSTATE;
    }

    /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
     *  Constant: '<Root>/tau1'
     *  Constant: '<Root>/tau3'
     *  Sum: '<Root>/Sum2'
     */
    ready_controller_B.relative_vel = ready_controller_B.In1.Data -
      ready_controller_B.Saturation;
    ready_controller_B.ego_accel = (ready_controller_B.relative_vel *
      ready_controller_P.tau1_Value + ready_controller_P.tau3_Value *
      ready_controller_B.UnitDelay) / (ready_controller_P.tau1_Value +
      ready_controller_P.tau3_Value);
    if (!(ready_controller_B.ego_accel <= 1.5)) {
      ready_controller_B.ego_accel = 1.5;
    }

    if (ready_controller_B.ego_accel <= -3.0) {
      ready_controller_B.ego_accel = -3.0;
    }

    /* Saturate: '<Root>/accel_desired_' */
    if (ready_controller_B.ego_accel > ready_controller_P.accel_desired_UpperSat)
    {
      /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
       *  Saturate: '<Root>/accel_desired_'
       */
      ready_controller_B.ego_accel = ready_controller_P.accel_desired_UpperSat;
    } else if (ready_controller_B.ego_accel <
               ready_controller_P.accel_desired_LowerSat) {
      /* MATLAB Function: '<Root>/MATLAB Function1' incorporates:
       *  Saturate: '<Root>/accel_desired_'
       */
      ready_controller_B.ego_accel = ready_controller_P.accel_desired_LowerSat;
    }

    /* End of Saturate: '<Root>/accel_desired_' */

    /* Product: '<Root>/Divide' */
    ready_controller_B.time_gap = ready_controller_B.In1.Data /
      ready_controller_B.Saturation;
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Gain: '<S7>/tau' incorporates:
       *  Constant: '<Root>/Constant6'
       */
      rtb_tau = ready_controller_P.tau_Gain * ready_controller_P.Constant6_Value;

      /* Product: '<S8>/Product2' incorporates:
       *  Bias: '<S8>/Bias'
       */
      ready_controller_B.Product2 = 1.0 / (rtb_tau +
        ready_controller_P.Bias_Bias) * rtb_tau;
    }

    /* Derivative: '<Root>/Derivative' */
    rtb_tau = ready_controller_M->Timing.t[0];
    if ((ready_controller_DW.TimeStampA >= rtb_tau) &&
        (ready_controller_DW.TimeStampB >= rtb_tau)) {
      rtb_tau = 0.0;
    } else {
      rtb_Sum = ready_controller_DW.TimeStampA;
      lastU = &ready_controller_DW.LastUAtTimeA;
      if (ready_controller_DW.TimeStampA < ready_controller_DW.TimeStampB) {
        if (ready_controller_DW.TimeStampB < rtb_tau) {
          rtb_Sum = ready_controller_DW.TimeStampB;
          lastU = &ready_controller_DW.LastUAtTimeB;
        }
      } else if (ready_controller_DW.TimeStampA >= rtb_tau) {
        rtb_Sum = ready_controller_DW.TimeStampB;
        lastU = &ready_controller_DW.LastUAtTimeB;
      }

      rtb_tau = (ready_controller_B.ego_accel - *lastU) / (rtb_tau - rtb_Sum);
    }

    /* End of Derivative: '<Root>/Derivative' */
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* UnitDelay: '<S7>/Unit Delay' */
      ready_controller_B.UnitDelay_m = ready_controller_DW.UnitDelay_DSTATE_m;
    }

    /* Sum: '<S7>/Sum' */
    rtb_Sum = rtb_tau + ready_controller_B.UnitDelay_m;

    /* Product: '<S7>/Product1' */
    ready_controller_B.Product1 = ready_controller_B.Product2 * rtb_Sum;
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Bias: '<S8>/Bias1' incorporates:
       *  Gain: '<S8>/Gain'
       */
      ready_controller_B.Bias1 = ready_controller_P.Gain_Gain *
        ready_controller_B.Product2 + ready_controller_P.Bias1_Bias;

      /* Constant: '<Root>/Constant5' */
      ready_controller_B.Constant5 = ready_controller_P.Constant5_Value;
    }

    /* Sum: '<S7>/Sum1' incorporates:
     *  Product: '<S7>/Product4'
     */
    ready_controller_B.Sum1 = ready_controller_B.Bias1 * rtb_Sum + rtb_tau;

    /* Integrator: '<S6>/Integrator1' */
    if (ready_controller_DW.Integrator1_IWORK != 0) {
      ready_controller_X.Integrator1_CSTATE = ready_controller_B.Constant5;
    }

    /* End of Integrator: '<S6>/Integrator1' */

    /* TransferFcn: '<S6>/Transfer Fcn' */
    ready_controller_B.TransferFcn = ready_controller_P.TransferFcn_C *
      ready_controller_X.TransferFcn_CSTATE;
  }

  if (rtmIsMajorTimeStep(ready_controller_M)) {
    real_T *lastU;

    /* Update for Integrator: '<S6>/Integrator' */
    ready_controller_DW.Integrator_IWORK = 0;
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Update for UnitDelay: '<Root>/Unit Delay' */
      ready_controller_DW.UnitDelay_DSTATE = ready_controller_B.ego_accel;
    }

    /* Update for Derivative: '<Root>/Derivative' */
    if (ready_controller_DW.TimeStampA == (rtInf)) {
      ready_controller_DW.TimeStampA = ready_controller_M->Timing.t[0];
      lastU = &ready_controller_DW.LastUAtTimeA;
    } else if (ready_controller_DW.TimeStampB == (rtInf)) {
      ready_controller_DW.TimeStampB = ready_controller_M->Timing.t[0];
      lastU = &ready_controller_DW.LastUAtTimeB;
    } else if (ready_controller_DW.TimeStampA < ready_controller_DW.TimeStampB)
    {
      ready_controller_DW.TimeStampA = ready_controller_M->Timing.t[0];
      lastU = &ready_controller_DW.LastUAtTimeA;
    } else {
      ready_controller_DW.TimeStampB = ready_controller_M->Timing.t[0];
      lastU = &ready_controller_DW.LastUAtTimeB;
    }

    *lastU = ready_controller_B.ego_accel;

    /* End of Update for Derivative: '<Root>/Derivative' */
    if (rtmIsMajorTimeStep(ready_controller_M)) {
      /* Update for UnitDelay: '<S7>/Unit Delay' */
      ready_controller_DW.UnitDelay_DSTATE_m = ready_controller_B.Sum1;
    }

    /* Update for Integrator: '<S6>/Integrator1' */
    ready_controller_DW.Integrator1_IWORK = 0;
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(ready_controller_M)) {
    rt_ertODEUpdateContinuousStates(&ready_controller_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ready_controller_M->Timing.clockTick0)) {
      ++ready_controller_M->Timing.clockTickH0;
    }

    ready_controller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&ready_controller_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      ready_controller_M->Timing.clockTick1++;
      if (!ready_controller_M->Timing.clockTick1) {
        ready_controller_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void ready_controller_derivatives(void)
{
  XDot_ready_controller_T *_rtXdot;
  _rtXdot = ((XDot_ready_controller_T *) ready_controller_M->derivs);

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = ready_controller_B.TransferFcn;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = ready_controller_B.Saturation;

  /* Derivatives for TransferFcn: '<S6>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = ready_controller_P.TransferFcn_A *
    ready_controller_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += ready_controller_B.ego_accel;
}

/* Model initialize function */
void ready_controller_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ready_controller_M->solverInfo,
                          &ready_controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&ready_controller_M->solverInfo, &rtmGetTPtr(ready_controller_M));
    rtsiSetStepSizePtr(&ready_controller_M->solverInfo,
                       &ready_controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&ready_controller_M->solverInfo, &ready_controller_M->derivs);
    rtsiSetContStatesPtr(&ready_controller_M->solverInfo, (real_T **)
                         &ready_controller_M->contStates);
    rtsiSetNumContStatesPtr(&ready_controller_M->solverInfo,
      &ready_controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ready_controller_M->solverInfo,
      &ready_controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&ready_controller_M->solverInfo,
      &ready_controller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&ready_controller_M->solverInfo,
      &ready_controller_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ready_controller_M->solverInfo, (boolean_T**)
      &ready_controller_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ready_controller_M->solverInfo, (&rtmGetErrorStatus
      (ready_controller_M)));
    rtsiSetRTModelPtr(&ready_controller_M->solverInfo, ready_controller_M);
  }

  rtsiSetSimTimeStep(&ready_controller_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&ready_controller_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ready_controller_M->solverInfo, false);
  ready_controller_M->intgData.y = ready_controller_M->odeY;
  ready_controller_M->intgData.f[0] = ready_controller_M->odeF[0];
  ready_controller_M->intgData.f[1] = ready_controller_M->odeF[1];
  ready_controller_M->intgData.f[2] = ready_controller_M->odeF[2];
  ready_controller_M->contStates = ((X_ready_controller_T *) &ready_controller_X);
  ready_controller_M->contStateDisabled = ((XDis_ready_controller_T *)
    &ready_controller_XDis);
  ready_controller_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ready_controller_M->solverInfo, static_cast<void *>
                    (&ready_controller_M->intgData));
  rtsiSetSolverName(&ready_controller_M->solverInfo,"ode3");
  rtmSetTPtr(ready_controller_M, &ready_controller_M->Timing.tArray[0]);
  ready_controller_M->Timing.stepSize0 = 0.1;
  rtmSetFirstInitCond(ready_controller_M, 1);

  /* block I/O */
  (void) memset((static_cast<void *>(&ready_controller_B)), 0,
                sizeof(B_ready_controller_T));

  /* states (continuous) */
  {
    (void) memset(static_cast<void *>(&ready_controller_X), 0,
                  sizeof(X_ready_controller_T));
  }

  /* disabled states */
  {
    (void) memset(static_cast<void *>(&ready_controller_XDis), 0,
                  sizeof(XDis_ready_controller_T));
  }

  /* states (dwork) */
  (void) memset(static_cast<void *>(&ready_controller_DW), 0,
                sizeof(DW_ready_controller_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic[21];
    char_T b_zeroDelimTopic_0[17];
    static const char_T b_zeroDelimTopic_1[21] = "/car/state/sim_vel_x";
    static const char_T b_zeroDelimTopic_2[17] = "/car/state/vel_x";

    /* Start for Constant: '<Root>/Constant4' */
    ready_controller_B.Constant4 = ready_controller_P.Constant4_Value;

    /* Start for Atomic SubSystem: '<Root>/Publish' */
    /* Start for MATLABSystem: '<S4>/SinkBlock' */
    ready_controller_DW.obj.matlabCodegenIsDeleted = false;
    ready_controller_DW.objisempty_k = true;
    ready_controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 21; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_1[i];
    }

    Pub_ready_controller_235.createPublisher(&b_zeroDelimTopic[0], 1);
    ready_controller_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/SinkBlock' */
    /* End of Start for SubSystem: '<Root>/Publish' */

    /* Start for Atomic SubSystem: '<Root>/Subscribe' */
    /* Start for MATLABSystem: '<S5>/SourceBlock' */
    ready_controller_DW.obj_n.matlabCodegenIsDeleted = false;
    ready_controller_DW.objisempty = true;
    ready_controller_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_2[i];
    }

    Sub_ready_controller_234.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    ready_controller_DW.obj_n.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S5>/SourceBlock' */
    /* End of Start for SubSystem: '<Root>/Subscribe' */

    /* Start for Constant: '<Root>/Constant5' */
    ready_controller_B.Constant5 = ready_controller_P.Constant5_Value;
  }

  /* InitializeConditions for Integrator: '<S6>/Integrator' incorporates:
   *  Integrator: '<S6>/Integrator1'
   */
  if (rtmIsFirstInitCond(ready_controller_M)) {
    ready_controller_X.Integrator_CSTATE = 5.0;
    ready_controller_X.Integrator1_CSTATE = 0.0;
  }

  ready_controller_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S6>/Integrator' */

  /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
  ready_controller_DW.UnitDelay_DSTATE =
    ready_controller_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  ready_controller_DW.TimeStampA = (rtInf);
  ready_controller_DW.TimeStampB = (rtInf);

  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  ready_controller_DW.UnitDelay_DSTATE_m =
    ready_controller_P.UnitDelay_InitialCondition_m;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  ready_controller_DW.Integrator1_IWORK = 1;

  /* InitializeConditions for TransferFcn: '<S6>/Transfer Fcn' */
  ready_controller_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Subscribe' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
   *  Outport: '<S9>/Out1'
   */
  ready_controller_B.In1 = ready_controller_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/Subscribe' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(ready_controller_M)) {
    rtmSetFirstInitCond(ready_controller_M, 0);
  }
}

/* Model terminate function */
void ready_controller_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Publish' */
  /* Terminate for MATLABSystem: '<S4>/SinkBlock' */
  if (!ready_controller_DW.obj.matlabCodegenIsDeleted) {
    ready_controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S4>/SinkBlock' */
  /* End of Terminate for SubSystem: '<Root>/Publish' */

  /* Terminate for Atomic SubSystem: '<Root>/Subscribe' */
  /* Terminate for MATLABSystem: '<S5>/SourceBlock' */
  if (!ready_controller_DW.obj_n.matlabCodegenIsDeleted) {
    ready_controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/SourceBlock' */
  /* End of Terminate for SubSystem: '<Root>/Subscribe' */
}
