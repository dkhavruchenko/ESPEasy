#ifndef PLUGINSTRUCTS_P027_DATA_STRUCT_H
#define PLUGINSTRUCTS_P027_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"
#ifdef USES_P027

# ifndef P027_FEATURE_POWERDOWN
#  ifndef LIMIT_BUILD_SIZE
#   define P027_FEATURE_POWERDOWN 1
#  else // ifndef LIMIT_BUILD_SIZE
#   define P027_FEATURE_POWERDOWN 0
#  endif // ifndef LIMIT_BUILD_SIZE
# endif // ifndef P027_FEATURE_POWERDOWN

struct P027_data_struct : public PluginTaskData_base {
public:

  P027_data_struct(uint8_t i2c_addr);

  P027_data_struct()          = delete;
  virtual ~P027_data_struct() = default;


  // **************************************************************************/
  // Configures to INA219 to be able to measure up to 32V and 2A

  /**************************************************************************/
  void setCalibration_32V_2A();

  // **************************************************************************/
  // Configures to INA219 to be able to measure up to 32V and 1A
  // **************************************************************************/
  void setCalibration_32V_1A();

  // **************************************************************************/
  // Configures to INA219 to be able to measure up to 16V and 400mA
  // **************************************************************************/
  void setCalibration_16V_400mA();

  // **************************************************************************/
  // Configures to INA219 to be able to measure up to 26V and 8A
  // **************************************************************************/
  void setCalibration_26V_8A();

  # if P027_FEATURE_POWERDOWN

  // **************************************************************************/
  // Configure INA219 to Powerdown mode, keeping current configuration
  // **************************************************************************/
  void setPowerDown();

  // **************************************************************************/
  // Configure INA219 to Active working mode, keeping current configuration
  // **************************************************************************/
  void setActiveMode();
  # endif // if P027_FEATURE_POWERDOWN

private:

  // **************************************************************************/
  // Gets the raw bus voltage (16-bit signed integer, so +-32767)
  // **************************************************************************/
  int16_t getBusVoltage_raw();

  // **************************************************************************/
  // Gets the raw shunt voltage (16-bit signed integer, so +-32767)
  // **************************************************************************/
  int16_t getShuntVoltage_raw();

  // **************************************************************************/
  // Gets the raw current value (16-bit signed integer, so +-32767)
  // **************************************************************************/
  int16_t getCurrent_raw();

public:

  // **************************************************************************/
  // Gets the shunt voltage in mV (so +-327mV)
  // **************************************************************************/
  float getShuntVoltage_mV();

  // **************************************************************************/
  // Gets the shunt voltage in volts
  // **************************************************************************/
  float getBusVoltage_V();

  // **************************************************************************/
  // Gets the current value in mA, taking into account the
  //            config settings and current LSB
  // **************************************************************************/
  float getCurrent_mA();

private:

  // **************************************************************************/
  // Sends a single command byte over I2C
  // **************************************************************************/
  void wireWriteRegister(uint8_t  reg,
                         uint16_t value);

  // **************************************************************************/
  // Reads a 16 bit values over I2C
  // **************************************************************************/
  void wireReadRegister(uint8_t   reg,
                        uint16_t *value);


  uint32_t calValue = 0;

  // The following multipliers are used to convert raw current and power
  // values to mA and mW, taking into account the current config settings
  uint32_t currentDivider_mA = 0;

  uint8_t i2caddr;
};
#endif // ifdef USES_P027
#endif // ifndef PLUGINSTRUCTS_P027_DATA_STRUCT_H
