/*
 * ready_controller_data.cpp
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

/* Block parameters (default storage) */
P_ready_controller_T ready_controller_P = {
  /* Computed Parameter: Constant_Value
   * Referenced by: '<S1>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S9>/Out1'
   */
  {
    0.0                                /* Data */
  },

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S5>/Constant'
   */
  {
    0.0                                /* Data */
  },

  /* Expression: 5
   * Referenced by: '<Root>/Constant4'
   */
  5.0,

  /* Expression: 80
   * Referenced by: '<S6>/Saturation'
   */
  80.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<Root>/tau'
   */
  3.0,

  /* Expression: 0.25
   * Referenced by: '<Root>/tau2'
   */
  0.25,

  /* Expression: 0.75
   * Referenced by: '<Root>/tau1'
   */
  0.75,

  /* Expression: 5
   * Referenced by: '<Root>/tau3'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<Root>/accel_desired_'
   */
  20.0,

  /* Expression: -20
   * Referenced by: '<Root>/accel_desired_'
   */
  -20.0,

  /* Expression: 0.25
   * Referenced by: '<Root>/Constant6'
   */
  0.25,

  /* Expression: tau
   * Referenced by: '<S7>/tau'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<S8>/Bias'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Unit Delay'
   */
  0.0,

  /* Expression: -2
   * Referenced by: '<S8>/Gain'
   */
  -2.0,

  /* Expression: 1
   * Referenced by: '<S8>/Bias1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S6>/Transfer Fcn'
   */
  -0.5,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S6>/Transfer Fcn'
   */
  0.5
};
