#ifndef HELPERS_NUMERICAL_H
#define HELPERS_NUMERICAL_H

#include "../../ESPEasy_common.h"

/********************************************************************************************\
  Check if string is valid float
  \*********************************************************************************************/

bool isValidFloat(float f);
bool isValidDouble(ESPEASY_RULES_FLOAT_TYPE f);

bool validIntFromString(const String& tBuf, int32_t& result);

bool validInt64FromString(const String& tBuf, int64_t& result);

bool validUIntFromString(const String& tBuf, uint32_t& result);

bool validUInt64FromString(const String& tBuf, uint64_t& result);

bool validFloatFromString(const String& tBuf, float& result);

bool validFloatFromString(const String& tBuf, float& result, int& nrDecimals);

bool validDoubleFromString(const String& tBuf, ESPEASY_RULES_FLOAT_TYPE& result);

bool validDoubleFromString(const String& tBuf, ESPEASY_RULES_FLOAT_TYPE& result, int& nrDecimals);

// Numerical types sorted from least specific to most specific.
enum class NumericalType {
  FloatingPoint,
  Integer,
  HexadecimalUInt,
  BinaryUint,
  Not_a_number
};

bool mustConsiderAsString(NumericalType detectedType);
bool mustConsiderAsJSONString(const String& value);

String getNumerical(const String& tBuf, NumericalType requestedType, NumericalType& detectedType);

bool isNumerical(const String& tBuf, NumericalType& detectedType);


#endif // HELPERS_NUMERICAL_H
