﻿#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <stdint.h>

#include "il2cpp-class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "il2cpp-object-internals.h"


// Mono.Unity.UnityTls/unitytls_tlsctx_read_callback
struct unitytls_tlsctx_read_callback_tD85E7923018681355C1D851137CEC527F04093F5;
// Mono.Unity.UnityTls/unitytls_tlsctx_write_callback
struct unitytls_tlsctx_write_callback_tBDF40F27E011F577C3E834B14788491861F870D6;
// System.Action`1<System.Object>
struct Action_1_t551A279CEADCF6EEAE8FA2B1E1E757D0D15290D0;
// System.Byte[]
struct ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821;
// System.Char[]
struct CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2;
// System.Int32[]
struct Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83;
// System.Reflection.MemberInfo
struct MemberInfo_t;
// System.Security.Cryptography.RandomNumberGenerator
struct RandomNumberGenerator_t12277F7F965BA79C54E4B3BFABD27A5FFB725EE2;
// System.String
struct String_t;
// System.Threading.CancellationTokenSource
struct CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE;
// System.Threading.ManualResetEvent
struct ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408;
// System.Threading.SendOrPostCallback
struct SendOrPostCallback_t3F9C0164860E4AA5138DF8B4488DFB0D33147F01;
// System.Type
struct Type_t;
// System.UInt32[]
struct UInt32U5BU5D_t9AA834AF2940E75BBF8E3F08FF0D20D266DB71CB;
// System.Void
struct Void_t22962CB4C05B1D89B55A6E1139F0E87A90987017;
// UnityEngine.Events.UnityAction
struct UnityAction_tD19B26F1B2C048E38FD5801A33573BE01064CAF4;




#ifndef RUNTIMEOBJECT_H
#define RUNTIMEOBJECT_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Object

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RUNTIMEOBJECT_H
#ifndef VALUETYPE_T4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_H
#define VALUETYPE_T4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ValueType
struct  ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF  : public RuntimeObject
{
public:

public:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_marshaled_com
{
};
#endif // VALUETYPE_T4D0C27076F7C36E76190FB3328E232BCB1CD1FFF_H
#ifndef UNITYTLS_KEY_REF_TE908606656A7C49CA1EB734722E4C3DED7CE6E5B_H
#define UNITYTLS_KEY_REF_TE908606656A7C49CA1EB734722E4C3DED7CE6E5B_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_key_ref
struct  unitytls_key_ref_tE908606656A7C49CA1EB734722E4C3DED7CE6E5B 
{
public:
	// System.UInt64 Mono.Unity.UnityTls_unitytls_key_ref::handle
	uint64_t ___handle_0;

public:
	inline static int32_t get_offset_of_handle_0() { return static_cast<int32_t>(offsetof(unitytls_key_ref_tE908606656A7C49CA1EB734722E4C3DED7CE6E5B, ___handle_0)); }
	inline uint64_t get_handle_0() const { return ___handle_0; }
	inline uint64_t* get_address_of_handle_0() { return &___handle_0; }
	inline void set_handle_0(uint64_t value)
	{
		___handle_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_KEY_REF_TE908606656A7C49CA1EB734722E4C3DED7CE6E5B_H
#ifndef UNITYTLS_TLSCTX_CALLBACKS_T7BB5F622E014A8EC300C578657E2B0550DA828B2_H
#define UNITYTLS_TLSCTX_CALLBACKS_T7BB5F622E014A8EC300C578657E2B0550DA828B2_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_tlsctx_callbacks
struct  unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2 
{
public:
	// Mono.Unity.UnityTls_unitytls_tlsctx_read_callback Mono.Unity.UnityTls_unitytls_tlsctx_callbacks::read
	unitytls_tlsctx_read_callback_tD85E7923018681355C1D851137CEC527F04093F5 * ___read_0;
	// Mono.Unity.UnityTls_unitytls_tlsctx_write_callback Mono.Unity.UnityTls_unitytls_tlsctx_callbacks::write
	unitytls_tlsctx_write_callback_tBDF40F27E011F577C3E834B14788491861F870D6 * ___write_1;
	// System.Void* Mono.Unity.UnityTls_unitytls_tlsctx_callbacks::data
	void* ___data_2;

public:
	inline static int32_t get_offset_of_read_0() { return static_cast<int32_t>(offsetof(unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2, ___read_0)); }
	inline unitytls_tlsctx_read_callback_tD85E7923018681355C1D851137CEC527F04093F5 * get_read_0() const { return ___read_0; }
	inline unitytls_tlsctx_read_callback_tD85E7923018681355C1D851137CEC527F04093F5 ** get_address_of_read_0() { return &___read_0; }
	inline void set_read_0(unitytls_tlsctx_read_callback_tD85E7923018681355C1D851137CEC527F04093F5 * value)
	{
		___read_0 = value;
		Il2CppCodeGenWriteBarrier((&___read_0), value);
	}

	inline static int32_t get_offset_of_write_1() { return static_cast<int32_t>(offsetof(unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2, ___write_1)); }
	inline unitytls_tlsctx_write_callback_tBDF40F27E011F577C3E834B14788491861F870D6 * get_write_1() const { return ___write_1; }
	inline unitytls_tlsctx_write_callback_tBDF40F27E011F577C3E834B14788491861F870D6 ** get_address_of_write_1() { return &___write_1; }
	inline void set_write_1(unitytls_tlsctx_write_callback_tBDF40F27E011F577C3E834B14788491861F870D6 * value)
	{
		___write_1 = value;
		Il2CppCodeGenWriteBarrier((&___write_1), value);
	}

	inline static int32_t get_offset_of_data_2() { return static_cast<int32_t>(offsetof(unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2, ___data_2)); }
	inline void* get_data_2() const { return ___data_2; }
	inline void** get_address_of_data_2() { return &___data_2; }
	inline void set_data_2(void* value)
	{
		___data_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of Mono.Unity.UnityTls/unitytls_tlsctx_callbacks
struct unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2_marshaled_pinvoke
{
	Il2CppMethodPointer ___read_0;
	Il2CppMethodPointer ___write_1;
	void* ___data_2;
};
// Native definition for COM marshalling of Mono.Unity.UnityTls/unitytls_tlsctx_callbacks
struct unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2_marshaled_com
{
	Il2CppMethodPointer ___read_0;
	Il2CppMethodPointer ___write_1;
	void* ___data_2;
};
#endif // UNITYTLS_TLSCTX_CALLBACKS_T7BB5F622E014A8EC300C578657E2B0550DA828B2_H
#ifndef UNITYTLS_X509_REF_TE1ED17887226610A1328A57FF787396C9457E7B7_H
#define UNITYTLS_X509_REF_TE1ED17887226610A1328A57FF787396C9457E7B7_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_x509_ref
struct  unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7 
{
public:
	// System.UInt64 Mono.Unity.UnityTls_unitytls_x509_ref::handle
	uint64_t ___handle_0;

public:
	inline static int32_t get_offset_of_handle_0() { return static_cast<int32_t>(offsetof(unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7, ___handle_0)); }
	inline uint64_t get_handle_0() const { return ___handle_0; }
	inline uint64_t* get_address_of_handle_0() { return &___handle_0; }
	inline void set_handle_0(uint64_t value)
	{
		___handle_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_X509_REF_TE1ED17887226610A1328A57FF787396C9457E7B7_H
#ifndef UNITYTLS_X509LIST_REF_TF01A6BF5ADA9C454E6B975D2669AF22D27555BF6_H
#define UNITYTLS_X509LIST_REF_TF01A6BF5ADA9C454E6B975D2669AF22D27555BF6_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_x509list_ref
struct  unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6 
{
public:
	// System.UInt64 Mono.Unity.UnityTls_unitytls_x509list_ref::handle
	uint64_t ___handle_0;

public:
	inline static int32_t get_offset_of_handle_0() { return static_cast<int32_t>(offsetof(unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6, ___handle_0)); }
	inline uint64_t get_handle_0() const { return ___handle_0; }
	inline uint64_t* get_address_of_handle_0() { return &___handle_0; }
	inline void set_handle_0(uint64_t value)
	{
		___handle_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_X509LIST_REF_TF01A6BF5ADA9C454E6B975D2669AF22D27555BF6_H
#ifndef BOOLEAN_TB53F6830F670160873277339AA58F15CAED4399C_H
#define BOOLEAN_TB53F6830F670160873277339AA58F15CAED4399C_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Boolean
struct  Boolean_tB53F6830F670160873277339AA58F15CAED4399C 
{
public:
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;

public:
	inline static int32_t get_offset_of_m_value_0() { return static_cast<int32_t>(offsetof(Boolean_tB53F6830F670160873277339AA58F15CAED4399C, ___m_value_0)); }
	inline bool get_m_value_0() const { return ___m_value_0; }
	inline bool* get_address_of_m_value_0() { return &___m_value_0; }
	inline void set_m_value_0(bool value)
	{
		___m_value_0 = value;
	}
};

struct Boolean_tB53F6830F670160873277339AA58F15CAED4399C_StaticFields
{
public:
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;

public:
	inline static int32_t get_offset_of_TrueString_5() { return static_cast<int32_t>(offsetof(Boolean_tB53F6830F670160873277339AA58F15CAED4399C_StaticFields, ___TrueString_5)); }
	inline String_t* get_TrueString_5() const { return ___TrueString_5; }
	inline String_t** get_address_of_TrueString_5() { return &___TrueString_5; }
	inline void set_TrueString_5(String_t* value)
	{
		___TrueString_5 = value;
		Il2CppCodeGenWriteBarrier((&___TrueString_5), value);
	}

	inline static int32_t get_offset_of_FalseString_6() { return static_cast<int32_t>(offsetof(Boolean_tB53F6830F670160873277339AA58F15CAED4399C_StaticFields, ___FalseString_6)); }
	inline String_t* get_FalseString_6() const { return ___FalseString_6; }
	inline String_t** get_address_of_FalseString_6() { return &___FalseString_6; }
	inline void set_FalseString_6(String_t* value)
	{
		___FalseString_6 = value;
		Il2CppCodeGenWriteBarrier((&___FalseString_6), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // BOOLEAN_TB53F6830F670160873277339AA58F15CAED4399C_H
#ifndef DICTIONARYENTRY_TB5348A26B94274FCC1DD77185BD5946E283B11A4_H
#define DICTIONARYENTRY_TB5348A26B94274FCC1DD77185BD5946E283B11A4_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.DictionaryEntry
struct  DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4 
{
public:
	// System.Object System.Collections.DictionaryEntry::_key
	RuntimeObject * ____key_0;
	// System.Object System.Collections.DictionaryEntry::_value
	RuntimeObject * ____value_1;

public:
	inline static int32_t get_offset_of__key_0() { return static_cast<int32_t>(offsetof(DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4, ____key_0)); }
	inline RuntimeObject * get__key_0() const { return ____key_0; }
	inline RuntimeObject ** get_address_of__key_0() { return &____key_0; }
	inline void set__key_0(RuntimeObject * value)
	{
		____key_0 = value;
		Il2CppCodeGenWriteBarrier((&____key_0), value);
	}

	inline static int32_t get_offset_of__value_1() { return static_cast<int32_t>(offsetof(DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4, ____value_1)); }
	inline RuntimeObject * get__value_1() const { return ____value_1; }
	inline RuntimeObject ** get_address_of__value_1() { return &____value_1; }
	inline void set__value_1(RuntimeObject * value)
	{
		____value_1 = value;
		Il2CppCodeGenWriteBarrier((&____value_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Collections.DictionaryEntry
struct DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4_marshaled_pinvoke
{
	Il2CppIUnknown* ____key_0;
	Il2CppIUnknown* ____value_1;
};
// Native definition for COM marshalling of System.Collections.DictionaryEntry
struct DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4_marshaled_com
{
	Il2CppIUnknown* ____key_0;
	Il2CppIUnknown* ____value_1;
};
#endif // DICTIONARYENTRY_TB5348A26B94274FCC1DD77185BD5946E283B11A4_H
#ifndef KEYVALUEPAIR_2_T23481547E419E16E3B96A303578C1EB685C99EEE_H
#define KEYVALUEPAIR_2_T23481547E419E16E3B96A303578C1EB685C99EEE_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.KeyValuePair`2<System.Object,System.Object>
struct  KeyValuePair_2_t23481547E419E16E3B96A303578C1EB685C99EEE 
{
public:
	// TKey System.Collections.Generic.KeyValuePair`2::key
	RuntimeObject * ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	RuntimeObject * ___value_1;

public:
	inline static int32_t get_offset_of_key_0() { return static_cast<int32_t>(offsetof(KeyValuePair_2_t23481547E419E16E3B96A303578C1EB685C99EEE, ___key_0)); }
	inline RuntimeObject * get_key_0() const { return ___key_0; }
	inline RuntimeObject ** get_address_of_key_0() { return &___key_0; }
	inline void set_key_0(RuntimeObject * value)
	{
		___key_0 = value;
		Il2CppCodeGenWriteBarrier((&___key_0), value);
	}

	inline static int32_t get_offset_of_value_1() { return static_cast<int32_t>(offsetof(KeyValuePair_2_t23481547E419E16E3B96A303578C1EB685C99EEE, ___value_1)); }
	inline RuntimeObject * get_value_1() const { return ___value_1; }
	inline RuntimeObject ** get_address_of_value_1() { return &___value_1; }
	inline void set_value_1(RuntimeObject * value)
	{
		___value_1 = value;
		Il2CppCodeGenWriteBarrier((&___value_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // KEYVALUEPAIR_2_T23481547E419E16E3B96A303578C1EB685C99EEE_H
#ifndef DATETIME_T349B7449FBAAFF4192636E2B7A07694DA9236132_H
#define DATETIME_T349B7449FBAAFF4192636E2B7A07694DA9236132_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.DateTime
struct  DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132 
{
public:
	// System.UInt64 System.DateTime::dateData
	uint64_t ___dateData_44;

public:
	inline static int32_t get_offset_of_dateData_44() { return static_cast<int32_t>(offsetof(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132, ___dateData_44)); }
	inline uint64_t get_dateData_44() const { return ___dateData_44; }
	inline uint64_t* get_address_of_dateData_44() { return &___dateData_44; }
	inline void set_dateData_44(uint64_t value)
	{
		___dateData_44 = value;
	}
};

struct DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132_StaticFields
{
public:
	// System.Int32[] System.DateTime::DaysToMonth365
	Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* ___DaysToMonth365_29;
	// System.Int32[] System.DateTime::DaysToMonth366
	Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* ___DaysToMonth366_30;
	// System.DateTime System.DateTime::MinValue
	DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  ___MinValue_31;
	// System.DateTime System.DateTime::MaxValue
	DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  ___MaxValue_32;

public:
	inline static int32_t get_offset_of_DaysToMonth365_29() { return static_cast<int32_t>(offsetof(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132_StaticFields, ___DaysToMonth365_29)); }
	inline Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* get_DaysToMonth365_29() const { return ___DaysToMonth365_29; }
	inline Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83** get_address_of_DaysToMonth365_29() { return &___DaysToMonth365_29; }
	inline void set_DaysToMonth365_29(Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* value)
	{
		___DaysToMonth365_29 = value;
		Il2CppCodeGenWriteBarrier((&___DaysToMonth365_29), value);
	}

	inline static int32_t get_offset_of_DaysToMonth366_30() { return static_cast<int32_t>(offsetof(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132_StaticFields, ___DaysToMonth366_30)); }
	inline Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* get_DaysToMonth366_30() const { return ___DaysToMonth366_30; }
	inline Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83** get_address_of_DaysToMonth366_30() { return &___DaysToMonth366_30; }
	inline void set_DaysToMonth366_30(Int32U5BU5D_t2B9E4FDDDB9F0A00EC0AC631BA2DA915EB1ECF83* value)
	{
		___DaysToMonth366_30 = value;
		Il2CppCodeGenWriteBarrier((&___DaysToMonth366_30), value);
	}

	inline static int32_t get_offset_of_MinValue_31() { return static_cast<int32_t>(offsetof(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132_StaticFields, ___MinValue_31)); }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  get_MinValue_31() const { return ___MinValue_31; }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132 * get_address_of_MinValue_31() { return &___MinValue_31; }
	inline void set_MinValue_31(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  value)
	{
		___MinValue_31 = value;
	}

	inline static int32_t get_offset_of_MaxValue_32() { return static_cast<int32_t>(offsetof(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132_StaticFields, ___MaxValue_32)); }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  get_MaxValue_32() const { return ___MaxValue_32; }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132 * get_address_of_MaxValue_32() { return &___MaxValue_32; }
	inline void set_MaxValue_32(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  value)
	{
		___MaxValue_32 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // DATETIME_T349B7449FBAAFF4192636E2B7A07694DA9236132_H
#ifndef DECIMAL_T44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_H
#define DECIMAL_T44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Decimal
struct  Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 
{
public:
	// System.Int32 System.Decimal::flags
	int32_t ___flags_14;
	// System.Int32 System.Decimal::hi
	int32_t ___hi_15;
	// System.Int32 System.Decimal::lo
	int32_t ___lo_16;
	// System.Int32 System.Decimal::mid
	int32_t ___mid_17;

public:
	inline static int32_t get_offset_of_flags_14() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8, ___flags_14)); }
	inline int32_t get_flags_14() const { return ___flags_14; }
	inline int32_t* get_address_of_flags_14() { return &___flags_14; }
	inline void set_flags_14(int32_t value)
	{
		___flags_14 = value;
	}

	inline static int32_t get_offset_of_hi_15() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8, ___hi_15)); }
	inline int32_t get_hi_15() const { return ___hi_15; }
	inline int32_t* get_address_of_hi_15() { return &___hi_15; }
	inline void set_hi_15(int32_t value)
	{
		___hi_15 = value;
	}

	inline static int32_t get_offset_of_lo_16() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8, ___lo_16)); }
	inline int32_t get_lo_16() const { return ___lo_16; }
	inline int32_t* get_address_of_lo_16() { return &___lo_16; }
	inline void set_lo_16(int32_t value)
	{
		___lo_16 = value;
	}

	inline static int32_t get_offset_of_mid_17() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8, ___mid_17)); }
	inline int32_t get_mid_17() const { return ___mid_17; }
	inline int32_t* get_address_of_mid_17() { return &___mid_17; }
	inline void set_mid_17(int32_t value)
	{
		___mid_17 = value;
	}
};

struct Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields
{
public:
	// System.UInt32[] System.Decimal::Powers10
	UInt32U5BU5D_t9AA834AF2940E75BBF8E3F08FF0D20D266DB71CB* ___Powers10_6;
	// System.Decimal System.Decimal::Zero
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___Zero_7;
	// System.Decimal System.Decimal::One
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___One_8;
	// System.Decimal System.Decimal::MinusOne
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___MinusOne_9;
	// System.Decimal System.Decimal::MaxValue
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___MaxValue_10;
	// System.Decimal System.Decimal::MinValue
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___MinValue_11;
	// System.Decimal System.Decimal::NearNegativeZero
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___NearNegativeZero_12;
	// System.Decimal System.Decimal::NearPositiveZero
	Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  ___NearPositiveZero_13;

public:
	inline static int32_t get_offset_of_Powers10_6() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___Powers10_6)); }
	inline UInt32U5BU5D_t9AA834AF2940E75BBF8E3F08FF0D20D266DB71CB* get_Powers10_6() const { return ___Powers10_6; }
	inline UInt32U5BU5D_t9AA834AF2940E75BBF8E3F08FF0D20D266DB71CB** get_address_of_Powers10_6() { return &___Powers10_6; }
	inline void set_Powers10_6(UInt32U5BU5D_t9AA834AF2940E75BBF8E3F08FF0D20D266DB71CB* value)
	{
		___Powers10_6 = value;
		Il2CppCodeGenWriteBarrier((&___Powers10_6), value);
	}

	inline static int32_t get_offset_of_Zero_7() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___Zero_7)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_Zero_7() const { return ___Zero_7; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_Zero_7() { return &___Zero_7; }
	inline void set_Zero_7(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___Zero_7 = value;
	}

	inline static int32_t get_offset_of_One_8() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___One_8)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_One_8() const { return ___One_8; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_One_8() { return &___One_8; }
	inline void set_One_8(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___One_8 = value;
	}

	inline static int32_t get_offset_of_MinusOne_9() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___MinusOne_9)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_MinusOne_9() const { return ___MinusOne_9; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_MinusOne_9() { return &___MinusOne_9; }
	inline void set_MinusOne_9(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___MinusOne_9 = value;
	}

	inline static int32_t get_offset_of_MaxValue_10() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___MaxValue_10)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_MaxValue_10() const { return ___MaxValue_10; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_MaxValue_10() { return &___MaxValue_10; }
	inline void set_MaxValue_10(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___MaxValue_10 = value;
	}

	inline static int32_t get_offset_of_MinValue_11() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___MinValue_11)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_MinValue_11() const { return ___MinValue_11; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_MinValue_11() { return &___MinValue_11; }
	inline void set_MinValue_11(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___MinValue_11 = value;
	}

	inline static int32_t get_offset_of_NearNegativeZero_12() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___NearNegativeZero_12)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_NearNegativeZero_12() const { return ___NearNegativeZero_12; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_NearNegativeZero_12() { return &___NearNegativeZero_12; }
	inline void set_NearNegativeZero_12(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___NearNegativeZero_12 = value;
	}

	inline static int32_t get_offset_of_NearPositiveZero_13() { return static_cast<int32_t>(offsetof(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_StaticFields, ___NearPositiveZero_13)); }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  get_NearPositiveZero_13() const { return ___NearPositiveZero_13; }
	inline Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8 * get_address_of_NearPositiveZero_13() { return &___NearPositiveZero_13; }
	inline void set_NearPositiveZero_13(Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  value)
	{
		___NearPositiveZero_13 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // DECIMAL_T44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8_H
#ifndef ENUM_T2AF27C02B8653AE29442467390005ABC74D8F521_H
#define ENUM_T2AF27C02B8653AE29442467390005ABC74D8F521_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Enum
struct  Enum_t2AF27C02B8653AE29442467390005ABC74D8F521  : public ValueType_t4D0C27076F7C36E76190FB3328E232BCB1CD1FFF
{
public:

public:
};

struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_StaticFields
{
public:
	// System.Char[] System.Enum::enumSeperatorCharArray
	CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* ___enumSeperatorCharArray_0;

public:
	inline static int32_t get_offset_of_enumSeperatorCharArray_0() { return static_cast<int32_t>(offsetof(Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_StaticFields, ___enumSeperatorCharArray_0)); }
	inline CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* get_enumSeperatorCharArray_0() const { return ___enumSeperatorCharArray_0; }
	inline CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2** get_address_of_enumSeperatorCharArray_0() { return &___enumSeperatorCharArray_0; }
	inline void set_enumSeperatorCharArray_0(CharU5BU5D_t4CC6ABF0AD71BEC97E3C2F1E9C5677E46D3A75C2* value)
	{
		___enumSeperatorCharArray_0 = value;
		Il2CppCodeGenWriteBarrier((&___enumSeperatorCharArray_0), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2AF27C02B8653AE29442467390005ABC74D8F521_marshaled_com
{
};
#endif // ENUM_T2AF27C02B8653AE29442467390005ABC74D8F521_H
#ifndef GUID_T_H
#define GUID_T_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Guid
struct  Guid_t 
{
public:
	// System.Int32 System.Guid::_a
	int32_t ____a_1;
	// System.Int16 System.Guid::_b
	int16_t ____b_2;
	// System.Int16 System.Guid::_c
	int16_t ____c_3;
	// System.Byte System.Guid::_d
	uint8_t ____d_4;
	// System.Byte System.Guid::_e
	uint8_t ____e_5;
	// System.Byte System.Guid::_f
	uint8_t ____f_6;
	// System.Byte System.Guid::_g
	uint8_t ____g_7;
	// System.Byte System.Guid::_h
	uint8_t ____h_8;
	// System.Byte System.Guid::_i
	uint8_t ____i_9;
	// System.Byte System.Guid::_j
	uint8_t ____j_10;
	// System.Byte System.Guid::_k
	uint8_t ____k_11;

public:
	inline static int32_t get_offset_of__a_1() { return static_cast<int32_t>(offsetof(Guid_t, ____a_1)); }
	inline int32_t get__a_1() const { return ____a_1; }
	inline int32_t* get_address_of__a_1() { return &____a_1; }
	inline void set__a_1(int32_t value)
	{
		____a_1 = value;
	}

	inline static int32_t get_offset_of__b_2() { return static_cast<int32_t>(offsetof(Guid_t, ____b_2)); }
	inline int16_t get__b_2() const { return ____b_2; }
	inline int16_t* get_address_of__b_2() { return &____b_2; }
	inline void set__b_2(int16_t value)
	{
		____b_2 = value;
	}

	inline static int32_t get_offset_of__c_3() { return static_cast<int32_t>(offsetof(Guid_t, ____c_3)); }
	inline int16_t get__c_3() const { return ____c_3; }
	inline int16_t* get_address_of__c_3() { return &____c_3; }
	inline void set__c_3(int16_t value)
	{
		____c_3 = value;
	}

	inline static int32_t get_offset_of__d_4() { return static_cast<int32_t>(offsetof(Guid_t, ____d_4)); }
	inline uint8_t get__d_4() const { return ____d_4; }
	inline uint8_t* get_address_of__d_4() { return &____d_4; }
	inline void set__d_4(uint8_t value)
	{
		____d_4 = value;
	}

	inline static int32_t get_offset_of__e_5() { return static_cast<int32_t>(offsetof(Guid_t, ____e_5)); }
	inline uint8_t get__e_5() const { return ____e_5; }
	inline uint8_t* get_address_of__e_5() { return &____e_5; }
	inline void set__e_5(uint8_t value)
	{
		____e_5 = value;
	}

	inline static int32_t get_offset_of__f_6() { return static_cast<int32_t>(offsetof(Guid_t, ____f_6)); }
	inline uint8_t get__f_6() const { return ____f_6; }
	inline uint8_t* get_address_of__f_6() { return &____f_6; }
	inline void set__f_6(uint8_t value)
	{
		____f_6 = value;
	}

	inline static int32_t get_offset_of__g_7() { return static_cast<int32_t>(offsetof(Guid_t, ____g_7)); }
	inline uint8_t get__g_7() const { return ____g_7; }
	inline uint8_t* get_address_of__g_7() { return &____g_7; }
	inline void set__g_7(uint8_t value)
	{
		____g_7 = value;
	}

	inline static int32_t get_offset_of__h_8() { return static_cast<int32_t>(offsetof(Guid_t, ____h_8)); }
	inline uint8_t get__h_8() const { return ____h_8; }
	inline uint8_t* get_address_of__h_8() { return &____h_8; }
	inline void set__h_8(uint8_t value)
	{
		____h_8 = value;
	}

	inline static int32_t get_offset_of__i_9() { return static_cast<int32_t>(offsetof(Guid_t, ____i_9)); }
	inline uint8_t get__i_9() const { return ____i_9; }
	inline uint8_t* get_address_of__i_9() { return &____i_9; }
	inline void set__i_9(uint8_t value)
	{
		____i_9 = value;
	}

	inline static int32_t get_offset_of__j_10() { return static_cast<int32_t>(offsetof(Guid_t, ____j_10)); }
	inline uint8_t get__j_10() const { return ____j_10; }
	inline uint8_t* get_address_of__j_10() { return &____j_10; }
	inline void set__j_10(uint8_t value)
	{
		____j_10 = value;
	}

	inline static int32_t get_offset_of__k_11() { return static_cast<int32_t>(offsetof(Guid_t, ____k_11)); }
	inline uint8_t get__k_11() const { return ____k_11; }
	inline uint8_t* get_address_of__k_11() { return &____k_11; }
	inline void set__k_11(uint8_t value)
	{
		____k_11 = value;
	}
};

struct Guid_t_StaticFields
{
public:
	// System.Guid System.Guid::Empty
	Guid_t  ___Empty_0;
	// System.Object System.Guid::_rngAccess
	RuntimeObject * ____rngAccess_12;
	// System.Security.Cryptography.RandomNumberGenerator System.Guid::_rng
	RandomNumberGenerator_t12277F7F965BA79C54E4B3BFABD27A5FFB725EE2 * ____rng_13;

public:
	inline static int32_t get_offset_of_Empty_0() { return static_cast<int32_t>(offsetof(Guid_t_StaticFields, ___Empty_0)); }
	inline Guid_t  get_Empty_0() const { return ___Empty_0; }
	inline Guid_t * get_address_of_Empty_0() { return &___Empty_0; }
	inline void set_Empty_0(Guid_t  value)
	{
		___Empty_0 = value;
	}

	inline static int32_t get_offset_of__rngAccess_12() { return static_cast<int32_t>(offsetof(Guid_t_StaticFields, ____rngAccess_12)); }
	inline RuntimeObject * get__rngAccess_12() const { return ____rngAccess_12; }
	inline RuntimeObject ** get_address_of__rngAccess_12() { return &____rngAccess_12; }
	inline void set__rngAccess_12(RuntimeObject * value)
	{
		____rngAccess_12 = value;
		Il2CppCodeGenWriteBarrier((&____rngAccess_12), value);
	}

	inline static int32_t get_offset_of__rng_13() { return static_cast<int32_t>(offsetof(Guid_t_StaticFields, ____rng_13)); }
	inline RandomNumberGenerator_t12277F7F965BA79C54E4B3BFABD27A5FFB725EE2 * get__rng_13() const { return ____rng_13; }
	inline RandomNumberGenerator_t12277F7F965BA79C54E4B3BFABD27A5FFB725EE2 ** get_address_of__rng_13() { return &____rng_13; }
	inline void set__rng_13(RandomNumberGenerator_t12277F7F965BA79C54E4B3BFABD27A5FFB725EE2 * value)
	{
		____rng_13 = value;
		Il2CppCodeGenWriteBarrier((&____rng_13), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // GUID_T_H
#ifndef READWRITEPARAMETERS_T5A9E416E0129249869039FC606326558DA3B597F_H
#define READWRITEPARAMETERS_T5A9E416E0129249869039FC606326558DA3B597F_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.IO.Stream_ReadWriteParameters
struct  ReadWriteParameters_t5A9E416E0129249869039FC606326558DA3B597F 
{
public:
	// System.Byte[] System.IO.Stream_ReadWriteParameters::Buffer
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Buffer_0;
	// System.Int32 System.IO.Stream_ReadWriteParameters::Offset
	int32_t ___Offset_1;
	// System.Int32 System.IO.Stream_ReadWriteParameters::Count
	int32_t ___Count_2;

public:
	inline static int32_t get_offset_of_Buffer_0() { return static_cast<int32_t>(offsetof(ReadWriteParameters_t5A9E416E0129249869039FC606326558DA3B597F, ___Buffer_0)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Buffer_0() const { return ___Buffer_0; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Buffer_0() { return &___Buffer_0; }
	inline void set_Buffer_0(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Buffer_0 = value;
		Il2CppCodeGenWriteBarrier((&___Buffer_0), value);
	}

	inline static int32_t get_offset_of_Offset_1() { return static_cast<int32_t>(offsetof(ReadWriteParameters_t5A9E416E0129249869039FC606326558DA3B597F, ___Offset_1)); }
	inline int32_t get_Offset_1() const { return ___Offset_1; }
	inline int32_t* get_address_of_Offset_1() { return &___Offset_1; }
	inline void set_Offset_1(int32_t value)
	{
		___Offset_1 = value;
	}

	inline static int32_t get_offset_of_Count_2() { return static_cast<int32_t>(offsetof(ReadWriteParameters_t5A9E416E0129249869039FC606326558DA3B597F, ___Count_2)); }
	inline int32_t get_Count_2() const { return ___Count_2; }
	inline int32_t* get_address_of_Count_2() { return &___Count_2; }
	inline void set_Count_2(int32_t value)
	{
		___Count_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // READWRITEPARAMETERS_T5A9E416E0129249869039FC606326558DA3B597F_H
#ifndef INTPTR_T_H
#define INTPTR_T_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.IntPtr
struct  IntPtr_t 
{
public:
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;

public:
	inline static int32_t get_offset_of_m_value_0() { return static_cast<int32_t>(offsetof(IntPtr_t, ___m_value_0)); }
	inline void* get_m_value_0() const { return ___m_value_0; }
	inline void** get_address_of_m_value_0() { return &___m_value_0; }
	inline void set_m_value_0(void* value)
	{
		___m_value_0 = value;
	}
};

struct IntPtr_t_StaticFields
{
public:
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;

public:
	inline static int32_t get_offset_of_Zero_1() { return static_cast<int32_t>(offsetof(IntPtr_t_StaticFields, ___Zero_1)); }
	inline intptr_t get_Zero_1() const { return ___Zero_1; }
	inline intptr_t* get_address_of_Zero_1() { return &___Zero_1; }
	inline void set_Zero_1(intptr_t value)
	{
		___Zero_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // INTPTR_T_H
#ifndef NULLABLE_1_T0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB_H
#define NULLABLE_1_T0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Nullable`1<System.Int32>
struct  Nullable_1_t0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB 
{
public:
	// T System.Nullable`1::value
	int32_t ___value_0;
	// System.Boolean System.Nullable`1::has_value
	bool ___has_value_1;

public:
	inline static int32_t get_offset_of_value_0() { return static_cast<int32_t>(offsetof(Nullable_1_t0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB, ___value_0)); }
	inline int32_t get_value_0() const { return ___value_0; }
	inline int32_t* get_address_of_value_0() { return &___value_0; }
	inline void set_value_0(int32_t value)
	{
		___value_0 = value;
	}

	inline static int32_t get_offset_of_has_value_1() { return static_cast<int32_t>(offsetof(Nullable_1_t0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB, ___has_value_1)); }
	inline bool get_has_value_1() const { return ___has_value_1; }
	inline bool* get_address_of_has_value_1() { return &___has_value_1; }
	inline void set_has_value_1(bool value)
	{
		___has_value_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // NULLABLE_1_T0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB_H
#ifndef CUSTOMATTRIBUTETYPEDARGUMENT_T238ACCB3A438CB5EDE4A924C637B288CCEC958E8_H
#define CUSTOMATTRIBUTETYPEDARGUMENT_T238ACCB3A438CB5EDE4A924C637B288CCEC958E8_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Reflection.CustomAttributeTypedArgument
struct  CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8 
{
public:
	// System.Type System.Reflection.CustomAttributeTypedArgument::argumentType
	Type_t * ___argumentType_0;
	// System.Object System.Reflection.CustomAttributeTypedArgument::value
	RuntimeObject * ___value_1;

public:
	inline static int32_t get_offset_of_argumentType_0() { return static_cast<int32_t>(offsetof(CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8, ___argumentType_0)); }
	inline Type_t * get_argumentType_0() const { return ___argumentType_0; }
	inline Type_t ** get_address_of_argumentType_0() { return &___argumentType_0; }
	inline void set_argumentType_0(Type_t * value)
	{
		___argumentType_0 = value;
		Il2CppCodeGenWriteBarrier((&___argumentType_0), value);
	}

	inline static int32_t get_offset_of_value_1() { return static_cast<int32_t>(offsetof(CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8, ___value_1)); }
	inline RuntimeObject * get_value_1() const { return ___value_1; }
	inline RuntimeObject ** get_address_of_value_1() { return &___value_1; }
	inline void set_value_1(RuntimeObject * value)
	{
		___value_1 = value;
		Il2CppCodeGenWriteBarrier((&___value_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Reflection.CustomAttributeTypedArgument
struct CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8_marshaled_pinvoke
{
	Type_t * ___argumentType_0;
	Il2CppIUnknown* ___value_1;
};
// Native definition for COM marshalling of System.Reflection.CustomAttributeTypedArgument
struct CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8_marshaled_com
{
	Type_t * ___argumentType_0;
	Il2CppIUnknown* ___value_1;
};
#endif // CUSTOMATTRIBUTETYPEDARGUMENT_T238ACCB3A438CB5EDE4A924C637B288CCEC958E8_H
#ifndef RESOURCELOCATOR_T1783916E271C27CB09DF57E7E5ED08ECA4B3275C_H
#define RESOURCELOCATOR_T1783916E271C27CB09DF57E7E5ED08ECA4B3275C_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Resources.ResourceLocator
struct  ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C 
{
public:
	// System.Object System.Resources.ResourceLocator::_value
	RuntimeObject * ____value_0;
	// System.Int32 System.Resources.ResourceLocator::_dataPos
	int32_t ____dataPos_1;

public:
	inline static int32_t get_offset_of__value_0() { return static_cast<int32_t>(offsetof(ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C, ____value_0)); }
	inline RuntimeObject * get__value_0() const { return ____value_0; }
	inline RuntimeObject ** get_address_of__value_0() { return &____value_0; }
	inline void set__value_0(RuntimeObject * value)
	{
		____value_0 = value;
		Il2CppCodeGenWriteBarrier((&____value_0), value);
	}

	inline static int32_t get_offset_of__dataPos_1() { return static_cast<int32_t>(offsetof(ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C, ____dataPos_1)); }
	inline int32_t get__dataPos_1() const { return ____dataPos_1; }
	inline int32_t* get_address_of__dataPos_1() { return &____dataPos_1; }
	inline void set__dataPos_1(int32_t value)
	{
		____dataPos_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Resources.ResourceLocator
struct ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C_marshaled_pinvoke
{
	Il2CppIUnknown* ____value_0;
	int32_t ____dataPos_1;
};
// Native definition for COM marshalling of System.Resources.ResourceLocator
struct ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C_marshaled_com
{
	Il2CppIUnknown* ____value_0;
	int32_t ____dataPos_1;
};
#endif // RESOURCELOCATOR_T1783916E271C27CB09DF57E7E5ED08ECA4B3275C_H
#ifndef DSAPARAMETERS_TCA1A96A151F47B1904693C457243E3B919425AC6_H
#define DSAPARAMETERS_TCA1A96A151F47B1904693C457243E3B919425AC6_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Security.Cryptography.DSAParameters
struct  DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6 
{
public:
	// System.Byte[] System.Security.Cryptography.DSAParameters::P
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___P_0;
	// System.Byte[] System.Security.Cryptography.DSAParameters::Q
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Q_1;
	// System.Byte[] System.Security.Cryptography.DSAParameters::G
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___G_2;
	// System.Byte[] System.Security.Cryptography.DSAParameters::Y
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Y_3;
	// System.Byte[] System.Security.Cryptography.DSAParameters::J
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___J_4;
	// System.Byte[] System.Security.Cryptography.DSAParameters::X
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___X_5;
	// System.Byte[] System.Security.Cryptography.DSAParameters::Seed
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Seed_6;
	// System.Int32 System.Security.Cryptography.DSAParameters::Counter
	int32_t ___Counter_7;

public:
	inline static int32_t get_offset_of_P_0() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___P_0)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_P_0() const { return ___P_0; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_P_0() { return &___P_0; }
	inline void set_P_0(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___P_0 = value;
		Il2CppCodeGenWriteBarrier((&___P_0), value);
	}

	inline static int32_t get_offset_of_Q_1() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___Q_1)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Q_1() const { return ___Q_1; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Q_1() { return &___Q_1; }
	inline void set_Q_1(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Q_1 = value;
		Il2CppCodeGenWriteBarrier((&___Q_1), value);
	}

	inline static int32_t get_offset_of_G_2() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___G_2)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_G_2() const { return ___G_2; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_G_2() { return &___G_2; }
	inline void set_G_2(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___G_2 = value;
		Il2CppCodeGenWriteBarrier((&___G_2), value);
	}

	inline static int32_t get_offset_of_Y_3() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___Y_3)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Y_3() const { return ___Y_3; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Y_3() { return &___Y_3; }
	inline void set_Y_3(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Y_3 = value;
		Il2CppCodeGenWriteBarrier((&___Y_3), value);
	}

	inline static int32_t get_offset_of_J_4() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___J_4)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_J_4() const { return ___J_4; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_J_4() { return &___J_4; }
	inline void set_J_4(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___J_4 = value;
		Il2CppCodeGenWriteBarrier((&___J_4), value);
	}

	inline static int32_t get_offset_of_X_5() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___X_5)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_X_5() const { return ___X_5; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_X_5() { return &___X_5; }
	inline void set_X_5(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___X_5 = value;
		Il2CppCodeGenWriteBarrier((&___X_5), value);
	}

	inline static int32_t get_offset_of_Seed_6() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___Seed_6)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Seed_6() const { return ___Seed_6; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Seed_6() { return &___Seed_6; }
	inline void set_Seed_6(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Seed_6 = value;
		Il2CppCodeGenWriteBarrier((&___Seed_6), value);
	}

	inline static int32_t get_offset_of_Counter_7() { return static_cast<int32_t>(offsetof(DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6, ___Counter_7)); }
	inline int32_t get_Counter_7() const { return ___Counter_7; }
	inline int32_t* get_address_of_Counter_7() { return &___Counter_7; }
	inline void set_Counter_7(int32_t value)
	{
		___Counter_7 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // DSAPARAMETERS_TCA1A96A151F47B1904693C457243E3B919425AC6_H
#ifndef RSAPARAMETERS_T6A568C1275FA8F8C02615666D998134DCFFB9717_H
#define RSAPARAMETERS_T6A568C1275FA8F8C02615666D998134DCFFB9717_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Security.Cryptography.RSAParameters
struct  RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717 
{
public:
	// System.Byte[] System.Security.Cryptography.RSAParameters::Exponent
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Exponent_0;
	// System.Byte[] System.Security.Cryptography.RSAParameters::Modulus
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Modulus_1;
	// System.Byte[] System.Security.Cryptography.RSAParameters::P
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___P_2;
	// System.Byte[] System.Security.Cryptography.RSAParameters::Q
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___Q_3;
	// System.Byte[] System.Security.Cryptography.RSAParameters::DP
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___DP_4;
	// System.Byte[] System.Security.Cryptography.RSAParameters::DQ
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___DQ_5;
	// System.Byte[] System.Security.Cryptography.RSAParameters::InverseQ
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___InverseQ_6;
	// System.Byte[] System.Security.Cryptography.RSAParameters::D
	ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* ___D_7;

public:
	inline static int32_t get_offset_of_Exponent_0() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___Exponent_0)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Exponent_0() const { return ___Exponent_0; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Exponent_0() { return &___Exponent_0; }
	inline void set_Exponent_0(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Exponent_0 = value;
		Il2CppCodeGenWriteBarrier((&___Exponent_0), value);
	}

	inline static int32_t get_offset_of_Modulus_1() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___Modulus_1)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Modulus_1() const { return ___Modulus_1; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Modulus_1() { return &___Modulus_1; }
	inline void set_Modulus_1(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Modulus_1 = value;
		Il2CppCodeGenWriteBarrier((&___Modulus_1), value);
	}

	inline static int32_t get_offset_of_P_2() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___P_2)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_P_2() const { return ___P_2; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_P_2() { return &___P_2; }
	inline void set_P_2(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___P_2 = value;
		Il2CppCodeGenWriteBarrier((&___P_2), value);
	}

	inline static int32_t get_offset_of_Q_3() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___Q_3)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_Q_3() const { return ___Q_3; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_Q_3() { return &___Q_3; }
	inline void set_Q_3(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___Q_3 = value;
		Il2CppCodeGenWriteBarrier((&___Q_3), value);
	}

	inline static int32_t get_offset_of_DP_4() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___DP_4)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_DP_4() const { return ___DP_4; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_DP_4() { return &___DP_4; }
	inline void set_DP_4(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___DP_4 = value;
		Il2CppCodeGenWriteBarrier((&___DP_4), value);
	}

	inline static int32_t get_offset_of_DQ_5() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___DQ_5)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_DQ_5() const { return ___DQ_5; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_DQ_5() { return &___DQ_5; }
	inline void set_DQ_5(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___DQ_5 = value;
		Il2CppCodeGenWriteBarrier((&___DQ_5), value);
	}

	inline static int32_t get_offset_of_InverseQ_6() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___InverseQ_6)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_InverseQ_6() const { return ___InverseQ_6; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_InverseQ_6() { return &___InverseQ_6; }
	inline void set_InverseQ_6(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___InverseQ_6 = value;
		Il2CppCodeGenWriteBarrier((&___InverseQ_6), value);
	}

	inline static int32_t get_offset_of_D_7() { return static_cast<int32_t>(offsetof(RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717, ___D_7)); }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* get_D_7() const { return ___D_7; }
	inline ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821** get_address_of_D_7() { return &___D_7; }
	inline void set_D_7(ByteU5BU5D_tD06FDBE8142446525DF1C40351D523A228373821* value)
	{
		___D_7 = value;
		Il2CppCodeGenWriteBarrier((&___D_7), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RSAPARAMETERS_T6A568C1275FA8F8C02615666D998134DCFFB9717_H
#ifndef ASYNCLOCALVALUECHANGEDARGS_1_T64BF6800935406CA808E9821DF12DBB72A71640D_H
#define ASYNCLOCALVALUECHANGEDARGS_1_T64BF6800935406CA808E9821DF12DBB72A71640D_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Threading.AsyncLocalValueChangedArgs`1<System.Object>
struct  AsyncLocalValueChangedArgs_1_t64BF6800935406CA808E9821DF12DBB72A71640D 
{
public:
	// T System.Threading.AsyncLocalValueChangedArgs`1::<PreviousValue>k__BackingField
	RuntimeObject * ___U3CPreviousValueU3Ek__BackingField_0;
	// T System.Threading.AsyncLocalValueChangedArgs`1::<CurrentValue>k__BackingField
	RuntimeObject * ___U3CCurrentValueU3Ek__BackingField_1;
	// System.Boolean System.Threading.AsyncLocalValueChangedArgs`1::<ThreadContextChanged>k__BackingField
	bool ___U3CThreadContextChangedU3Ek__BackingField_2;

public:
	inline static int32_t get_offset_of_U3CPreviousValueU3Ek__BackingField_0() { return static_cast<int32_t>(offsetof(AsyncLocalValueChangedArgs_1_t64BF6800935406CA808E9821DF12DBB72A71640D, ___U3CPreviousValueU3Ek__BackingField_0)); }
	inline RuntimeObject * get_U3CPreviousValueU3Ek__BackingField_0() const { return ___U3CPreviousValueU3Ek__BackingField_0; }
	inline RuntimeObject ** get_address_of_U3CPreviousValueU3Ek__BackingField_0() { return &___U3CPreviousValueU3Ek__BackingField_0; }
	inline void set_U3CPreviousValueU3Ek__BackingField_0(RuntimeObject * value)
	{
		___U3CPreviousValueU3Ek__BackingField_0 = value;
		Il2CppCodeGenWriteBarrier((&___U3CPreviousValueU3Ek__BackingField_0), value);
	}

	inline static int32_t get_offset_of_U3CCurrentValueU3Ek__BackingField_1() { return static_cast<int32_t>(offsetof(AsyncLocalValueChangedArgs_1_t64BF6800935406CA808E9821DF12DBB72A71640D, ___U3CCurrentValueU3Ek__BackingField_1)); }
	inline RuntimeObject * get_U3CCurrentValueU3Ek__BackingField_1() const { return ___U3CCurrentValueU3Ek__BackingField_1; }
	inline RuntimeObject ** get_address_of_U3CCurrentValueU3Ek__BackingField_1() { return &___U3CCurrentValueU3Ek__BackingField_1; }
	inline void set_U3CCurrentValueU3Ek__BackingField_1(RuntimeObject * value)
	{
		___U3CCurrentValueU3Ek__BackingField_1 = value;
		Il2CppCodeGenWriteBarrier((&___U3CCurrentValueU3Ek__BackingField_1), value);
	}

	inline static int32_t get_offset_of_U3CThreadContextChangedU3Ek__BackingField_2() { return static_cast<int32_t>(offsetof(AsyncLocalValueChangedArgs_1_t64BF6800935406CA808E9821DF12DBB72A71640D, ___U3CThreadContextChangedU3Ek__BackingField_2)); }
	inline bool get_U3CThreadContextChangedU3Ek__BackingField_2() const { return ___U3CThreadContextChangedU3Ek__BackingField_2; }
	inline bool* get_address_of_U3CThreadContextChangedU3Ek__BackingField_2() { return &___U3CThreadContextChangedU3Ek__BackingField_2; }
	inline void set_U3CThreadContextChangedU3Ek__BackingField_2(bool value)
	{
		___U3CThreadContextChangedU3Ek__BackingField_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // ASYNCLOCALVALUECHANGEDARGS_1_T64BF6800935406CA808E9821DF12DBB72A71640D_H
#ifndef CANCELLATIONTOKEN_T9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_H
#define CANCELLATIONTOKEN_T9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Threading.CancellationToken
struct  CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB 
{
public:
	// System.Threading.CancellationTokenSource System.Threading.CancellationToken::m_source
	CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * ___m_source_0;

public:
	inline static int32_t get_offset_of_m_source_0() { return static_cast<int32_t>(offsetof(CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB, ___m_source_0)); }
	inline CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * get_m_source_0() const { return ___m_source_0; }
	inline CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE ** get_address_of_m_source_0() { return &___m_source_0; }
	inline void set_m_source_0(CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * value)
	{
		___m_source_0 = value;
		Il2CppCodeGenWriteBarrier((&___m_source_0), value);
	}
};

struct CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_StaticFields
{
public:
	// System.Action`1<System.Object> System.Threading.CancellationToken::s_ActionToActionObjShunt
	Action_1_t551A279CEADCF6EEAE8FA2B1E1E757D0D15290D0 * ___s_ActionToActionObjShunt_1;

public:
	inline static int32_t get_offset_of_s_ActionToActionObjShunt_1() { return static_cast<int32_t>(offsetof(CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_StaticFields, ___s_ActionToActionObjShunt_1)); }
	inline Action_1_t551A279CEADCF6EEAE8FA2B1E1E757D0D15290D0 * get_s_ActionToActionObjShunt_1() const { return ___s_ActionToActionObjShunt_1; }
	inline Action_1_t551A279CEADCF6EEAE8FA2B1E1E757D0D15290D0 ** get_address_of_s_ActionToActionObjShunt_1() { return &___s_ActionToActionObjShunt_1; }
	inline void set_s_ActionToActionObjShunt_1(Action_1_t551A279CEADCF6EEAE8FA2B1E1E757D0D15290D0 * value)
	{
		___s_ActionToActionObjShunt_1 = value;
		Il2CppCodeGenWriteBarrier((&___s_ActionToActionObjShunt_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Threading.CancellationToken
struct CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_marshaled_pinvoke
{
	CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * ___m_source_0;
};
// Native definition for COM marshalling of System.Threading.CancellationToken
struct CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_marshaled_com
{
	CancellationTokenSource_tF480B7E74A032667AFBD31F0530D619FB43AD3FE * ___m_source_0;
};
#endif // CANCELLATIONTOKEN_T9E956952F7F20908F2AE72EDF36D97E6C7DB63AB_H
#ifndef VOIDTASKRESULT_T66EBC10DDE738848DB00F6EC1A2536D7D4715F40_H
#define VOIDTASKRESULT_T66EBC10DDE738848DB00F6EC1A2536D7D4715F40_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Threading.Tasks.VoidTaskResult
struct  VoidTaskResult_t66EBC10DDE738848DB00F6EC1A2536D7D4715F40 
{
public:
	union
	{
		struct
		{
		};
		uint8_t VoidTaskResult_t66EBC10DDE738848DB00F6EC1A2536D7D4715F40__padding[1];
	};

public:
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // VOIDTASKRESULT_T66EBC10DDE738848DB00F6EC1A2536D7D4715F40_H
#ifndef VALUETUPLE_2_T446756A8057B54D18CAD5BA1D73699DA4B40A264_H
#define VALUETUPLE_2_T446756A8057B54D18CAD5BA1D73699DA4B40A264_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ValueTuple`2<System.Int32,System.Boolean>
struct  ValueTuple_2_t446756A8057B54D18CAD5BA1D73699DA4B40A264 
{
public:
	// T1 System.ValueTuple`2::Item1
	int32_t ___Item1_0;
	// T2 System.ValueTuple`2::Item2
	bool ___Item2_1;

public:
	inline static int32_t get_offset_of_Item1_0() { return static_cast<int32_t>(offsetof(ValueTuple_2_t446756A8057B54D18CAD5BA1D73699DA4B40A264, ___Item1_0)); }
	inline int32_t get_Item1_0() const { return ___Item1_0; }
	inline int32_t* get_address_of_Item1_0() { return &___Item1_0; }
	inline void set_Item1_0(int32_t value)
	{
		___Item1_0 = value;
	}

	inline static int32_t get_offset_of_Item2_1() { return static_cast<int32_t>(offsetof(ValueTuple_2_t446756A8057B54D18CAD5BA1D73699DA4B40A264, ___Item2_1)); }
	inline bool get_Item2_1() const { return ___Item2_1; }
	inline bool* get_address_of_Item2_1() { return &___Item2_1; }
	inline void set_Item2_1(bool value)
	{
		___Item2_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // VALUETUPLE_2_T446756A8057B54D18CAD5BA1D73699DA4B40A264_H
#ifndef ORDERBLOCK_T3B2BBCE8320FAEC3DB605F7DC9AB641102F53727_H
#define ORDERBLOCK_T3B2BBCE8320FAEC3DB605F7DC9AB641102F53727_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.BeforeRenderHelper_OrderBlock
struct  OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727 
{
public:
	// System.Int32 UnityEngine.BeforeRenderHelper_OrderBlock::order
	int32_t ___order_0;
	// UnityEngine.Events.UnityAction UnityEngine.BeforeRenderHelper_OrderBlock::callback
	UnityAction_tD19B26F1B2C048E38FD5801A33573BE01064CAF4 * ___callback_1;

public:
	inline static int32_t get_offset_of_order_0() { return static_cast<int32_t>(offsetof(OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727, ___order_0)); }
	inline int32_t get_order_0() const { return ___order_0; }
	inline int32_t* get_address_of_order_0() { return &___order_0; }
	inline void set_order_0(int32_t value)
	{
		___order_0 = value;
	}

	inline static int32_t get_offset_of_callback_1() { return static_cast<int32_t>(offsetof(OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727, ___callback_1)); }
	inline UnityAction_tD19B26F1B2C048E38FD5801A33573BE01064CAF4 * get_callback_1() const { return ___callback_1; }
	inline UnityAction_tD19B26F1B2C048E38FD5801A33573BE01064CAF4 ** get_address_of_callback_1() { return &___callback_1; }
	inline void set_callback_1(UnityAction_tD19B26F1B2C048E38FD5801A33573BE01064CAF4 * value)
	{
		___callback_1 = value;
		Il2CppCodeGenWriteBarrier((&___callback_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of UnityEngine.BeforeRenderHelper/OrderBlock
struct OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727_marshaled_pinvoke
{
	int32_t ___order_0;
	Il2CppMethodPointer ___callback_1;
};
// Native definition for COM marshalling of UnityEngine.BeforeRenderHelper/OrderBlock
struct OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727_marshaled_com
{
	int32_t ___order_0;
	Il2CppMethodPointer ___callback_1;
};
#endif // ORDERBLOCK_T3B2BBCE8320FAEC3DB605F7DC9AB641102F53727_H
#ifndef CULLINGGROUPEVENT_TC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85_H
#define CULLINGGROUPEVENT_TC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.CullingGroupEvent
struct  CullingGroupEvent_tC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85 
{
public:
	// System.Int32 UnityEngine.CullingGroupEvent::m_Index
	int32_t ___m_Index_0;
	// System.Byte UnityEngine.CullingGroupEvent::m_PrevState
	uint8_t ___m_PrevState_1;
	// System.Byte UnityEngine.CullingGroupEvent::m_ThisState
	uint8_t ___m_ThisState_2;

public:
	inline static int32_t get_offset_of_m_Index_0() { return static_cast<int32_t>(offsetof(CullingGroupEvent_tC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85, ___m_Index_0)); }
	inline int32_t get_m_Index_0() const { return ___m_Index_0; }
	inline int32_t* get_address_of_m_Index_0() { return &___m_Index_0; }
	inline void set_m_Index_0(int32_t value)
	{
		___m_Index_0 = value;
	}

	inline static int32_t get_offset_of_m_PrevState_1() { return static_cast<int32_t>(offsetof(CullingGroupEvent_tC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85, ___m_PrevState_1)); }
	inline uint8_t get_m_PrevState_1() const { return ___m_PrevState_1; }
	inline uint8_t* get_address_of_m_PrevState_1() { return &___m_PrevState_1; }
	inline void set_m_PrevState_1(uint8_t value)
	{
		___m_PrevState_1 = value;
	}

	inline static int32_t get_offset_of_m_ThisState_2() { return static_cast<int32_t>(offsetof(CullingGroupEvent_tC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85, ___m_ThisState_2)); }
	inline uint8_t get_m_ThisState_2() const { return ___m_ThisState_2; }
	inline uint8_t* get_address_of_m_ThisState_2() { return &___m_ThisState_2; }
	inline void set_m_ThisState_2(uint8_t value)
	{
		___m_ThisState_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // CULLINGGROUPEVENT_TC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85_H
#ifndef PROPERTYNAME_T75EB843FEA2EC372093479A35C24364D2DF98529_H
#define PROPERTYNAME_T75EB843FEA2EC372093479A35C24364D2DF98529_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.PropertyName
struct  PropertyName_t75EB843FEA2EC372093479A35C24364D2DF98529 
{
public:
	// System.Int32 UnityEngine.PropertyName::id
	int32_t ___id_0;

public:
	inline static int32_t get_offset_of_id_0() { return static_cast<int32_t>(offsetof(PropertyName_t75EB843FEA2EC372093479A35C24364D2DF98529, ___id_0)); }
	inline int32_t get_id_0() const { return ___id_0; }
	inline int32_t* get_address_of_id_0() { return &___id_0; }
	inline void set_id_0(int32_t value)
	{
		___id_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PROPERTYNAME_T75EB843FEA2EC372093479A35C24364D2DF98529_H
#ifndef SCENE_T942E023788C2BC9FBB7EC8356B4FB0088B2CFED2_H
#define SCENE_T942E023788C2BC9FBB7EC8356B4FB0088B2CFED2_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.SceneManagement.Scene
struct  Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2 
{
public:
	// System.Int32 UnityEngine.SceneManagement.Scene::m_Handle
	int32_t ___m_Handle_0;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2, ___m_Handle_0)); }
	inline int32_t get_m_Handle_0() const { return ___m_Handle_0; }
	inline int32_t* get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(int32_t value)
	{
		___m_Handle_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // SCENE_T942E023788C2BC9FBB7EC8356B4FB0088B2CFED2_H
#ifndef RANGE_T2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC_H
#define RANGE_T2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.SocialPlatforms.Range
struct  Range_t2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC 
{
public:
	// System.Int32 UnityEngine.SocialPlatforms.Range::from
	int32_t ___from_0;
	// System.Int32 UnityEngine.SocialPlatforms.Range::count
	int32_t ___count_1;

public:
	inline static int32_t get_offset_of_from_0() { return static_cast<int32_t>(offsetof(Range_t2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC, ___from_0)); }
	inline int32_t get_from_0() const { return ___from_0; }
	inline int32_t* get_address_of_from_0() { return &___from_0; }
	inline void set_from_0(int32_t value)
	{
		___from_0 = value;
	}

	inline static int32_t get_offset_of_count_1() { return static_cast<int32_t>(offsetof(Range_t2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC, ___count_1)); }
	inline int32_t get_count_1() const { return ___count_1; }
	inline int32_t* get_address_of_count_1() { return &___count_1; }
	inline void set_count_1(int32_t value)
	{
		___count_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RANGE_T2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC_H
#ifndef WORKREQUEST_T0247B62D135204EAA95FC0B2EC829CB27B433F94_H
#define WORKREQUEST_T0247B62D135204EAA95FC0B2EC829CB27B433F94_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.UnitySynchronizationContext_WorkRequest
struct  WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94 
{
public:
	// System.Threading.SendOrPostCallback UnityEngine.UnitySynchronizationContext_WorkRequest::m_DelagateCallback
	SendOrPostCallback_t3F9C0164860E4AA5138DF8B4488DFB0D33147F01 * ___m_DelagateCallback_0;
	// System.Object UnityEngine.UnitySynchronizationContext_WorkRequest::m_DelagateState
	RuntimeObject * ___m_DelagateState_1;
	// System.Threading.ManualResetEvent UnityEngine.UnitySynchronizationContext_WorkRequest::m_WaitHandle
	ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 * ___m_WaitHandle_2;

public:
	inline static int32_t get_offset_of_m_DelagateCallback_0() { return static_cast<int32_t>(offsetof(WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94, ___m_DelagateCallback_0)); }
	inline SendOrPostCallback_t3F9C0164860E4AA5138DF8B4488DFB0D33147F01 * get_m_DelagateCallback_0() const { return ___m_DelagateCallback_0; }
	inline SendOrPostCallback_t3F9C0164860E4AA5138DF8B4488DFB0D33147F01 ** get_address_of_m_DelagateCallback_0() { return &___m_DelagateCallback_0; }
	inline void set_m_DelagateCallback_0(SendOrPostCallback_t3F9C0164860E4AA5138DF8B4488DFB0D33147F01 * value)
	{
		___m_DelagateCallback_0 = value;
		Il2CppCodeGenWriteBarrier((&___m_DelagateCallback_0), value);
	}

	inline static int32_t get_offset_of_m_DelagateState_1() { return static_cast<int32_t>(offsetof(WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94, ___m_DelagateState_1)); }
	inline RuntimeObject * get_m_DelagateState_1() const { return ___m_DelagateState_1; }
	inline RuntimeObject ** get_address_of_m_DelagateState_1() { return &___m_DelagateState_1; }
	inline void set_m_DelagateState_1(RuntimeObject * value)
	{
		___m_DelagateState_1 = value;
		Il2CppCodeGenWriteBarrier((&___m_DelagateState_1), value);
	}

	inline static int32_t get_offset_of_m_WaitHandle_2() { return static_cast<int32_t>(offsetof(WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94, ___m_WaitHandle_2)); }
	inline ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 * get_m_WaitHandle_2() const { return ___m_WaitHandle_2; }
	inline ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 ** get_address_of_m_WaitHandle_2() { return &___m_WaitHandle_2; }
	inline void set_m_WaitHandle_2(ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 * value)
	{
		___m_WaitHandle_2 = value;
		Il2CppCodeGenWriteBarrier((&___m_WaitHandle_2), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of UnityEngine.UnitySynchronizationContext/WorkRequest
struct WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94_marshaled_pinvoke
{
	Il2CppMethodPointer ___m_DelagateCallback_0;
	Il2CppIUnknown* ___m_DelagateState_1;
	ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 * ___m_WaitHandle_2;
};
// Native definition for COM marshalling of UnityEngine.UnitySynchronizationContext/WorkRequest
struct WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94_marshaled_com
{
	Il2CppMethodPointer ___m_DelagateCallback_0;
	Il2CppIUnknown* ___m_DelagateState_1;
	ManualResetEvent_tDFAF117B200ECA4CCF4FD09593F949A016D55408 * ___m_WaitHandle_2;
};
#endif // WORKREQUEST_T0247B62D135204EAA95FC0B2EC829CB27B433F94_H
#ifndef UNITYTLS_ERROR_CODE_TA9272A71D51F7FE555C03185AE244FB01EAF998F_H
#define UNITYTLS_ERROR_CODE_TA9272A71D51F7FE555C03185AE244FB01EAF998F_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_error_code
struct  unitytls_error_code_tA9272A71D51F7FE555C03185AE244FB01EAF998F 
{
public:
	// System.UInt32 Mono.Unity.UnityTls_unitytls_error_code::value__
	uint32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(unitytls_error_code_tA9272A71D51F7FE555C03185AE244FB01EAF998F, ___value___2)); }
	inline uint32_t get_value___2() const { return ___value___2; }
	inline uint32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(uint32_t value)
	{
		___value___2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_ERROR_CODE_TA9272A71D51F7FE555C03185AE244FB01EAF998F_H
#ifndef UNITYTLS_PROTOCOL_T4E7BF0D3D575EDD09EA7BF6593AAB40BBAC60DF8_H
#define UNITYTLS_PROTOCOL_T4E7BF0D3D575EDD09EA7BF6593AAB40BBAC60DF8_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_protocol
struct  unitytls_protocol_t4E7BF0D3D575EDD09EA7BF6593AAB40BBAC60DF8 
{
public:
	// System.UInt32 Mono.Unity.UnityTls_unitytls_protocol::value__
	uint32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(unitytls_protocol_t4E7BF0D3D575EDD09EA7BF6593AAB40BBAC60DF8, ___value___2)); }
	inline uint32_t get_value___2() const { return ___value___2; }
	inline uint32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(uint32_t value)
	{
		___value___2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_PROTOCOL_T4E7BF0D3D575EDD09EA7BF6593AAB40BBAC60DF8_H
#ifndef KEYVALUEPAIR_2_T5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B_H
#define KEYVALUEPAIR_2_T5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Collections.Generic.KeyValuePair`2<System.DateTime,System.Object>
struct  KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B 
{
public:
	// TKey System.Collections.Generic.KeyValuePair`2::key
	DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  ___key_0;
	// TValue System.Collections.Generic.KeyValuePair`2::value
	RuntimeObject * ___value_1;

public:
	inline static int32_t get_offset_of_key_0() { return static_cast<int32_t>(offsetof(KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B, ___key_0)); }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  get_key_0() const { return ___key_0; }
	inline DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132 * get_address_of_key_0() { return &___key_0; }
	inline void set_key_0(DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  value)
	{
		___key_0 = value;
	}

	inline static int32_t get_offset_of_value_1() { return static_cast<int32_t>(offsetof(KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B, ___value_1)); }
	inline RuntimeObject * get_value_1() const { return ___value_1; }
	inline RuntimeObject ** get_address_of_value_1() { return &___value_1; }
	inline void set_value_1(RuntimeObject * value)
	{
		___value_1 = value;
		Il2CppCodeGenWriteBarrier((&___value_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // KEYVALUEPAIR_2_T5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B_H
#ifndef CONSOLEKEY_T0196714F06D59B40580F7B85EA2663D81394682C_H
#define CONSOLEKEY_T0196714F06D59B40580F7B85EA2663D81394682C_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ConsoleKey
struct  ConsoleKey_t0196714F06D59B40580F7B85EA2663D81394682C 
{
public:
	// System.Int32 System.ConsoleKey::value__
	int32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(ConsoleKey_t0196714F06D59B40580F7B85EA2663D81394682C, ___value___2)); }
	inline int32_t get_value___2() const { return ___value___2; }
	inline int32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(int32_t value)
	{
		___value___2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // CONSOLEKEY_T0196714F06D59B40580F7B85EA2663D81394682C_H
#ifndef CONSOLEMODIFIERS_TCB55098B71E4DCCEE972B1056E64D1B8AB9EAB34_H
#define CONSOLEMODIFIERS_TCB55098B71E4DCCEE972B1056E64D1B8AB9EAB34_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ConsoleModifiers
struct  ConsoleModifiers_tCB55098B71E4DCCEE972B1056E64D1B8AB9EAB34 
{
public:
	// System.Int32 System.ConsoleModifiers::value__
	int32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(ConsoleModifiers_tCB55098B71E4DCCEE972B1056E64D1B8AB9EAB34, ___value___2)); }
	inline int32_t get_value___2() const { return ___value___2; }
	inline int32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(int32_t value)
	{
		___value___2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // CONSOLEMODIFIERS_TCB55098B71E4DCCEE972B1056E64D1B8AB9EAB34_H
#ifndef CUSTOMATTRIBUTENAMEDARGUMENT_T08BA731A94FD7F173551DF3098384CB9B3056E9E_H
#define CUSTOMATTRIBUTENAMEDARGUMENT_T08BA731A94FD7F173551DF3098384CB9B3056E9E_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Reflection.CustomAttributeNamedArgument
struct  CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E 
{
public:
	// System.Reflection.CustomAttributeTypedArgument System.Reflection.CustomAttributeNamedArgument::typedArgument
	CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  ___typedArgument_0;
	// System.Reflection.MemberInfo System.Reflection.CustomAttributeNamedArgument::memberInfo
	MemberInfo_t * ___memberInfo_1;

public:
	inline static int32_t get_offset_of_typedArgument_0() { return static_cast<int32_t>(offsetof(CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E, ___typedArgument_0)); }
	inline CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  get_typedArgument_0() const { return ___typedArgument_0; }
	inline CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8 * get_address_of_typedArgument_0() { return &___typedArgument_0; }
	inline void set_typedArgument_0(CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  value)
	{
		___typedArgument_0 = value;
	}

	inline static int32_t get_offset_of_memberInfo_1() { return static_cast<int32_t>(offsetof(CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E, ___memberInfo_1)); }
	inline MemberInfo_t * get_memberInfo_1() const { return ___memberInfo_1; }
	inline MemberInfo_t ** get_address_of_memberInfo_1() { return &___memberInfo_1; }
	inline void set_memberInfo_1(MemberInfo_t * value)
	{
		___memberInfo_1 = value;
		Il2CppCodeGenWriteBarrier((&___memberInfo_1), value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Reflection.CustomAttributeNamedArgument
struct CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E_marshaled_pinvoke
{
	CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8_marshaled_pinvoke ___typedArgument_0;
	MemberInfo_t * ___memberInfo_1;
};
// Native definition for COM marshalling of System.Reflection.CustomAttributeNamedArgument
struct CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E_marshaled_com
{
	CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8_marshaled_com ___typedArgument_0;
	MemberInfo_t * ___memberInfo_1;
};
#endif // CUSTOMATTRIBUTENAMEDARGUMENT_T08BA731A94FD7F173551DF3098384CB9B3056E9E_H
#ifndef STREAMINGCONTEXTSTATES_T6D16CD7BC584A66A29B702F5FD59DF62BB1BDD3F_H
#define STREAMINGCONTEXTSTATES_T6D16CD7BC584A66A29B702F5FD59DF62BB1BDD3F_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Runtime.Serialization.StreamingContextStates
struct  StreamingContextStates_t6D16CD7BC584A66A29B702F5FD59DF62BB1BDD3F 
{
public:
	// System.Int32 System.Runtime.Serialization.StreamingContextStates::value__
	int32_t ___value___2;

public:
	inline static int32_t get_offset_of_value___2() { return static_cast<int32_t>(offsetof(StreamingContextStates_t6D16CD7BC584A66A29B702F5FD59DF62BB1BDD3F, ___value___2)); }
	inline int32_t get_value___2() const { return ___value___2; }
	inline int32_t* get_address_of_value___2() { return &___value___2; }
	inline void set_value___2(int32_t value)
	{
		___value___2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // STREAMINGCONTEXTSTATES_T6D16CD7BC584A66A29B702F5FD59DF62BB1BDD3F_H
#ifndef RUNTIMEFIELDHANDLE_T844BDF00E8E6FE69D9AEAA7657F09018B864F4EF_H
#define RUNTIMEFIELDHANDLE_T844BDF00E8E6FE69D9AEAA7657F09018B864F4EF_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.RuntimeFieldHandle
struct  RuntimeFieldHandle_t844BDF00E8E6FE69D9AEAA7657F09018B864F4EF 
{
public:
	// System.IntPtr System.RuntimeFieldHandle::value
	intptr_t ___value_0;

public:
	inline static int32_t get_offset_of_value_0() { return static_cast<int32_t>(offsetof(RuntimeFieldHandle_t844BDF00E8E6FE69D9AEAA7657F09018B864F4EF, ___value_0)); }
	inline intptr_t get_value_0() const { return ___value_0; }
	inline intptr_t* get_address_of_value_0() { return &___value_0; }
	inline void set_value_0(intptr_t value)
	{
		___value_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RUNTIMEFIELDHANDLE_T844BDF00E8E6FE69D9AEAA7657F09018B864F4EF_H
#ifndef RUNTIMEMETHODHANDLE_T85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F_H
#define RUNTIMEMETHODHANDLE_T85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.RuntimeMethodHandle
struct  RuntimeMethodHandle_t85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F 
{
public:
	// System.IntPtr System.RuntimeMethodHandle::value
	intptr_t ___value_0;

public:
	inline static int32_t get_offset_of_value_0() { return static_cast<int32_t>(offsetof(RuntimeMethodHandle_t85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F, ___value_0)); }
	inline intptr_t get_value_0() const { return ___value_0; }
	inline intptr_t* get_address_of_value_0() { return &___value_0; }
	inline void set_value_0(intptr_t value)
	{
		___value_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RUNTIMEMETHODHANDLE_T85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F_H
#ifndef RUNTIMETYPEHANDLE_T7B542280A22F0EC4EAC2061C29178845847A8B2D_H
#define RUNTIMETYPEHANDLE_T7B542280A22F0EC4EAC2061C29178845847A8B2D_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.RuntimeTypeHandle
struct  RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D 
{
public:
	// System.IntPtr System.RuntimeTypeHandle::value
	intptr_t ___value_0;

public:
	inline static int32_t get_offset_of_value_0() { return static_cast<int32_t>(offsetof(RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D, ___value_0)); }
	inline intptr_t get_value_0() const { return ___value_0; }
	inline intptr_t* get_address_of_value_0() { return &___value_0; }
	inline void set_value_0(intptr_t value)
	{
		___value_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // RUNTIMETYPEHANDLE_T7B542280A22F0EC4EAC2061C29178845847A8B2D_H
#ifndef TIMESPAN_TA8069278ACE8A74D6DF7D514A9CD4432433F64C4_H
#define TIMESPAN_TA8069278ACE8A74D6DF7D514A9CD4432433F64C4_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.TimeSpan
struct  TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4 
{
public:
	// System.Int64 System.TimeSpan::_ticks
	int64_t ____ticks_3;

public:
	inline static int32_t get_offset_of__ticks_3() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4, ____ticks_3)); }
	inline int64_t get__ticks_3() const { return ____ticks_3; }
	inline int64_t* get_address_of__ticks_3() { return &____ticks_3; }
	inline void set__ticks_3(int64_t value)
	{
		____ticks_3 = value;
	}
};

struct TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields
{
public:
	// System.TimeSpan System.TimeSpan::Zero
	TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  ___Zero_0;
	// System.TimeSpan System.TimeSpan::MaxValue
	TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  ___MaxValue_1;
	// System.TimeSpan System.TimeSpan::MinValue
	TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  ___MinValue_2;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.TimeSpan::_legacyConfigChecked
	bool ____legacyConfigChecked_4;
	// System.Boolean modreq(System.Runtime.CompilerServices.IsVolatile) System.TimeSpan::_legacyMode
	bool ____legacyMode_5;

public:
	inline static int32_t get_offset_of_Zero_0() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields, ___Zero_0)); }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  get_Zero_0() const { return ___Zero_0; }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4 * get_address_of_Zero_0() { return &___Zero_0; }
	inline void set_Zero_0(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  value)
	{
		___Zero_0 = value;
	}

	inline static int32_t get_offset_of_MaxValue_1() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields, ___MaxValue_1)); }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  get_MaxValue_1() const { return ___MaxValue_1; }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4 * get_address_of_MaxValue_1() { return &___MaxValue_1; }
	inline void set_MaxValue_1(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  value)
	{
		___MaxValue_1 = value;
	}

	inline static int32_t get_offset_of_MinValue_2() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields, ___MinValue_2)); }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  get_MinValue_2() const { return ___MinValue_2; }
	inline TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4 * get_address_of_MinValue_2() { return &___MinValue_2; }
	inline void set_MinValue_2(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  value)
	{
		___MinValue_2 = value;
	}

	inline static int32_t get_offset_of__legacyConfigChecked_4() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields, ____legacyConfigChecked_4)); }
	inline bool get__legacyConfigChecked_4() const { return ____legacyConfigChecked_4; }
	inline bool* get_address_of__legacyConfigChecked_4() { return &____legacyConfigChecked_4; }
	inline void set__legacyConfigChecked_4(bool value)
	{
		____legacyConfigChecked_4 = value;
	}

	inline static int32_t get_offset_of__legacyMode_5() { return static_cast<int32_t>(offsetof(TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4_StaticFields, ____legacyMode_5)); }
	inline bool get__legacyMode_5() const { return ____legacyMode_5; }
	inline bool* get_address_of__legacyMode_5() { return &____legacyMode_5; }
	inline void set__legacyMode_5(bool value)
	{
		____legacyMode_5 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // TIMESPAN_TA8069278ACE8A74D6DF7D514A9CD4432433F64C4_H
#ifndef SCRIPTABLERENDERCONTEXT_TEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D_H
#define SCRIPTABLERENDERCONTEXT_TEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Experimental.Rendering.ScriptableRenderContext
struct  ScriptableRenderContext_tEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D 
{
public:
	// System.IntPtr UnityEngine.Experimental.Rendering.ScriptableRenderContext::m_Ptr
	intptr_t ___m_Ptr_0;

public:
	inline static int32_t get_offset_of_m_Ptr_0() { return static_cast<int32_t>(offsetof(ScriptableRenderContext_tEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D, ___m_Ptr_0)); }
	inline intptr_t get_m_Ptr_0() const { return ___m_Ptr_0; }
	inline intptr_t* get_address_of_m_Ptr_0() { return &___m_Ptr_0; }
	inline void set_m_Ptr_0(intptr_t value)
	{
		___m_Ptr_0 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // SCRIPTABLERENDERCONTEXT_TEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D_H
#ifndef PLAYABLEGRAPH_TEC38BBCA59BDD496F75037F220984D41339AB8BA_H
#define PLAYABLEGRAPH_TEC38BBCA59BDD496F75037F220984D41339AB8BA_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Playables.PlayableGraph
struct  PlayableGraph_tEC38BBCA59BDD496F75037F220984D41339AB8BA 
{
public:
	// System.IntPtr UnityEngine.Playables.PlayableGraph::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableGraph::m_Version
	uint32_t ___m_Version_1;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(PlayableGraph_tEC38BBCA59BDD496F75037F220984D41339AB8BA, ___m_Handle_0)); }
	inline intptr_t get_m_Handle_0() const { return ___m_Handle_0; }
	inline intptr_t* get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(intptr_t value)
	{
		___m_Handle_0 = value;
	}

	inline static int32_t get_offset_of_m_Version_1() { return static_cast<int32_t>(offsetof(PlayableGraph_tEC38BBCA59BDD496F75037F220984D41339AB8BA, ___m_Version_1)); }
	inline uint32_t get_m_Version_1() const { return ___m_Version_1; }
	inline uint32_t* get_address_of_m_Version_1() { return &___m_Version_1; }
	inline void set_m_Version_1(uint32_t value)
	{
		___m_Version_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PLAYABLEGRAPH_TEC38BBCA59BDD496F75037F220984D41339AB8BA_H
#ifndef PLAYABLEHANDLE_T9D3B4E540D4413CED81DDD6A24C5373BEFA1D182_H
#define PLAYABLEHANDLE_T9D3B4E540D4413CED81DDD6A24C5373BEFA1D182_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Playables.PlayableHandle
struct  PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182 
{
public:
	// System.IntPtr UnityEngine.Playables.PlayableHandle::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableHandle::m_Version
	uint32_t ___m_Version_1;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182, ___m_Handle_0)); }
	inline intptr_t get_m_Handle_0() const { return ___m_Handle_0; }
	inline intptr_t* get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(intptr_t value)
	{
		___m_Handle_0 = value;
	}

	inline static int32_t get_offset_of_m_Version_1() { return static_cast<int32_t>(offsetof(PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182, ___m_Version_1)); }
	inline uint32_t get_m_Version_1() const { return ___m_Version_1; }
	inline uint32_t* get_address_of_m_Version_1() { return &___m_Version_1; }
	inline void set_m_Version_1(uint32_t value)
	{
		___m_Version_1 = value;
	}
};

struct PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182_StaticFields
{
public:
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.PlayableHandle::m_Null
	PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  ___m_Null_2;

public:
	inline static int32_t get_offset_of_m_Null_2() { return static_cast<int32_t>(offsetof(PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182_StaticFields, ___m_Null_2)); }
	inline PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  get_m_Null_2() const { return ___m_Null_2; }
	inline PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182 * get_address_of_m_Null_2() { return &___m_Null_2; }
	inline void set_m_Null_2(PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  value)
	{
		___m_Null_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PLAYABLEHANDLE_T9D3B4E540D4413CED81DDD6A24C5373BEFA1D182_H
#ifndef PLAYABLEOUTPUTHANDLE_T0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922_H
#define PLAYABLEOUTPUTHANDLE_T0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Playables.PlayableOutputHandle
struct  PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922 
{
public:
	// System.IntPtr UnityEngine.Playables.PlayableOutputHandle::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableOutputHandle::m_Version
	uint32_t ___m_Version_1;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922, ___m_Handle_0)); }
	inline intptr_t get_m_Handle_0() const { return ___m_Handle_0; }
	inline intptr_t* get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(intptr_t value)
	{
		___m_Handle_0 = value;
	}

	inline static int32_t get_offset_of_m_Version_1() { return static_cast<int32_t>(offsetof(PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922, ___m_Version_1)); }
	inline uint32_t get_m_Version_1() const { return ___m_Version_1; }
	inline uint32_t* get_address_of_m_Version_1() { return &___m_Version_1; }
	inline void set_m_Version_1(uint32_t value)
	{
		___m_Version_1 = value;
	}
};

struct PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922_StaticFields
{
public:
	// UnityEngine.Playables.PlayableOutputHandle UnityEngine.Playables.PlayableOutputHandle::m_Null
	PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  ___m_Null_2;

public:
	inline static int32_t get_offset_of_m_Null_2() { return static_cast<int32_t>(offsetof(PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922_StaticFields, ___m_Null_2)); }
	inline PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  get_m_Null_2() const { return ___m_Null_2; }
	inline PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922 * get_address_of_m_Null_2() { return &___m_Null_2; }
	inline void set_m_Null_2(PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  value)
	{
		___m_Null_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PLAYABLEOUTPUTHANDLE_T0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922_H
#ifndef UNITYTLS_ERRORSTATE_T64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6_H
#define UNITYTLS_ERRORSTATE_T64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_errorstate
struct  unitytls_errorstate_t64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6 
{
public:
	// System.UInt32 Mono.Unity.UnityTls_unitytls_errorstate::magic
	uint32_t ___magic_0;
	// Mono.Unity.UnityTls_unitytls_error_code Mono.Unity.UnityTls_unitytls_errorstate::code
	uint32_t ___code_1;
	// System.UInt64 Mono.Unity.UnityTls_unitytls_errorstate::reserved
	uint64_t ___reserved_2;

public:
	inline static int32_t get_offset_of_magic_0() { return static_cast<int32_t>(offsetof(unitytls_errorstate_t64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6, ___magic_0)); }
	inline uint32_t get_magic_0() const { return ___magic_0; }
	inline uint32_t* get_address_of_magic_0() { return &___magic_0; }
	inline void set_magic_0(uint32_t value)
	{
		___magic_0 = value;
	}

	inline static int32_t get_offset_of_code_1() { return static_cast<int32_t>(offsetof(unitytls_errorstate_t64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6, ___code_1)); }
	inline uint32_t get_code_1() const { return ___code_1; }
	inline uint32_t* get_address_of_code_1() { return &___code_1; }
	inline void set_code_1(uint32_t value)
	{
		___code_1 = value;
	}

	inline static int32_t get_offset_of_reserved_2() { return static_cast<int32_t>(offsetof(unitytls_errorstate_t64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6, ___reserved_2)); }
	inline uint64_t get_reserved_2() const { return ___reserved_2; }
	inline uint64_t* get_address_of_reserved_2() { return &___reserved_2; }
	inline void set_reserved_2(uint64_t value)
	{
		___reserved_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_ERRORSTATE_T64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6_H
#ifndef UNITYTLS_TLSCTX_PROTOCOLRANGE_T36243D72F83DAD47C95928314F58026DE8D38F47_H
#define UNITYTLS_TLSCTX_PROTOCOLRANGE_T36243D72F83DAD47C95928314F58026DE8D38F47_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Mono.Unity.UnityTls_unitytls_tlsctx_protocolrange
struct  unitytls_tlsctx_protocolrange_t36243D72F83DAD47C95928314F58026DE8D38F47 
{
public:
	// Mono.Unity.UnityTls_unitytls_protocol Mono.Unity.UnityTls_unitytls_tlsctx_protocolrange::min
	uint32_t ___min_0;
	// Mono.Unity.UnityTls_unitytls_protocol Mono.Unity.UnityTls_unitytls_tlsctx_protocolrange::max
	uint32_t ___max_1;

public:
	inline static int32_t get_offset_of_min_0() { return static_cast<int32_t>(offsetof(unitytls_tlsctx_protocolrange_t36243D72F83DAD47C95928314F58026DE8D38F47, ___min_0)); }
	inline uint32_t get_min_0() const { return ___min_0; }
	inline uint32_t* get_address_of_min_0() { return &___min_0; }
	inline void set_min_0(uint32_t value)
	{
		___min_0 = value;
	}

	inline static int32_t get_offset_of_max_1() { return static_cast<int32_t>(offsetof(unitytls_tlsctx_protocolrange_t36243D72F83DAD47C95928314F58026DE8D38F47, ___max_1)); }
	inline uint32_t get_max_1() const { return ___max_1; }
	inline uint32_t* get_address_of_max_1() { return &___max_1; }
	inline void set_max_1(uint32_t value)
	{
		___max_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // UNITYTLS_TLSCTX_PROTOCOLRANGE_T36243D72F83DAD47C95928314F58026DE8D38F47_H
#ifndef CONSOLEKEYINFO_T5BE3CE05E8258CDB5404256E96AF7C22BC5DE768_H
#define CONSOLEKEYINFO_T5BE3CE05E8258CDB5404256E96AF7C22BC5DE768_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.ConsoleKeyInfo
struct  ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768 
{
public:
	// System.Char System.ConsoleKeyInfo::_keyChar
	Il2CppChar ____keyChar_0;
	// System.ConsoleKey System.ConsoleKeyInfo::_key
	int32_t ____key_1;
	// System.ConsoleModifiers System.ConsoleKeyInfo::_mods
	int32_t ____mods_2;

public:
	inline static int32_t get_offset_of__keyChar_0() { return static_cast<int32_t>(offsetof(ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768, ____keyChar_0)); }
	inline Il2CppChar get__keyChar_0() const { return ____keyChar_0; }
	inline Il2CppChar* get_address_of__keyChar_0() { return &____keyChar_0; }
	inline void set__keyChar_0(Il2CppChar value)
	{
		____keyChar_0 = value;
	}

	inline static int32_t get_offset_of__key_1() { return static_cast<int32_t>(offsetof(ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768, ____key_1)); }
	inline int32_t get__key_1() const { return ____key_1; }
	inline int32_t* get_address_of__key_1() { return &____key_1; }
	inline void set__key_1(int32_t value)
	{
		____key_1 = value;
	}

	inline static int32_t get_offset_of__mods_2() { return static_cast<int32_t>(offsetof(ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768, ____mods_2)); }
	inline int32_t get__mods_2() const { return ____mods_2; }
	inline int32_t* get_address_of__mods_2() { return &____mods_2; }
	inline void set__mods_2(int32_t value)
	{
		____mods_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.ConsoleKeyInfo
struct ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768_marshaled_pinvoke
{
	uint8_t ____keyChar_0;
	int32_t ____key_1;
	int32_t ____mods_2;
};
// Native definition for COM marshalling of System.ConsoleKeyInfo
struct ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768_marshaled_com
{
	uint8_t ____keyChar_0;
	int32_t ____key_1;
	int32_t ____mods_2;
};
#endif // CONSOLEKEYINFO_T5BE3CE05E8258CDB5404256E96AF7C22BC5DE768_H
#ifndef STREAMINGCONTEXT_T2CCDC54E0E8D078AF4A50E3A8B921B828A900034_H
#define STREAMINGCONTEXT_T2CCDC54E0E8D078AF4A50E3A8B921B828A900034_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.Runtime.Serialization.StreamingContext
struct  StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034 
{
public:
	// System.Object System.Runtime.Serialization.StreamingContext::m_additionalContext
	RuntimeObject * ___m_additionalContext_0;
	// System.Runtime.Serialization.StreamingContextStates System.Runtime.Serialization.StreamingContext::m_state
	int32_t ___m_state_1;

public:
	inline static int32_t get_offset_of_m_additionalContext_0() { return static_cast<int32_t>(offsetof(StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034, ___m_additionalContext_0)); }
	inline RuntimeObject * get_m_additionalContext_0() const { return ___m_additionalContext_0; }
	inline RuntimeObject ** get_address_of_m_additionalContext_0() { return &___m_additionalContext_0; }
	inline void set_m_additionalContext_0(RuntimeObject * value)
	{
		___m_additionalContext_0 = value;
		Il2CppCodeGenWriteBarrier((&___m_additionalContext_0), value);
	}

	inline static int32_t get_offset_of_m_state_1() { return static_cast<int32_t>(offsetof(StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034, ___m_state_1)); }
	inline int32_t get_m_state_1() const { return ___m_state_1; }
	inline int32_t* get_address_of_m_state_1() { return &___m_state_1; }
	inline void set_m_state_1(int32_t value)
	{
		___m_state_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Native definition for P/Invoke marshalling of System.Runtime.Serialization.StreamingContext
struct StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034_marshaled_pinvoke
{
	Il2CppIUnknown* ___m_additionalContext_0;
	int32_t ___m_state_1;
};
// Native definition for COM marshalling of System.Runtime.Serialization.StreamingContext
struct StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034_marshaled_com
{
	Il2CppIUnknown* ___m_additionalContext_0;
	int32_t ___m_state_1;
};
#endif // STREAMINGCONTEXT_T2CCDC54E0E8D078AF4A50E3A8B921B828A900034_H
#ifndef TYPEDREFERENCE_T118BC3B643F75F52DB9C99D5E051299F886EB2A8_H
#define TYPEDREFERENCE_T118BC3B643F75F52DB9C99D5E051299F886EB2A8_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// System.TypedReference
struct  TypedReference_t118BC3B643F75F52DB9C99D5E051299F886EB2A8 
{
public:
	// System.RuntimeTypeHandle System.TypedReference::type
	RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D  ___type_0;
	// System.IntPtr System.TypedReference::Value
	intptr_t ___Value_1;
	// System.IntPtr System.TypedReference::Type
	intptr_t ___Type_2;

public:
	inline static int32_t get_offset_of_type_0() { return static_cast<int32_t>(offsetof(TypedReference_t118BC3B643F75F52DB9C99D5E051299F886EB2A8, ___type_0)); }
	inline RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D  get_type_0() const { return ___type_0; }
	inline RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D * get_address_of_type_0() { return &___type_0; }
	inline void set_type_0(RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D  value)
	{
		___type_0 = value;
	}

	inline static int32_t get_offset_of_Value_1() { return static_cast<int32_t>(offsetof(TypedReference_t118BC3B643F75F52DB9C99D5E051299F886EB2A8, ___Value_1)); }
	inline intptr_t get_Value_1() const { return ___Value_1; }
	inline intptr_t* get_address_of_Value_1() { return &___Value_1; }
	inline void set_Value_1(intptr_t value)
	{
		___Value_1 = value;
	}

	inline static int32_t get_offset_of_Type_2() { return static_cast<int32_t>(offsetof(TypedReference_t118BC3B643F75F52DB9C99D5E051299F886EB2A8, ___Type_2)); }
	inline intptr_t get_Type_2() const { return ___Type_2; }
	inline intptr_t* get_address_of_Type_2() { return &___Type_2; }
	inline void set_Type_2(intptr_t value)
	{
		___Type_2 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // TYPEDREFERENCE_T118BC3B643F75F52DB9C99D5E051299F886EB2A8_H
#ifndef PLAYABLE_T4ABB910C374FCAB6B926DA4D34A85857A59950D0_H
#define PLAYABLE_T4ABB910C374FCAB6B926DA4D34A85857A59950D0_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Playables.Playable
struct  Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0 
{
public:
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.Playable::m_Handle
	PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  ___m_Handle_0;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0, ___m_Handle_0)); }
	inline PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  get_m_Handle_0() const { return ___m_Handle_0; }
	inline PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182 * get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(PlayableHandle_t9D3B4E540D4413CED81DDD6A24C5373BEFA1D182  value)
	{
		___m_Handle_0 = value;
	}
};

struct Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0_StaticFields
{
public:
	// UnityEngine.Playables.Playable UnityEngine.Playables.Playable::m_NullPlayable
	Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0  ___m_NullPlayable_1;

public:
	inline static int32_t get_offset_of_m_NullPlayable_1() { return static_cast<int32_t>(offsetof(Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0_StaticFields, ___m_NullPlayable_1)); }
	inline Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0  get_m_NullPlayable_1() const { return ___m_NullPlayable_1; }
	inline Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0 * get_address_of_m_NullPlayable_1() { return &___m_NullPlayable_1; }
	inline void set_m_NullPlayable_1(Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0  value)
	{
		___m_NullPlayable_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PLAYABLE_T4ABB910C374FCAB6B926DA4D34A85857A59950D0_H
#ifndef PLAYABLEOUTPUT_T5E024C3D28C983782CD4FDB2FA5AD23998D21345_H
#define PLAYABLEOUTPUT_T5E024C3D28C983782CD4FDB2FA5AD23998D21345_H
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// UnityEngine.Playables.PlayableOutput
struct  PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345 
{
public:
	// UnityEngine.Playables.PlayableOutputHandle UnityEngine.Playables.PlayableOutput::m_Handle
	PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  ___m_Handle_0;

public:
	inline static int32_t get_offset_of_m_Handle_0() { return static_cast<int32_t>(offsetof(PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345, ___m_Handle_0)); }
	inline PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  get_m_Handle_0() const { return ___m_Handle_0; }
	inline PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922 * get_address_of_m_Handle_0() { return &___m_Handle_0; }
	inline void set_m_Handle_0(PlayableOutputHandle_t0D0C9D8ACC1A4061BD4EAEB61F3EE0357052F922  value)
	{
		___m_Handle_0 = value;
	}
};

struct PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345_StaticFields
{
public:
	// UnityEngine.Playables.PlayableOutput UnityEngine.Playables.PlayableOutput::m_NullPlayableOutput
	PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345  ___m_NullPlayableOutput_1;

public:
	inline static int32_t get_offset_of_m_NullPlayableOutput_1() { return static_cast<int32_t>(offsetof(PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345_StaticFields, ___m_NullPlayableOutput_1)); }
	inline PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345  get_m_NullPlayableOutput_1() const { return ___m_NullPlayableOutput_1; }
	inline PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345 * get_address_of_m_NullPlayableOutput_1() { return &___m_NullPlayableOutput_1; }
	inline void set_m_NullPlayableOutput_1(PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345  value)
	{
		___m_NullPlayableOutput_1 = value;
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif // PLAYABLEOUTPUT_T5E024C3D28C983782CD4FDB2FA5AD23998D21345_H



static  RuntimeObject * UnresolvedVirtualCall_0 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_1 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_2 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_3 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_4 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_5 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_6 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_7 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_8 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  intptr_t UnresolvedVirtualCall_9 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_10 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int8_t ___SByte3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_11 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int16_t UnresolvedVirtualCall_12 (RuntimeObject * __this, int16_t ___Int161, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_13 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_14 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_15 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_16 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_17 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_18 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_19 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_20 (RuntimeObject * __this, RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717  ___RSAParameters1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_21 (RuntimeObject * __this, DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6  ___DSAParameters1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RSAParameters_t6A568C1275FA8F8C02615666D998134DCFFB9717  UnresolvedVirtualCall_22 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_23 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_24 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, RuntimeObject * ___Object4, int32_t ___Int325, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_25 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  DSAParameters_tCA1A96A151F47B1904693C457243E3B919425AC6  UnresolvedVirtualCall_26 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_27 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_28 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_29 (RuntimeObject * __this, RuntimeObject * ___Object1, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_30 (RuntimeObject * __this, RuntimeObject * ___Object1, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_31 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_32 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_33 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_34 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  ConsoleKeyInfo_t5BE3CE05E8258CDB5404256E96AF7C22BC5DE768  UnresolvedVirtualCall_35 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int16_t UnresolvedVirtualCall_36 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint8_t UnresolvedVirtualCall_37 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint16_t UnresolvedVirtualCall_38 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_39 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int64_t UnresolvedVirtualCall_40 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint64_t UnresolvedVirtualCall_41 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  float UnresolvedVirtualCall_42 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  double UnresolvedVirtualCall_43 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  UnresolvedVirtualCall_44 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  UnresolvedVirtualCall_45 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_46 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_47 (RuntimeObject * __this, DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  ___DateTime1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_48 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, RuntimeObject * ___Object4, int32_t ___Int325, int32_t ___Int326, int32_t ___Int327, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_49 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_50 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_51 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, int32_t ___Int323, int32_t ___Int324, int32_t ___Int325, int32_t ___Int326, int32_t ___Int327, int32_t ___Int328, RuntimeObject * ___Object9, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_52 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Guid_t  UnresolvedVirtualCall_53 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_54 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  UnresolvedVirtualCall_55 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, int32_t ___Int323, int32_t ___Int324, int32_t ___Int325, int32_t ___Int326, int32_t ___Int327, int32_t ___Int328, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  DateTime_t349B7449FBAAFF4192636E2B7A07694DA9236132  UnresolvedVirtualCall_56 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_57 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_58 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_59 (RuntimeObject * __this, int32_t ___Int321, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_60 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Nullable_1_t0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB  UnresolvedVirtualCall_61 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_62 (RuntimeObject * __this, int64_t ___Int641, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_63 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_64 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, int32_t ___Int324, int8_t ___SByte5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int64_t UnresolvedVirtualCall_65 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int64_t UnresolvedVirtualCall_66 (RuntimeObject * __this, int64_t ___Int641, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint8_t UnresolvedVirtualCall_67 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_68 (RuntimeObject * __this, uint8_t ___Byte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_69 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, RuntimeObject * ___Object4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_70 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, CancellationToken_t9E956952F7F20908F2AE72EDF36D97E6C7DB63AB  ___CancellationToken4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_71 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, RuntimeObject * ___Object4, int32_t ___Int325, int8_t ___SByte6, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_72 (RuntimeObject * __this, int16_t ___Int161, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_73 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  double UnresolvedVirtualCall_74 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_75 (RuntimeObject * __this, RuntimeObject * ___Object1, int8_t ___SByte2, int8_t ___SByte3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_76 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  UnresolvedVirtualCall_77 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E  UnresolvedVirtualCall_78 (RuntimeObject * __this, int32_t ___Int321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_79 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, RuntimeObject * ___Object4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_80 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_81 (RuntimeObject * __this, int64_t ___Int641, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int16_t UnresolvedVirtualCall_82 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint16_t UnresolvedVirtualCall_83 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_84 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint64_t UnresolvedVirtualCall_85 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  float UnresolvedVirtualCall_86 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Decimal_t44EE9DA309A1BF848308DE4DDFC070CAE6D95EE8  UnresolvedVirtualCall_87 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  DictionaryEntry_tB5348A26B94274FCC1DD77185BD5946E283B11A4  UnresolvedVirtualCall_88 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_89 (RuntimeObject * __this, TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  ___TimeSpan1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_90 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_91 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_92 (RuntimeObject * __this, RuntimeObject * ___Object1, int8_t ___SByte2, int8_t ___SByte3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  UnresolvedVirtualCall_93 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  UnresolvedVirtualCall_94 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  UnresolvedVirtualCall_95 (RuntimeObject * __this, TimeSpan_tA8069278ACE8A74D6DF7D514A9CD4432433F64C4  ___TimeSpan1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_96 (RuntimeObject * __this, RuntimeObject * ___Object1, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_97 (RuntimeObject * __this, RuntimeObject * ___Object1, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_98 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_99 (RuntimeObject * __this, int64_t ___Int641, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_100 (RuntimeObject * __this, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_101 (RuntimeObject * __this, int64_t ___Int641, RuntimeObject * ___Object2, int64_t ___Int643, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int64_t UnresolvedVirtualCall_102 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_103 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_104 (RuntimeObject * __this, float ___Single1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_105 (RuntimeObject * __this, double ___Double1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_106 (RuntimeObject * __this, uint16_t ___UInt161, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_107 (RuntimeObject * __this, uint32_t ___UInt321, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_108 (RuntimeObject * __this, uint64_t ___UInt641, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_109 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_110 (RuntimeObject * __this, TypedReference_t118BC3B643F75F52DB9C99D5E051299F886EB2A8  ___TypedReference1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_111 (RuntimeObject * __this, StreamingContext_t2CCDC54E0E8D078AF4A50E3A8B921B828A900034  ___StreamingContext1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeFieldHandle_t844BDF00E8E6FE69D9AEAA7657F09018B864F4EF  UnresolvedVirtualCall_112 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeMethodHandle_t85058E06EFF8AE085FAB91CE2B9E28E7F6FAE33F  UnresolvedVirtualCall_113 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_114 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_115 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, RuntimeObject * ___Object6, RuntimeObject * ___Object7, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeTypeHandle_t7B542280A22F0EC4EAC2061C29178845847A8B2D  UnresolvedVirtualCall_116 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_117 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_118 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_119 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, int32_t ___Int324, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_120 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, int32_t ___Int324, int32_t ___Int325, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_121 (RuntimeObject * __this, int16_t ___Int161, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_122 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_123 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, int8_t ___SByte4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_124 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int8_t ___SByte3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_125 (RuntimeObject * __this, int16_t ___Int161, int16_t ___Int162, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_126 (RuntimeObject * __this, int16_t ___Int161, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_127 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_128 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_129 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, RuntimeObject * ___Object6, RuntimeObject * ___Object7, RuntimeObject * ___Object8, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_130 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int8_t ___SByte3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_131 (RuntimeObject * __this, RuntimeObject * ___Object1, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_132 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, int32_t ___Int325, int32_t ___Int326, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_133 (RuntimeObject * __this, int32_t ___Int321, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_134 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, int32_t ___Int323, RuntimeObject * ___Object4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_135 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, int32_t ___Int324, RuntimeObject * ___Object5, RuntimeObject * ___Object6, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_136 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, RuntimeObject * ___Object3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, RuntimeObject * ___Object6, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  ValueTuple_2_t446756A8057B54D18CAD5BA1D73699DA4B40A264  UnresolvedVirtualCall_137 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  unitytls_errorstate_t64FA817A583B1CD3CB1AFCFF9606F1F2782ABBE6  UnresolvedVirtualCall_138 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_139 (RuntimeObject * __this, RuntimeObject * ___Object1, uint32_t ___UInt322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  unitytls_key_ref_tE908606656A7C49CA1EB734722E4C3DED7CE6E5B  UnresolvedVirtualCall_140 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_141 (RuntimeObject * __this, RuntimeObject * ___Object1, intptr_t ___IntPtr2, RuntimeObject * ___Object3, intptr_t ___IntPtr4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_142 (RuntimeObject * __this, RuntimeObject * ___Object1, intptr_t ___IntPtr2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_143 (RuntimeObject * __this, unitytls_tlsctx_protocolrange_t36243D72F83DAD47C95928314F58026DE8D38F47  ___unitytls_tlsctx_protocolrange1, unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2  ___unitytls_tlsctx_callbacks2, RuntimeObject * ___Object3, intptr_t ___IntPtr4, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_144 (RuntimeObject * __this, unitytls_tlsctx_protocolrange_t36243D72F83DAD47C95928314F58026DE8D38F47  ___unitytls_tlsctx_protocolrange1, unitytls_tlsctx_callbacks_t7BB5F622E014A8EC300C578657E2B0550DA828B2  ___unitytls_tlsctx_callbacks2, uint64_t ___UInt643, uint64_t ___UInt644, RuntimeObject * ___Object5, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_145 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  intptr_t UnresolvedVirtualCall_146 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, intptr_t ___IntPtr3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_147 (RuntimeObject * __this, RuntimeObject * ___Object1, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_148 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_149 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, intptr_t ___IntPtr3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  intptr_t UnresolvedVirtualCall_150 (RuntimeObject * __this, unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7  ___unitytls_x509_ref1, RuntimeObject * ___Object2, intptr_t ___IntPtr3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_151 (RuntimeObject * __this, RuntimeObject * ___Object1, unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7  ___unitytls_x509_ref2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  UnresolvedVirtualCall_152 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7  UnresolvedVirtualCall_153 (RuntimeObject * __this, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref1, intptr_t ___IntPtr2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_154 (RuntimeObject * __this, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref1, RuntimeObject * ___Object2, intptr_t ___IntPtr3, RuntimeObject * ___Object4, RuntimeObject * ___Object5, RuntimeObject * ___Object6, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_155 (RuntimeObject * __this, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref1, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref2, RuntimeObject * ___Object3, intptr_t ___IntPtr4, RuntimeObject * ___Object5, RuntimeObject * ___Object6, RuntimeObject * ___Object7, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_156 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, intptr_t ___IntPtr4, RuntimeObject * ___Object5, intptr_t ___IntPtr6, RuntimeObject * ___Object7, RuntimeObject * ___Object8, RuntimeObject * ___Object9, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_157 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, RuntimeObject * ___Object3, intptr_t ___IntPtr4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_158 (RuntimeObject * __this, RuntimeObject * ___Object1, unitytls_x509list_ref_tF01A6BF5ADA9C454E6B975D2669AF22D27555BF6  ___unitytls_x509list_ref2, RuntimeObject * ___Object3, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_159 (RuntimeObject * __this, RuntimeObject * ___Object1, unitytls_x509_ref_tE1ED17887226610A1328A57FF787396C9457E7B7  ___unitytls_x509_ref2, uint32_t ___UInt323, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_160 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int8_t ___SByte3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_161 (RuntimeObject * __this, CullingGroupEvent_tC36FFE61D0A4E7B31F575A1FCAEE05AC41FACA85  ___CullingGroupEvent1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_162 (RuntimeObject * __this, ScriptableRenderContext_tEB273FD29C26BEA887D85DCCAE9B10D1A521EE6D  ___ScriptableRenderContext1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_163 (RuntimeObject * __this, int32_t ___Int321, RuntimeObject * ___Object2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_164 (RuntimeObject * __this, Guid_t  ___Guid1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_165 (RuntimeObject * __this, Guid_t  ___Guid1, RuntimeObject * ___Object2, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Playable_t4ABB910C374FCAB6B926DA4D34A85857A59950D0  UnresolvedVirtualCall_166 (RuntimeObject * __this, PlayableGraph_tEC38BBCA59BDD496F75037F220984D41339AB8BA  ___PlayableGraph1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  PlayableOutput_t5E024C3D28C983782CD4FDB2FA5AD23998D21345  UnresolvedVirtualCall_167 (RuntimeObject * __this, PlayableGraph_tEC38BBCA59BDD496F75037F220984D41339AB8BA  ___PlayableGraph1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_168 (RuntimeObject * __this, PropertyName_t75EB843FEA2EC372093479A35C24364D2DF98529  ___PropertyName1, float ___Single2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  uint32_t UnresolvedVirtualCall_169 (RuntimeObject * __this, uint32_t ___UInt321, intptr_t ___IntPtr2, uint32_t ___UInt323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Range_t2332F6C6E1E19A355F5C1A93FF4434B92FBDBABC  UnresolvedVirtualCall_170 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_171 (RuntimeObject * __this, float ___Single1, float ___Single2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_172 (RuntimeObject * __this, int32_t ___Int321, int64_t ___Int642, int64_t ___Int643, int8_t ___SByte4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_173 (RuntimeObject * __this, RuntimeObject * ___Object1, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_22, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_174 (RuntimeObject * __this, RuntimeObject * ___Object1, int32_t ___Int322, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_175 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_176 (RuntimeObject * __this, RuntimeObject * ___Object1, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock2, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_177 (RuntimeObject * __this, RuntimeObject * ___Object1, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest2, int32_t ___Int323, int32_t ___Int324, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_178 (RuntimeObject * __this, AsyncLocalValueChangedArgs_1_t64BF6800935406CA808E9821DF12DBB72A71640D  ___AsyncLocalValueChangedArgs_11, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_179 (RuntimeObject * __this, int8_t ___SByte1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_180 (RuntimeObject * __this, int8_t ___SByte1, int8_t ___SByte2, int32_t ___Int323, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  KeyValuePair_2_t23481547E419E16E3B96A303578C1EB685C99EEE  UnresolvedVirtualCall_181 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_182 (RuntimeObject * __this, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_21, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_22, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_183 (RuntimeObject * __this, uint64_t ___UInt641, uint64_t ___UInt642, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_184 (RuntimeObject * __this, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock1, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_185 (RuntimeObject * __this, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest1, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_186 (RuntimeObject * __this, int8_t ___SByte1, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_187 (RuntimeObject * __this, ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C  ___ResourceLocator1, ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C  ___ResourceLocator2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_188 (RuntimeObject * __this, int8_t ___SByte1, int8_t ___SByte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_189 (RuntimeObject * __this, int8_t ___SByte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_190 (RuntimeObject * __this, uint8_t ___Byte1, uint8_t ___Byte2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_191 (RuntimeObject * __this, uint8_t ___Byte1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_192 (RuntimeObject * __this, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_21, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_22, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_193 (RuntimeObject * __this, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_21, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_194 (RuntimeObject * __this, ResourceLocator_t1783916E271C27CB09DF57E7E5ED08ECA4B3275C  ___ResourceLocator1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_195 (RuntimeObject * __this, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock1, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_196 (RuntimeObject * __this, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_197 (RuntimeObject * __this, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest1, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_198 (RuntimeObject * __this, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  UnresolvedVirtualCall_199 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  UnresolvedVirtualCall_200 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  UnresolvedVirtualCall_201 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_202 (RuntimeObject * __this, CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E  ___CustomAttributeNamedArgument1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_203 (RuntimeObject * __this, CustomAttributeNamedArgument_t08BA731A94FD7F173551DF3098384CB9B3056E9E  ___CustomAttributeNamedArgument1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_204 (RuntimeObject * __this, CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  ___CustomAttributeTypedArgument1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int32_t UnresolvedVirtualCall_205 (RuntimeObject * __this, CustomAttributeTypedArgument_t238ACCB3A438CB5EDE4A924C637B288CCEC958E8  ___CustomAttributeTypedArgument1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  VoidTaskResult_t66EBC10DDE738848DB00F6EC1A2536D7D4715F40  UnresolvedVirtualCall_206 (RuntimeObject * __this, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  Nullable_1_t0D03270832B3FFDDC0E7C2D89D4A0EA25376A1EB  UnresolvedVirtualCall_207 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  VoidTaskResult_t66EBC10DDE738848DB00F6EC1A2536D7D4715F40  UnresolvedVirtualCall_208 (RuntimeObject * __this, RuntimeObject * ___Object1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_209 (RuntimeObject * __this, int32_t ___Int321, intptr_t ___IntPtr2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  VoidTaskResult_t66EBC10DDE738848DB00F6EC1A2536D7D4715F40  UnresolvedVirtualCall_210 (RuntimeObject * __this, RuntimeObject * ___Object1, RuntimeObject * ___Object2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  RuntimeObject * UnresolvedVirtualCall_211 (RuntimeObject * __this, RuntimeObject * ___Object1, ReadWriteParameters_t5A9E416E0129249869039FC606326558DA3B597F  ___ReadWriteParameters2, RuntimeObject * ___Object3, RuntimeObject * ___Object4, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_212 (RuntimeObject * __this, KeyValuePair_2_t5DDBBB9A3C8CBE3A4A39721E8F0A10AEBF13737B  ___KeyValuePair_21, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_213 (RuntimeObject * __this, OrderBlock_t3B2BBCE8320FAEC3DB605F7DC9AB641102F53727  ___OrderBlock1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  int8_t UnresolvedVirtualCall_214 (RuntimeObject * __this, WorkRequest_t0247B62D135204EAA95FC0B2EC829CB27B433F94  ___WorkRequest1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_215 (RuntimeObject * __this, Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2  ___Scene1, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_216 (RuntimeObject * __this, Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2  ___Scene1, int32_t ___Int322, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

static  void UnresolvedVirtualCall_217 (RuntimeObject * __this, Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2  ___Scene1, Scene_t942E023788C2BC9FBB7EC8356B4FB0088B2CFED2  ___Scene2, const RuntimeMethod* method)
{
	il2cpp_codegen_raise_execution_engine_exception(method);
	il2cpp_codegen_no_return();
}

extern const Il2CppMethodPointer g_UnresolvedVirtualMethodPointers[218] = 
{
	(const Il2CppMethodPointer) UnresolvedVirtualCall_0,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_1,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_2,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_3,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_4,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_5,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_6,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_7,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_8,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_9,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_10,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_11,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_12,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_13,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_14,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_15,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_16,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_17,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_18,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_19,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_20,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_21,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_22,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_23,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_24,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_25,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_26,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_27,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_28,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_29,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_30,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_31,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_32,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_33,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_34,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_35,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_36,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_37,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_38,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_39,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_40,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_41,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_42,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_43,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_44,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_45,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_46,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_47,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_48,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_49,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_50,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_51,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_52,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_53,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_54,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_55,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_56,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_57,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_58,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_59,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_60,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_61,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_62,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_63,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_64,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_65,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_66,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_67,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_68,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_69,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_70,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_71,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_72,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_73,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_74,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_75,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_76,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_77,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_78,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_79,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_80,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_81,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_82,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_83,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_84,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_85,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_86,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_87,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_88,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_89,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_90,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_91,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_92,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_93,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_94,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_95,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_96,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_97,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_98,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_99,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_100,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_101,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_102,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_103,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_104,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_105,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_106,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_107,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_108,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_109,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_110,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_111,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_112,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_113,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_114,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_115,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_116,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_117,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_118,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_119,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_120,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_121,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_122,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_123,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_124,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_125,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_126,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_127,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_128,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_129,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_130,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_131,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_132,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_133,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_134,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_135,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_136,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_137,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_138,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_139,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_140,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_141,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_142,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_143,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_144,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_145,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_146,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_147,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_148,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_149,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_150,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_151,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_152,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_153,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_154,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_155,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_156,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_157,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_158,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_159,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_160,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_161,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_162,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_163,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_164,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_165,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_166,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_167,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_168,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_169,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_170,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_171,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_172,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_173,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_174,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_175,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_176,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_177,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_178,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_179,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_180,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_181,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_182,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_183,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_184,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_185,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_186,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_187,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_188,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_189,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_190,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_191,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_192,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_193,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_194,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_195,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_196,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_197,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_198,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_199,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_200,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_201,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_202,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_203,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_204,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_205,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_206,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_207,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_208,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_209,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_210,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_211,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_212,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_213,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_214,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_215,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_216,
	(const Il2CppMethodPointer) UnresolvedVirtualCall_217,
};
