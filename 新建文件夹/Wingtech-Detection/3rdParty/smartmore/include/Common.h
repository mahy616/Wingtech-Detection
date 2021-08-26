/*
 * @Descripttion: 
 * @version: 
 * @Author: max.ma
 * @Date: 2020-11-19 16:55:35
 * @LastEditors: max.ma
 * @LastEditTime: 2020-11-23 22:18:51
 */
/*******************************************************************************
 *  FILENAME:      Common.h
 *
 *  AUTHORS:       Wang Xiaofei    START DATE: Tuesday November 3rd 2020
 *
 *  LAST MODIFIED: Thursday, November 5th 2020, 3:55:59 pm
 *
 *  CONTACT:       xiaofei.wang@smartmore.com
*******************************************************************************/
#ifndef __SM_COMMON_H__
#define __SM_COMMON_H__

#ifdef _MSC_VER
#ifdef SM_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else
#define DLL_API
#endif

#ifdef _MSC_VER
using CHAR_T = wchar_t;
#else
using CHAR_T = char;
#endif

#include <array>
namespace smartmore
{
    enum class ResultCode
    {
        Success = 0,

        NotInited = 10001,
        BadModel = 10101,
        BadInput = 10102,
        NotImage = 10103,
        NotVideo = 10104,

        InternalError = 20001,
        OutOfMemory = 20002,
        CudaError = 20003,

        NoLicense = 30000,
        CallLimited = 30001,
        LicenseExpired = 30002,
        WrongAppName = 30003,
    };

    enum class QCCode
    {
        NotAvailable = 0,
        OK = 1,
        NG = 2,
    };

} // namespace smartmore

#endif
